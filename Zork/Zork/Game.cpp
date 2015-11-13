#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Game.h"
#include "Exit.h"
#include "Item.h"

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
	Room* m_upperHall = new Room("Upper hall", "This is the upper hall. There are 3 doors and stairs to lower floor.");
	m_rooms.push_back(m_upperHall);
	Room* m_parentsRoom = new Room("Parents room", "Your daddy and mommy room. This is a forbidden sanctuary for you.");
	m_rooms.push_back(m_parentsRoom);
	Room* m_bathroom = new Room("Bathroom", "A classic bathroom. Sink, toilet, shower... ");
	m_rooms.push_back(m_bathroom);

	//Main floor rooms
	Room* m_mainHall = new Room("Main hall", "The main hall of the house");
	m_rooms.push_back(m_mainHall);
	Room* m_livingRoom = new Room("Living Room", "");
	m_rooms.push_back(m_livingRoom);
	Room* m_kitchen = new Room("Kitchen", "");
	m_rooms.push_back(m_kitchen);
	Room* m_garage = new Room("Garage", "");
	m_rooms.push_back(m_garage);
	Room* m_mainYard = new Room("Main Yard", "");
	m_rooms.push_back(m_mainYard);
	Room* m_backYard = new Room("Back Yard", "");
	m_rooms.push_back(m_backYard);

	//Basement rooms
	Room* m_basement = new Room("Basement", "Dark, cold and terrifying. What are you doing here?");
	m_rooms.push_back(m_basement);

	//Room linking
	m_playersRoom->AddExit(Room::Directions::South, m_upperHall, false, nullptr, "");

	m_parentsRoom->AddExit(Room::Directions::West, m_upperHall, false, nullptr, "");

	m_bathroom->AddExit(Room::Directions::East, m_upperHall, false, nullptr, "");

	m_upperHall->AddExit(Room::Directions::North, m_playersRoom, false, nullptr, "");
	m_upperHall->AddExit(Room::Directions::South, nullptr, true, nullptr, "The door is locked from the other side. It leads to your sister's room. If you pay attention you could hear some subtle moans inside.");
	m_upperHall->AddExit(Room::Directions::East, m_parentsRoom, false, nullptr, "");
	m_upperHall->AddExit(Room::Directions::West, m_bathroom, false, nullptr, "");
	m_upperHall->AddExit(Room::Directions::Down, m_mainHall, false, nullptr, "");

	m_mainHall->AddExit(Room::Directions::Up, m_upperHall, false, nullptr, "");
	m_mainHall->AddExit(Room::Directions::South, m_garage, false, nullptr, "");
	m_mainHall->AddExit(Room::Directions::West, m_mainYard, true, nullptr, "You have not the true power of the monsters yet. Come back later when you are ready");
	m_mainHall->AddExit(Room::Directions::East, m_livingRoom, false, nullptr, "");

	m_garage->AddExit(Room::Directions::North, m_mainHall, false, nullptr, "");

	m_livingRoom->AddExit(Room::Directions::West, m_mainHall, false, nullptr, "");
	m_livingRoom->AddExit(Room::Directions::South, m_kitchen, false, nullptr, "");

	m_kitchen->AddExit(Room::Directions::North, m_livingRoom, false, nullptr, "");
	m_kitchen->AddExit(Room::Directions::East, m_backYard, false, nullptr, "");
	m_kitchen->AddExit(Room::Directions::Down, m_basement, true, nullptr, "The door to the basement is locked. The lock seems old and rusty.");

	m_backYard->AddExit(Room::Directions::West, m_kitchen, false, nullptr, "");

	m_basement->AddExit(Room::Directions::Up, m_kitchen, false, nullptr, "");

	//Items
	Item* m_showerCurtain = new Item("Curtain", "A shower curtain. It has some colourful fishes painted on it. It seems a perfect cape.", true, true);
	m_items.push_back(m_showerCurtain);

	m_bathroom->AddItem(m_showerCurtain);

	m_player = new Player("You", "This is you! A child, a hero, a monster, an explorer, a crusader.", m_playersRoom);
}

void Game::Finalize()
{
	delete(m_player);

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
	m_player->ParseCommand("l");

	while (!playerWon && !playerQuit)
	{
		string input;
		getline(cin, input);

		playerQuit = m_player->ParseCommand(input);

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


