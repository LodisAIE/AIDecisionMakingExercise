#pragma once
#include "Component.h"
#include <raylib.h>
#include <Vector2.h>

class UITextComponent :
	public Component
{
public:

	/// <param name="width">The width of the text box</param>
	/// <param name="height">The height of the text box</param>
	/// <param name="color">The color of the text</param>
	/// <param name="fontSize">The size of the text</param>
	/// <param name="owner">The actor that this component is attached to</param>
	/// <param name="text">The text to display</param>
	/// <param name="name">The name of this component</param>
	UITextComponent(int width, int height, RAYLIB_H::Color color, int fontSize, const char* text = "");

	/// <summary>
	/// Gets the text that this component will display
	/// </summary>
	const char* getText() { return m_text; }
	/// <summary>
	/// Sets the text that this component will display
	/// </summary>
	/// <param name="text">The new text to display</param>
	void setText(const char* text);
	
	/// <summary>
	/// Gets the width of the text box
	/// </summary>
	int getWidth() { return m_width; }
	/// <summary>
	/// Sets the width of the text box
	/// </summary>
	/// <param name="width">The new width of the text box</param>
	void setWidth(int width) { m_width = width; }

	/// <summary>
	/// Gets the height of the text box
	/// </summary>
	int getHeight() { return m_height; }
	/// <summary>
	/// Sets the height of the text box
	/// </summary>
	/// <param name="width">The new height of the text box</param>
	void setHeight(int height) { m_height = height; }

	/// <summary>
	/// Gets the size of the text within the text box
	/// </summary>
	int getFontSize() { return m_fontSize; }
	/// <summary>
	/// Sets the size of the text 
	/// </summary>
	/// <param name="fontSize"></param>
	void setFontSize(int fontSize) { m_fontSize = fontSize; }

	/// <summary>
	/// Gets the font style of the text
	/// </summary>
	RAYLIB_H::Font getFont() { return m_font; }
	/// <summary>
	/// Sets the font style of the text
	/// </summary>
	/// <param name="font"></param>
	void setFont(RAYLIB_H::Font font) { m_font = font; }

	/// <summary>
	/// Gets the color of the text
	/// </summary>
	RAYLIB_H::Color getFontColor() { return m_fontColor; }
	/// <summary>
	/// Sets the color of the text
	/// </summary>
	/// <param name="color">The new text color</param>
	void setFontColor(RAYLIB_H::Color color) { m_fontColor = color; }

	/// <summary>
	/// Gets the offset of the text from its attached actor
	/// </summary>
	MathLibrary::Vector2 getOffset() { return m_offset; }

	/// <summary>
	/// Sets the offset of the text from its attached actor
	/// </summary>
	/// <param name="offset">the new offset position</param>
	void setOffset(MathLibrary::Vector2 offset) { m_offset = offset; }

	void draw() override;

private:
	const char* m_text;
	int m_width;
	int m_height;
	int m_fontSize;
	RAYLIB_H::Font m_font;
	RAYLIB_H::Color m_fontColor;
	MathLibrary::Vector2 m_offset;
};

