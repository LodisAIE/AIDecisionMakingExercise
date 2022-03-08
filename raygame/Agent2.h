#pragma once
#include "Character.h"

class Agent2 :
    public Character
{
public:
    Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health);
    virtual void onCollision(Actor* actor) override;
    virtual void update(float deltaTime) override;

    virtual void onDeath();
    virtual void onDamageRecieved() {};
};


