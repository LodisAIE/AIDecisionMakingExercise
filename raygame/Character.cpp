#include "Character.h"
#include <string.h>
#include "Transform2D.h"
#include "CircleCollider.h"

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

void Character::update(float deltaTime)
{
	Agent::update(deltaTime);

	if (!getIsAlive() && getActive())
	{
		onDeath();
		return;
	}

	if (!getIsAlive())
	{
		m_currentTime += deltaTime;
		if (m_currentTime >= m_respawnTime)
		{
			setActive(true);
			m_health = 3;
			m_currentTime = 0;
		}
	}
	
	m_isAlive = m_health > 0;
}

void Character::onDeath()
{
	setActive(false);
	dropBall();
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
