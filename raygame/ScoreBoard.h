#pragma once
#include "Actor.h"
#include "ActorArray.h"
class UITextComponent;

class ScoreBoard :
	public Actor
{
public:
	/// <param name="x">The x position of the center of the hud</param>
	/// <param name="y">The y position of the center of the hud</param>
	/// <param name="name">The name of the player hud</param>
	ScoreBoard();
	
	//Inherited from the actor class
	void update(float deltaTime) override;

private:
	UITextComponent* m_agent1ScoreText;
	UITextComponent* m_agent2ScoreText;

	Actor* m_agent1Score;
	Actor* m_agent2Score;
};

