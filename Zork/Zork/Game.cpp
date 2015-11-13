#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Game.h"

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


void Game::Initialize()
{
	m_room = new Room("Your room", "This is your room. It's a mess and you are pretty sure something has just blinked under your bed.");
	m_player = new Player("You", "This is you! A child, a hero, a monster, an explorer, a crusader.", m_room);
}

void Game::Run()
{

	WelcomePlayer();

	while (!playerWon && !playerQuit)
	{
		string input;
		getline(cin, input);

		m_player->ParseCommand(input);

		playerWon = true;
	}

	if (playerWon)
	{
		cout << "Congratulations, you are ready to scare your neighborhood!" << endl;
		cout << "Your grandma is dead, by the way." << endl;
		cout << "Type anything to exit" << endl;

		string input;
		cin >> input;
	}
}

void Game::Finalize()
{
	delete(m_room);
	delete(m_player);
}
