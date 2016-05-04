#include <iostream>
#include <cstdlib>
#include "Players.h"
using namespace std;

Players::Players()
{
int puntajePlayer=0;
int puntajePC=0;
}
	//Player
	void Players::setPlayername(string Playername)
	{
		this->Playername=Playername;
	}
	string Players::getPlayername()
	{
		return Playername;
	}
	void Players::setPlayerbalance(int balancePlayer)
	{
		this->balancePlayer=balancePlayer;
	}
	int Players::getPlayerbalance()
	{
		return balancePlayer;
	}
	void Players::setpuntajePlayer(int puntajePlayer)
	{
		this->puntajePlayer=puntajePlayer;
	}
	int Players::getpuntajePlayer()
	{
		return puntajePlayer;
	}

	//PC
	void Players::setPCname(string PCname)
	{
		this->PCname=PCname;
	}
	string Players::getPCname()
	{
		return PCname;
	}
	void Players::setPCbalance(int balancePC)
	{
		this->balancePC=balancePC;
	}
	int Players::getPCbalance()
	{
		return balancePC;
	}
	void Players::setpuntajePC(int puntajePC)
	{
		this->puntajePC=puntajePC;
	}
	int Players::getpuntajePC()
	{
		return puntajePC;
	}

