#pragma once
#include "Actor.h"
#include "GameManager.h"

class Character;

typedef void (GameManager::*ScoreEvent)(Character* character);
class Goal :
    public Actor
{
public:
    /// <param name="x">The x position of the goal</param>
    /// <param name="y">The y position of the goal</param>
    /// <param name="name">The name of the goal</param>
    /// <param name="owner">The actor that will score if they collide with this goal</param>
    Goal(float x, float y, const char* name, Actor* owner);

    /// <summary>
    /// Inherited from the actor class. 
    /// Increases points and resets the agent's postion if the owner
    /// collides with this goal with the ball in hand.
    /// </summary>
    /// <param name="actor"></param>
    void onCollision(Actor* actor) override;

    void draw() override;

private:
    ScoreEvent m_onGoalScored;
    Actor* m_owner;
    friend GameManager;
};

