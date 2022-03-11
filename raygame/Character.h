#pragma once
#include "Agent.h"
#include "GameManager.h"

class SpriteComponent;

class Character :
    public Agent
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    Character(float x, float y, const char* name, float maxForce, float maxSpeed, float health);
    /// <summary>
    /// Inherited from the Agent class. 
    /// Characters pick up the ball if they collide with it
    /// </summary>
    virtual void onCollision(Actor* actor) override;
    /// <summary>
    /// Inherited from the Agent class. 
    /// Initializes the sprite component
    /// </summary>
    virtual void start() override;
    /// <summary>
    /// Inherited from the Agent class. 
    /// Handles invincibility and respawning
    /// </summary>
    virtual void update(float deltaTime) override;

    /// <summary>
    /// Called when a character's health reaches zero
    /// </summary>
    virtual void onDeath();
    /// <summary>
    /// Called when the character takes damage
    /// </summary>
    virtual void onDamageRecieved() {};

    /// <summary>
    /// Decrements the character's health by one and activates invincibility
    /// </summary>
    void takeDamage();

    /// <summary>
    /// Gets whether or not this character's health is greater than zero
    /// </summary>
    bool getIsAlive() { return m_isAlive; }
    /// <summary>
    /// Gets the current amount of health this character has
    /// </summary>
    float getHealth() { return m_health; }
    /// <summary>
    /// Gets whether or not this character has the ball
    /// </summary>
    bool getHasBall() { return m_hasBall; }

private:
    void pickUpBall(Actor* ball);
    void dropBall();
    friend class GameManager;
    Actor* m_ball;
    float m_health;
    bool m_hasBall;
    bool m_isAlive = true;
    bool m_isInvincible;
    float m_respawnTime = 1;
    float m_invincibilityTime = 0.4f;
    float m_currentTime = 0;
    SpriteComponent* m_spriteComponent;
};

