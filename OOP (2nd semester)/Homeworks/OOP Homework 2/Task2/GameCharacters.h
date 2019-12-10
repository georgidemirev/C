#pragma once
#include <iostream>
using namespace std;
class GameCharacter {
private:

	char* name;
	int HP;
	int MP;
	int AP;
	int DP;
public:

	void setName(char*);
	void setHP(int);
	void setMP(int);
	void setAP(int);
	void setDP(int);

	void getattacked(int);

	void print() {
		cout << name << endl << HP << endl<<MP<<endl<<AP<<endl<<DP<<endl;
	}
};

void GameCharacter::setName(char* p) {
	name = p;
}

 void GameCharacter::setHP(int a)
{
	HP = a;
}

 void GameCharacter::setMP(int a)
{
	MP = a;
}

 void GameCharacter::setAP(int a)
{
	AP = a;
}

 void GameCharacter::setDP(int a)
{
	DP = a;
}

void GameCharacter::getattacked(int p)
{
	if (p <= DP)return;
	HP = HP + DP - p;
}

class Warrior : public GameCharacter {
public:
	Warrior() {
		setName("Warrior");
		setHP(20);
		setMP(5);
		setAP(4);
		setDP(1);
	};
};

class Guardian : public GameCharacter {
public:
	Guardian() {
		setName("Guardian");
		setHP(40);
		setMP(25);
		setAP(1);
		setDP(3);
	};
};

class Wizzard : public GameCharacter {
public:
	Wizzard() {
		setName("Wizzard");
		setHP(30);
		setMP(30);
		setAP(2);
		setDP(2);
	};
};