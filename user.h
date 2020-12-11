#include <SFML/Graphics.hpp>
#include <utility>
#include <ctime>

using namespace std;
using namespace sf;

class User
{
private:
	int id;
	pair<int,int> position;
	float dy;
	int life;
	time_t last_attack;
	RenderWindow *app;
public:
	User(int ID, RenderWindow *app);
	~User();
	pair<int,int> get_position();
	void MovePlayer(int type);
	void Jump();
	void Damage();
	int get_life();
	float get_dy();
	void plus_y();
};


