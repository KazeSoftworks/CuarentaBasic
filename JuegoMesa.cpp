#include <iostream>
#include "JuegoMesa.h"
using namespace std;
JuegoMesa::JuegoMesa()
{

}

void JuegoMesa::asignarMesa(string cartaEntrante)
{
	Mesa.push_back(cartaEntrante);
}
string JuegoMesa::verMesa(int a)
{
	return Mesa[a];
}

int JuegoMesa::sizeMesa()
{
	return Mesa.size();
}
void JuegoMesa::quitardeMesa(int i)
{
	Mesa.erase(Mesa.begin()+i);

}
