#include "stdafx.h"
#include <sstream>
#include "Game.h"
#include "Exit.h"
#include "Item.h"

#include "CommandGoNorth.h"
#include "CommandGoSouth.h"
#include "CommandGoEast.h"
#include "CommandGoWest.h"
#include "CommandGoUp.h"
#include "CommandGoDown.h"
#include "CommandLook.h"
#include "CommandExamine.h"
#include "CommandPick.h"
#include "CommandDrop.h"
#include "CommandUnlock.h"
#include "CommandInventory.h"
#include "CommandUse.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::WelcomePlayer() const
{
	cout << "Welcome to Halloween eve game" << endl;
	cout << "You must disguise yourself as terrifying as possible before you can go and get candies." << endl << endl;
}

bool Game::ParseCommand(const std::string & playerInput) const
{
	vector<string> commands;

	//move sentence to vector
	istringstream command{ playerInput };
	while (command)
	{
		string sub;
		command >> sub;
		if (!sub.empty())
		{
			commands.push_back(sub);
		}
	}

	if (commands.size() > 0)
	{
		string word = commands[0];

		//Special case: quit
		if (word == "q" || word == "Q" || word == "quit" || word == "exit")
		{
			return true;
		}

		CommandsMap::const_iterator command = m_commands.find(word);
		if (command != m_commands.end())
		{
			command->second->Execute(commands);
		}
		else
		{
			cout << "What the hell did you just say? Do you speak my language?" << endl << endl;
		}
	}

	return false;
}

void Game::CheckPlayerWon()
{
	//nooope
	//playerWon = true;
}


void Game::Initialize()
{
	//Create rooms
	//1st floor rooms
	Room* m_playersRoom = new Room("Your room", "This is your room. It's a mess and you are pretty sure something has just blinked under your bed.");
	m_rooms.push_back(m_playersRoom);
	Room* m_upperHall = new Room("Upper hall", "This is the upper hall. There are 4 doors and stairs to lower floor.");
	m_rooms.push_back(m_upperHall);
	Room* m_parentsRoom = new Room("Parents room", "Your daddy and mommy room. This is a forbidden sanctuary for you.");
	m_rooms.push_back(m_parentsRoom);
	Room* m_bathroom = new Room("Bathroom", "A classic bathroom. Sink, toilet, shower... When was the last time you took a shower?");
	m_rooms.push_back(m_bathroom);
	//Main floor rooms
	Room* m_mainHall = new Room("Main hall", "The main hall of the house. It has the main entrance and leads to the garage and the living room. A stairs go to upper floor.");
	m_rooms.push_back(m_mainHall);
	Room* m_livingRoom = new Room("Living Room", "Oh, the living room. Big TV, confortable couch and the PlayStation 4. What else can you ask for? You can see the kitchen from here.");
	m_rooms.push_back(m_livingRoom);
	Room* m_kitchen = new Room("Kitchen", "Mmmm... Smells good. Your mom can cook the best pumpkin pie of the town. From here you can access the back yard and the basement.");
	m_rooms.push_back(m_kitchen);
	Room* m_garage = new Room("Garage", "Here is where your dad parks his old Toyota and your mom stores old and useless stuff.");
	m_rooms.push_back(m_garage);
	Room* m_mainYard = new Room("Main Yard", "The main yard of your house. When you opened the door your grandma was there about to ring the bell. You gave her a heart attack.");
	m_rooms.push_back(m_mainYard);
	Room* m_backYard = new Room("Back Yard", "A small garden full of flowers. A table and four chairs lay where it should be a swimming pool. Why your mom doesn't want a swimming pool?");
	m_rooms.push_back(m_backYard);
	//Basement rooms
	Room* m_basement = new Room("Basement", "Dark, cold and terrifying. What are you doing here? What was that sound??");
	m_rooms.push_back(m_basement);

	//Items
	Item* m_showerCurtain = new Item("Curtain", "A shower curtain. It has some colourful fishes painted on it. It would be a perfect cape if it was in dark color.", true);
	m_items.push_back(m_showerCurtain);
	m_bathroom->AddItem(m_showerCurtain);

	Item* m_blackPaint = new Item("Paint", "A can of the darkest black paint you've ever seen.", true);
	m_items.push_back(m_blackPaint);
	m_basement->AddItem(m_blackPaint);

	Item* m_cape = new Item("Cape", "The cape of a true monster! Wait a minute. Monsters wear capes?", true);
	m_items.push_back(m_cape);
	m_showerCurtain->AddTransformationItems(m_blackPaint, m_cape);

	Item* m_closet = new Item("Closet", "Your mom's closet. You can see the usual stuff: Dresses, sockets, panties... and a rubber... cucumber?", false);
	m_items.push_back(m_closet);
	m_parentsRoom->AddItem(m_closet);

	Item* m_basementKey = new Item("Key", "An old and rusty key.", true);
	m_items.push_back(m_basementKey);
	m_closet->AddItem(m_basementKey);

	//Room linking
	m_playersRoom->AddExit(Room::Direction::South, m_upperHall, false, nullptr, "");

	m_parentsRoom->AddExit(Room::Direction::West, m_upperHall, false, nullptr, "");

	m_bathroom->AddExit(Room::Direction::East, m_upperHall, false, nullptr, "");

	m_upperHall->AddExit(Room::Direction::North, m_playersRoom, false, nullptr, "");
	m_upperHall->AddExit(Room::Direction::South, nullptr, true, nullptr, "The door is locked from the other side. It leads to your sister's room. If you pay attention you could hear some subtle moans inside.");
	m_upperHall->AddExit(Room::Direction::East, m_parentsRoom, false, nullptr, "");
	m_upperHall->AddExit(Room::Direction::West, m_bathroom, false, nullptr, "");
	m_upperHall->AddExit(Room::Direction::Down, m_mainHall, false, nullptr, "");

	m_mainHall->AddExit(Room::Direction::Up, m_upperHall, false, nullptr, "");
	m_mainHall->AddExit(Room::Direction::South, m_garage, false, nullptr, "");
	m_mainHall->AddExit(Room::Direction::West, m_mainYard, true, nullptr, "You have not the true power of the monsters yet. Come back later when you are ready.");
	m_mainHall->AddExit(Room::Direction::East, m_livingRoom, false, nullptr, "");

	m_garage->AddExit(Room::Direction::North, m_mainHall, false, nullptr, "");

	m_livingRoom->AddExit(Room::Direction::West, m_mainHall, false, nullptr, "");
	m_livingRoom->AddExit(Room::Direction::South, m_kitchen, false, nullptr, "");

	m_kitchen->AddExit(Room::Direction::North, m_livingRoom, false, nullptr, "");
	m_kitchen->AddExit(Room::Direction::East, m_backYard, false, nullptr, "");
	m_kitchen->AddExit(Room::Direction::Down, m_basement, true, m_basementKey, "The door to the basement is locked. The lock seems old and rusty.");

	m_backYard->AddExit(Room::Direction::West, m_kitchen, false, nullptr, "");

	m_basement->AddExit(Room::Direction::Up, m_kitchen, false, nullptr, "");


	//Player
	m_player = new Player("You", "This is you! A child, a hero, a monster, an explorer, a crusader.", m_playersRoom);

	//Create commands
	ManageNewCommand(new CommandGoNorth(m_player), "n N north");
	ManageNewCommand(new CommandGoSouth(m_player), "s S south");
	ManageNewCommand(new CommandGoEast(m_player), "e E east");
	ManageNewCommand(new CommandGoWest(m_player), "w W west");
	ManageNewCommand(new CommandGoUp(m_player), "u U up");
	ManageNewCommand(new CommandGoDown(m_player), "d D down");
	ManageNewCommand(new CommandLook(m_player), "l L look");
	ManageNewCommand(new CommandExamine(m_player), "ex EX examine in IN inspect");
	ManageNewCommand(new CommandPick(m_player), "p P pick t T take");
	ManageNewCommand(new CommandDrop(m_player), "dr DR drop");
	ManageNewCommand(new CommandUnlock(m_player), "un UN unlock");
	ManageNewCommand(new CommandUse(m_player), "use");
	ManageNewCommand(new CommandInventory(m_player), "i I inventory");	
}

void Game::ManageNewCommand(Command* command, const string& words)
{
	m_commandVector.push_back(command);

	//move sentence to vector
	istringstream isWords{ words };
	while (isWords)
	{
		string sub;
		isWords >> sub;
		if (!sub.empty())
		{
			m_commands[sub] = command;
		}
	}
}

void Game::Finalize()
{
	delete(m_player);

	for (auto& command : m_commandVector)
	{
		delete(command);
	}

	for (auto& room : m_rooms)
	{
		delete(room);
	}

	for (auto& item : m_items)
	{
		delete(item);
	}
}

void Game::Run()
{

	WelcomePlayer();
	m_player->Look();

	while (!playerWon && !playerQuit)
	{
		string input;
		getline(cin, input);

		playerQuit = ParseCommand(input);

		CheckPlayerWon();
	}

	if (playerWon)
	{
		cout << "Congratulations, you are ready to scare your neighborhood!" << endl;
		cout << "Your grandma is dead, by the way." << endl;
	}
	else //player quit
	{
		cout << "Are you giving up? So laaaaame." << endl;
	}

	cout << "Type anything to exit" << endl;

	string input;
	cin >> input;
}


