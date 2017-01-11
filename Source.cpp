/*  What I did Last time:
I used an Enum to define the people and made a Struct to
Hold Data, this is paired witht the queues (need to start..)
and i will have an effictive battle system

Part 2: What I have done is make the system for the actual
setting up of the Combat Order, Next should be a way to 'Emplace'
and 'pop' the combat System, BUT should have the combat and Attacks
set up beforehand.

*/

#include <iostream>
#include <Windows.h>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <string> // gives us data type string
#include <iomanip>
#include <ctime>
#include <queue>

using namespace std;
int DragonHealth;

queue <int> BattleQue;

int DragonLife = 20;
int color;
string HowManyPlayersString;
int HowManyPlayersInt; // How Many Players Are There? 
bool ProtectionFromUserInputBool = true;
int UserInputInt; // A Universal Integer for disposal... 
string UserInputString; // A Universal String for disposal...
bool Player1OnlyBool = false, Players2Bool = false, Players3Bool = false, Players4Bool = false; // How Many Players Are Playing?
int Player1Life, Player2Life, Player3Life, Player4Life; // Life of Players
string Player1Name, Player2Name, Player3Name, Player4Name; // Names of Characters
string Player1Class, Player2Class, Player3Class, Player4Class; // Classes of Characters
bool PlayersWin = false;

enum PlayerQueueIntegerVal { Player1Queue = 1, Player2Queue, Player3Queue, Player4Queue, DragonQueue };

struct Players {
	string ClassOfCharacter;
	int LifeOfCharacter;

} Player1, Player2, Player3, Player4;

int OrderOfCombatants() {
	// This allows for the organization of the Combat, if the player 
	// is actually playing, then they are included, they are
	// set the integer value in order with the Drgaon being last
	if (Player1OnlyBool == true) { BattleQue.push(Player1Queue); }
	else if (Players2Bool == true) { BattleQue.push(Player2Queue); }
	else if (Players3Bool == true) { BattleQue.push(Player3Queue); }
	else if (Players4Bool == true) { BattleQue.push(Player4Queue); }
	BattleQue.push(DragonQueue);
	system("pause");
	return 0;
}

int LifeOfDragon() {
	// Displays the Life in a Unique Way
	//cout << "Life of The Dragon";
	switch (DragonLife) {
	case 999: cout << "You Win!!!" << endl; PlayersWin = true; break;
	case 20: cout << (char)(219) << " ";
	case 19: cout << (char)(219) << " ";
	case 18: cout << (char)(219) << " ";
	case 17: cout << (char)(219) << " ";
	case 16: cout << (char)(219) << " ";
	case 15: cout << (char)(219) << " ";
	case 14: cout << (char)(219) << " ";
	case 13: cout << (char)(219) << " ";
	case 12: cout << (char)(219) << " ";
	case 11: cout << (char)(219) << " ";
	case 10: cout << (char)(219) << " ";
	case 9: cout << (char)(219) << " ";
	case 8: cout << (char)(219) << " ";
	case 7: cout << (char)(219) << " ";
	case 6: cout << (char)(219) << " ";
	case 5: cout << (char)(219) << " ";
	case 4: cout << (char)(219) << " ";
	case 3: cout << (char)(219) << " ";
	case 2: cout << (char)(219) << " ";
	case 1: cout << (char)(219) << " ";
	default: break;
	}
	cout << endl;
	return 8;
}
int DragonPicture() {
	cout << "\n                           DRAGON'S HEALTH: ";
	LifeOfDragon();
	cout << endl << endl << "                              ";
	cout << "                    /            /                     " << endl << "                              "
		<< "                   /'  .,,,,  ./                       " << endl << "                              "
		<< "                  /';'      ,/                         " << endl << "                              "
		<< "                 / /    ,,//,`'`                       " << endl << "                              "
		<< "                ( ,,  '_,  ,,,' ``                     " << endl << "                              "
		<< "                |     /@  ,,, ;" "                     " << endl << "                              "
		<< "               /    .    ,''/' `,``                    " << endl << "                              "
		<< "              /   .     ./, `,, `  ;                   " << endl << "                              "
		<< "           ,./  .   ,-,',` ,,/''\, '                   " << endl << "                              "
		<< "          |   /; ./,,'`,,'' |   |                      " << endl << "                              "
		<< "          |     /   ','    /    |                      " << endl << "                              "
		<< "          { ___/'   '     |     |                      " << endl << "                              "
		<< "             `,,'  |      /     `\                     " << endl << "                              "
		<< "                  /      |        ~\                   " << endl << "                              "
		<< "                 '       (                             " << endl;
	return 8;
}

int NamesAndDone() {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "How Many Players do you have?" << endl;
	while (ProtectionFromUserInputBool) {
		cin >> HowManyPlayersInt;
		if (HowManyPlayersInt < 1 || HowManyPlayersInt > 4) {
			cout << "Please Enter a Number 1 - 4" << endl;
		}
		else { ProtectionFromUserInputBool = false; }
	}
	system("Cls");
	switch (HowManyPlayersInt) {
	case 1: cout << " Please Put in your Names for the Game" << endl;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 1 :  ";
		color = 12; SetConsoleTextAttribute(hcon, color);
		cin >> Player1Name;
		Player1OnlyBool = true;
		break;
	case 2:cout << " Please Put in your Names for the Game" << endl;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 1 :  ";
		color = 12; SetConsoleTextAttribute(hcon, color);
		cin >> Player1Name;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 2 :  ";
		color = 9; SetConsoleTextAttribute(hcon, color);
		cin >> Player2Name;
		Player1OnlyBool = true;
		Players2Bool = true;
		break;
	case 3: cout << " Please Put in your Names for the Game" << endl;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 1 :  ";
		color = 12; SetConsoleTextAttribute(hcon, color);
		cin >> Player1Name;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 2 :  ";
		color = 9; SetConsoleTextAttribute(hcon, color);
		cin >> Player2Name;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 3 :  ";
		color = 2; SetConsoleTextAttribute(hcon, color);
		cin >> Player3Name;
		Player1OnlyBool = true;
		Players2Bool = true;
		Players3Bool = true;
		break;
	case 4: cout << " Please Put in your Names for the Game" << endl;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 1 :  ";
		color = 12; SetConsoleTextAttribute(hcon, color);
		cin >> Player1Name;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 2 :  ";
		color = 9; SetConsoleTextAttribute(hcon, color);
		cin >> Player2Name;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 3 :  ";
		color = 2; SetConsoleTextAttribute(hcon, color);
		cin >> Player3Name;
		color = 7; SetConsoleTextAttribute(hcon, color);
		cout << " Player 4 :  ";
		color = 14; SetConsoleTextAttribute(hcon, color);
		cin >> Player4Name;
		Player1OnlyBool = true;
		Players2Bool = true;
		Players3Bool = true;
		Players4Bool = true;
		break;
	}
	return 7;
}
int ClassesAndTheirMeaning() {
	if (UserInputInt == 1) { UserInputString = "WARRIOR"; }
	if (UserInputInt == 2) { UserInputString = "ARCHER"; }
	if (UserInputInt == 3) { UserInputString = "MAGE"; }
	if (UserInputInt == 4) { UserInputString = "PREIST"; }
	return 7;
}
int ClassOfCharacters() {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	ProtectionFromUserInputBool = true;
	system("CLS");
	color = 7; // White
	SetConsoleTextAttribute(hcon, color);
	cout << "The Classes You May Pick From Are:" << endl;
	cout << "1.) WARRIOR" << endl <<
		"2.) ARCHER" << endl <<
		"3.) MAGE" << endl <<
		"4.) PREIST" << endl;
	if (Player1OnlyBool == true) {
		color = 12;
		SetConsoleTextAttribute(hcon, color);
		cout << "Player 1, Please Make a Choice of Class" << endl;
		while (ProtectionFromUserInputBool) {
			cin >> UserInputInt;
			if (UserInputInt < 1 || UserInputInt > 4) { cout << "Please Make a Choice, 1 - 4..." << endl; }
			else { ClassesAndTheirMeaning(); Player1Class = UserInputString; ProtectionFromUserInputBool = false; }
		}
		ProtectionFromUserInputBool = true;
	}
	if (Players2Bool == true) {
		color = 9;
		SetConsoleTextAttribute(hcon, color);
		cout << "Player 2, Please Make a Choice of Class" << endl;
		while (ProtectionFromUserInputBool) {
			cin >> UserInputInt;
			if (UserInputInt < 1 || UserInputInt > 4) { cout << "Please Make a Choice, 1 - 4..." << endl; }
			else { ClassesAndTheirMeaning(); Player2Class = UserInputString; ProtectionFromUserInputBool = false; }
		}
		ProtectionFromUserInputBool = true;
	}
	if (Players3Bool == true) {
		color = 2;
		SetConsoleTextAttribute(hcon, color);
		cout << "Player 3, Please Make a Choice of Class" << endl;
		while (ProtectionFromUserInputBool) {
			cin >> UserInputInt;
			if (UserInputInt < 1 || UserInputInt > 4) { cout << "Please Make a Choice, 1 - 4..." << endl; }
			else { ClassesAndTheirMeaning(); Player3Class = UserInputString; ProtectionFromUserInputBool = false; }
		}
		ProtectionFromUserInputBool = true;
	}
	if (Players4Bool == true) {
		color = 14;
		SetConsoleTextAttribute(hcon, color);
		cout << "Player 4, Please Make a Choice of Class" << endl;
		while (ProtectionFromUserInputBool) {
			cin >> UserInputInt;
			if (UserInputInt < 1 || UserInputInt > 4) { cout << "Please Make a Choice, 1 - 4..." << endl; }
			else { ClassesAndTheirMeaning(); Player4Class = UserInputString; ProtectionFromUserInputBool = false; }
		}
		ProtectionFromUserInputBool = true;
	}
	return 9;
}

int MainGameScreen() {
	system("CLS");
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	color = 13;
	SetConsoleTextAttribute(hcon, color);
	DragonPicture(); // Displays Dragon's Stats
	color = 12; SetConsoleTextAttribute(hcon, color); // Red
	cout << "\n      " << Player1Name << "'s Life:" << Player1Life << endl; // Displays Player 1's stats
	cout << "          " << Player1Class << endl;
	color = 9; SetConsoleTextAttribute(hcon, color); // Blue
	if (Players2Bool == true) {
		cout << "      " << Player2Name << "'s Life:" << Player2Life << endl; // Displays Player 2's stats
		cout << "          " << Player2Class << endl;
	}
	color = 2; SetConsoleTextAttribute(hcon, color); // Green
	if (Players3Bool == true) {
		cout << "      " << Player3Name << "'s Life:" << Player3Life << endl; // Displays Player 3's stats
		cout << "          " << Player3Class << endl;
	}
	color = 14; SetConsoleTextAttribute(hcon, color); // Yellow
	if (Players4Bool == true) {
		cout << "      " << Player4Name << "'s Life:" << Player4Life << endl; // Displays Player 4's stats
		cout << "          " << Player4Class << endl;
	}
	color = 13; SetConsoleTextAttribute(hcon, color); // Back to Purple
	return 0;
}

int main() {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);

	NamesAndDone();
	ClassOfCharacters();
	MainGameScreen();
	system("pause");
	return 9;
}