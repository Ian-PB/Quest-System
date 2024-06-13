// Made by: Ian Perez Bunuel, 13/06/2024

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Quest.h"
#include "Global.h"

class QuestManager
{
public:
	QuestManager();

	void replaceCompletedQuests();
	void generateNewQuests();

	// Visual
	void setQuestPositions();

	/// ----- Quests ----- ///
	Quest quests[QUEST_AMOUNT];
	int currentQuestsIndex[MAX_QUESTS]; // Saves the index of the current quests

private:

	// ------ QUESTS ------ //
	static bool wPressTask();
	static bool aPressTask();
	static bool sPressTask();
	static bool dPressTask();

	static bool emptyTask();
};

