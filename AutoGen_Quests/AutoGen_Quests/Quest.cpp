#include "Quest.h"

Quest::Quest()
{
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	// Background setup
	background.setSize({ (float)QUEST_WIDTH, (float)QUEST_HEIGHT });
	background.setOrigin({ QUEST_WIDTH / 2.0f, QUEST_HEIGHT / 2.0f });

	// Text setup
	text.setPosition({ (position.x - QUEST_WIDTH / 2.0f) + 5, (position.y - QUEST_HEIGHT / 2.0f) + 5 });
	text.setCharacterSize(20);
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
}

void Quest::draw(sf::RenderWindow& t_window)
{
	t_window.draw(background);
	t_window.draw(text);
}

void Quest::setPos(sf::Vector2f t_pos)
{
	position = t_pos; 
	background.setPosition(position);
	text.setPosition({ (position.x - QUEST_WIDTH / 2.0f) + 5, (position.y - QUEST_HEIGHT / 2.0f) + 5 });
}

void Quest::createQuest(std::string t_message, QuestType t_type, bool (*t_task)())
{
	message = t_message;
	text.setString(message);

	type = t_type;

	switch (type)
	{
	case QuestType::Good:
		background.setFillColor(goodQuest);
		break;

	case QuestType::None:
		background.setFillColor(neutralQuest);
		break;

	case QuestType::Evil:
		background.setFillColor(evilQuest);
		break;

	}

	// Set the task
	task = t_task;
}

void Quest::taskProgress()
{
	if (task == nullptr)
	{
		std::cout << "ERROR, NO TASK EQUIPPED \n";
	}
	else
	{
		if (task()) // Checks if the task is complete
		{
			if (!completed)
			{
				completeQuest();
			}
		}
	}
}

void Quest::completeQuest()
{
	completed = true;

	background.setFillColor(completedColor);

	std::cout << "COMPLETED TASK \n";
}

