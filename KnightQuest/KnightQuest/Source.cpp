//Things To work on: adapting this to any screen (No Fixed Points), and taking off the power bars once they go down
// Make more functions that are able to dicide up the workload - Past Erik
// Please do so, it makes our job easier - Future Erik
// You might as well add a Lich Class, and Hey, make the Fighting universal with Queues
// OH MY GOSH THERE ARE 3 WEEKS LEFT IN THIS PROJECT AHHHHHHHHHHHHH 4/19/2017
// P.s. Work on "AttackTargetAndAttack", "attackMoves", and
// P.s.s. Work on the Attacks for the game and the queues, make the Attacks in the Struct but Generalize the Crap Out of them(?)
// Im sick and tired of the Enemies not having the health bar 
// Today 4/21/2017 : Work on Giving The Enemy 12 boxes of power, Give the players the attacks in the struct 
// sort of done with knight and archer 
// 4/24/17: Due To Time Constraints, just focus on the actual players and interactions:
// What to limit (for now) : Only Have Dragon and Goblin King, The 8 Primary classes -> Achive throughout the game 
// Work on itoa (basically ints to strings )
// Problems with the Zero, not doing anything 
// Work on the Dragon and The Goblin King Randomizing attacks and making the strings work for the players and the Enemy Bosses 
// Should also probably get the other power of the characters to work...//Things To work on: adapting this to any screen (No Fixed Points), and taking off the power bars once they go down
// Make more functions that are able to dicide up the workload - Past Erik
// Please do so, it makes our job easier - Future Erik
// You might as well add a Lich Class, and Hey, make the Fighting universal with Queues
// OH MY GOSH THERE ARE 3 WEEKS LEFT IN THIS PROJECT AHHHHHHHHHHHHH 4/19/2017
// P.s. Work on "AttackTargetAndAttack", "attackMoves", and
// P.s.s. Work on the Attacks for the game and the queues, make the Attacks in the Struct but Generalize the Crap Out of them(?)
// Im sick and tired of the Enemies not having the health bar 
// Today 4/21/2017 : Work on Giving The Enemy 12 boxes of power, Give the players the attacks in the struct 
// sort of done with knight and archer 
// 4/24/17: Due To Time Constraints, just focus on the actual players and interactions:
// What to limit (for now) : Only Have Dragon and Goblin King, The 8 Primary classes -> Achive throughout the game 
// Work on itoa (basically ints to strings )
// Problems with the Zero, not doing anything 
// Work on the Dragon and The Goblin King Randomizing attacks and making the strings work for the players and the Enemy Bosses 
// Should also probably get the other power of the characters to work...
// Work on the Health and attacks... And i guess everything else but ya' know 4/26/17
// The Health should go to zero

#include <iostream>
#include <Windows.h>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <ctime>
#include <queue>
#include <time.h>
#include <graphics.h>
#include <cmath>
#include <winbgi.cpp>
#include "VirtualKeys.h"

using namespace std;
void gr_Start(int &GrDriver, int&GrMode, int&ErrorCode) {
	//set the graphics driver
	GrDriver = VGA; //800x600 by monitor
	GrMode = VGAMAX;//set graphics mode
	initgraph(&GrDriver, &GrMode, "");//start graphics
									  //check for problems
	ErrorCode = graphresult();
	if (ErrorCode != grOk)
	{
		cout << "Error:" << ErrorCode;
	}
}


enum CLASS { KNIGHT, ARCHER, WIZARD, PRIEST, CAVALIER, JUGGERNAUGHT, BMAGE, GUARDIAN, DKNIGHT, LICH, DRAGON, GOBLINKING };
enum PLAYERS { PLAYER1 = 1, PLAYER2 = 2, PLAYER3 = 3, PLAYER4 = 4, ENEMY = 5 };
enum SCREEN { OPENING, TITLE, GOBLINK };
int enemyColor = 5;
int AttackSpot, ClassSpot, PlayerBeingAttackedSpot;

struct PlayerStruct {
	// Just Test Variables 
	string Name;
	string Class;
	string Power = "6";
	string Health = "100";
	int HealthInt = 100;
	int SaveHealth; bool saveHealthTurn;
	int SetHealth = 100;
	string Attack = "6";
	int AttackInt = 6;
	string AtkStr1, AtkStr2, AtkStr3, AtkStr4, AtkStr5, WAIT;
	int AtkInt1 = 1, AtkInt2 = 2, AtkInt3 = 3, AtkInt4 = 4, AtkInt5 = 4;
	string AtKChoice = "0"; // 1, 2, 3, 4, 5
	int PlayerTarget; // Who the player targets, Will always be Dragon / Lich, this is mainly for the GP
	int PowerInt = 7;
	bool Alive = true;
	bool CannotAttack = false;
	bool ThornInTheSide = false;
	void init(CLASS CLASSNAME) {
		switch (CLASSNAME) {
		case KNIGHT:
			Class = "Knight"; // Basic Tank, With some attacking and Defending moves, Classic Warrior w/ Sheild and Sword
			Health = "20";
			HealthInt = 20;
			SetHealth = 20;
			Attack = "5";
			AttackInt = 5;
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Swift Slash"; AtkStr2 = "Sheild Block"; AtkStr3 = "WarCry";
			AtkStr4 = "Sheild Wall"; AtkStr5 = "Sword Rush"; WAIT;
			AtkInt1 = 1; AtkInt2 = 2; AtkInt3 = 2; AtkInt4 = 3; AtkInt5 = 4;
			break;
		case ARCHER:
			Class = "Archer"; // Blocker, Stop the Dragon from attacking, Wears Disk Helmet w/ Bow 
			Health = "16"; // 16
			HealthInt = 16;
			SetHealth = 16;
			Attack = "4"; // 4
			Power = "1"; // 4
			PowerInt = 1; // 4
			Alive = true;
			AtkStr1 = "Accurate Arrow"; AtkStr2 = "Multiple Shots"; AtkStr3 = "Caging The Beast";
			AtkStr4 = "Dragon Trip"; AtkStr5 = "Thorn In The Side"; WAIT;
			AtkInt1 = 1; AtkInt2 = 2; AtkInt3 = 2; AtkInt4 = 3; AtkInt5 = 3;
			break;
		case WIZARD:
			Class = "Wizard"; // Glass Cannon, Can build up huge damage over time, Scepter w/ robes
			Health = "14";
			HealthInt = 14;
			SetHealth = 14;
			Attack = "6";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Ice Storm"; AtkStr2 = "Fire Blast"; AtkStr3 = "Lightning Bolt";
			AtkStr4 = "Shadow Reach"; AtkStr5 = "Terra Blessing"; WAIT;
			AtkInt1 = 2; AtkInt2 = 2; AtkInt3 = 2; AtkInt4 = 3; AtkInt5 = 4;
			break;
		case PRIEST:
			Class = "Priest"; // Primary Healer, Gets the Healing Done, Hammer and Helmet with slits Horizontal
			Health = "18";
			HealthInt = 18;
			SetHealth = 18;
			Attack = "3";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Holy Hammer"; AtkStr2 = "Soothing Touch"; AtkStr3 = "Spirit Call";
			AtkStr4 = "Divine Deed"; AtkStr5 = "Revival"; WAIT;
			AtkInt1 = 1; AtkInt2 = 1; AtkInt3 = 3; AtkInt4 = 3; AtkInt5 = 4;
			break;
		case CAVALIER:
			Class = "Cavalier"; // More Damage Oriented, Yet is very Bulky, FlatTop w/ lance and horse
			Health = "25";
			HealthInt = 25;
			SetHealth = 25;
			Attack = "6";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Lightning Lance"; AtkStr2 = "Holding Ground"; AtkStr3 = "Lytherick's Light";
			AtkStr4 = "CHARGE!!!"; AtkStr5 = "Judgement Jousting"; WAIT;
			AtkInt1 = 1; AtkInt2 = 2; AtkInt3 = 2; AtkInt4 = 3; AtkInt5 = 4;
			break;
		case JUGGERNAUGHT:
			Class = "Juggernaught"; // A True Tank, ment to take a lot of Damage, More of a Gladiator huge axe
			Health = "30";
			HealthInt = 30;
			SetHealth = 30;
			Attack = "3";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Axe Throw"; AtkStr2 = "PowerShot!"; AtkStr3 = "Triumphant Charge";
			AtkStr4 = "\"Hey Ugly!\""; AtkStr5 = "Earthquake"; WAIT;
			AtkInt1 = 1; AtkInt2 = 3; AtkInt3 = 2; AtkInt4 = 3; AtkInt5 = 3;
			break;
		case BMAGE:
			Class = "Blood Mage"; // Small Buff over the Mage Focuses on How weak he is (think BLOOD MAGE)
			Health = "15";
			HealthInt = 15;
			SetHealth = 15;
			Attack = "7";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Discharge"; AtkStr2 = "Self Sacrifice"; AtkStr3 = "Anger To Life";
			AtkStr4 = "Half To Death"; AtkStr5 = "Repaid For Burdens"; WAIT;
			AtkInt1 = 1; AtkInt2 = 1; AtkInt3 = 1; AtkInt4 = 1; AtkInt5 = 1;
			break;
		case GUARDIAN:
			Class = "Guardian"; // Status Buffs and Healing, suffers with damage output, Angel
			Health = "18";
			HealthInt = 18;
			SetHealth = 18;
			Attack = "4";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			AtkStr1 = "Healing Aura"; AtkStr2 = "Attack Aura"; AtkStr3 = "Power Aura";
			AtkStr4 = "Fly"; AtkStr5 = "Lytheric's Blessing"; WAIT;
			AtkInt1 = 0; AtkInt2 = 0; AtkInt3 = 0; AtkInt4 = 2; AtkInt5 = 1;
			break;
		case DKNIGHT:
			Class = "Dragon Knight"; // Huge Attack but has to charge up a shot, Can also decide the order of the Attacks being placed, BroadSword
			Health = "23";
			HealthInt = 23;
			SetHealth = 23;
			Attack = "16";
			Power = "1";
			PowerInt = 1;
			Alive = true;
			// So i'll describe the attacks of this char: Meditate-Brings up the power, Life, and attack. BroadSword Blitz-Wait a Turn to do 16 damage
			// Breakneck Blade-Wait a Turn and cut 3 with random damage accounts, Dragon Form-Heals the DKnight Fully and turns him into a Dragon, can 
			// only be used once before turning back into a human, Ordering the Attacks-Deciding the Order of The Attack order(passive)
			AtkStr1 = "Meditate"; AtkStr2 = "BroadSword Blitz"; AtkStr3 = "Breakneck Blade";
			AtkStr4 = "Dragon Form"; AtkStr5 = "Ordering The Attacks"; WAIT;
			AtkInt1 = 1; AtkInt2 = 2; AtkInt3 = 2; AtkInt4 = 4; AtkInt5 = 0;
			break;
		case DRAGON:
			Health = "100";
			HealthInt = 100;
			SetHealth = 100;
			Attack = "4";
			Power = "1";
			PowerInt = 1;
			enemyColor = 5;
			Alive = true;
			Class = "Dragon";
			break;
		case LICH:
			Health = "75";
			HealthInt = 75;
			SetHealth = 75;
			Attack = "7";
			Power = "1";
			PowerInt = 1;
			enemyColor = 9;
			Alive = true;
			Class = "Lich";
			break;
		case GOBLINKING:
			Health = "25";
			HealthInt = 25;
			SetHealth = 25;
			Attack = "3";
			Power = "1";
			PowerInt = 1;
			enemyColor = 12;
			AtkInt1 = 1; AtkInt2 = 2; AtkInt3 = 3; AtkInt4 = 4; AtkInt5 = 5;
			Alive = true;
			Class = "Goblin King";
			break;
		}
	}

	void Attacks(int PlayerAtking, CLASS CLASSNAME, int AttackSpot, int PlayerBeingAttacked) {
		// Goes Who is attacking? -> Class Of Char? -> Which Attack? -> Used on who? 
		switch (PlayerAtking) {
		case 1:
			switch (CLASSNAME) {
			case KNIGHT:switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Swift Strike
			case 5:
			case 1: Enemy.HealthInt = Enemy.HealthInt - Player1.AttackInt; break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player1.AttackInt; break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player1.AttackInt; break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player1.AttackInt; break;
			}
			case 2: switch (PlayerBeingAttacked) { // Sheild Block
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: Player1.SaveHealth = Player1.HealthInt; break;

			}
			case 3: switch (PlayerBeingAttacked) { // WarCry
			case 1:
			case 2:
			case 3:
			case 4: Player1.AttackInt++; break;
			case 5: Player1.AttackInt++; Player2.AttackInt++; Player3.AttackInt++; Player4.AttackInt++; break;
			}
			case 4: switch (PlayerBeingAttacked) { // Large Sheild
			case 1:
			case 2:
			case 3:
			case 4: Player1.SaveHealth = Player1.HealthInt; break;
			case 5: Player1.SaveHealth = Player1.HealthInt; Player2.SaveHealth = Player2.HealthInt; Player3.SaveHealth = Player3.HealthInt; Player4.SetHealth = Player4.HealthInt; break;
			}
			case 5: switch (PlayerBeingAttacked) {
			case 5:
			case 1: Enemy.HealthInt = Enemy.HealthInt - (Player1.AttackInt * 2); break;
			case 2: Player2.HealthInt = Player2.HealthInt - (Player1.AttackInt * 2); break;
			case 3: Player3.HealthInt = Player3.HealthInt - (Player1.AttackInt * 2); break;
			case 4: Player4.HealthInt = Player4.HealthInt - (Player1.AttackInt * 2); break;
			}
			} break;
			case ARCHER:switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Accurate Arrow
			case 5:
			case 1: Enemy.HealthInt = Enemy.HealthInt - Player1.AttackInt; break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player1.AttackInt; break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player1.AttackInt; break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player1.AttackInt; break;
			} break;
			case 2: switch (PlayerBeingAttacked) { // Multiple Shots
												   // Accurate Arrow
			case 1:
			case 2:
			case 3:
			case 4: Player2.HealthInt = Player2.HealthInt - (Player1.AttackInt / 3); Player3.HealthInt = Player3.HealthInt - (Player1.AttackInt / 3); Player4.HealthInt = Player4.HealthInt - (Player1.AttackInt / 3); break;
			case 5: Enemy.HealthInt = Enemy.HealthInt - (Player1.AttackInt + 1); break;
			} break;
			case 3: switch (PlayerBeingAttacked) { // Caging the beast
			case 1:
			case 2:
			case 3:
			case 4: Player2.CannotAttack = true; Player3.CannotAttack = true; Player4.CannotAttack = true; break;
			case 5: Enemy.CannotAttack = true; break;
			} break;
			case 4: switch (PlayerBeingAttacked) { // Dragon Trip
			case 1:
			case 2:
			case 3:
			case 4: Player2.CannotAttack = true; Player3.CannotAttack = true; Player4.CannotAttack = true;
				Player2.HealthInt = Player2.HealthInt - (Player1.AttackInt / 3); Player3.HealthInt = Player3.HealthInt - (Player1.AttackInt / 3); Player4.HealthInt = Player4.HealthInt - (Player1.AttackInt / 3);
				break;
			case 5: Enemy.CannotAttack = true; Enemy.HealthInt = Enemy.HealthInt - (Player1.AttackInt / 3); break;
			} break;
			case 5: switch (PlayerBeingAttacked) {
			case 2: Player2.ThornInTheSide = true; break;
			case 3: Player3.ThornInTheSide = true; break;
			case 4: Player4.ThornInTheSide = true; break;
			case 1:
			case 5: Enemy.ThornInTheSide = true; break;
			} break;
			}
			case WIZARD: break;
			case PRIEST: break;
			case CAVALIER: break;
			case DKNIGHT: break;
			}
			break; //Player1
		case 2:
			switch (CLASSNAME) {
			case KNIGHT:switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Swift Strike
			case 5:
			case 2: Enemy.HealthInt = Enemy.HealthInt - Player2.AttackInt; break;
			case 1: Player1.HealthInt = Player1.HealthInt - Player2.AttackInt; break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player2.AttackInt; break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player2.AttackInt; break;
			}
			case 2: switch (PlayerBeingAttacked) { // Sheild Block
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: Player2.SaveHealth = Player2.HealthInt; break;

			}
			case 3: switch (PlayerBeingAttacked) { // WarCry
			case 1:
			case 2:
			case 3:
			case 4: Player2.AttackInt++; break;
			case 5: Player1.AttackInt++; Player2.AttackInt++; Player3.AttackInt++; Player4.AttackInt++; break;
			}
			case 4: switch (PlayerBeingAttacked) { // Large Sheild
			case 1:
			case 2:
			case 3:
			case 4: Player2.SaveHealth = Player2.HealthInt; break;
			case 5: Player1.SaveHealth = Player1.HealthInt; Player2.SaveHealth = Player2.HealthInt; Player3.SaveHealth = Player3.HealthInt; Player4.SetHealth = Player4.HealthInt; break;

			}
			case 5: switch (PlayerBeingAttacked) {
			case 5:
			case 2: Enemy.HealthInt = Enemy.HealthInt - (Player2.AttackInt * 2); break;
			case 1: Player1.HealthInt = Player1.HealthInt - (Player2.AttackInt * 2); break;
			case 3: Player3.HealthInt = Player3.HealthInt - (Player2.AttackInt * 2); break;
			case 4: Player4.HealthInt = Player4.HealthInt - (Player2.AttackInt * 2); break;
			}
			} break;
			case ARCHER: switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Accurate Arrow
			case 5:
			case 2: Enemy.HealthInt = Enemy.HealthInt - Player2.AttackInt; break;
			case 1: Player1.HealthInt = Player1.HealthInt - Player2.AttackInt; break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player2.AttackInt; break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player2.AttackInt; break;
			} break;
			case 2: switch (PlayerBeingAttacked) { // Multiple Shots
			case 1:
			case 2:
			case 3:
			case 4: Player1.HealthInt = Player1.HealthInt - (Player2.AttackInt / 3); Player3.HealthInt = Player3.HealthInt - (Player2.AttackInt / 3); Player4.HealthInt = Player4.HealthInt - (Player2.AttackInt / 3); break;
			case 5: Enemy.HealthInt = Enemy.HealthInt - (Player2.AttackInt + 1); break;
			} break;
			case 3: switch (PlayerBeingAttacked) { // Caging the beast
			case 1:
			case 2:
			case 3:
			case 4: Player1.CannotAttack = true; Player3.CannotAttack = true; Player4.CannotAttack = true; break;
			case 5: Enemy.CannotAttack = true; break;
			} break;
			case 4: switch (PlayerBeingAttacked) { // Dragon Trip
			case 1:
			case 2:
			case 3:
			case 4: Player1.CannotAttack = true; Player3.CannotAttack = true; Player4.CannotAttack = true;
				Player1.HealthInt = Player1.HealthInt - (Player2.AttackInt / 3); Player3.HealthInt = Player3.HealthInt - (Player2.AttackInt / 3); Player4.HealthInt = Player4.HealthInt - (Player2.AttackInt / 3);
				break;
			case 5: Enemy.CannotAttack = true; Enemy.HealthInt = Enemy.HealthInt - (Player2.AttackInt / 3); break;

			} break;
			case 5: switch (PlayerBeingAttacked) {
			case 2: Player1.ThornInTheSide = true; break;
			case 3: Player3.ThornInTheSide = true; break;
			case 4: Player4.ThornInTheSide = true; break;
			case 1:
			case 5: Enemy.ThornInTheSide = true; break;
			} break;
			}break;
			case WIZARD: break;
			case PRIEST: break;
			case JUGGERNAUGHT: break;
			}
			break; // Player2
		case 3:
			switch (CLASSNAME) {
			case KNIGHT: switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Swift Strike
			case 5:
			case 3: Enemy.HealthInt = Enemy.HealthInt - Player3.AttackInt; break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player3.AttackInt; break;
			case 1: Player1.HealthInt = Player1.HealthInt - Player3.AttackInt; break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player3.AttackInt; break;
			}
			case 2: switch (PlayerBeingAttacked) { // Sheild Block
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: Player3.SaveHealth = Player3.HealthInt; break;

			}
			case 3: switch (PlayerBeingAttacked) { // WarCry
			case 1:
			case 2:
			case 3:
			case 4: Player3.AttackInt++; break;
			case 5: Player1.AttackInt++; Player2.AttackInt++; Player3.AttackInt++; Player4.AttackInt++; break;
			}
			case 4: switch (PlayerBeingAttacked) { // Large Sheild
			case 1:
			case 2:
			case 3:
			case 4: Player3.SaveHealth = Player3.HealthInt; break;
			case 5: Player1.SaveHealth = Player1.HealthInt; Player2.SaveHealth = Player2.HealthInt; Player3.SaveHealth = Player3.HealthInt; Player4.SetHealth = Player4.HealthInt; break;

			}
			case 5: switch (PlayerBeingAttacked) {
			case 5:
			case 3: Enemy.HealthInt = Enemy.HealthInt - (Player3.AttackInt * 2); break;
			case 2: Player2.HealthInt = Player2.HealthInt - (Player3.AttackInt * 2); break;
			case 1: Player1.HealthInt = Player1.HealthInt - (Player3.AttackInt * 2); break;
			case 4: Player4.HealthInt = Player4.HealthInt - (Player3.AttackInt * 2); break;
			}
			}break;
			case ARCHER: switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Accurate Arrow
			case 5:
			case 3: Enemy.HealthInt = Enemy.HealthInt - Player3.AttackInt; break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player3.AttackInt; break;
			case 1: Player1.HealthInt = Player1.HealthInt - Player3.AttackInt; break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player3.AttackInt; break;
			} break;
			case 2: switch (PlayerBeingAttacked) { // Multiple Shots
			case 1:
			case 2:
			case 3:
			case 4: Player2.HealthInt = Player2.HealthInt - (Player3.AttackInt / 3); Player1.HealthInt = Player1.HealthInt - (Player3.AttackInt / 3); Player4.HealthInt = Player4.HealthInt - (Player3.AttackInt / 3); break;
			case 5: Enemy.HealthInt = Enemy.HealthInt - (Player3.AttackInt + 1); break;
			} break;
			case 3: switch (PlayerBeingAttacked) { // Caging the beast
			case 1:
			case 2:
			case 3:
			case 4: Player2.CannotAttack = true; Player1.CannotAttack = true; Player4.CannotAttack = true; break;
			case 5: Enemy.CannotAttack = true; break;
			} break;
			case 4: switch (PlayerBeingAttacked) { // Dragon Trip
			case 1:
			case 2:
			case 3:
			case 4: Player2.CannotAttack = true; Player1.CannotAttack = true; Player4.CannotAttack = true;
				Player2.HealthInt = Player2.HealthInt - (Player3.AttackInt / 3); Player1.HealthInt = Player1.HealthInt - (Player3.AttackInt / 3); Player4.HealthInt = Player4.HealthInt - (Player3.AttackInt / 3);
				break;
			case 5: Enemy.CannotAttack = true; Enemy.HealthInt = Enemy.HealthInt - (Player3.AttackInt / 3); break;

			} break;
			case 5: switch (PlayerBeingAttacked) {
			case 2: Player2.ThornInTheSide = true; break;
			case 1: Player1.ThornInTheSide = true; break;
			case 4: Player4.ThornInTheSide = true; break;
			case 3:
			case 5: Enemy.ThornInTheSide = true; break;
			} break;
			}break;
			case WIZARD: break;
			case PRIEST: break;
			case BMAGE: break;
			}
			break; // Player3
		case 4:
			switch (CLASSNAME) {
			case KNIGHT:switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Swift Strike
			case 5:
			case 4: Enemy.HealthInt = Enemy.HealthInt - Player4.AttackInt; break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player4.AttackInt; break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player4.AttackInt; break;
			case 1: Player1.HealthInt = Player1.HealthInt - Player4.AttackInt; break;
			}
			case 2: switch (PlayerBeingAttacked) { // Sheild Block
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: Player4.SaveHealth = Player4.HealthInt; break;

			}
			case 3: switch (PlayerBeingAttacked) { // WarCry
			case 1:
			case 2:
			case 3:
			case 4: Player4.AttackInt++; break;
			case 5: Player1.AttackInt++; Player2.AttackInt++; Player3.AttackInt++; Player4.AttackInt++; break;
			}
			case 4: switch (PlayerBeingAttacked) {
			case 1:
			case 2:
			case 3:
			case 4: Player4.SaveHealth = Player4.HealthInt; break;
			case 5: Player1.SaveHealth = Player1.HealthInt; Player2.SaveHealth = Player2.HealthInt; Player3.SaveHealth = Player3.HealthInt; Player4.SetHealth = Player4.HealthInt; break;

			}
			case 5: switch (PlayerBeingAttacked) {
			case 5:
			case 4: Enemy.HealthInt = Enemy.HealthInt - (Player4.AttackInt * 2); break;
			case 2: Player2.HealthInt = Player2.HealthInt - (Player4.AttackInt * 2); break;
			case 3: Player3.HealthInt = Player3.HealthInt - (Player4.AttackInt * 2); break;
			case 1: Player1.HealthInt = Player1.HealthInt - (Player4.AttackInt * 2); break;
			}
			} break;
			case ARCHER:switch (AttackSpot) {
			case 1: switch (PlayerBeingAttacked) { // Accurate Arrow
			case 5:
			case 4: Enemy.HealthInt = Enemy.HealthInt - Player4.AttackInt; break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player4.AttackInt; break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player4.AttackInt; break;
			case 1: Player1.HealthInt = Player1.HealthInt - Player4.AttackInt; break;
			} break;
			case 2: switch (PlayerBeingAttacked) { // Multiple Shots
			case 1:
			case 2:
			case 3:
			case 4: Player2.HealthInt = Player2.HealthInt - (Player4.AttackInt / 3); Player3.HealthInt = Player3.HealthInt - (Player4.AttackInt / 3); Player1.HealthInt = Player1.HealthInt - (Player4.AttackInt / 3); break;
			case 5: Enemy.HealthInt = Enemy.HealthInt - (Player4.AttackInt + 1); break;
			} break;
			case 3: switch (PlayerBeingAttacked) { // Caging the beast
			case 1:
			case 2:
			case 3:
			case 4: Player2.CannotAttack = true; Player3.CannotAttack = true; Player1.CannotAttack = true; break;
			case 5: Enemy.CannotAttack = true; break;
			} break;
			case 4: switch (PlayerBeingAttacked) { // Dragon Trip
			case 1:
			case 2:
			case 3:
			case 4: Player2.CannotAttack = true; Player3.CannotAttack = true; Player1.CannotAttack = true;
				Player2.HealthInt = Player2.HealthInt - (Player4.AttackInt / 3); Player3.HealthInt = Player3.HealthInt - (Player4.AttackInt / 3); Player1.HealthInt = Player1.HealthInt - (Player4.AttackInt / 3);
				break;
			case 5: Enemy.CannotAttack = true; Enemy.HealthInt = Enemy.HealthInt - (Player4.AttackInt / 3); break;

			} break;
			case 5: switch (PlayerBeingAttacked) {
			case 2: Player2.ThornInTheSide = true; break;
			case 3: Player3.ThornInTheSide = true; break;
			case 1: Player1.ThornInTheSide = true; break;
			case 4:
			case 5: Enemy.ThornInTheSide = true; break;
			} break;
			} break;
			case WIZARD: break;
			case PRIEST: break;
			case GUARDIAN: break;
			}
			break; // Player4
		case 5:
			switch (CLASSNAME) {
			case GOBLINKING: break;
			case DRAGON: break;
			case LICH: break;
			}
			break; // Enemy
		}
	}
}Player1, Player2, Player3, Player4, Enemy;

int GameType = 1; //1 = Single Player 2 = Dragon, 3 = Lich, 4 = Gladiator Pit
string Power = "PWR: ", HealthPoints = "HP: ", Class = "CLS: ", Attack = "ATK: ";
string Sample = "Sample", SampleLong = "This is a Long Sample that shows how far the text box can go. This is a test to see the capabilities of this...";
string GoblinKingWord = "GOBLIN KING", DragonWord = "DRAGON", LichWord = "LICH", GladiatorWord = "GLADIATOR PIT", GAMEOVER = "GAME OVER", YOUWIN = "YOU WIN", THEWINNERIS = "THE WINNER IS ";
bool KnightToDragon = false;
bool GameStillGoing = true;
string FillerString;
string FreeClass;
int player1Color = 1, player2Color = 2, player3Color = 4, player4Color = 14;
int GlobalFreeVar;
int TheAttackChoice;
#pragma region StartUpCode
int GrDriver, GrMode, ErrorCode;
int maxX, maxY, penColor, Sppeedd; // max X and Y as well as penColor
int XCord = (maxX / 2);
int YCord = (maxY / 2);
#pragma endregion
int SmallMovementVar = maxX / 111;
int ThisPositionX1, ThisPositionY1, ThisPositionX2, ThisPositionY2, ThisPositionX3, ThisPositionY3, ThisPositionX4, ThisPositionY4, ThisPositionXEnemy, ThisPositionYEnemy;

void attackMoves(int PlayerNumber, int AttackMoveNumber, int AttackWho) {
	switch (PlayerNumber) {
	case 1: switch (AttackMoveNumber) {
	case 1:
		if (Player1.Class == "Knight" || Player1.Class == "Archer" || Player1.Class == "Wizard" || Player1.Class == "Priest" || Player1.Class == "Cavalier") {
			switch (AttackWho) { // Swift Slash
			case 1: Player1.HealthInt = Player1.HealthInt - Player1.AttackInt; Player1.Health = to_string(Player1.HealthInt); break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player1.AttackInt; Player2.Health = to_string(Player2.HealthInt); break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player1.AttackInt; Player3.Health = to_string(Player3.HealthInt); break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player1.AttackInt; Player4.Health = to_string(Player4.HealthInt); break;
			case 5: Enemy.HealthInt = Enemy.HealthInt - Player1.AttackInt; Enemy.Health = to_string(Enemy.HealthInt); 
				break;
			}
		}
		if (Player1.Class == "Dragon Knight") {
			if (KnightToDragon == false) {
				switch (AttackWho) { // Meditate
				case 1: Player1.HealthInt = Player1.HealthInt + (Player1.SetHealth / 3); Player1.Power = Player1.PowerInt++; break;
				case 2: Player1.HealthInt = Player1.HealthInt + (Player1.SetHealth / 3); Player1.Power = Player1.PowerInt++; break;
				case 3: Player1.HealthInt = Player1.HealthInt + (Player1.SetHealth / 3); Player1.Power = Player1.PowerInt++; break;
				case 4: Player1.HealthInt = Player1.HealthInt + (Player1.SetHealth / 3); Player1.Power = Player1.PowerInt++; break;
				case 5: Player1.HealthInt = Player1.HealthInt + (Player1.SetHealth / 3); Player1.Power = Player1.PowerInt++; break;
				}
			}
			if (KnightToDragon == true) {
				switch (AttackWho) { // Dragon Flame
				case 1: Player1.HealthInt = Player1.HealthInt - Player1.AttackInt; Player1.Health = Player1.HealthInt; break;
				case 2: Player2.HealthInt = Player2.HealthInt - Player1.AttackInt; Player2.Health = Player2.HealthInt;
				case 3: Player3.HealthInt = Player3.HealthInt - Player1.AttackInt; Player3.Health = Player3.HealthInt;
				case 4: Player4.HealthInt = Player4.HealthInt - Player1.AttackInt; Player4.Health = Player4.HealthInt; break;
				case 5: Enemy.HealthInt = Enemy.HealthInt - Player1.AttackInt; Enemy.Health = Enemy.HealthInt; break;
				}
			}
		}
		break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	} break; // Player1
	case 2: switch (AttackMoveNumber) {
	case 1: if (Player2.Class == "Knight" || Player2.Class == "Archer" || Player2.Class == "Wizard" || Player2.Class == "Priest" || Player2.Class == "Juggernaught") {
		switch (AttackWho) { // Swift Slash
		case 1: Player1.HealthInt = Player1.HealthInt - Player2.AttackInt; Player1.Health = to_string(Player1.HealthInt); break;
		case 2: Player2.HealthInt = Player2.HealthInt - Player2.AttackInt; Player2.Health = to_string(Player2.HealthInt); break;
		case 3: Player3.HealthInt = Player3.HealthInt - Player2.AttackInt; Player3.Health = to_string(Player3.HealthInt); break;
		case 4: Player4.HealthInt = Player4.HealthInt - Player2.AttackInt; Player4.Health = to_string(Player4.HealthInt); break;
		case 5: Enemy.HealthInt = Enemy.HealthInt - Player2.AttackInt; Enemy.Health = to_string(Enemy.HealthInt); break;
		}
	} break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	} break; // Player2
	case 3: switch (AttackMoveNumber) {
	case 1: if (Player3.Class == "Knight" || Player3.Class == "Archer" || Player3.Class == "Wizard" || Player3.Class == "Priest" || Player3.Class == "Blood Mage") {
		switch (AttackWho) { // Swift Slash
		case 1: Player1.HealthInt = Player1.HealthInt - Player3.AttackInt; Player1.Health = to_string(Player1.HealthInt); break;
		case 2: Player2.HealthInt = Player2.HealthInt - Player3.AttackInt; Player2.Health = to_string(Player2.HealthInt); break;
		case 3: Player3.HealthInt = Player3.HealthInt - Player3.AttackInt; Player3.Health = to_string(Player3.HealthInt); break;
		case 4: Player4.HealthInt = Player4.HealthInt - Player3.AttackInt; Player4.Health = to_string(Player4.HealthInt); break;
		case 5: Enemy.HealthInt = Enemy.HealthInt - Player3.AttackInt; Enemy.Health = Enemy.HealthInt; break;
		}
	} break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	} break; // Player3
	case 4: switch (AttackMoveNumber) {
	case 1:
		if (Player4.Class == "Knight" || Player4.Class == "Archer" || Player4.Class == "Wizard" || Player4.Class == "Priest") {
			switch (AttackWho) { // Swift Slash
			case 1: Player1.HealthInt = Player1.HealthInt - Player4.AttackInt; Player1.Health = to_string(Player1.HealthInt); break;
			case 2: Player2.HealthInt = Player2.HealthInt - Player4.AttackInt; Player2.Health = to_string(Player2.HealthInt); break;
			case 3: Player3.HealthInt = Player3.HealthInt - Player4.AttackInt; Player3.Health = to_string(Player3.HealthInt); break;
			case 4: Player4.HealthInt = Player4.HealthInt - Player4.AttackInt; Player4.Health = to_string(Player4.HealthInt); break;
			case 5: Enemy.HealthInt = Enemy.HealthInt - Player4.AttackInt; Enemy.Health = to_string(Enemy.HealthInt); break;
			}
		}
		if (Player4.Class == "Guardian") {
			switch (AttackWho) { // Health Aura
			case 1: Player4.HealthInt = Player4.HealthInt + 3; Player4.Health = to_string(Player4.HealthInt); break;
			case 2: Player4.HealthInt = Player4.HealthInt + 3; Player4.Health = to_string(Player4.HealthInt); break;
			case 3: Player4.HealthInt = Player4.HealthInt + 3; Player4.Health = to_string(Player4.HealthInt); break;
			case 4: Player4.HealthInt = Player4.HealthInt + 3; Player4.Health = to_string(Player4.HealthInt); break;
			case 5: Player1.HealthInt = Player1.HealthInt + 3; Player1.Health = to_string(Player1.HealthInt);
				Player2.HealthInt = Player2.HealthInt + 3; Player2.Health = to_string(Player2.HealthInt);
				Player3.HealthInt = Player3.HealthInt + 3; Player3.Health = to_string(Player3.HealthInt);
				Player4.HealthInt = Player4.HealthInt + 3; Player4.Health = to_string(Player4.HealthInt);
			}
		}
		break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	} break; // Player4
	case 5: switch (AttackMoveNumber) {
	case 0: break;
	case 1:
		if (Enemy.Class == "Goblin King" || Enemy.Class == "Dragon" || Enemy.Class == "Lich") { // Basic Attack
			switch (AttackWho) {
			case 1: Player1.HealthInt = Player1.HealthInt - Enemy.AttackInt; Player1.Health = to_string(Player1.HealthInt); break;
			case 2: Player2.HealthInt = Player2.HealthInt - Enemy.AttackInt; Player2.Health = to_string(Player2.HealthInt); break;
			case 3: Player3.HealthInt = Player3.HealthInt - Enemy.AttackInt; Player3.Health = to_string(Player3.HealthInt); break;
			case 4: Player4.HealthInt = Player4.HealthInt - Enemy.AttackInt; Player4.Health = to_string(Player4.HealthInt); break;
			}
		}	
		break;
	case 2: 
		if (Enemy.Class == "Goblin King") {
			switch (AttackWho) {
			case 1: 
			case 2: 
			case 3: 
			case 4: Enemy.SaveHealth = Enemy.HealthInt; Enemy.saveHealthTurn = true; break;
				break;
			}
		}

		break;
	case 3: 
		if (Enemy.Class == "Goblin King") {
			switch (AttackWho) {
			case 1: Player1.HealthInt = Player1.HealthInt - (Enemy.AttackInt * 2); Player1.Health = to_string(Player1.HealthInt); break;
			case 2: Player2.HealthInt = Player2.HealthInt - (Enemy.AttackInt * 2); Player2.Health = to_string(Player2.HealthInt); break;
			case 3: Player3.HealthInt = Player3.HealthInt - (Enemy.AttackInt * 2); Player3.Health = to_string(Player3.HealthInt); break;
			case 4: Player4.HealthInt = Player4.HealthInt - (Enemy.AttackInt * 2); Player4.Health = to_string(Player4.HealthInt); break;
			}
		}
		break;
	case 4: 
		if (Enemy.Class == "Goblin King") { // Drinking Ale, replenish life
			switch (AttackWho) {
			case 1: 
			case 2: 
			case 3: 
			case 4: Enemy.HealthInt = Enemy.HealthInt + 6; Enemy.Health = to_string(Enemy.HealthInt); break;
			}
		}
		break;
	case 5: 
		if (Enemy.Class == "Goblin King"){
			switch (AttackWho) {
			case 1: 
			case 2: 
			case 3: 
			case 4: Player1.AttackInt = Player1.AttackInt - 1; Player1.Attack = to_string(Player1.AttackInt);
				break;
			}
		}
		break;
} break; // Enemy
	}
}
int AttackTargetAndAttack(int PLAYERS) {
	//Input What Attack
	//Check To See if Allowed Power Wise
	//Have Target
	//Apply
	int AttackName;
	int FreeVar; // Free Variable At My disposal
	bool FreeBool = true; // Free Bool At my disposal : If "false" you may continue with your turn
						  // Only Player 1 is sort of set up

	switch (PLAYERS) {
	case 1:
		while (FreeBool) {
			if (Player1.Alive == true) {
				cin >> FreeVar; if (GameType == 4) { cin >> TheAttackChoice; }
				else { TheAttackChoice = 5; }
			}
			else { Player1.AtKChoice = FreeVar = 0; }
			if (0 <= FreeVar <= 5) {
				switch (FreeVar) {
				case 0: FreeBool = false; break;
				case 1: if (0 <= Player1.PowerInt - Player1.AtkInt1) { Player1.PowerInt = Player1.PowerInt - Player1.AtkInt1; attackMoves(1, 1, TheAttackChoice); FreeBool = false; } break;
				case 2: if (0 <= Player1.PowerInt - Player1.AtkInt2) { Player1.PowerInt = Player1.PowerInt - Player1.AtkInt2; attackMoves(1, 2, TheAttackChoice); FreeBool = false; } break;
				case 3: if (0 <= Player1.PowerInt - Player1.AtkInt3) { Player1.PowerInt = Player1.PowerInt - Player1.AtkInt3; attackMoves(1, 3, TheAttackChoice); FreeBool = false; } break;
				case 4: if (0 <= Player1.PowerInt - Player1.AtkInt4) { Player1.PowerInt = Player1.PowerInt - Player1.AtkInt4; attackMoves(1, 4, TheAttackChoice); FreeBool = false; } break;
				case 5: if (0 <= Player1.PowerInt - Player1.AtkInt5) { Player1.PowerInt = Player1.PowerInt - Player1.AtkInt5; attackMoves(1, 5, TheAttackChoice); FreeBool = false; } break;
				}
			}
			Player1.Power = to_string(Player1.PowerInt);
		}
		break;
	case 2:
		while (FreeBool) {
			if (Player2.Alive == true) {
				cin >> FreeVar; if (GameType == 4) { cin >> TheAttackChoice; }
				else { TheAttackChoice = 5; }
			}
			else { Player2.AtKChoice = FreeVar = 0; }
			if (0 <= FreeVar <= 5) {
				switch (FreeVar) {
				case 0: FreeBool = false; break;
				case 1: if (0 <= Player2.PowerInt - Player2.AtkInt1) { Player2.PowerInt = Player2.PowerInt - Player2.AtkInt1; attackMoves(2, 1, TheAttackChoice); FreeBool = false; } break;
				case 2: if (0 <= Player2.PowerInt - Player2.AtkInt2) { Player2.PowerInt = Player2.PowerInt - Player2.AtkInt2; attackMoves(2, 2, TheAttackChoice); FreeBool = false; } break;
				case 3: if (0 <= Player2.PowerInt - Player2.AtkInt3) { Player2.PowerInt = Player2.PowerInt - Player2.AtkInt3; attackMoves(2, 3, TheAttackChoice); FreeBool = false; } break;
				case 4: if (0 <= Player2.PowerInt - Player2.AtkInt4) { Player2.PowerInt = Player2.PowerInt - Player2.AtkInt4; attackMoves(2, 4, TheAttackChoice); FreeBool = false; } break;
				case 5: if (0 <= Player2.PowerInt - Player2.AtkInt5) { Player2.PowerInt = Player2.PowerInt - Player2.AtkInt5; attackMoves(2, 5, TheAttackChoice); FreeBool = false; } break;
				}
			}
			Player2.Power = to_string(Player2.PowerInt);
		}
		break;
	case 3:
		while (FreeBool) {
			if (Player3.Alive == true) {
				cin >> FreeVar; if (GameType == 4) { cin >> TheAttackChoice; }
				else { TheAttackChoice = 5; }
			}
			else { Player3.AtKChoice = FreeVar = 0; }
			if (0 <= FreeVar <= 5) {
				switch (FreeVar) {
				case 0: FreeBool = false; break;
				case 1: if (0 <= Player3.PowerInt - Player3.AtkInt1) { Player3.PowerInt = Player3.PowerInt - Player3.AtkInt1; attackMoves(3, 1, TheAttackChoice); FreeBool = false; } break;
				case 2: if (0 <= Player3.PowerInt - Player3.AtkInt2) { Player3.PowerInt = Player3.PowerInt - Player3.AtkInt2; attackMoves(3, 2, TheAttackChoice); FreeBool = false; } break;
				case 3: if (0 <= Player3.PowerInt - Player3.AtkInt3) { Player3.PowerInt = Player3.PowerInt - Player3.AtkInt3; attackMoves(3, 3, TheAttackChoice); FreeBool = false; } break;
				case 4: if (0 <= Player3.PowerInt - Player3.AtkInt4) { Player3.PowerInt = Player3.PowerInt - Player3.AtkInt4; attackMoves(3, 4, TheAttackChoice); FreeBool = false; } break;
				case 5: if (0 <= Player3.PowerInt - Player3.AtkInt5) { Player3.PowerInt = Player3.PowerInt - Player3.AtkInt5; attackMoves(3, 5, TheAttackChoice); FreeBool = false; } break;
				}
			}
			Player3.Power = to_string(Player3.PowerInt);
		}
		break;
	case 4:
		while (FreeBool) {
			if (Player4.Alive == true) {
				cin >> FreeVar; if (GameType == 4) { cin >> TheAttackChoice; }
				else { TheAttackChoice = 5; }
			}
			else { Player4.AtKChoice = FreeVar = 0; }
			if (0 <= FreeVar <= 5) {
				switch (FreeVar) {
				case 0: FreeBool = false; break;
				case 1: if (0 <= Player4.PowerInt - Player4.AtkInt1) { Player4.PowerInt = Player4.PowerInt - Player4.AtkInt1; attackMoves(4, 1, TheAttackChoice); FreeBool = false; } break;
				case 2: if (0 <= Player4.PowerInt - Player4.AtkInt2) { Player4.PowerInt = Player4.PowerInt - Player4.AtkInt2; attackMoves(4, 2, TheAttackChoice); FreeBool = false; } break;
				case 3: if (0 <= Player4.PowerInt - Player4.AtkInt3) { Player4.PowerInt = Player4.PowerInt - Player4.AtkInt3; attackMoves(4, 3, TheAttackChoice); FreeBool = false; } break;
				case 4: if (0 <= Player4.PowerInt - Player4.AtkInt4) { Player4.PowerInt = Player4.PowerInt - Player4.AtkInt4; attackMoves(4, 4, TheAttackChoice); FreeBool = false; } break;
				case 5: if (0 <= Player4.PowerInt - Player4.AtkInt5) { Player4.PowerInt = Player4.PowerInt - Player4.AtkInt5; attackMoves(4, 5, TheAttackChoice); FreeBool = false; } break;
				}
			}
			Player4.Power = to_string(Player4.PowerInt);
		}
		break;
	case 5:
		while (FreeBool) {
			if (Enemy.Alive == true) {
				if (GameType == 4) { Enemy.Alive = false; }
				else if (GameType == 1) { TheAttackChoice = 1; FreeVar = rand() % 6; }
				else { TheAttackChoice = rand() % 4 + 1; FreeVar = rand() % 6; }
			}
			else { Enemy.AtKChoice = FreeVar = 0; }
			if (0 <= FreeVar <= 5) {
				switch (FreeVar) {
				case 0: FreeBool = false; break;
				case 1: if (0 <= Enemy.PowerInt - Enemy.AtkInt1) { Enemy.PowerInt = Enemy.PowerInt - Enemy.AtkInt1; attackMoves(5, 1, TheAttackChoice); FreeBool = false; } break;
				case 2: if (0 <= Enemy.PowerInt - Enemy.AtkInt2) { Enemy.PowerInt = Enemy.PowerInt - Enemy.AtkInt2; attackMoves(5, 2, TheAttackChoice); FreeBool = false; } break;
				case 3: if (0 <= Enemy.PowerInt - Enemy.AtkInt3) { Enemy.PowerInt = Enemy.PowerInt - Enemy.AtkInt3; attackMoves(5, 3, TheAttackChoice); FreeBool = false; } break;
				case 4: if (0 <= Enemy.PowerInt - Enemy.AtkInt4) { Enemy.PowerInt = Enemy.PowerInt - Enemy.AtkInt4; attackMoves(5, 4, TheAttackChoice); FreeBool = false; } break;
				case 5: if (0 <= Enemy.PowerInt - Enemy.AtkInt5) { Enemy.PowerInt = Enemy.PowerInt - Enemy.AtkInt5; attackMoves(5, 5, TheAttackChoice); FreeBool = false; } break;
				}
			}
			Enemy.Power = to_string(Enemy.PowerInt);
		}
		break;
	}
	return 0;
}

int theConversionFromIntToString(int PlayerConvertInt, string PlayerConvertString) {
	PlayerConvertString = to_string(PlayerConvertInt);
	return 0;
}

int TalkingOnTwoLines(string ThisIS, string ThisIS2, int ThisColor) {
	int HIEGHT;
	int WIDTH;
	setcolor(ThisColor);
	Sample = ThisIS;
	HIEGHT = textheight(Sample.c_str());
	WIDTH = textwidth(Sample.c_str());
	moveto((maxX / 2) - (WIDTH / 2), (maxY / 2) - (HIEGHT * 1.25));
	outtext(Sample.c_str());
	Sample = ThisIS2;
	HIEGHT = textheight(Sample.c_str());
	WIDTH = textwidth(Sample.c_str());
	moveto((maxX / 2) - (WIDTH / 2), (maxY / 2) - (HIEGHT));
	moverel(0, (HIEGHT));
	outtext(Sample.c_str());

	return 0;
}
int TalkingOnThreeLines(string ThisIS, string ThisIS2, string ThisIS3, int ThisColor) {
	int HIEGHT;
	int WIDTH;
	setcolor(ThisColor);
	Sample = ThisIS;
	HIEGHT = textheight(Sample.c_str());
	WIDTH = textwidth(Sample.c_str());
	moveto((maxX / 2) - (WIDTH / 2), (maxY / 2) - (HIEGHT * 2.50));
	outtext(Sample.c_str());
	Sample = ThisIS2;
	HIEGHT = textheight(Sample.c_str());
	WIDTH = textwidth(Sample.c_str());
	moveto((maxX / 2) - (WIDTH / 2), (maxY / 2) - (HIEGHT * 1.25));
	moverel(0, (HIEGHT));
	outtext(Sample.c_str());
	Sample = ThisIS3;
	moveto((maxX / 2) - (WIDTH / 2), (maxY / 2) - (HIEGHT));
	moverel(0, (HIEGHT));
	outtext(Sample.c_str());

	return 0;
}
int ShakingOneLine(string NAMEifAny, string ThisIS, int ThisColorTalking, int ThisColorText, int Number1, int Number2) {
	int HIEGHT;
	int WIDTH;
	setcolor(ThisColorTalking);
	Sample = NAMEifAny;
	HIEGHT = textheight(Sample.c_str());
	WIDTH = textwidth(Sample.c_str());
	moveto(((maxX / 2) - (WIDTH / 2)) + Number1, ((maxY / 2) - (HIEGHT* 2.5)) + Number2);
	outtext(Sample.c_str());
	setcolor(ThisColorText);
	Sample = ThisIS;
	HIEGHT = textheight(Sample.c_str());
	WIDTH = textwidth(Sample.c_str());
	moveto(((maxX / 2) - (WIDTH / 2)) + Number1, ((maxY / 2) - (HIEGHT)) + Number2);
	outtext(Sample.c_str());
	return 0;
}
int TextToScreen(SCREEN WhatTheScreenIs) {
	// You use this for talking, its not as much the function as much as it is the initalizer
	int x = 4;
	int HIEGHT;
	int WIDTH;
	setcolor(0);
	bar(0, 0, maxX, maxY);
	cleardevice();
	settextstyle(6, 0, 2);
	setcolor(15);

	switch (WhatTheScreenIs) {
	case OPENING:
		Sleep(1400);
#pragma region FirstScreen
		Sleep(500);
		TalkingOnTwoLines("Eons ago", "Two Brothers,  LYTHERICK  and  POLLARS , fought against each other...", 8);
		Sleep(500);
		TalkingOnTwoLines("Eons ago", "Two Brothers,  LYTHERICK  and  POLLARS , fought against each other...", 7);
		Sleep(700);
		TalkingOnTwoLines("Eons ago", "Two Brothers,  LYTHERICK  and  POLLARS , fought against each other...", 15);
		Sleep(4000);
		TalkingOnTwoLines("Eons ago", "Two Brothers,  LYTHERICK  and  POLLARS , fought against each other...", 7);
		Sleep(700);
		TalkingOnTwoLines("Eons ago", "Two Brothers,  LYTHERICK  and  POLLARS , fought against each other...", 8);
		Sleep(500);
		TalkingOnTwoLines("Eons ago", "Two Brothers,  LYTHERICK  and  POLLARS , fought against each other...", 0);
#pragma endregion
		Sleep(1000);
#pragma region SecondScreen
		TalkingOnTwoLines("LYTHERICK  sought the ways of the Light, training  Knights  in the  Art of Chivalry,", "But  POLLARS  followed a different path...", 8);
		Sleep(500);
		TalkingOnTwoLines("LYTHERICK  sought the ways of the Light, training  Knights  in the  Art of Chivalry,", "But  POLLARS  followed a different path...", 7);
		Sleep(700);
		TalkingOnTwoLines("LYTHERICK  sought the ways of the Light, training  Knights  in the  Art of Chivalry,", "But  POLLARS  followed a different path...", 15);
		Sleep(7000);
		TalkingOnTwoLines("LYTHERICK  sought the ways of the Light, training  Knights  in the  Art of Chivalry,", "But  POLLARS  followed a different path...", 7);
		Sleep(700);
		TalkingOnTwoLines("LYTHERICK  sought the ways of the Light, training  Knights  in the  Art of Chivalry,", "But  POLLARS  followed a different path...", 8);
		Sleep(500);
		TalkingOnTwoLines("LYTHERICK  sought the ways of the Light, training  Knights  in the  Art of Chivalry,", "But  POLLARS  followed a different path...", 0);
#pragma endregion		
		Sleep(1000);
#pragma region ThirdScreen
		TalkingOnTwoLines("When most vunrable,  LYTHERICK  was captured and locked away by his Brother,", "Ever since,  POLLARS  and his Minions regined over the land and terrorized the People...", 8);
		Sleep(500);
		TalkingOnTwoLines("When most vunrable,  LYTHERICK  was captured and locked away by his Brother,", "Ever since,  POLLARS  and his Minions regined over the land and terrorized the People...", 7);
		Sleep(700);
		TalkingOnTwoLines("When most vunrable,  LYTHERICK  was captured and locked away by his Brother,", "Ever since,  POLLARS  and his Minions regined over the land and terrorized the People...", 15);
		Sleep(9000);
		TalkingOnTwoLines("When most vunrable,  LYTHERICK  was captured and locked away by his Brother,", "Ever since,  POLLARS  and his Minions regined over the land and terrorized the People...", 7);
		Sleep(700);
		TalkingOnTwoLines("When most vunrable,  LYTHERICK  was captured and locked away by his Brother,", "Ever since,  POLLARS  and his Minions regined over the land and terrorized the People...", 8);
		Sleep(500);
		TalkingOnTwoLines("When most vunrable,  LYTHERICK  was captured and locked away by his Brother,", "Ever since,  POLLARS  and his Minions regined over the land and terrorized the People...", 0);
#pragma endregion		
		Sleep(1000);
#pragma region FourthScreen
		TalkingOnTwoLines("Heros are spread far and few, but some still follow  LYTHERICK'S  Teachings,", "Now  YOU  must save the World from certain doom in...", 8);
		Sleep(500);
		TalkingOnTwoLines("Heros are spread far and few, but some still follow  LYTHERICK'S  Teachings,", "Now  YOU  must save the World from certain doom in...", 7);
		Sleep(700);
		TalkingOnTwoLines("Heros are spread far and few, but some still follow  LYTHERICK'S  Teachings,", "Now  YOU  must save the World from certain doom in...", 15);
		Sleep(7000);
		TalkingOnTwoLines("Heros are spread far and few, but some still follow  LYTHERICK'S  Teachings,", "Now  YOU  must save the World from certain doom in...", 7);
		Sleep(700);
		TalkingOnTwoLines("Heros are spread far and few, but some still follow  LYTHERICK'S  Teachings,", "Now  YOU  must save the World from certain doom in...", 8);
		Sleep(500);
		TalkingOnTwoLines("Heros are spread far and few, but some still follow  LYTHERICK'S  Teachings,", "Now  YOU  must save the World from certain doom in...", 0);
		Sleep(1500);
#pragma endregion		
		break;
	case TITLE:
		settextstyle(1, 0, 9);
		while (x <= 9) {
			TalkingOnTwoLines("KNIGHT", "QUEST", 7);
			Sleep(40);
			TalkingOnTwoLines("KNIGHT", "QUEST", 9);
			Sleep(40);
			TalkingOnTwoLines("KNIGHT", "QUEST", 11);
			Sleep(40);
			TalkingOnTwoLines("KNIGHT", "QUEST", 3);
			Sleep(40);
			TalkingOnTwoLines("KNIGHT", "QUEST", 1);
			Sleep(40);
			x++;
		}
		
		break;
	case GOBLINK:
		Sleep(750);
#pragma region FirstScreen
		while (x <= 9) {
			cleardevice();
			ShakingOneLine("GOBLIN KING:", "WWWWWWAAAAAAAARRRRRRR!!!", enemyColor, 15, 4, 4);
			Sleep(25);
			cleardevice();
			ShakingOneLine("GOBLIN KING:", "WWWWWWAAAAAAAARRRRRRR!!!", enemyColor, 15, 14, -14);
			Sleep(25);
			cleardevice();
			ShakingOneLine("GOBLIN KING:", "WWWWWWAAAAAAAARRRRRRR!!!", enemyColor, 15, -4, -14);
			Sleep(25);
			cleardevice();
			ShakingOneLine("GOBLIN KING:", "WWWWWWAAAAAAAARRRRRRR!!!", enemyColor, 15, -14, 14);
			Sleep(25);
			x++;
		}
		cleardevice();
		ShakingOneLine("GOBLIN KING:", "WWWWWWAAAAAAAARRRRRRR!!!", enemyColor, 15, 0, 0);
#pragma endregion 
		Sleep(1400);
#pragma region SecondScreen
		cleardevice();
		ShakingOneLine("VILLAGER:", "Help Us!", 9, 15, 0, 0);
		Sleep(1250);
		cleardevice();
		ShakingOneLine("VILLAGER:", "The GOBLINS are attacking!", 12, 15, 0, 0);
		Sleep(1450);
		cleardevice();
		ShakingOneLine("VILLAGER:", "RUUUNNN!!!", 13, 15, 0, 0);
		Sleep(950);
#pragma endregion
		Sleep(900);
#pragma region ThirdScreen
		cleardevice();
		TalkingOnTwoLines("A nearby TAVERN is being pillaged by a  GOBLIN KING  !!!", "YOU  must defeat the Barbaric Creature at all costs!!!", 15);
		Sleep(3000);
#pragma endregion
		system("pause");
		break;
	}
	return 0;
}

int Sword() {
	//Test To See if My Graphics Skills are up to par
	setcolor(15);
	bar(87, 57, 290, 37);
	setcolor(8);
	bar(25, 37, 87, 57);
	setcolor(1);
	bar(107, 10, 87, 85);
	return 0;
}
int ForDragon() {
	if (KnightToDragon == true) {
		Player1.Alive = true; Player1.Attack = 9; Player1.Health = 20; Player1.Power = "4"; Player1.PowerInt = 4;
		Player1.AtkStr1 = "Dragon Breath"; Player1.AtkStr2 = "Fly"; Player1.AtkStr3 = "Tail Whip"; Player1.AtkStr4 = "Mighty Roar"; Player1.AtkStr5 = "Knight Form";
	}
	return 0;
}
void PlayerAndClassSetUp(int ThePlayerNumber) {
	if (FreeClass == "Knight" || FreeClass == "knight" || FreeClass == "KNIGHT" || FreeClass == "KNight" || FreeClass == "K" || FreeClass == "k") {
		switch (ThePlayerNumber) {
		case 1: Player1.init(KNIGHT); break;
		case 2: Player2.init(KNIGHT); break;
		case 3: Player3.init(KNIGHT); break;
		case 4: Player4.init(KNIGHT); break;
		}
	}
	if (FreeClass == "Archer" || FreeClass == "archer" || FreeClass == "ARCHER" || FreeClass == "ARcher" || FreeClass == "A" || FreeClass == "a") {
		switch (ThePlayerNumber) {
		case 1: Player1.init(ARCHER);
		case 2: Player2.init(ARCHER);
		case 3: Player3.init(ARCHER);
		case 4: Player4.init(ARCHER);
		}
	}
	if (FreeClass == "Wizard" || FreeClass == "wizard" || FreeClass == "WIZARD" || FreeClass == "WIzard" || FreeClass == "W" || FreeClass == "w") {
		switch (ThePlayerNumber) {
		case 1: Player1.init(WIZARD);
		case 2: Player2.init(WIZARD);
		case 3: Player3.init(WIZARD);
		case 4: Player4.init(WIZARD);
		}
	}
	if (FreeClass == "Priest" || FreeClass == "priest" || FreeClass == "PRIEST" || FreeClass == "PRiest" || FreeClass == "P" || FreeClass == "p") {
		switch (ThePlayerNumber) {
		case 1: Player1.init(PRIEST);
		case 2: Player2.init(PRIEST);
		case 3: Player3.init(PRIEST);
		case 4: Player4.init(PRIEST);
		}
	}
	if (Player1.Name == "Odax" || Player1.Name == "odax" || Player1.Name == "ODAX") { Player1.init(CAVALIER); player1Color = 10; }
	if (Player2.Name == "Issej" || Player2.Name == "issej" || Player2.Name == "ISSEJ") { Player2.init(JUGGERNAUGHT); player2Color = 6; }
	if (Player3.Name == "Raxxis" || Player3.Name == "raxxis" || Player3.Name == "RAXXIS") { Player3.init(BMAGE); player3Color = 13; }
	if (Player4.Name == "Ankilles" || Player4.Name == "ankilles" || Player4.Name == "ANKILLES") { Player4.init(GUARDIAN); player4Color = 8; }
	if (Player1.Name == "Erik" && (FreeClass == "KnightHood" || FreeClass == "Knighthood" || FreeClass == "KNIGHTHOOD" || FreeClass == "knighthood" || FreeClass == "kn" || FreeClass == "Kn" || FreeClass == "KN" || FreeClass == "kN")) {
		Player1.init(DKNIGHT); player1Color = 7; // 7 is a Gray, 9 is a Light Blue, 11 is a Shade darker than white, 12 is a Light Red, 13 is a Light Purple 
	}
}
void BarsForPlayers(int PlayerNumber, int ThePower) {
	switch (PlayerNumber) {
	case 1: setcolor(player1Color);
		switch (ThePower) { // Don't forget to have a Black Rectangle at the begining of the "DividingUpTheScreen"
		case 0: break;
		case 1: bar(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 60)), ThisPositionY1 + (maxY / 50)); break;
		case 2: bar(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 30)), ThisPositionY1 + (maxY / 50)); break;
		case 3: bar(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 20)), ThisPositionY1 + (maxY / 50)); break;
		case 4: bar(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 15)), ThisPositionY1 + (maxY / 50)); break;
		} break;
	case 2: setcolor(player2Color);
		switch (ThePower) {
		case 0: break;
		case 1: bar(ThisPositionX2, ThisPositionY2, ThisPositionX2 + (maxX / 60), ThisPositionY2 + (maxY / 50)); break;// Making the Rectangles for the power box for player 1
		case 2: bar(ThisPositionX2, ThisPositionY2, ThisPositionX2 + ((maxX / 30)), ThisPositionY2 + (maxY / 50)); break;
		case 3: bar(ThisPositionX2, ThisPositionY2, ThisPositionX2 + ((maxX / 20)), ThisPositionY2 + (maxY / 50)); break;
		case 4: bar(ThisPositionX2, ThisPositionY2, ThisPositionX2 + ((maxX / 15)), ThisPositionY2 + (maxY / 50)); break;
		} break;
	case 3: setcolor(player3Color);
		switch (ThePower) {
		case 0: break;
		case 1: bar(ThisPositionX3, ThisPositionY3, ThisPositionX3 + (maxX / 60), ThisPositionY3 + (maxY / 50)); break;// Making the Rectangles for the power box for player 1
		case 2: bar(ThisPositionX3, ThisPositionY3, ThisPositionX3 + ((maxX / 30)), ThisPositionY3 + (maxY / 50)); break;
		case 3: bar(ThisPositionX3, ThisPositionY3, ThisPositionX3 + ((maxX / 20)), ThisPositionY3 + (maxY / 50)); break;
		case 4: bar(ThisPositionX3, ThisPositionY3, ThisPositionX3 + ((maxX / 15)), ThisPositionY3 + (maxY / 50)); break;
		}  break;
	case 4: setcolor(player4Color);
		switch (ThePower) {
		case 0: break;
		case 1: bar(ThisPositionX4, ThisPositionY4, ThisPositionX4 + (maxX / 60), ThisPositionY4 + (maxY / 50)); break;// Making the Rectangles for the power box for player 1
		case 2: bar(ThisPositionX4, ThisPositionY4, ThisPositionX4 + ((maxX / 30)), ThisPositionY4 + (maxY / 50)); break;
		case 3: bar(ThisPositionX4, ThisPositionY4, ThisPositionX4 + ((maxX / 20)), ThisPositionY4 + (maxY / 50)); break;
		case 4: bar(ThisPositionX4, ThisPositionY4, ThisPositionX4 + ((maxX / 15)), ThisPositionY4 + (maxY / 50)); break;
		}  break;
	case 5:
		switch (ThePower) {
		case 0: break;
		case 7: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50)); break;
		case 6: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 8.17), ThisPositionYEnemy + (maxY / 50)); break;
		case 5: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 9.8), ThisPositionYEnemy + (maxY / 50)); break;
		case 4: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 12.25), ThisPositionYEnemy + (maxY / 50)); break;
		case 3: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 16.4), ThisPositionYEnemy + (maxY / 50)); break;
		case 2: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 24.5), ThisPositionYEnemy + (maxY / 50)); break;
		case 1: bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 49), ThisPositionYEnemy + (maxY / 50)); break;
		} break;
	}
}
void DividingUpTheScreenBoss(int x) {
#pragma region TheExInts
	// May make these Integers Global soon
	int MaxX = maxX / 3; // 1/3 The Screen
	int MaxY;
	int MaxX1 = maxX / 3 * 2; // 2/ 3 the screen
	int MaxX2 = maxX / 4; //1/4 of the screen
	int MaxX3 = maxX / 4 * 2; // 1/2 of the Screen 
	int MaxX4 = maxX / 4 * 3; // 3/4 of the Screen
	int MaxX5 = maxX / 6; //1/6 of the screen
	int MaxX6 = maxX / 6 * 2; // 1/3 of the screen
	int MaxX7 = maxX / 6 * 3; // 1/2 of the screen
	int MaxX8 = maxX / 6 * 4; // 2/3 of the screen
	int MaxX9 = maxX / 6 * 5; // 5/6 of the screen
	int MaxY1 = maxY / 4;
	int MaxY2 = maxY / 2;
	int MaxY3 = maxY * 8 / 15;
	int MaxY4 = maxY * 8 / 8.25;
	// Ment for dividing up the screen into the parts that I need 
	/*
	setlinestyle(1, 2, 0);
	setcolor(15); // Accros Screen
	line(0, 0, maxX, maxY);
	setcolor(5);
	line(MaxX, 0, MaxX, maxY);
	line(MaxX1, 0, MaxX1, maxY);
	setcolor(14); // Player Bars
	line(MaxX2, 0, MaxX2, maxY);
	line(MaxX3, 0, MaxX3, maxY);
	line(MaxX4, 0, MaxX4, maxY);
	setcolor(3); // Text/Bottom Bars
	line(MaxX5, 0, MaxX5, maxY);
	line(MaxX6, 0, MaxX6, maxY);
	line(MaxX7, 0, MaxX7, maxY);
	line(MaxX8, 0, MaxX8, maxY);
	line(MaxX9, 0, MaxX9, maxY);
	setcolor(5); // Division of Dragon
	line(0, MaxY1, maxX, MaxY1);
	setcolor(14); // Division of Players
	line(0, MaxY2, maxX, MaxY2);
	setcolor(2); // Division of Talking Screen Must be inbetween the two of these
	line(0, MaxY3, maxX, MaxY3);
	line(0, MaxY4, maxX, MaxY4);
	*/
#pragma endregion 
	int HIEGHT;
	int WIDTH;

	if (GameType == 2 || GameType == 3 || GameType == 4) {
#pragma region DragonSetup
		if (GameType == 2) {
			moveto(MaxX * 1.18, MaxY1 * 0.20); // New Dragon Name
			setcolor(enemyColor);
			settextstyle(1, 0, 5);
			outtext(DragonWord.c_str());
			moveto(MaxX * 1.36 - (maxX / 250), (MaxY1 * 0.20) + (maxY / 13));
			setcolor(15);
			settextstyle(1, 0, 1);
			outtext(HealthPoints.c_str());
			moverel(SmallMovementVar, 0);
			setcolor(enemyColor);
			FillerString = Enemy.Health;
			outtext(FillerString.c_str());
			setcolor(15);
			moveto(MaxX * 1.18 - (maxX / 250), ((MaxY1 * 0.20) + (maxY / 9))); // * 17
			outtext(Power.c_str());
			moverel(SmallMovementVar, 0);
			setlinestyle(1, 0, 2);
			ThisPositionXEnemy = getx();
			ThisPositionYEnemy = gety();
			setcolor(0);
			bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50));
			setcolor(enemyColor);
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 49), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 24.5), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 16.4), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 12.25), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 9.8), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 8.17), ThisPositionYEnemy + (maxY / 50));
			BarsForPlayers(5, Enemy.PowerInt);
			setlinestyle(1, 0, 2);
		}
#pragma endregion
#pragma region LichSetup
		if (GameType == 3) {
			moveto(MaxX * 1.30, MaxY1 * 0.20); // New Dragon Name
			setcolor(enemyColor);
			settextstyle(1, 0, 5);
			outtext(LichWord.c_str());
			moveto(MaxX * 1.36 - (maxX / 250), (MaxY1 * 0.20) + (maxY / 13));
			setcolor(15);
			settextstyle(1, 0, 1);
			outtext(HealthPoints.c_str());
			moverel(SmallMovementVar, 0);
			setcolor(enemyColor);
			FillerString = Enemy.Health;
			outtext(FillerString.c_str());
			setcolor(15);
			moveto(MaxX * 1.18 - (maxX / 250), ((MaxY1 * 0.20) + (maxY / 9))); // * 17
			outtext(Power.c_str());
			moverel(SmallMovementVar, 0);
			setcolor(enemyColor);
			setlinestyle(1, 0, 2);
			ThisPositionXEnemy = getx();
			ThisPositionYEnemy = gety();
			setcolor(0);
			bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50));
			setcolor(enemyColor);
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 49), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 24.5), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 16.4), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 12.25), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 9.8), ThisPositionYEnemy + (maxY / 50));
			rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 8.17), ThisPositionYEnemy + (maxY / 50));
			BarsForPlayers(5, Enemy.PowerInt);
			setlinestyle(1, 0, 2);
		}
#pragma endregion
#pragma region GladiatorSetup
		if (GameType == 4) {
			moveto(MaxX * 1, MaxY1 * 0.20); // New Dragon Name
			setcolor(12);
			settextstyle(1, 0, 5);
			outtext(GladiatorWord.c_str());
			setlinestyle(1, 0, 2);
		}
#pragma endregion

#pragma region Player1setup
		int ThisIsATest = (maxX - 0) * 0.06; // Basic Idea: Take the last val and put it with the new one
		moveto(ThisIsATest, MaxY2 * 0.62);
		settextstyle(1, 0, 3);
		setcolor(player1Color);
		outtext(Player1.Name.c_str());
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 25));
		settextstyle(1, 0, 1);
		outtext(HealthPoints.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player1Color);
		outtext(Player1.Health.c_str());
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 14));
		outtext(Power.c_str());
		moverel(SmallMovementVar, 0);
		ThisPositionX1 = getx();
		ThisPositionY1 = gety();
		setcolor(0);
		bar(ThisPositionX1, ThisPositionY1, ThisPositionX1 + (maxX / 15), ThisPositionY1 + (maxY / 50));
		setcolor(player1Color);
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + (maxX / 15), ThisPositionY1 + (maxY / 50)); // Making the Rectangles for the power box for player 1
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 60)), ThisPositionY1 + (maxY / 50));
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 30)), ThisPositionY1 + (maxY / 50));
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 20)), ThisPositionY1 + (maxY / 50));
		setcolor(15);
		BarsForPlayers(1, Player1.PowerInt);
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 10));
		outtext(Class.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player1Color);
		outtext(Player1.Class.c_str());
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 8));
		outtext(Attack.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player1Color);
		outtext(Player1.Attack.c_str());
#pragma endregion
#pragma region Player2setup
		int ThisIsATest1 = (maxX - 0) * 0.3; // Basic Idea: Take the last val and put it with the new one
		moveto(ThisIsATest1, MaxY2 * 0.62);
		setcolor(player2Color);
		settextstyle(1, 0, 3);
		outtext(Player2.Name.c_str());
		setcolor(15);
		moveto(ThisIsATest1 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 25));
		settextstyle(1, 0, 1);
		outtext(HealthPoints.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player2Color);
		outtext(Player2.Health.c_str());
		setcolor(15);
		moveto(ThisIsATest1 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 14));
		outtext(Power.c_str());
		moverel(SmallMovementVar, 0);
		ThisPositionX2 = getx();
		ThisPositionY2 = gety();
		setcolor(0);
		bar(ThisPositionX2, ThisPositionY2, ThisPositionX2 + (maxX / 15), ThisPositionY2 + (maxY / 50));
		setcolor(player2Color);
		rectangle(ThisPositionX2, ThisPositionY2, ThisPositionX2 + (maxX / 15), ThisPositionY2 + (maxY / 50)); // Making the Rectangles for the power box for player 1
		rectangle(ThisPositionX2, ThisPositionY2, ThisPositionX2 + ((maxX / 60)), ThisPositionY2 + (maxY / 50));
		rectangle(ThisPositionX2, ThisPositionY2, ThisPositionX2 + ((maxX / 30)), ThisPositionY2 + (maxY / 50));
		rectangle(ThisPositionX2, ThisPositionY2, ThisPositionX2 + ((maxX / 20)), ThisPositionY2 + (maxY / 50));
		setcolor(15);
		BarsForPlayers(2, Player2.PowerInt);
		setcolor(15);
		moveto(ThisIsATest1 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 10));
		outtext(Class.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player2Color);
		outtext(Player2.Class.c_str());
		setcolor(15);
		moveto(ThisIsATest1 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 8));
		outtext(Attack.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player2Color);
		outtext(Player2.Attack.c_str());
#pragma endregion
#pragma region Player3setup
		int ThisIsATest2 = (maxX - 0) * 0.54; // Basic Idea: Take the last val and put it with the new one
		moveto(ThisIsATest2, MaxY2 * 0.62);
		setcolor(player3Color);
		settextstyle(1, 0, 3);
		outtext(Player3.Name.c_str());
		setcolor(15);
		moveto(ThisIsATest2 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 25));
		settextstyle(1, 0, 1);
		outtext(HealthPoints.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player3Color);
		outtext(Player3.Health.c_str());
		setcolor(15);
		moveto(ThisIsATest2 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 14));
		outtext(Power.c_str());
		moverel(SmallMovementVar, 0);
		ThisPositionX3 = getx();
		ThisPositionY3 = gety();
		setcolor(0);
		bar(ThisPositionX3, ThisPositionY3, ThisPositionX3 + (maxX / 15), ThisPositionY3 + (maxY / 50));
		setcolor(player3Color);
		rectangle(ThisPositionX3, ThisPositionY3, ThisPositionX3 + (maxX / 15), ThisPositionY3 + (maxY / 50)); // Making the Rectangles for the power box for player 1
		rectangle(ThisPositionX3, ThisPositionY3, ThisPositionX3 + ((maxX / 60)), ThisPositionY3 + (maxY / 50));
		rectangle(ThisPositionX3, ThisPositionY3, ThisPositionX3 + ((maxX / 30)), ThisPositionY3 + (maxY / 50));
		rectangle(ThisPositionX3, ThisPositionY3, ThisPositionX3 + ((maxX / 20)), ThisPositionY3 + (maxY / 50));
		setcolor(15);
		BarsForPlayers(3, Player3.PowerInt);
		setcolor(15);
		moveto(ThisIsATest2 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 10));
		outtext(Class.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player3Color);
		outtext(Player3.Class.c_str());
		setcolor(15);
		moveto(ThisIsATest2 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 8));
		outtext(Attack.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player3Color);
		outtext(Player3.Attack.c_str());
#pragma endregion
#pragma region Player4setup 
		int ThisIsATest3 = (maxX - 0) * 0.78; // Basic Idea: Take the last val and put it with the new one
		moveto(ThisIsATest3, MaxY2 * 0.62);
		setcolor(player4Color);
		settextstyle(1, 0, 3);
		outtext(Player4.Name.c_str());
		setcolor(15);
		moveto(ThisIsATest3 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 25));
		settextstyle(1, 0, 1);
		outtext(HealthPoints.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player4Color);
		outtext(Player4.Health.c_str());
		setcolor(15);
		moveto(ThisIsATest3 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 14));
		outtext(Power.c_str());
		moverel(SmallMovementVar, 0);
		ThisPositionX4 = getx();
		ThisPositionY4 = gety();
		setcolor(0);
		bar(ThisPositionX4, ThisPositionY4, ThisPositionX4 + (maxX / 15), ThisPositionY4 + (maxY / 50));
		setcolor(player4Color);
		rectangle(ThisPositionX4, ThisPositionY4, ThisPositionX4 + (maxX / 15), ThisPositionY4 + (maxY / 50)); // Making the Rectangles for the power box for player 1
		rectangle(ThisPositionX4, ThisPositionY4, ThisPositionX4 + ((maxX / 60)), ThisPositionY4 + (maxY / 50));
		rectangle(ThisPositionX4, ThisPositionY4, ThisPositionX4 + ((maxX / 30)), ThisPositionY4 + (maxY / 50));
		rectangle(ThisPositionX4, ThisPositionY4, ThisPositionX4 + ((maxX / 20)), ThisPositionY4 + (maxY / 50));
		setcolor(15);
		BarsForPlayers(4, Player4.PowerInt);
		setcolor(15);
		moveto(ThisIsATest3 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 10));
		outtext(Class.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player4Color);
		outtext(Player4.Class.c_str()); setcolor(15);
		moveto(ThisIsATest3 - (maxX / 250), (MaxY2 * 0.62) + (maxY / 8));
		outtext(Attack.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player4Color);
		outtext(Player4.Attack.c_str());
#pragma endregion
	}
	if (GameType == 1) {
#pragma region GoblinKingSetup
		WIDTH = textwidth(GoblinKingWord.c_str());
		moveto((maxX / 2) - (maxX / 6), MaxY1 * 0.20); // New Name
		setcolor(enemyColor);
		settextstyle(1, 0, 5);
		outtext(GoblinKingWord.c_str());
		moveto(MaxX * 1.36 - (maxX / 250), (MaxY1 * 0.20) + (maxY / 13));
		setcolor(15);
		settextstyle(1, 0, 1);
		outtext(HealthPoints.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(enemyColor);
		// Draw a box around it using the text width ad height function
		Enemy.Health = to_string(Enemy.HealthInt);

		setlinestyle(1, 0, 4);
		ThisPositionXEnemy = getx();
		ThisPositionYEnemy = gety();
		setcolor(0);
		bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 400));

		setcolor(enemyColor);
		outtext(Enemy.Health.c_str());
		setcolor(15);
		moveto(MaxX * 1.18 - (maxX / 250), ((MaxY1 * 0.20) + (maxY / 9))); // * 17
		outtext(Power.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(enemyColor);
		setlinestyle(1, 0, 2);
		ThisPositionXEnemy = getx();
		ThisPositionYEnemy = gety();
		setcolor(0);
		bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50));
		setcolor(enemyColor);
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 50));
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 49), ThisPositionYEnemy + (maxY / 50));
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 24.5), ThisPositionYEnemy + (maxY / 50));
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 16.4), ThisPositionYEnemy + (maxY / 50));
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 12.25), ThisPositionYEnemy + (maxY / 50));
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 9.8), ThisPositionYEnemy + (maxY / 50));
		rectangle(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 8.17), ThisPositionYEnemy + (maxY / 50));
		BarsForPlayers(5, Enemy.PowerInt);
		setlinestyle(1, 0, 2);

#pragma endregion
#pragma region Player1SimglePlayerSetUp
		int ThisIsATest = MaxX7 - (maxX / 11); // Basic Idea: Take the last val and put it with the new one
		moveto(ThisIsATest, MaxY2 * 0.62);
		settextstyle(1, 0, 3);
		setcolor(player1Color);
		outtext(Player1.Name.c_str());
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 25));
		settextstyle(1, 0, 1);
		outtext(HealthPoints.c_str());
		moverel(SmallMovementVar, 0);

		Player1.Health = to_string(Player1.HealthInt);

		setlinestyle(1, 0, 4);
		ThisPositionXEnemy = getx();
		ThisPositionYEnemy = gety();
		setcolor(0);
		bar(ThisPositionXEnemy, ThisPositionYEnemy, ThisPositionXEnemy + (maxX / 7), ThisPositionYEnemy + (maxY / 400));
		setlinestyle(1, 0, 3);

		setcolor(player1Color);
		outtext(Player1.Health.c_str());
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 14));
		outtext(Power.c_str());
		moverel(SmallMovementVar, 0);
		ThisPositionX1 = getx();
		ThisPositionY1 = gety();
		setcolor(0);
		bar(ThisPositionX1, ThisPositionY1, ThisPositionX1 + (maxX / 15), ThisPositionY1 + (maxY / 50));
		setcolor(player1Color);
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + (maxX / 15), ThisPositionY1 + (maxY / 50)); // Making the Rectangles for the power box for player 1
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 60)), ThisPositionY1 + (maxY / 50));
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 30)), ThisPositionY1 + (maxY / 50));
		rectangle(ThisPositionX1, ThisPositionY1, ThisPositionX1 + ((maxX / 20)), ThisPositionY1 + (maxY / 50));
		setcolor(15);
		BarsForPlayers(1, Player1.PowerInt);
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 10));
		outtext(Class.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player1Color);
		outtext(Player1.Class.c_str());
		setcolor(15);
		moveto(ThisIsATest - (maxX / 250), (MaxY2 * 0.62) + (maxY / 8));
		outtext(Attack.c_str());
		moverel(SmallMovementVar, 0);
		setcolor(player1Color);
		outtext(Player1.Attack.c_str());


#pragma endregion
	}

#pragma region BoxSetup
	setlinestyle(1, 2, 4);
	switch (x) {
	case 1: setcolor(player1Color); break;
	case 2: setcolor(player2Color); break;
	case 3: setcolor(player3Color); break;
	case 4: setcolor(player4Color); break;
	case 5: setcolor(enemyColor); break;
	}
	rectangle(0, MaxY3, maxX, MaxY4); // Main Rectangle
	rectangle((0 + (maxX / 100)), (MaxY3 + (maxX / 100)), (MaxX8 - (maxX / 100)), (MaxY4 - (maxX / 100))); // Far Box to the Left(inside the main one)
	rectangle(MaxX8, MaxY3, maxX, MaxY4); // The Dividing box
	rectangle((MaxX8 + (maxX / 100)), (MaxY3 + (maxX / 100)), (maxX - (maxX / 100)), (MaxY4 - (maxX / 100))); // The Box farthest to the Right 
	system("pause");
#pragma endregion
}
void NameInput() {
	
	int CaptureKeyPress;
	do {
		CaptureKeyPress = getch();
		if (CaptureKeyPress == 49) { /// PRESS 1
			GameType = 1;
		}
		else if (CaptureKeyPress == 50) { /// PRESS 2
			GameType = 2;
		}
	} while (49 != CaptureKeyPress && 50 != CaptureKeyPress); /// UNCOOPERATIVE

	int FreeVar = GameType;
	TalkingOnThreeLines("Pick a Game Type (Number):", " 1.) Single Player Match"," 2.) 4 Player Dragon Boss", 15);
	cout << "Pick a Game Type (Number):\n 1.) Single Player Match\n 2.) 4 Player Dragon Boss" << endl; //\n 3.) 4 Player Lich Boss\n 4.) Gladiator Pit" Later to add
	//cin >> FreeVar;
	
	cleardevice();
	if (FreeVar == 1) {
		GameType = FreeVar;
		cout << "Name And Then Class Name:" << endl;
		cin >> Player1.Name;
		if (Player1.Name == "Odax") { player1Color = 10; }
		cin >> FreeClass; PlayerAndClassSetUp(1);
		Player2.Alive = false;
		Player3.Alive = false;
		Player4.Alive = false;
	}
	if (FreeVar == 2 || FreeVar == 3 || FreeVar == 4) {
		GameType = FreeVar;
		cout << "Name And Then Class Name:" << endl;
		cin >> Player1.Name;
		if (Player1.Name == "Odax") { player1Color = 10; }
		cin >> FreeClass; PlayerAndClassSetUp(1);
		cin >> Player2.Name;
		if (Player2.Name == "Issej") { player2Color = 6; }
		cin >> FreeClass; PlayerAndClassSetUp(2);
		cin >> Player3.Name;
		if (Player3.Name == "Raxxis") { player3Color = 3; }
		cin >> FreeClass; PlayerAndClassSetUp(3);
		cin >> Player4.Name;
		if (Player4.Name == "Ankilles") { player4Color = 8; }
		cin >> FreeClass; PlayerAndClassSetUp(4);
		if (Player1.Name == "Odax", Player2.Name == "Issej", Player3.Name == "Raxxis", Player4.Name == "Ankilles") {
			cout << " THE DEFENDERS ARE HERE" << endl;
		}
		if (Player1.Name == "Erik" && Player1.Class == "Crusader") { cout << " A CRUSADER WALKS AMONG YOU, TO HIM GOES THE HONOR" << endl; }
	}
}
void EndTurnAffects() {
	// End turn stuff: In Order: Power, Endturn Damage
	if (Player1.Alive == true) {
		Player1.PowerInt++;
		Player1.Power = Player1.PowerInt;
		if (Player1.PowerInt >= 4) {
			Player1.PowerInt = 4;
			Player1.Power = to_string(Player1.PowerInt);
		}
		if (Player1.HealthInt > Player1.SetHealth) {
			Player1.HealthInt = (Player1.SetHealth);
			Player1.Health = to_string(Player1.HealthInt);
		}
		if (Player1.HealthInt < 0) {
			Player1.HealthInt = 0;
			theConversionFromIntToString(Player1.HealthInt, Player1.Health);
		}
	}
	if (Player2.Alive == true) {
		Player2.PowerInt++;
		Player2.Power = Player2.PowerInt;
		if (Player2.PowerInt >= 4) {
			Player2.PowerInt = 4;
			Player2.Power = to_string(Player2.PowerInt);
		}
		if (Player2.HealthInt > Player2.SetHealth) {
			Player2.HealthInt = (Player2.SetHealth);
			Player2.Health = to_string(Player2.HealthInt);
		}
		if (Player2.HealthInt < 0) {
			Player2.HealthInt = 0;
			Player2.Health = to_string(Player2.HealthInt);
		}
	}
	if (Player3.Alive == true) {
		Player3.PowerInt++;
		Player3.Power = Player3.PowerInt;
		if (Player3.PowerInt >= 4) {
			Player3.PowerInt = 4;
			Player3.Power = to_string(Player3.PowerInt);
		}
		if (Player3.HealthInt > Player3.SetHealth) {
			Player3.HealthInt = (Player3.SetHealth);
			Player3.Health = to_string(Player3.HealthInt);
		}
		if (Player3.HealthInt < 0) {
			Player3.HealthInt = 0;
			Player3.Health = to_string(Player3.HealthInt);
		}
	}
	if (Player4.Alive == true) {
		Player4.PowerInt++;
		Player4.Power = Player1.PowerInt;
		if (Player4.PowerInt >= 4) {
			Player4.PowerInt = 4;
			Player4.Power = to_string(Player4.PowerInt);
		}
		if (Player4.HealthInt > Player4.SetHealth) {
			Player4.HealthInt = (Player4.SetHealth);
			Player4.Health = to_string(Player4.HealthInt);
		}
		if (Player4.HealthInt < 0) {
			Player4.HealthInt = 0;
			Player4.Health = to_string(Player4.HealthInt);
		}
	}
	if (Enemy.Alive == true) {
		if (Enemy.Alive == true) {
			Enemy.PowerInt = Enemy.PowerInt + 2;
			Enemy.Power = Enemy.PowerInt;
			if (Enemy.PowerInt > 7) {
				Enemy.PowerInt = 7;
				Enemy.Power = to_string(Enemy.PowerInt);
			}
			if (Enemy.HealthInt > Enemy.SetHealth) {
				Enemy.HealthInt = (Enemy.SetHealth);
				theConversionFromIntToString(Enemy.HealthInt, Enemy.Health);
				Enemy.Health = to_string(Enemy.HealthInt);
			}
			if (Enemy.HealthInt < 0) {
				Enemy.HealthInt = 0;
				Enemy.Health = to_string(Enemy.HealthInt);
			}
		}
	}
}
void DeadAliveLossWin(string Player1Health, string Player2Health, string Player3Health, string Player4Health, int GameType, bool Endturn) {
	// handles the death and makes the game end

	if (Player1.ThornInTheSide == true) { Player1.HealthInt--; theConversionFromIntToString(Player1.HealthInt, Player1.Health); }
	if (Player2.ThornInTheSide == true) { Player2.HealthInt--; theConversionFromIntToString(Player2.HealthInt, Player2.Health); }
	if (Player3.ThornInTheSide == true) { Player3.HealthInt--; theConversionFromIntToString(Player3.HealthInt, Player3.Health); }
	if (Player4.ThornInTheSide == true) { Player4.HealthInt--; theConversionFromIntToString(Player4.HealthInt, Player4.Health); }
	if (Enemy.ThornInTheSide == true) { Enemy.HealthInt--; theConversionFromIntToString(Enemy.HealthInt, Enemy.Health); }


	if (Player1.Health == "0") { Player1.Alive = false; }
	else { Player1.Alive = true; }
	if (Player2.Health == "0") { Player2.Alive = false; }
	else { Player1.Alive = true; }
	if (Player3.Health == "0") { Player3.Alive = false; }
	else { Player3.Alive = true; }
	if (Player4.Health == "0") { Player4.Alive = false; }
	else { Player4.Alive = true; }
	if (Enemy.Health == "0") { Enemy.Alive = false; }
	else { Enemy.Alive = true; }

	if (Endturn == true) { EndTurnAffects(); }

	switch (GameType) {
	case 1:
		if (Player1.Alive == false && Enemy.Alive == true) { GameStillGoing = false; moveto(0, 0); outtext(GAMEOVER.c_str()); }
		if (Player1.Alive == true && Enemy.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(YOUWIN.c_str()); }
	case 2:
		if ((Player1.Alive == true || Player2.Alive == true || Player3.Alive == true || Player4.Alive == true) && Enemy.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(YOUWIN.c_str()); }
		if (Player1.Alive == false && Player2.Alive == false && Player3.Alive == false && Player4.Alive == false && Enemy.Alive == true) { GameStillGoing = false; moveto(0, 0); outtext(GAMEOVER.c_str()); }
		break; // Dragon
	case 3:
		if ((Player1.Alive == true || Player2.Alive == true || Player3.Alive == true || Player4.Alive == true) && Enemy.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(YOUWIN.c_str()); }
		if (Player1.Alive == false && Player2.Alive == false && Player3.Alive == false && Player4.Alive == false && Enemy.Alive == true) { GameStillGoing = false; moveto(0, 0); outtext(GAMEOVER.c_str()); }
		break; // Lich
	case 4:
		if (Player1.Alive == true && Player2.Alive == false && Player3.Alive == false && Player4.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(THEWINNERIS.c_str()); moverel(15, 0); outtext(Player1.Name.c_str()); }
		if (Player2.Alive == true && Player3.Alive == false && Player4.Alive == false && Player1.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(THEWINNERIS.c_str()); moverel(15, 0); outtext(Player2.Name.c_str()); }
		if (Player3.Alive == true && Player4.Alive == false && Player1.Alive == false && Player2.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(THEWINNERIS.c_str()); moverel(15, 0); outtext(Player3.Name.c_str()); }
		if (Player4.Alive == true && Player1.Alive == false && Player1.Alive == false && Player3.Alive == false) { GameStillGoing = false; moveto(0, 0); outtext(THEWINNERIS.c_str()); moverel(15, 0); outtext(Player4.Name.c_str()); }
		break; // Gladiator Pit
	}
}

int ClearStats() {
	//Clears all stats for the characters
	Player1.Alive = false; Player2.Alive = false; Player3.Alive = false; Player4.Alive = false; Enemy.Alive = false;
	Player1.AttackInt, Player2.AttackInt, Player3.AttackInt, Player4.AttackInt, Enemy.AttackInt = 0;
	Player1.Class, Player2.Class, Player3.Class, Player4.Class, Enemy.Class = " ";
	GameStillGoing = true;
	return 0;
}

int main() {
#pragma region SetUp
	srand((unsigned int)time(NULL));
	gr_Start(GrDriver, GrMode, ErrorCode);
	/* USEFUL
	int CATCH = getch();
	cout << CATCH;
	*/
	maxY = getmaxy();
	maxX = getmaxx();
	bool BoolForGame = true;
#pragma endregion
	getch();
	//int Attack;
	TextToScreen(OPENING);
	TextToScreen(TITLE);
	// Show the 2 Options
	while (BoolForGame == true) {
		NameInput();

		if (GameType == 1) {
			Enemy.init(GOBLINKING);
			TextToScreen(GOBLINK);
			cleardevice();
			while (GameStillGoing) {
				DividingUpTheScreenBoss(1); // Screen Check
				AttackTargetAndAttack(1);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(5);
				AttackTargetAndAttack(5);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, true);
			}
		}

		if (GameType == 2 || GameType == 3) {
			switch (GameType)
			{
			case 2: Enemy.init(DRAGON);
				break;
			case 3: Enemy.init(LICH);
				break;
			}
			while (GameStillGoing) {
				DividingUpTheScreenBoss(1); // Screen Check
				AttackTargetAndAttack(1);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(2);
				AttackTargetAndAttack(2);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(3);
				AttackTargetAndAttack(3);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(4);
				AttackTargetAndAttack(4);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(5);
				AttackTargetAndAttack(5);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, true);
			}
		}

		if (GameType == 4) {
			while (GameStillGoing) {

				DividingUpTheScreenBoss(1); // Screen Check
				AttackTargetAndAttack(1);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(2);
				AttackTargetAndAttack(2);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(3);
				AttackTargetAndAttack(3);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, false);
				DividingUpTheScreenBoss(4);
				AttackTargetAndAttack(4);
				DeadAliveLossWin(Player1.Health, Player2.Health, Player3.Health, Player4.Health, GameType, true);
			}
		}

		if (GameType == 9) { BoolForGame = false; }

		cout << maxY << " : Max Y" << endl << maxX << " : Max X" << endl;
		system("pause");
		ClearStats();
	}
	system("pause");
	return 0;
}
