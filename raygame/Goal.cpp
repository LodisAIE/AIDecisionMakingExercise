#include "Goal.h"
#include "Character.h"

void Goal::onCollision(Actor* actor)
{
	Character* character = dynamic_cast<Character*>(actor);

	if (!character) return;

	if (character->getHasBall())
		//increase point here
		
}
