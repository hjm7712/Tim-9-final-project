class Bullet{
	private:
		pair<int,int> position;
		int velocity;
	public:
		Bullet(pair<int,int> position);
		~Bullet(){};
		pair<int,int> get_position();
		void Move(int dir);
}
