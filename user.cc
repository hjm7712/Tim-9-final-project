#include <SFML/Graphics.hpp>
#include "user.h"
#include "bullet.h"
using namespace sf;

User::User(int ID, RenderWindow *app)
{
	id = ID;
	score = 0;
	position = ID ? make_pair(800, 600) : make_pair(100, 600);
	dy = 0;
	life = 5;
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
			position.first+=3;
		else if(type == 2)
			position.first-=3;
		if(Keyboard::isKeyPressed(Keyboard::D) && dy == 0)
			Jump();
	}
	else		//player 2
	{
		if(type == 1)
			position.first+=3;
		else if(type == 2)
			position.first-=3;
		if(Keyboard::isKeyPressed(Keyboard::Up) && dy == 0)
			Jump();
	}
}

void User::Jump()
{
	
}

void User::Attack(User *u)
{
	Bullet bullet(position, app);
	if(id==0){
		bullet.Move(0);
	}
	else if(id==1){
		bullet.Move(1);
	}
}


