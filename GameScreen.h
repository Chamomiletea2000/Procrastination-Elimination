#ifndef GameScreen_H
#define GameScreen_H

#include <conio.h>
#include <iostream>
#include "Character.h"
#include <vector>
#include <string>

class GameScreen
	{
	private:
	int _windowx;
	int _windowy;
	std::vector<std::string> rows;
	Player *player;
	char lastkeypressed='\0';
	
	public:
	GameScreen(int windowx,int windowy);
	~GameScreen() {};
	void InitWindow() {};
	void display() {};
	int GetMaxRows() {return _windowy;}
	int GetMaxCols() {return _windowx;}
	void SetPlayer(Player *player){};
	void Setlastkeypressed(char ch){keylastpressed=ch;}
	char Getlastkeypressed(){return keylastpressed;}
	
	
}
#endif