#include "GameScreen.h"

#include <iostream>

GameScreen::GameScreen(int windowx,int windowy,) : _windowx(windowx),_windowy(windowy)
{
	InitWindow();
}

void GameScreen::InitWindow()
{
    std::string spaceRow(GetMaxCols(), ' '); // Create a string filled with spaces, size of GetMaxCols()

    for(int i=0; i<GetMaxRows(); i++){
        rows.push_back(spaceRow); // Push the spaceRow string into rows
    }
	while(true)
	{
		char ch=_getch();
		Setlastkeypressed(ch);
		
	}
}

void GameScreen::display()
{
	for(auto i : rows)
	{
		std::cout<<i<<std::endl;
	}
}

void GameScreen::SetPlayer(Player *_player)
{
	player=_player;
	rows[player->GetYpos()][player->GetXpos()]='+';
}