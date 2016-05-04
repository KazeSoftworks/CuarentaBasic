#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
using namespace std;

class Juego
{
	public:
		Juego();
		void asignarmanoPlayer(string);
		string vermanoPlayer(int);
		int sizemanoPlayer();
		void caermanoPlayer(int i);

	private:
		vector < string > manoPlayer;

};
#endif 
