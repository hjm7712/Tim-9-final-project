#include "bullet.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

Bullet::Bullet(pair<int,int> position, RenderWindow *app){
	this->position=position;
	velocity=20;
	this->app = app;
}

pair<int,int> Bullet::Get_Position(){
	return position;
}


void Bullet::Move(int dir){
	pair<int,int> position;
	int x=position.first;
	int y=position.second;
	
	Texture bullet_img;
	bullet_img.loadFromFile("bullet.png");

	Sprite sBullet(bullet_img);

	if(dir==0){	//user 1 left side
		if(Keyboard::isKeyPressed(Keyboard::A)){
			while(1){
				for(int i=0; i<velocity; i++){
					sBullet.setPosition(x++,y);
					app->draw(sBullet);
				}
				app->display();
			}
		}
	}
	else if(dir==1){//user 2 right side
		if(Keyboard::isKeyPressed(Keyboard::L)){
			while(1){
				for(int i=0; i<velocity; i++){
					sBullet.setPosition(x--,y);
					app->draw(sBullet);
				}
				app->display();
			}
		}
	}
}

