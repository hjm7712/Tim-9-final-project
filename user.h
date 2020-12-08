#include <utiliy>

using namespace std;

class User
{
private:
	int id;
	int score;
	pair<int,int> position;
	int life;
public:
	User(int ID);
	~User();
}
