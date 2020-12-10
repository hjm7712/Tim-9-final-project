#include<SFML/Graphics.hpp>
#include<time.h>
#include<utility>
using namespace sf;

int main(){
	srand(time(0));

	RenderWindow app(VideoMode(1000, 750), "Among Us!");
	app.setFramerateLimit(60);

	Texture t0, t1, t2, t3, t4, t5;
	t0.loadFromFile("images/gamestart_2.png");
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/player1.png");
	t4.loadFromFile("images/player2.png");
	t5.loadFromFile("images/knife.png");

	while(app.isOpen()){
	Sprite sStart(t0);
	app.draw(sStart);
	app.display();
	Event event;


	while(app.pollEvent(event)){

		switch(event.type){
				
			case Event::Closed:
				app.close();
				break;

			case Event::KeyPressed:
				while(1){
					//game start!
					Sprite sBackground(t1), sPlate(t2), sPlayer1(t3), sPlayer2(t4), sKnf(t5);

					std::pair<int, int> plat[5];

					plat[0].first = 100;
					plat[0].second = 250;
					plat[1].first = 200;
					plat[1].second = 500;
					plat[2].first = 300;
					plat[2].second = 250;

					plat[3].first = 600;
					plat[3].second = 250;
					plat[4].first = 700;
					plat[4].second = 500;
					plat[5].first = 800;
					plat[5].second = 250;
					app.draw(sBackground);

					for(int i=0;i<6;i++){
						sPlate.setPosition(plat[i].first, plat[i].second);
						app.draw(sPlate);
					}

					sPlayer1.setPosition(100,600);
					app.draw(sPlayer1);

					sPlayer2.setPosition(800,600);
					app.draw(sPlayer2);

					app.display();

					if(Keyboard::isKeyPressed(Keyboard::Q))
						break;
				}
				break;
			}
		}
	}
	return 0;
}
