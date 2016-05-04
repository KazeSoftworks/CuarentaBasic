#include <iostream>
#include <vector>
#include "Juego.h"
using namespace std;
Juego::Juego()
{

}

void Juego::asignarmanoPlayer(string cartaEntrante)
{
	manoPlayer.push_back(cartaEntrante);
}
string Juego::vermanoPlayer(int a)
{
	return manoPlayer[a];
}

int Juego::sizemanoPlayer()
{
	return manoPlayer.size();
}

void Juego::caermanoPlayer(int i)
{
	i=i-1;
	manoPlayer.erase(manoPlayer.begin()+i);

}

