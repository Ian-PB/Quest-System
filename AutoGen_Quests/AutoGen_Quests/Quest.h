#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <functional>

#include "Global.h"


enum class QuestType
{
	None,
	Good,
	Evil
};

class Quest
{
public:
	Quest();

	void draw(sf::RenderWindow& t_window);
	sf::RectangleShape getBackground() { return background; }
	sf::Text getText() { return text; }

	// "Set" functions
	void setPos(sf::Vector2f t_pos);

	void createQuest(std::string t_message, QuestType t_type, bool (*t_task)());

	void taskProgress(); // Returns if the quest was completed or not
	bool (*task)(); // Define a pointer funtions. This will allow it to copy another function's definition
	void completeQuest();

	bool completed = false;
	bool active = false;

protected:
	// Body
	sf::RectangleShape background;
	sf::Vector2f position = { 500, 500 };
	// Text
	sf::Text text;
	std::string message = "";

	// Quest stats
	QuestType type;
	int good = 0;
	int neutral = 0;
	int evil = 0;

private:
	sf::Font font;

	const int QUEST_HEIGHT = 100;
	const int QUEST_WIDTH = 200;


	// Quest colors
	sf::Color completedColor = { 255, 255, 255, 255 };
	sf::Color goodQuest = sf::Color::Green;
	sf::Color neutralQuest = { 175,175, 175, 255 };
	sf::Color evilQuest = sf::Color::Red;
};

