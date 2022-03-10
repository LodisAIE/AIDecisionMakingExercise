#include "Agent1.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "Goal.h"
#include "GameManager.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
	if (dynamic_cast<Character*>(actor))
		for (int i = 0; i < 3; i++)
			takeDamage();
}

void Agent1::start()
{
	Character::start();
	SeekComponent* comp = new SeekComponent();
	comp->setTarget(GameManager::getInstance()->getRightGoal());
	addComponent(comp);
	//add steering behaviours here
}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);

}

void Agent1::onDeath()
{
	Character::onDeath();

}
