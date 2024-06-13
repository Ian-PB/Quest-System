#include "QuestManager.h"


QuestManager::QuestManager()
{
	// Make all possible quests
	quests[0].createQuest("Press W", QuestType::Good, wPressTask);
	quests[1].createQuest("Press A", QuestType::Good, aPressTask);
	quests[2].createQuest("Press S", QuestType::Good, sPressTask);
	quests[3].createQuest("Press D", QuestType::Good, dPressTask);
	quests[4].createQuest("Neutral 1", QuestType::None, emptyTask);
	quests[5].createQuest("Neutral 2", QuestType::None, emptyTask);
	quests[6].createQuest("Neutral 3", QuestType::None, emptyTask);
	quests[7].createQuest("Neutral 4", QuestType::None, emptyTask);
	quests[8].createQuest("Evil 1", QuestType::Evil, emptyTask);
	quests[9].createQuest("Evil 2", QuestType::Evil, emptyTask);
	quests[10].createQuest("Evil 3", QuestType::Evil, emptyTask);
	quests[11].createQuest("Evil 4", QuestType::Evil, emptyTask);

	// Set the current 5 quests
	for (int i = 0; i < MAX_QUESTS; i++)
	{
		int r = rand() % QUEST_AMOUNT;

		currentQuestsIndex[i] = r;
	}

	generateNewQuests();
	setQuestPositions();
}

void QuestManager::replaceCompletedQuests()
{
	for (int i = 0; i < MAX_QUESTS; i++)
	{
		if (quests[currentQuestsIndex[i]].completed)
		{
			int randomQuest = rand() % QUEST_AMOUNT;

			while (quests[randomQuest].completed) // Goes till it finds an un-completed quest
			{
				// Checks that the quest found isn't chosen already
				for (int t = 0; t < MAX_QUESTS; t++)
				{
					if (randomQuest == t)
					{
						randomQuest = rand() % QUEST_AMOUNT; // Re-randomize
					}
				}
			}

			std::cout << "Completed quests changed \n";

			currentQuestsIndex[i] = randomQuest;

			setQuestPositions();
		}
	}
}

void QuestManager::generateNewQuests()
{
	int r = 0;

	// Set the current 5 quests - (NO ERROR CHECKING)
	for (int i = 0; i < MAX_QUESTS; i++)
	{
		r = rand() % QUEST_AMOUNT;

		currentQuestsIndex[i] = r; // Set the quest that is active
	}

	for (int i = 0; i < MAX_QUESTS; i++) 
	{
		for (int j = i + 1; j < MAX_QUESTS; j++)
		{
			if (currentQuestsIndex[i] == currentQuestsIndex[j])
			{
				// Randomize the value of the second duplicate until it's unique
				bool isDuplicate;
				do 
				{
					r = rand() % QUEST_AMOUNT;  // New Quest

					isDuplicate = false;
					for (int k = 0; k < MAX_QUESTS; k++) 
					{
						if (k != j && currentQuestsIndex[k] == r) 
						{
							isDuplicate = true;
							break;
						}
					}
				} while (isDuplicate);
				currentQuestsIndex[j] = r;
			}
		}
	}

	// Set quest positions
	setQuestPositions();
}

void QuestManager::setQuestPositions()
{
	for (int i = 0; i < MAX_QUESTS; i++)
	{
		quests[currentQuestsIndex[i]].setPos({ SCREEN_SIZE / 2.0f, 100.0f + (i * 110) });
	}
}

// ------- Possible quests ------- //

bool QuestManager::wPressTask()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		return true;
	}

	return false;
}

bool QuestManager::aPressTask()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		return true;
	}

	return false;
}

bool QuestManager::sPressTask()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		return true;
	}

	return false;
}

bool QuestManager::dPressTask()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return true;
	}

	return false;
}



bool QuestManager::emptyTask()
{
	return false;
}
