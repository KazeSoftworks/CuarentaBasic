#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H
#include <vector>
#include "Card.h"
using namespace std;

class Mazo
{
	public:
		Mazo(); // constructor
		void shuffle(); // baraja
		Carta darCarta(); // da cartas del mazo
		bool masCartas() const; // quedan cartas?
		//Carta darmanoCarta();
		void nuevoMazo();
		void resetCarta();
	
	private:
		vector< Carta > mazo; // mazo de cartas
		unsigned actualCarta; // carta encima del mazo
};
#endif 
