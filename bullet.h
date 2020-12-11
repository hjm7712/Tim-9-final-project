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
		Bullet(pair<int,int> position, RenderWindow *app);
		~Bullet(){};
		pair<int,int> Get_Position();
		void Move(int dir);
};
