#include "GameManager.h"

GameManager* GameManager::m_instance = nullptr;

void GameManager::init(Character* agent1, Character* agent2, int pointsToWin)
{
	m_agent1 = agent1;
	m_agent2 = agent2;
	m_pointsToWin = pointsToWin;
}

GameManager* GameManager::getInstance()
{
	if (!m_instance)
		m_instance = new GameManager();

	return m_instance;
}

void GameManager::increasePoints(Character* character)
{
	if (character == m_agent1)
		m_agent1Points++;
	else if (character == m_agent2)
		m_agent2Points++;
}
