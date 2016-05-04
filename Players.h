#ifndef PLAYERS_H
#define PLAYERS_H
#include <string>
using namespace std;

class Players
{
	public:
		Players(); // constructor
		void setPlayername(string); // set nombre del jugador
		void setPCname(string); // set nombre del contrincante

		string getPlayername();
		string getPCname();

		void setPlayerbalance(int);
		void setPCbalance(int);

		int getPlayerbalance();
		int getPCbalance();

		void setpuntajePlayer(int);
		void setpuntajePC(int);

		int getpuntajePlayer();
		int getpuntajePC();

	
	private:
		string Playername; // nombre jugador
		string PCname; // nombre contrincante
		int puntajePlayer;
		int puntajePC;
		int balancePlayer;
		int balancePC;
};
#endif 
