#include "Player.h"
#include "Input.h"
#include "Asteroids.h"

Player::Player() : GameObject({new CircleCollider(*this, Vector2(0.0f, 0.0f), 50.0f), new Rigidbody(*this)}), invunerability(2.0f){
	lives = 3;
	id = (char)Object::player;
	turret.transform.SetParent(this);
	//turret.transform.Position = Vector2(0.0f, 0.0f);

	rb = GetComponent<Rigidbody>();

	CircleCollider* c = GetComponent<CircleCollider>();
	if(c)
		c->layerMask = 0b10;

	rotVel = 0;
	velocity = Vector2(0, 0);

	// Load the player's sprite.
	m_texture = new aie::Texture("./textures/ship.png");

	// Set the player's position.
	transform.Position = Vector2(600, 400);
}

Player::~Player(){
	id = (char)Object::player;
	// Delete the player's sprite.
	delete m_texture;
	m_texture = nullptr;
}

void Player::update(float deltaTime){
	invunerability.Update(deltaTime);
	float Width = Master::application->GetWindowWidth();
	float Height = Master::application->GetWindowHeight();

	// Update input for the player.
	aie::Input* input = aie::Input::GetInstance();
	if(input->IsKeyDown(aie::INPUT_KEY_A)){
		rotVel += RotationSpeed * deltaTime;
	}
	if(input->IsKeyDown(aie::INPUT_KEY_D)){
		rotVel -= RotationSpeed * deltaTime;
	}

	rotVel -= (rotVel * 5.0f * deltaTime);
	transform.Rotation += rotVel * deltaTime;

	Vector2 dir(sinf(transform.Rotation), -cosf(transform.Rotation));

	if(input->IsKeyDown(aie::INPUT_KEY_W)){
		velocity -= dir * MoveSpeed * deltaTime;
	}
	if(input->IsKeyDown(aie::INPUT_KEY_S)){
		velocity += dir * MoveSpeed * deltaTime;
	}

	velocity -= (velocity * 4.0f * deltaTime);
	//transform.Position += velocity * deltaTime;
	rb->velocity = velocity;

	if(transform.Position.x > Width)transform.Position.x = 0;
	if(transform.Position.x < 0)transform.Position.x = Width;
	if(transform.Position.y > Height)transform.Position.y = 0;
	if(transform.Position.y < 0)transform.Position.y = Height;
}

void Player::draw(aie::Renderer2D& renderer){
	renderer.SetRenderColour(invunerability.hasRunOut ? 0xffffffff : 0xffffff58);
	renderer.DrawSpriteTransformed3x3(m_texture, transform.globalTransform);
	renderer.SetRenderColour(0xffffffff);
}

void Player::OnCollision(GameObject& other){
	if(other.id == (char)Object::asteroid){
		if(invunerability.hasRunOut){
			invunerability.Reset();
			--lives;
			if(lives <= 0){
				Master::application->Quit();
			}
		}
	}
}
