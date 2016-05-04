#ifndef JUEGOPC_H
#define JUEGOPC_H
#include <vector>
using namespace std;

class JuegoPC
{
	public:
		JuegoPC();
		void asignarmanoPC(string);
		string vermanoPC(int);
		int sizemanoPC();
		void caermanoPC(int);

	private:
		vector < string > manoPC;

};
#endif 
