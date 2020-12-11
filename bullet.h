#include <SFML/Graphics.hpp>
#include <utility>
using namespace std;
using namespace sf;
class Bullet{
	private:
		pair<int,int> position;
		int velocity;
		RenderWindow *app;
	public:
		Bullet();
		~Bullet(){};
		void set_position(pair<int,int> position);
		pair<int,int> move_1_position();
		pair<int,int> move_2_position();
};
