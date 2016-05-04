#ifndef JUEGOMESA_H
#define JUEGOMESA_H
#include <vector>
using namespace std;

class JuegoMesa
{
	public:
		JuegoMesa();
		void asignarMesa(string);
		string verMesa(int);
		int sizeMesa();
		void quitardeMesa(int);
	private:
		vector < string > Mesa;

};
#endif 
