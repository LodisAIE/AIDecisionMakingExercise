#include "UITextComponent.h"
#include <string>
#include "Transform2D.h"
#include "Actor.h"

UITextComponent::UITextComponent(int width, int height, RAYLIB_H::Color color, int fontSize, const char* text)
{
	//Initialize default stats
	m_text = text;	
	m_width = width;
	m_height = height;
	m_fontColor = color;
	m_fontSize = fontSize;
	m_font = RAYLIB_H::LoadFont("resources/fonts/alagard.png");
}

void UITextComponent::setText(const char* text)
{
	m_text = text;
}

void UITextComponent::draw()
{
	//Create a new rectangle to draw text in
	Rectangle rec = { getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y, getWidth(), getHeight() };

	//Draw text using the rectangle
	RAYLIB_H::DrawTextRec(getFont(), getText(), rec, getFontSize(), 1, true, getFontColor());
}
