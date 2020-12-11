#include "user.h"

using namespace std;
using namespace sf;

User::User(int ID)
{
	id = ID;
	score = 0;
	position = ID ? make_pair(800, 600) : make_pair(100, 600);
	dy = 0;
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
		if(Keyboard::isKeyPressed(Keyboard::V))
			position.first+=3;
		if(Keyboard::isKeyPressed(Keyboard::X))
			position.first-=3;
		if(Keyboard::isKeyPressed(Keyboard::D) && dy = 0)
			Jump();
	}
	else		//player 2
	{
		if(Keyboard::isKeyPressed(Keyboard::Right))
			position.first+=3;
		if(Keyboard::isKeyPressed(Keyboard::Left))
			position.first-=3;
		if(Keyboard::isKeyPressed(Keyboard::Up) && dy = 0)
			Jump();
	}
}

void User::Jump()
{
	
}

void User::Attack(User *u)
{
	
}


