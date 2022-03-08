#pragma once
#include "Actor.h"
class Goal :
    public Actor
{
public:
    void onCollision(Actor* actor) override;
};

