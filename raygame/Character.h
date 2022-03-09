#pragma once
#include "Agent.h"
#include "GameManager.h"

class Character :
    public Agent
{
public:
    Character(float x, float y, const char* name, float maxForce, float maxSpeed, float health);
    virtual void onCollision(Actor* actor) override;
    virtual void update(float deltaTime) override;

    virtual void onDeath();
    virtual void onDamageRecieved() {};

    void takeDamage() { m_health--; onDamageRecieved(); }

    bool getIsAlive() { return m_isAlive; }
    float getHealth() { return m_health; }
    bool getHasBall() { return m_hasBall; }

private:
    void pickUpBall(Actor* ball);
    void dropBall();
    friend void GameManager::resetPositions();
    Actor* m_ball;
    float m_health;
    bool m_hasBall;
    bool m_isAlive = true;
    float m_respawnTime = 2;
    float m_currentTime = 0;
};

