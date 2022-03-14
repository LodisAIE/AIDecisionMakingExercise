#pragma once
#include <Vector2.h>
#include "raylib.h"
#include "Engine.h"

class Character;
class ScoreBoard;
class Actor;
class Goal;

class GameManager
{
public:
	void init(Character* agent1, Character* agent2, Actor* ball, int pointsToWin);

	/// <summary>
	/// Gets the single instance of the game manager object
	/// </summary>
	/// <returns></returns>
	static GameManager* getInstance();

	/// <summary>
	/// Gets the the amount of points agent 1 currently has
	/// </summary>
	int getAgent1Points() { return m_agent1Points; }
	/// <summary>
	/// Gets the the amount of points agent 2 currently has
	/// </summary>
	int getAgent2Points() { return m_agent2Points; }

	/// <summary>
	/// Gets a reference to agent 1
	/// </summary>
	Character* getAgent1() { return m_agent1; }
	/// <summary>
	/// Gets a reference to agent 2
	/// </summary>
	Character* getAgent2() { return m_agent2; }

	/// <summary>
	/// Gets a reference to agent 2's goal
	/// </summary>
	Goal* getLeftGoal() { return m_agent1Goal; }
	/// <summary>
	/// Gets a reference to agent 1's goal
	/// </summary>
	Goal* getRightGoal() { return m_agent2Goal; }

	/// <summary>
	/// Returns the ball. The ball is no longer updated when carried by an agent.
	/// </summary>
	Actor* getBall();
private:
	void resetPositions();

	void displayWinText(const char* winText, Color color);
	static GameManager* m_instance;
	void increasePoints(Character* character);
	Character* m_agent1;
	Character* m_agent2;
	ScoreBoard* m_scoreBoard;
	int m_pointsToWin;
	int m_agent1Points = 0;
	int m_agent2Points = 0;
	MathLibrary::Vector2 m_agent1SpawnPosition = { 250, 400 };
	MathLibrary::Vector2 m_agent2SpawnPosition = { Engine::getScreenWidth() - 250.0f, 400 };
	MathLibrary::Vector2 m_ballSpawnPosition = { Engine::getScreenWidth() / 2.0f, Engine::getScreenHeight() / 2.0f };
	Goal* m_agent1Goal;
	Goal* m_agent2Goal;
	Actor* m_ball;
};

