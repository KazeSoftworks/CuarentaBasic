#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Carta
{
	public:
		static const int totalNumero = 10; 
		static const int totalPalo = 4; 
		Carta( int cartaNumero = 1, int cartaPalo = 1 ); 
		string toString() const; 

		int getNumero() const
		{
			return numero;
		} 
		
		int getPalo() const
		{
			return palo;
		}

	private:
		int numero;
		int palo;
		static const string numeroNombre[ totalNumero ];
		static const string paloNombre[ totalPalo ];
}; // end class Card
#endif 
