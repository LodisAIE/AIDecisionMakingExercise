#include "Agent2.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);

}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);

}

void Agent2::onDeath()
{
	Character::onDeath();

}