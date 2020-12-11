#include <SFML/Graphics.hpp>
#include "user.h"
#include "bullet.h"
using namespace sf;

User::User(int ID, RenderWindow *app)
{
	id = ID;
	position = ID ? make_pair(800, 600) : make_pair(100, 600);
	dy = 0;
	life = 3;
	last_attack = time(NULL)-100;
	this->app = app;
}

User::~User() {}

pair<int,int> User::get_position()
{
	return position;
}

void User::MovePlayer(int type)
{
	if(id == 0)	//player 1
	{
		if(type == 1)
		{
			if(position.first < 380)
				position.first+=3;
		}
		else if(type == 2)
		{
			if(position.first > -70)
				position.first-=3;
		}
		else if(type == 3)
			Jump();
	}
	else		//player 2
	{
		if(type == 1)
		{
			if(position.first < 990)
				position.first+=3;
		}
		else if(type == 2)
		{
			if(position.first > 540)
				position.first-=3;
		}
		else if(type == 3)
			Jump();
	}
}

void User::Jump()
{
	dy = -12;	
}

void User::Damage()
{
	life--;
}

int User::get_life()
{
	return life;
}

float User::get_dy()
{
	return dy;
}

void User::plus_y()
{
	if(dy != 0)
		dy += 0.2;
	if(id == 0)
	{
		if(position.first < 200 && position.first > -30 && position.second <= 200 && position.second > 185 && dy > 0)
		{
			dy = 0;
			position.second = 200;
		}
		else if(position.first < 350 && position.first > 120 && position.second <= 400 && position.second > 385 && dy > 0)
		{
			dy = 0;
			position.second = 400;
		}
		else
			dy += 0.1;
	}
	else
	{
		if(position.first < 950 && position.first > 720 && position.second <= 200 && position.second > 185 && dy > 0)
		{
			dy = 0;
			position.second = 200;
		}
		else if(position.first < 800 && position.first > 570 && position.second <= 400 && position.second > 385 && dy > 0)
		{
			dy = 0;
			position.second = 400;
		}
		else
			dy += 0.1;
	}
	if(position.second > 600)
	{
		dy = 0;
		position.second = 600;
	}
	position.second += dy;
}


