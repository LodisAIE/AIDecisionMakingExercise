#pragma once
#include "Actor.h"
class Goal :
    public Actor
{
public:
    Goal(float x, float y, const char* name, Actor* owner);
    void onCollision(Actor* actor) override;

    void draw() override;

private:
    Actor* m_owner;
};

