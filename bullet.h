#include <utility>
using namespace std;
class Bullet{
	private:
		pair<int,int> position;
		int velocity;
	public:
		Bullet(pair<int,int> position);
		~Bullet(){};
		pair<int,int> Get_Position();
		void Move(int dir);
};
