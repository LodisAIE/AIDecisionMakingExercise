#include "Character.h"
#include <string.h>
#include "Transform2D.h"

Character::Character(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_health = health;
}

void Character::onCollision(Actor* actor)
{
	if (strcmp(actor->getName(), "Ball") == 0)
		pickUpBall(actor);
}

void Character::update(float deltaTime)
{
	Agent::update(deltaTime);
	

	if (!getIsAlive())
		onDeath();
	
	m_isAlive = m_health > 0;
}

void Character::onDeath()
{
	dropBall();
}

void Character::pickUpBall(Actor* ball)
{
	m_ball = ball;
	m_ball->setActive(false);
}

void Character::dropBall()
{
	m_ball->setActive(true);
	m_ball->getTransform()->setWorldPostion(getTransform()->getWorldPosition());
	m_ball = nullptr;
}
