#pragma once

class Character;

class GameManager
{
public:
	void init(Character* agent1, Character* agent2, int pointsToWin);

	static GameManager* getInstance();

	void increasePoints(Character* character);

	int getAgent1Points() { return m_agent1Points; }
	int getAgent2Points() { return m_agent2Points; }

private:;
	static GameManager* m_instance;
	Character* m_agent1;
	Character* m_agent2;
	int m_pointsToWin;
	int m_agent1Points;
	int m_agent2Points;
};

