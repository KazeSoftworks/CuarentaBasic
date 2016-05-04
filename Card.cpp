#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

const string Carta::numeroNombre[ totalNumero ] = {"As", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "J ", "Q ", "K "};
const string Carta::paloNombre[ totalPalo ] = {"Corazones", "Diamantes", "Picas", "Trebol"};

Carta::Carta( int cartaNumero, int cartaPalo )
{
	numero = cartaNumero;
	palo = cartaPalo;
}

string Carta::toString() const
{
	return numeroNombre[ numero ] + " de " + paloNombre[ palo ];
}
