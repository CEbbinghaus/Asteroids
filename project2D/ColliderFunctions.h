#include <atyp_Vector2.h>
#include "ColliderManager.h"
#include "CircleCollider.h"
#include "BoxCollider.h"
#include "LineCollider.h"


bool CircleCircle(Colission& out, Collider* a, Collider* b){
	CircleCollider& ca = *(CircleCollider*)a;
	CircleCollider& cb = *(CircleCollider*)b;

	Vector2 aPos = ca.GetWorldPosition();
	Vector2 bPos = cb.GetWorldPosition();

	float distance = (aPos - bPos).magnitude();

	//Exit Early since the Two Circles arent colliding
	if(distance > ca.radius + cb.radius)return false;

	//Check for Two Colliding Objects at the same position
	if(distance == 0.0f){
		out.depth = ca.radius;
    	out.normal = Vector2( 1, 0 );
	} else{
		out.depth = ((ca.radius + cb.radius) - distance);
		out.normal = (aPos - bPos).normalise();
	}

	return true;
}

bool CircleBox(Colission& out, Collider* a, Collider* b){
	CircleCollider& ca = *(CircleCollider*)a;
	BoxCollider& bb = *(BoxCollider*)b;

	Vector2 center = Vector2::clamp(ca.GetWorldPosition(), bb.min(), bb.max());

	Vector2 displacement = center - ca.GetWorldPosition();

	float overlap = ca.radius - displacement.magnitude();

	if (overlap > 0.0f){
		out.normal = displacement.normalise();
		out.depth = overlap;
		return true;
	}
	return false;
}

bool CircleLine(Colission& out, Collider* a, Collider* b){
	CircleCollider& ca = *(CircleCollider*)a;
	LineCollider& lb = *(LineCollider*)b;
	return false;
}

bool BoxBox(Colission& out, Collider* a, Collider* b){
	BoxCollider& ba = *(BoxCollider*)a;
	BoxCollider& bb = *(BoxCollider*)b;

	Vector2 apos = ba.GetWorldPosition();
	Vector2 bpos = bb.GetWorldPosition();

	Vector2 distance = apos - bpos;
	
	Vector2 amax = ba.max();
	Vector2 bmax = bb.max();
	Vector2 amin = ba.min();
	Vector2 bmin = bb.min();

	//immediately Dismiss Non Colliding Boxes
	if(!(amax.x >= bmin.x && amin.x <= bmax.x &&
	   amax.y >= bmin.y && amin.y <= bmax.y)){
		return false;
	}

	// Calculate half extents along x axis for each object
	float a_extent = (amax.x - amin.x) / 2;
	float b_extent = (bmax.x - bmin.x) / 2;
	
	// Calculate overlap on x axis
	float x_overlap = a_extent + b_extent - abs( distance.x );
	
	// SAT test on x axis
	if(x_overlap > 0){
		// Calculate half extents along x axis for each object
		float a_extent = (amax.y - amin.y) / 2;
		float b_extent = (bmax.y - bmin.y) / 2;
	
		// Calculate overlap on y axis
		float y_overlap = a_extent + b_extent - abs( distance.y );
	
		// SAT test on y axis
		if(y_overlap > 0){
			// Find out which axis is axis of least penetration
			if(x_overlap > y_overlap){
				// Point towards B knowing that n points from A to B
				if(distance.x < 0)
					out.normal = Vector2( -1, 0 );
				else
					out.normal = Vector2( 0, 0 );

				out.depth = x_overlap;
			}else{
				// Point toward B knowing that n points from A to B
				if(distance.y < 0)
					out.normal = Vector2( 0, -1 );
				else
					out.normal = Vector2( 0, 1 );

				out.depth = y_overlap;
			}
			return true;
		}
	}

	// Vector2 aextent = (amax - amin) / 2;
	// Vector2 bextent = (bmax - bmin) / 2;

	// Vector2 overlap = aextent + bextent - Vector2::Abs(distance);

	// if(overlap.x > overlap.y){
	// 	if(overlap.x > 0)
	// 		out.normal = Vector2(1, 0);
	// 	else
	// 		out.normal = Vector2(-1, 0);
	// 	out.depth = overlap.x;
	// }else{
	// 	if(overlap.y > 0)
	// 		out.normal = Vector2(0, 1);
	// 	else
	// 		out.normal = Vector2(0, -1);
	// 	out.depth = overlap.y;
	// }
	// return true;

}

bool BoxLine(Colission& out, Collider* a, Collider* b){
	BoxCollider& sa = *(BoxCollider*)a;
	LineCollider& lb = *(LineCollider*)b;
	return false;
}

bool LineLine(Colission& out, Collider* a, Collider* b){
	out.depth = 0;
	out.normal = Vector2(0.0f);
	return false;
}