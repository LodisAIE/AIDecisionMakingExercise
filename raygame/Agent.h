#pragma once
#include "Actor.h"
#include "ActorArray.h"
#include <Vector2.h>

class SteeringComponent;
class MoveComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed);
	void update(float deltaTime) override;
	/// <summary>
	/// Called when a component is added. If the component is a steering component, it 
	/// is added to the array of steering components
	/// </summary>
	/// <param name="component"></param>
	void onAddComponent(Component* component) override;

	/// <summary>
	/// Gets a float representing the maximum magnitude of the force vector
	/// </summary>
	float getMaxForce() { return m_maxForce; }
	/// <summary>
	/// Sets a float representing the maximum magnitude of the force vector
	/// </summary>
	void setMaxForce(float maxForce) { m_maxForce = maxForce; }
	/// <summary>
	/// Gets the move component attached to this agent
	/// </summary>
	MoveComponent* getMoveComponent() { return m_moveComponent; }

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	float m_maxForce;
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_force;
};

