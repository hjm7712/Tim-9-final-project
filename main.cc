#include<SFML/Graphics.hpp>
#include<time.h>
using namespace sf;

void main(){
	srand(time(0));

	RenderWindow app(VideoMode(1000, 750), "Among Us!");
	app.setFramerateLimit(60);

	Texture t1, t2, t3;
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/player1.png");
	t4.loadFromFile("images/player2.png");
	t5.loadFromFile("images/knife.png");

	Sprite sBackground(t1), sPlate(t2), sPlayer1(t3), sPlayer2(t4), sKnf(t5);

	std::pair<int, int> plat[5];
	plat[0].x = 200;
	plat[0].y = 250;
	plat[1].x = 100;
	plat[1],y = 500;
	plat[2].x = 300;
	plat[2].y = 500;

	plat[3].x = 600;
	plat[3].y = 500;
	plat[4].x = 700;
	plat[4].y = 250;
	plat[5].x = 800;
	plat[5].y = 500;

	while(app.isOpen()){
		Event event;

		while(app.pollEvent(event)){
			switch(event.type){
				
				case Event::Closed:
					app.close();
					break;

				case Event::KeyPressed:
					//game start!
					break;

				default : break;

			}
		}



