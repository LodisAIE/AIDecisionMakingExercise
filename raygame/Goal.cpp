#include "Goal.h"
#include "Character.h"
#include "GameManager.h"
#include "raylib.h"
#include "Transform2D.h"
#include "AABBCollider.h"

Goal::Goal(float x, float y, const char* name, Actor* owner) : Actor(x, y, name)
{
	m_owner = owner;
	getTransform()->setScale({ 50,100 });
	setCollider(new AABBCollider(getTransform()->getScale().x, getTransform()->getScale().y, this));
}

void Goal::onCollision(Actor* actor)
{
	Character* character = dynamic_cast<Character*>(actor);

	if (!character || character != m_owner) return;

	if (character->getHasBall())
		(GameManager::getInstance()->*m_onGoalScored)(character);
}

void Goal::draw()
{
	MathLibrary::Vector2 position = getTransform()->getWorldPosition();
	MathLibrary::Vector2 scale = getTransform()->getScale();

	RAYLIB_H::DrawRectangle(position.x - scale.x / 2, position.y - scale.y / 2, scale.x, scale.y, GREEN);
}
