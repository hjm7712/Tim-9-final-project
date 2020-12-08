#include <utiliy>
#include <ctime>

using namespace std;

class User
{
private:
	int id;
	int score;
	pair<int,int> position;
	int life;
	time_t last_attack;
public:
	User(int ID);
	~User();
	pair<int,int> get_position();
	void MovePlayer();
}

