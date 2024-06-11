#ifndef CHARACTER_H 
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class> T;
class Character
{
private:
    string _name;
	string _description;
	vector<T> *InitRunMods;
	//Add map/room details 
	//Movement *movement;
	int _balance;
	int _posx;
	int _posy;
	//more

public:
    Character(string name,int posx,int posy) {};
    ~Character(){};
    virtual string GetName() {return _name;}
    virtual int GetXpos() {return _posx;}
    virtual int GetYpos() {return _posy;}
};

class Player : public Character
{
public:
    Player(string name, int posx, int posy) : Character(name, posx, posy) {}
    ~Player() {}
};

class AI : public Character
{
public:
    AI(string name, int posx, int posy) : Character(name, posx, posy) {}
    ~AI() {}
};

#endif