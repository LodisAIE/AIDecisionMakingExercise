#include "GameManager.h"
#include "Character.h"
#include "Transform2D.h"
#include "ScoreBoard.h"
#include "Engine.h"
#include "UITextComponent.h"
#include "Goal.h"

GameManager* GameManager::m_instance = nullptr;

void GameManager::init(Character* agent1, Character* agent2, Actor* ball, int pointsToWin)
{
	m_agent1 = agent1;
	m_agent2 = agent2;
	m_ball = ball;
	m_pointsToWin = pointsToWin;

	m_scoreBoard = new ScoreBoard();
	Engine::getCurrentScene()->addUIElement(m_scoreBoard);

	m_agent1Goal = new Goal(0, 400, "LeftGoal", agent2);
	m_agent2Goal = new Goal(Engine::getScreenWidth() - 10, 400, "RightGoal", agent1);
	m_agent1Goal->m_onGoalScored = &GameManager::increasePoints;
	m_agent2Goal->m_onGoalScored = &GameManager::increasePoints;
	Engine::getCurrentScene()->addActor(m_agent1Goal);
	Engine::getCurrentScene()->addActor(m_agent2Goal);
}

GameManager* GameManager::getInstance()
{
	if (!m_instance)
		m_instance = new GameManager();

	return m_instance;
}

void GameManager::increasePoints(Character* character)
{
	if (character->m_ball != m_ball)
		return;

	if (character == m_agent1)
		m_agent1Points++;
	else if (character == m_agent2)
		m_agent2Points++;

	resetPositions();

	if (m_agent1Points >= m_pointsToWin)
	{
		m_agent1->setActive(false);
		m_agent2->setActive(false);
		displayWinText("Agent1 Wins", ORANGE);
	}
	else if (m_agent2Points >= m_pointsToWin)
	{
		m_agent1->setActive(false);
		m_agent2->setActive(false);
		displayWinText("Agent2 Wins", GREEN);
	}
}

MathLibrary::Vector2 GameManager::getBallPosition()
{
	if (m_agent1->getHasBall())
		return m_agent1->getTransform()->getWorldPosition();
	else if (m_agent2->getHasBall())
		return m_agent2->getTransform()->getWorldPosition();
	else
		return m_ball->getTransform()->getWorldPosition();
}

void GameManager::resetPositions()
{
	m_agent1->dropBall();
	m_agent2->dropBall();

	m_agent1->getTransform()->setWorldPostion(m_agent1SpawnPosition);
	m_agent2->getTransform()->setWorldPostion(m_agent2SpawnPosition);
	m_agent1->setActive(true);
	m_agent2->setActive(true);
	m_agent1->m_health = 3;
	m_agent2->m_health = 3;
	m_agent1->m_isInvincible = false;
	m_agent2->m_isInvincible = false;

	m_ball->getTransform()->setWorldPostion(m_ballSpawnPosition);

}

void GameManager::displayWinText(const char* text, Color color)
{
	Actor* winText = new Actor((Engine::getScreenWidth() - 300)  / 2, 50, "WinText");
	UITextComponent* winTextComp = dynamic_cast<UITextComponent*>(winText->addComponent(new UITextComponent(600, 100, color, 50)));
	winTextComp->setText(text);

	Engine::getCurrentScene()->addUIElement(winText);
}
