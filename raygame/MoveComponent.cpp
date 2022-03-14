#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void MoveComponent::update(float deltaTime)
{
	//Add the new velocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	//Update facing
	if (getVelocity().getMagnitude() > 0)
		getOwner()->getTransform()->setForward(getVelocity().getNormalized());

	if (getVelocity().getMagnitude() > getMaxSpeed())
		setVelocity(getVelocity().getNormalized() * getMaxSpeed());

	//Set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
