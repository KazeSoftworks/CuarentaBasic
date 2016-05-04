#include <iostream>
#include "JuegoPC.h"
using namespace std;
JuegoPC::JuegoPC()
{

}

void JuegoPC::asignarmanoPC(string cartaEntrante)
{
	manoPC.push_back(cartaEntrante);
}
string JuegoPC::vermanoPC(int a)
{
	return manoPC[a];
}

int JuegoPC::sizemanoPC()
{
	return manoPC.size();
}

//bool JuegoPC::InteligenciaPC(string cartaMesa, string cartaMano)
//{
//	string subcartaMesa = cartaMesa.substr(0,1);
//	string subcartaMano = cartaMano.substr(0,1);
 //	if(subcartaMesa==subcartaMano)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

void JuegoPC::caermanoPC(int i)
{
	manoPC.erase(manoPC.begin()+i);

}
