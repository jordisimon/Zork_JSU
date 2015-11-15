#include "stdafx.h"
#include <sstream>
#include "Game.h"
#include "Exit.h"
#include "Item.h"
#include "Dad.h"
#include "Mom.h"

#include "CommandQuit.h"
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
#include "CommandTalk.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::WelcomePlayer() const
{
	cout << "********************************************************************" << endl;
	cout << "                    WELCOME TO JORK ©" << endl;
	cout << "********************************************************************" << endl;
	cout << "It's Halloween eve" << endl;
	cout << "You must disguise yourself as amazing as possible before you can go and get candies with your friends." << endl << endl;
}

void Game::ParseCommand(const std::string & playerInput) const
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
}

void Game::CheckPlayerWon()
{
	playerWon = (m_player->GetCurrentRoom() == m_winningRoom);
}


void Game::Initialize()
{
	/*************************************
	**** Rooms ***************************
	**************************************/
	//Penthouse
	Room* penthouse = CreateNewRoom("Penthouse", "Here is where your parents store old and useless stuff. It's dusty. Achoo!!");
	//1st floor rooms
	Room* playersRoom = CreateNewRoom("Your room", "This is your room. It's a mess and you are pretty sure something has just blinked under your bed.");
	Room* upperHall = CreateNewRoom("Upper hall", "The upper hall. There are 4 doors and stairs to lower floor and to the penthouse.");
	Room* parentsRoom = CreateNewRoom("Parents room", "Your daddy and mommy room. This is a forbidden sanctuary for you.");
	Room* bathroom = CreateNewRoom("Bathroom", "A classic bathroom. Sink, toilet, shower... When was the last time you took a shower?");
	//Main floor rooms
	Room* mainHall = CreateNewRoom("Main hall", "The main hall of the house. It has the main entrance and leads to the garage and the living room. A stairs go to upper floor.");
	Room* livingRoom = CreateNewRoom("Living Room", "Oh, the living room. Big TV, confortable couch and the PlayStation 4. What else can you ask for? You can see the kitchen from here.");
	Room* kitchen = CreateNewRoom("Kitchen", "Mmmm... Smells good. Your mom can cook the best pumpkin pie of the town. From here you can access the back yard and the basement.");
	Room* garage = CreateNewRoom("Garage", "Here is where your dad parks his old Toyota.");
	Room* mainYard = CreateNewRoom("Main Yard", "The main yard of your house. When you opened the door your grandma was there about to ring the bell. You gave her a heart attack.");
	Room* backYard = CreateNewRoom("Back Yard", "A small garden full of flowers. A table and four chairs lay where it should be a swimming pool. Why your mom doesn't want a swimming pool?");
	//Basement rooms
	Room* basement = CreateNewRoom("Basement", "Dark, cold and terrifying. What are you doing here? What was that sound??");

	/*************************************
	**** Characters **********************
	**************************************/
	Dad* dad = new Dad("Dad", "Your daddy.");
	m_characters.push_back(dad);
	livingRoom->AddCharacter(dad);

	Mom* mom = new Mom("Mom", "Your mommy.");
	m_characters.push_back(mom);
	mainHall->AddCharacter(mom);

	/*************************************
	**** Items ***************************
	**************************************/
	//Cape items
	Item* showerCurtain = CreateNewItem("Curtain", "A shower curtain. It has some colourful fishes painted on it. It would be a perfect cape if it was in dark color.", true);
	bathroom->AddItem(showerCurtain);

	Item* blackPaint = CreateNewItem("Paint", "A can of the darkest black paint you've ever seen.", true);
	penthouse->AddItem(blackPaint);

	Item* cape = CreateNewItem("Cape", "The cape of a true hero! You are the dark knight.", true);
	showerCurtain->AddTransformationItems(blackPaint, cape);
	mom->AddNeeededItem(cape);

	//Sword Items
	Item* umbrella = CreateNewItem("Umbrella", "Your dad's umbrella. Big, but almost broken.", true);
	mainHall->AddItem(umbrella);

	Item* ductTape = CreateNewItem("Tape", "A roll of duct tape. It can fix almost anything.", true);
	basement->AddItem(ductTape);

	Item* sword = CreateNewItem("Sword", "A big sword! Ready to cut your enemies' throats.", true);
	umbrella->AddTransformationItems(ductTape, sword);
	mom->AddNeeededItem(sword);

	//Boots
	Item* boots = CreateNewItem("Boots", "Your sister's rain boots. They are pink and fancy, but a true hero can wear anything, right? Right??", true);
	garage->AddItem(boots);
	mom->AddNeeededItem(boots);

	//Shield items
	Item* trashCan = CreateNewItem("Can", "The garbage can. It's full and stinks. Puagggg!", false);
	backYard->AddItem(trashCan);

	Item* lid = CreateNewItem("Lid", "It ressembles Captain America's shield, but it's dented.", true);
	trashCan->AddItem(lid);

	Item* hammer = CreateNewItem("Hammer", "Hammer time! It's a common hammer.", true);
	basement->AddItem(hammer);

	Item* shield = CreateNewItem("Shield", "It's not made of vibranium but it will do.", true);
	lid->AddTransformationItems(hammer, shield);
	mom->AddNeeededItem(shield);

	//Helmet items
	Item* cupboard = CreateNewItem("Cupboard", "The kitchen cupboard where your mom stores the vegetables.", false);
	kitchen->AddItem(cupboard);

	Item* potato = CreateNewItem("Potato", "Oh hi, how are you holding up? BECAUSE I'M A POTATO.", true); //The cake is a lie
	cupboard->AddItem(potato);

	Item* pumpkin = CreateNewItem("Pumpkin", "A pumpkin bigger than your head. If you can make just a pair of holes...", true);
	cupboard->AddItem(pumpkin);

	Item* knife = CreateNewItem("Knife", "Your dad just gave this!! Parenting fail.", true);
	dad->AddItem(knife);

	Item* helmet = CreateNewItem("Helmet", "You feel like Ironman when you put this helmet on. Don't try to fly though.", true);
	pumpkin->AddTransformationItems(knife, helmet);
	mom->AddNeeededItem(helmet);

	Item* chicken = CreateNewItem("Chicken", "A rubber chicken with a pulley in the middle", true);
	dad->AddItem(chicken);

	//Other
	Item* closet = CreateNewItem("Closet", "Your mom's closet. You can see the usual stuff: Dresses, sockets, panties... and a rubber... cucumber?", false);
	parentsRoom->AddItem(closet);

	Item* basementKey = CreateNewItem("Key", "An old and rusty key.", true);
	closet->AddItem(basementKey);

	Item* mainKey = CreateNewItem("Key", "Your way to freedom!", true);
	mom->AddItem(mainKey);
	
	/*************************************
	**** Room linking ********************
	**************************************/
	penthouse->AddExit(Room::Direction::Down, upperHall, true, nullptr, "Ooops! The door closed and it's stuck! The only exit is a window at the other side.");
	penthouse->AddExit(Room::Direction::East, backYard, false, nullptr, "");

	playersRoom->AddExit(Room::Direction::South, upperHall, false, nullptr, "");

	parentsRoom->AddExit(Room::Direction::West, upperHall, false, nullptr, "");

	bathroom->AddExit(Room::Direction::East, upperHall, false, nullptr, "");

	upperHall->AddExit(Room::Direction::North, playersRoom, false, nullptr, "");
	upperHall->AddExit(Room::Direction::South, nullptr, true, nullptr, "The door is locked from the other side. It leads to your sister's room. If you pay attention you could hear some subtle moans inside.");
	upperHall->AddExit(Room::Direction::East, parentsRoom, false, nullptr, "");
	upperHall->AddExit(Room::Direction::West, bathroom, false, nullptr, "");
	upperHall->AddExit(Room::Direction::Up, penthouse, false, nullptr, "");
	upperHall->AddExit(Room::Direction::Down, mainHall, false, nullptr, "");

	mainHall->AddExit(Room::Direction::Up, upperHall, false, nullptr, "");
	mainHall->AddExit(Room::Direction::South, garage, false, nullptr, "");
	mainHall->AddExit(Room::Direction::West, mainYard, true, mainKey, "You have not the true power of the hero yet. Come back later when you are ready (and have the key).");
	mainHall->AddExit(Room::Direction::East, livingRoom, false, nullptr, "");

	garage->AddExit(Room::Direction::North, mainHall, false, nullptr, "");

	livingRoom->AddExit(Room::Direction::West, mainHall, false, nullptr, "");
	livingRoom->AddExit(Room::Direction::South, kitchen, false, nullptr, "");

	kitchen->AddExit(Room::Direction::North, livingRoom, false, nullptr, "");
	kitchen->AddExit(Room::Direction::East, backYard, false, nullptr, "");
	kitchen->AddExit(Room::Direction::Down, basement, true, basementKey, "The door to the basement is locked. The lock seems old and rusty.");

	backYard->AddExit(Room::Direction::West, kitchen, false, nullptr, "");

	basement->AddExit(Room::Direction::Up, kitchen, false, nullptr, "");

	/*************************************
	**** Player ***************************
	**************************************/
	m_player = new Player("You", "This is you! A child, a hero, a monster, an explorer, a crusader.", playersRoom);

	/*************************************
	**** Winning condition ***************
	**************************************/
	m_winningRoom = mainYard;

	/*************************************
	**** Commands ************************
	**************************************/
	ManageNewCommand(new CommandQuit(m_player), "q Q quit exit leave fuckyou Quit Exit Leave FuckYou");
	ManageNewCommand(new CommandGoNorth(m_player), "n N north North");
	ManageNewCommand(new CommandGoSouth(m_player), "s S south South");
	ManageNewCommand(new CommandGoEast(m_player), "e E east East");
	ManageNewCommand(new CommandGoWest(m_player), "w W west West");
	ManageNewCommand(new CommandGoUp(m_player), "u U up Up");
	ManageNewCommand(new CommandGoDown(m_player), "d D down Down");
	ManageNewCommand(new CommandLook(m_player), "l L look Look");
	ManageNewCommand(new CommandExamine(m_player), "ex EX examine Examine in IN inspect Inspect");
	ManageNewCommand(new CommandPick(m_player), "p P pick Pick t T take Take");
	ManageNewCommand(new CommandDrop(m_player), "dr DR drop Drop");
	ManageNewCommand(new CommandUnlock(m_player), "un UN unlock Unlock");
	ManageNewCommand(new CommandUse(m_player), "use Use");
	ManageNewCommand(new CommandInventory(m_player), "i I inventory Inventory");
	ManageNewCommand(new CommandTalk(m_player), "ta TA talk Talk sp SP speak Speak");
}

Room* Game::CreateNewRoom(const string & name, const string & description)
{
	Room* room = new Room(name, description);
	m_rooms.push_back(room);
	return room;
}

Item* Game::CreateNewItem(const string& name, const string& description, bool pickable)
{
	Item* item = new Item(name, description, pickable);
	m_items.push_back(item);
	return item;
}

void Game::ManageNewCommand(Command* command, const string& words)
{
	m_commandVector.push_back(command);

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

	for (auto& character : m_characters)
	{
		delete(character);
	}
}

void Game::Run()
{

	WelcomePlayer();
	m_player->Look();

	while (!playerWon && !m_player->GetPlayerQuit())
	{
		string input;
		getline(cin, input);
		cout << endl;

		ParseCommand(input);

		CheckPlayerWon();
	}

	if (playerWon)
	{
		cout << "********************************************************************" << endl;
		cout << "                    YOU WON!!!!!" << endl;
		cout << "********************************************************************" << endl;
		cout << "CONGRATULATIONS, you are ready to scare your neighborhood!" << endl << endl;
		cout << "Thanks for playing. We hope you enjoyed this game." << endl;
		cout << "Stay tunned for our new adventure JORK 2: Into the Gates of Hell ©" << endl << endl << endl << endl;
		cout << "Your grandma is dead, by the way." << endl << endl;
		cout << "Type anything to exit" << endl;
	}
	else //player quit
	{
		cout << "Are you giving up? So laaaaame." << endl << endl;
		cout << "Well, thanks for playing. Type anything to exit" << endl;
	}

	string input;
	cin >> input;
}


