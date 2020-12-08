#include "user.h"

using namespace std;
using namespace sf;

User::User(int ID)
{
	id = ID;
	score = 0;
	position = 
	life = 5;
	last_attack = time(NULL)-100;
}

User::~User() {}

pair<int,int> User::get_position()
{
	return position;
}

void User::MovePlayer()
{
	if(id == 0)	//player 1
	{
		if(Keyboard::isKeyPressed(Keyboard::Right))
	}
	else		//player 2
	{
		
	}
}


