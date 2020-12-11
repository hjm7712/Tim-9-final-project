#include<SFML/Graphics.hpp>
#include<ctime>
#include<utility>
#include"user.h"
#include"bullet.h"
#include <iostream>
using namespace std;
using namespace sf;

int main(){
	srand(time(0));

	RenderWindow app(VideoMode(1000, 750), "Among Us!");
	app.setFramerateLimit(60);

	Texture t0, t1, t2, t3, t4, t5, t6, t10, t11, t12, t13, t20, t21, t22, t23;
	t0.loadFromFile("images/gamestart_2.png");
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/player1.png");
	t4.loadFromFile("images/player2.png");
	t5.loadFromFile("images/knife_1.png");
	t6.loadFromFile("images/knife_2.png");
	t10.loadFromFile("images/player1_life0.png");
	t11.loadFromFile("images/player1_life1.png");
	t12.loadFromFile("images/player1_life2.png");
	t13.loadFromFile("images/player1_life3.png");
	t20.loadFromFile("images/player2_life0.png");
	t21.loadFromFile("images/player2_life1.png");
	t22.loadFromFile("images/player2_life2.png");
	t23.loadFromFile("images/player2_life3.png");

	int p1x, p1y, p2x, p2y;
	p1x = 100; p1y = 550; p2x = 800; p2y = 550;
	int dy1, dy2, dx1, dx2;
	dy1 = 0; dy2 = 0; dx1 = 0; dx2 = 0;
	User U1(0, &app), U2(1, &app);
	Bullet bullet_1;
	Bullet bullet_2;
	time_t fire_1=time(NULL);
	time_t fire_2=time(NULL);
	
	while(app.isOpen()){
		Sprite sStart(t0);
		app.draw(sStart);
		app.display();
		Event event;


		while(app.pollEvent(event)){
			if(Keyboard::isKeyPressed(Keyboard::Q))
				app.close();


			switch(event.type){
				
				case Event::Closed:
					app.close();
					break;

				case Event::KeyPressed:
					while(1){
						//game start!
						Sprite sBackground(t1), sPlate(t2), sPlayer1(t3), sPlayer2(t4), sKnf_1(t5),sKnf_2(t6);
						Sprite sPlayer1_life0(t10), sPlayer1_life1(t11), sPlayer1_life2(t12), sPlayer1_life3(t13), sPlayer2_life0(t20), sPlayer2_life1(t21), sPlayer2_life2(t22), sPlayer2_life3(t23);
						std::pair<int, int> plat[4];
							
						plat[0].first = 50;
						plat[0].second = 300;
						plat[1].first = 200;
						plat[1].second = 500;
						
						plat[2].first = 650;
						plat[2].second = 500;
						plat[3].first = 800;
						plat[3].second = 300;
						
						app.draw(sBackground);

						for(int i=0;i<6;i++){
							sPlate.setPosition(plat[i].first, plat[i].second);
							app.draw(sPlate);
						}
	
						// player1 movement //
						p1x=U1.get_position().first;
						p1y=U1.get_position().second;
						
						//------------------//
						sPlayer1.setPosition(p1x,p1y);
						app.draw(sPlayer1);

						// player2 maovment //
						p2x=U2.get_position().first;
						p2y=U2.get_position().second;
						
						//------------------//
						sPlayer2.setPosition(p2x,p2y);
						app.draw(sPlayer2);

						//------------------//
						int mv1_x,mv1_y,mv2_x,mv2_y;
						mv1_x=bullet_1.move_1_position().first;
						mv1_y=bullet_1.move_1_position().second;
						mv2_x=bullet_2.move_2_position().first;
						mv2_y=bullet_2.move_2_position().second;
						sKnf_1.setPosition(mv1_x,mv1_y);
						app.draw(sKnf_1);
						sKnf_2.setPosition(mv2_x,mv2_y);
						app.draw(sKnf_2);

						int u1_x,u1_y,u2_x,u2_y;
						u1_x=U1.get_position().first;
						u1_y=U1.get_position().second;
						u2_x=U2.get_position().first;
						u2_y=U2.get_position().second;

						if(u1_x>mv2_x-80 && u1_x<mv2_x && u1_y>mv2_y-45 && u1_y<mv2_y+10){
							if(bullet_2.get_hit()==0){
								bullet_2.set_hit(1);
								U1.Damage();
								cout << "damage1" << endl;
							}
						}
						if(u2_x>mv1_x-80 && u2_x<mv1_x && u2_y>mv1_y-45 && u2_y<mv1_y+10){
							if(bullet_1.get_hit()==0){
								bullet_1.set_hit(1);
								U2.Damage();
								cout << "damage2" << endl;
							}
						}

						time_t now=time(NULL);

						if(Keyboard::isKeyPressed(Keyboard::A) && difftime(now,fire_1)>=1){
							int x,y;
							x=U1.get_position().first;
							y=U1.get_position().second;
							sKnf_1.setPosition(x,y);
							app.draw(sKnf_1);
							bullet_1.set_position(make_pair(x,y));
							bullet_1.set_hit(0);
							fire_1=time(NULL);
						}

						if(Keyboard::isKeyPressed(Keyboard::L) && difftime(now,fire_2)>=1){
							int x,y;
							x=U2.get_position().first;
							y=U2.get_position().second;
							sKnf_2.setPosition(x,y);
							app.draw(sKnf_2);
							bullet_2.set_position(make_pair(x,y));
							bullet_2.set_hit(0);
							fire_2=time(NULL);
						}


						switch(U1.get_life()){
							case 3:
								sPlayer1_life3.setPosition(p1x+20,p1y);
								app.draw(sPlayer1_life3);
								break;
							case 2:
								sPlayer1_life2.setPosition(p1x+20,p1y);
								app.draw(sPlayer1_life2);
								break;
							case 1:
								sPlayer1_life1.setPosition(p1x+20,p1y);
								app.draw(sPlayer1_life1);
								break;
							case 0:
								sPlayer1_life0.setPosition(p1x+20,p1y);
								app.draw(sPlayer1_life0);
								break;
						}
						
						switch(U2.get_life()){
							case 3:
								sPlayer2_life3.setPosition(p2x+20,p2y);
								app.draw(sPlayer2_life3);
								break;
							case 2:
								sPlayer2_life2.setPosition(p2x+20,p2y);
								app.draw(sPlayer2_life2);
								break;
							case 1:
								sPlayer2_life1.setPosition(p2x+20,p2y);
								app.draw(sPlayer2_life1);
								break;
							case 0:
								sPlayer2_life0.setPosition(p2x+20,p2y);
								app.draw(sPlayer2_life0);
								break;
						}
							

						if(Keyboard::isKeyPressed(Keyboard::V))
							U1.MovePlayer(1);
						if(Keyboard::isKeyPressed(Keyboard::X))
							U1.MovePlayer(2);
						if(Keyboard::isKeyPressed(Keyboard::D) && U1.get_dy() == 0)
							U1.MovePlayer(3);
						if(Keyboard::isKeyPressed(Keyboard::Right))
							U2.MovePlayer(1);
						if(Keyboard::isKeyPressed(Keyboard::Left))
							U2.MovePlayer(2);
						if(Keyboard::isKeyPressed(Keyboard::Up) && U2.get_dy() == 0)
							U2.MovePlayer(3);
						U1.plus_y();
						U2.plus_y();


						app.display();

						if(Keyboard::isKeyPressed(Keyboard::P))
							break;
					}
					break;
				}
			}
	}
	return 0;
}
