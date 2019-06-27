#include "Player.h"
#include "Input.h"
#include "Asteroids.h"

Player::Player() : GameObject({new Collider(*this, Vector2(0.0f, 0.0f), 50.0f)})
{
	id = (char)Object::player;
	turret.transform.SetParent(this);
	//turret.transform.Position = Vector2(0.0f, 0.0f);

	rotVel = 0;
	velocity = Vector2(0, 0);

	// Load the player's sprite.
	m_texture = new aie::Texture("./textures/ship.png");

	// Set the player's position.
	transform.Position = Vector2(600, 400);
}

Player::~Player()
{
	id = (char)Object::player;
	// Delete the player's sprite.
	delete m_texture;
	m_texture = nullptr;
}

void Player::update(float deltaTime)
{
	float Width = Master::application->GetWindowWidth();
	float Height = Master::application->GetWindowHeight();

	// Update input for the player.
	aie::Input* input = aie::Input::GetInstance();
	if (input->IsKeyDown(aie::INPUT_KEY_A))
	{
		rotVel += deltaTime * RotationSpeed;
	}
	if (input->IsKeyDown(aie::INPUT_KEY_D))
	{
		rotVel -= deltaTime * RotationSpeed;
	}

	rotVel *= 0.90f;
	transform.Rotation += rotVel;

	Vector2 dir(sinf(transform.Rotation), -cosf(transform.Rotation));

	if (input->IsKeyDown(aie::INPUT_KEY_W))
	{
		velocity -= dir * MoveSpeed * deltaTime;
	}
	if (input->IsKeyDown(aie::INPUT_KEY_S))
	{
		velocity += dir * MoveSpeed * deltaTime;
	}

	velocity *= 0.95f;
	transform.Position += velocity;


	if (transform.Position.x > Width)transform.Position.x = 0;
	if (transform.Position.x < 0)transform.Position.x = Width;
	if (transform.Position.y > Height)transform.Position.y = 0;
	if (transform.Position.y < 0)transform.Position.y = Height;
}

void Player::draw(aie::Renderer2D& renderer)
{
	// Draw the player's sprite.
	//renderer.DrawSprite(m_texture, transform.Position.x, transform.Position.y);
	renderer.DrawSpriteTransformed3x3(m_texture, transform.globalTransform);
}

void Player::OnCollision(GameObject& other){
	if (other.id == (char)Object::asteroid){
		//Master::application->Quit();
		//system("pause");
	}
}
