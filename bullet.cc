#include "bullet.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

Bullet::Bullet(){
	this->position=make_pair(-1000,-1000);
	velocity=25;
	hit=0;
}

void Bullet::set_position(pair<int,int> position){
	this->position=position;
}

void Bullet::set_hit(int hit){
	this->hit=hit;
}

int Bullet::get_hit(){
	return hit;
}

pair<int,int> Bullet::move_1_position(){
	position.first+=velocity;
	return position;
}

pair<int,int> Bullet::move_2_position(){
	position.first-=velocity;
	return position;
}


