#include "Character.h"
#include <string.h>
#include "Transform2D.h"
#include "CircleCollider.h"
#include "SpriteComponent.h"

Character::Character(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_health = health;
	getTransform()->setScale({ 50,50 });
	setCollider(new CircleCollider(50, this));
}

void Character::onCollision(Actor* actor)
{
	if (strcmp(actor->getName(), "Ball") == 0)
		pickUpBall(actor);
}

void Character::start()
{
	Agent::start();
	m_spriteComponent = getComponent<SpriteComponent>();
}

void Character::update(float deltaTime)
{
	Agent::update(deltaTime);
	
	m_isAlive = m_health > 0;

	//If the actor isn't alive and is active in the scene...
	if (!getIsAlive() && getActive())
	{
		//...call the onDeath function
		onDeath();
		return;
	}

	//If the actor isn't alive...
	if (!getIsAlive())
	{
		//...start the timer for a respawn
		m_currentTime += deltaTime;
		//If the enough time has passed...
		if (m_currentTime >= m_respawnTime)
		{
			//...respawn the actor
			setActive(true);
			m_health = 3;
			m_currentTime = 0;
			m_isInvincible = true;
		}
	}
	//otherwise if the actor is invincible...
	else if (m_isInvincible)
	{
		//...increase the invincibility timer and change the color
		m_currentTime += deltaTime;
		m_isInvincible = m_currentTime < m_invincibilityTime;
		m_spriteComponent->setColor(RAYLIB_H::GREEN);
	}
	//otherwise...
	else
	{
		//...reset the timer and the color
		m_spriteComponent->setColor(RAYLIB_H::WHITE);
		m_currentTime = 0;
	}
}

void Character::onDeath()
{
	//Actor's are disabled in the scene and must drop the ball on death
	setActive(false);
	dropBall();
}

void Character::takeDamage()
{
	//Do nothing if the actor is invincible
	if (m_isInvincible) return;

	//Otherwise decrement the health and activate invincibility
	m_health--;
	onDamageRecieved();
	m_isInvincible = true;
}

void Character::pickUpBall(Actor* ball)
{
	m_ball = ball;
	m_ball->setActive(false);
	m_hasBall = true;
}

void Character::dropBall()
{
	if (!m_ball) return;

	m_ball->setActive(true);
	m_ball->getTransform()->setWorldPostion(getTransform()->getWorldPosition());
	m_ball = nullptr;
	m_hasBall = false;
}
