#include "bullet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Bullet::Bullet(pair<int,int> position){
	this.position=position;
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
		if(Keyboard::isKeyPressed(Keyboard::Q)){
			while(1){
				for(int i=0; i<10; i++){
					sBullet.setPosition(x++,y);
					app.draw(sBullet);
				}
				app.display();
			}
		}
	}
	else if(dir==1){//user 2 right side
		if(Keyboard::isKeyPressed(Keyboard::P)){
			while(1){
				for(int i=0; i<10; i++){
					sBullet.setPosition(x--,y);
					app.draw(sBullet);
				}
				app.display();
			}
		}
	}
}

