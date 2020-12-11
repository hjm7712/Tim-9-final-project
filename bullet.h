#include <SFML/Graphics.hpp>
#include <utility>
using namespace std;
using namespace sf;
class Bullet{
	private:
		pair<int,int> position;
		int velocity;
		int hit;
		RenderWindow *app;
	public:
		Bullet();
		~Bullet(){};
		void set_position(pair<int,int> position);
		void set_hit(int hit);
		int get_hit();
		pair<int,int> MoveBullet1();
		pair<int,int> MoveBullet2();
};
