#include "Player.h"
#include "Input.h"
#include "Asteroids.h"

Player::Player() : GameObject({new Collider(*this, Vector2(0.0f, 0.0f), 50.0f)})
{
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
	float speed = 200.0f;
	// Update input for the player.
	aie::Input* input = aie::Input::GetInstance();
	if (input->IsKeyDown(aie::INPUT_KEY_LEFT))
	{
		transform.Position.x -= speed * deltaTime;
	}
	if (input->IsKeyDown(aie::INPUT_KEY_RIGHT))
	{
		transform.Position.x += speed * deltaTime;
	}
	if (input->IsKeyDown(aie::INPUT_KEY_UP))
	{
		transform.Position.y += speed * deltaTime;
	}
	if (input->IsKeyDown(aie::INPUT_KEY_DOWN))
	{
		transform.Position.y -= speed * deltaTime;
	}
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
