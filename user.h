#include <SFML/Graphics.hpp>
#include <utility>
#include <ctime>

using namespace std;
using namespace sf;

class User
{
private:
	int id;
	int score;
	pair<int,int> position;
	float dy;
	int life;
	time_t last_attack;
	RenderWindow *app;
public:
	User(int ID, RenderWindow *app);
	~User();
	pair<int,int> get_position();
	void MovePlayer();
	void Jump();
	void Attack(User *u);
};


