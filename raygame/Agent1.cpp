#include "Agent1.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);

}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);

}

void Agent1::onDeath()
{
	Character::onDeath();

}
