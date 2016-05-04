#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DeckOfCards.h"
#include "Card.h"
using namespace std;

Mazo::Mazo()
{
int actualCarta=0;
srand (time(NULL)); // crea seed
	// crea vector mazo
	vector <Carta> nuevoMazo;

	// llena el mazo
    for (int i = 0; i < Carta::totalNumero; i++)
    {
        for (int j = 0; j < Carta::totalPalo; j++)
        {
            nuevoMazo.push_back(Carta(i,j));
            actualCarta++;
        }
    } 

	// nuevo mazo del mazo original
	mazo = nuevoMazo;
}

void Mazo::shuffle() // baraja
{
	for (int i = 0; i < 40; i++)
	{
		int randCarta = rand() % 40;

		Carta swap = mazo[i];
		mazo[i] = mazo[randCarta];
		mazo[randCarta] = swap;
	}
}

Carta Mazo::darCarta() 
{
	return mazo[actualCarta++];

} 

bool Mazo::masCartas() const 
{
	if(actualCarta<40)
		return true;
	else
		return false;
}
void Mazo::nuevoMazo()
{
int actualCarta=0;
srand (time(NULL)); // crea seed
	// crea vector mazo
	vector <Carta> nuevoMazo;

	// llena el mazo
    for (int i = 0; i < Carta::totalNumero; i++)
    {
        for (int j = 0; j < Carta::totalPalo; j++)
        {
            nuevoMazo.push_back(Carta(i,j));
            actualCarta++;
        }
    } 
}

void Mazo::resetCarta()
{
	actualCarta=0;
}

