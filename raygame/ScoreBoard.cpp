#include "ScoreBoard.h"
#include "UITextComponent.h"
#include <string>
#include "GameManager.h"
#include "Engine.h"
#include "Transform2D.h"

char* tempText1 = nullptr;
char* tempText2 = nullptr;

ScoreBoard::ScoreBoard() : Actor(Engine::getScreenWidth() / 2, Engine::getScreenHeight() / 2, "ScoreBoard")
{ 
	m_agent1Score = new Actor(0, 0, "Agent1Score");
	getTransform()->addChild(m_agent1Score->getTransform());
	m_agent1Score->getTransform()->setWorldPostion({ 10, 20 });

	m_agent2Score = new Actor(0, 0, "Agent2Score");
	getTransform()->addChild(m_agent2Score->getTransform());
	m_agent2Score->getTransform()->setWorldPostion({ Engine::getScreenWidth() - 250.0f, 20 });

	m_agent1ScoreText = dynamic_cast<UITextComponent*>(m_agent1Score->addComponent(new UITextComponent(600, 100, ORANGE, 30)));
	m_agent2ScoreText = dynamic_cast<UITextComponent*>(m_agent2Score->addComponent(new UITextComponent(600, 100, GREEN, 30)));
}

void ScoreBoard::update(float deltaTime)
{
	if (tempText1)
		delete[] tempText1;

	//Update the score text
	int score1 = GameManager::getInstance()->getAgent1Points();
	char scoreString[32];
	tempText1 = new char[32]{ "Agent 1 Score: " };
	sprintf_s(scoreString, sizeof(char) * 32, "%d", score1);
	strcat_s(tempText1, sizeof(scoreString), scoreString);
	m_agent1ScoreText->setText(tempText1);
	
	if (tempText2)
		delete[] tempText2;

	int score2 = GameManager::getInstance()->getAgent2Points();
	char scoreString2[32];
	tempText2 = new char[32]{ "Agent 2 Score: " };
	sprintf_s(scoreString2, sizeof(char) * 32, "%d", score2);
	strcat_s(tempText2, sizeof(scoreString2), scoreString2);
	m_agent2ScoreText->setText(tempText2);
}
