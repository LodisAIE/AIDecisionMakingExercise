#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "Agent1.h"
#include "Agent2.h"
#include "CircleCollider.h"
#include "Goal.h"
#include "GameManager.h"
#include "ScoreBoard.h"
#include "Engine.h"

void MainScene::start()
{
	Agent1* agent1 = new Agent1(250, 400, "Agent1", 50, 50, 3);
	Agent2* agent2 = new Agent2(Engine::getScreenWidth() - 250.0f, 400, "Agent2", 50, 50, 3);

	Actor* ball = new Actor(Engine::getScreenWidth() / 2.0f, Engine::getScreenHeight() / 2.0f, "Ball");
	ball->addComponent(new SpriteComponent("Images/ball.png"));
	ball->getTransform()->setScale({100, 100 });
	ball->setCollider(new CircleCollider(1, ball));

	GameManager::getInstance()->init(agent1, agent2, ball, 3);

	addActor(agent1);
	addActor(agent2);
	addActor(ball);
}
