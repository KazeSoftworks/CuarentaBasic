#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include "DeckOfCards.h"
#include "Players.h"
#include "Card.h"
#include "Juego.h"
#include "JuegoPC.h"
#include "JuegoMesa.h"
using namespace std;

int main()
{
//Variables
	string player;
	int balance=0;
	string cartaSalida=" ";
	string cartaEntrante=" ";
	int ordenCarta=0;
	bool inteligenciaPC=false;
	bool jugadaPC=false;
	bool jugadaPlayer=false;
	//int cartonPC=0;
	//int cartonPlayer=0;

//Inicio de clases


	Carta carta;
	Mazo crearMazo;
	Players players;
	Juego juego;
	JuegoPC juegopc;
	JuegoMesa juegomesa;


//Ingreso de datos
	cout<<"Ingrese nombre del jugador: "<<endl; //Nombre jugador
	cin>>player;
	players.setPlayername(player);
	cout<<"Ingrese nombre del contrincante: "<<endl; //Nombre PC
	cin>>player;
	players.setPCname(player);
	cout<<"Cantidad a apostar: "<<endl; //Cantidad de Apuesta//
	cin>>balance;
	players.setPlayerbalance(balance);
	players.setPCbalance(balance);

	//cout<<players.getPlayername()<<endl;
	//cout<<players.getPCname()<<endl;
	//cout<<players.getPlayerbalance()<<endl;
	//cout<<players.getPCbalance()<<endl;

//Ingreso de datos automaticos
	//players.setPCname("PC");
	//players.setPlayerbalance(35);
	//players.setPCbalance(35);
	players.setpuntajePlayer(0);
	players.setpuntajePC(0);

while ((players.getpuntajePlayer()<40) || (players.getpuntajePC()<40))
{
	crearMazo.resetCarta();
	crearMazo.nuevoMazo();
	crearMazo.shuffle(); //Barajar mazo
	//cartonPC=0;
	//cartonPlayer=0;

//-------------------------------
while(crearMazo.masCartas()==true)
{
	
	for (int i=0 ; i<5 ; i++) //Asigna cartas a mano Player
	{	
		cartaSalida = crearMazo.darCarta().toString();
		juego.asignarmanoPlayer(cartaSalida);
		//cout<<cartaSalida<<endl;
	}

	for (int i=0 ; i<5 ; i++) //Asigna cartas a mano PC
	{	
		cartaSalida = crearMazo.darCarta().toString();
		juegopc.asignarmanoPC(cartaSalida);
		//cout<<cartaSalida<<endl;
	}
//-----------------------
while (juego.sizemanoPlayer()>0)
{
	cout<<"Mano de "<<players.getPlayername()<<": "<<endl;
	for (int i=0; i<juego.sizemanoPlayer(); i++)
	{
		cout<<i+1<<". "<<juego.vermanoPlayer(i)<<endl;
	}


	cout<<"Mano de "<<players.getPCname()<<": "<<endl;
	for (int i=0; i<juegopc.sizemanoPC(); i++)
	{
		cout<<i+1<<". "<<juegopc.vermanoPC(i)<<endl;
	}
//--------------------------
	cout<<"Que carta bota?"<<endl;
	cin>>ordenCarta;
	while((ordenCarta>juego.sizemanoPlayer()) && (ordenCarta<=0)){
	cout<<"Numero invalido, ingrese de nuevo:"<<endl;
	cin>>ordenCarta;
	}
	cartaSalida = juego.vermanoPlayer(ordenCarta-1);
	
	juegomesa.asignarMesa(cartaSalida);

	juego.caermanoPlayer(ordenCarta);

	//cout<<"Mano Jugador:"<<endl;
	//for (int i=0; i<juego.sizemanoPlayer(); i++)
	//{
	//	cout<<i+1<<". "<<juego.vermanoPlayer(i)<<endl;
	//}
	//cout<<"Mesa:"<<endl;
	//for (int i=0; i<juegomesa.sizeMesa(); ++i)
	//{
	//	cout<<i+1<<". "<<juegomesa.verMesa(i)<<endl;
	//}
//Analisis de juegada Player ---------------------------------------------------
	jugadaPlayer=false;
if (juegomesa.sizeMesa()>=2)
{
	for(int i=0; i<juegomesa.sizeMesa(); ++i)
	{
		for(int j=i+1; j<juegomesa.sizeMesa(); ++j)
			{
				cartaEntrante=juegomesa.verMesa(i);
				cartaSalida=juegomesa.verMesa(j);
					if (cartaEntrante.substr(0,1)==cartaSalida.substr(0,1))
						{
							juegomesa.quitardeMesa(i);
							juegomesa.quitardeMesa(j);
							//cartonPlayer=cartonPlayer+2;
							jugadaPlayer=true;
							if ((i==j-1) && (jugadaPC==false))
								{	
									cout<<"Caída!"<<endl;
									players.setpuntajePlayer(players.getpuntajePlayer()+2);
									break;
								}
							break;
						}
			}
	}
	if (juegomesa.sizeMesa()==0)
	{	
		cout<<"Limpia!"<<endl;
		players.setpuntajePlayer(players.getpuntajePlayer()+2);
	}
}
	if (players.getpuntajePlayer()>=40)
	{
	goto WinPlayer;
	}
	cout<<"Puntaje Player: "<<players.getpuntajePlayer()<<endl;
	cout<<"Puntaje PC: "<<players.getpuntajePC()<<endl;

//Inteligencia PC ---------------------------------------------------
	inteligenciaPC=false;	
	for(int i=juegomesa.sizeMesa()-1; i==0; --i)
	{
		if (inteligenciaPC==false)
		{
			for(int j=0; j<juegopc.sizemanoPC(); ++j)
			{
				cartaEntrante=juegomesa.verMesa(i);
				cartaSalida=juegopc.vermanoPC(j);
					if (cartaEntrante.substr(0,1)==cartaSalida.substr(0,1))
						{
							cartaSalida = juegopc.vermanoPC(j);
							cout<<"PC a botado a: "<<cartaSalida<<endl;
							juegomesa.asignarMesa(cartaSalida);
							juegopc.caermanoPC(j); 
							inteligenciaPC=true;
							break;
						}
	
			}
		}
	}

	if (inteligenciaPC==false)
	{
		srand (time(NULL));
		int random = rand() % juegopc.sizemanoPC();
		cartaSalida = juegopc.vermanoPC(random);
		cout<<players.getPCname()<<" a botado a: "<<cartaSalida<<endl;
		juegomesa.asignarMesa(cartaSalida);
		juegopc.caermanoPC(random);
		inteligenciaPC=true;
	}

//Analisis de juegada PC ------------------
jugadaPC=false;
if (juegomesa.sizeMesa()>=2)
{
	for(int i=0; i<juegomesa.sizeMesa(); ++i)
	{
		for(int j=i+1; j<juegomesa.sizeMesa(); ++j)
			{
				cartaEntrante=juegomesa.verMesa(i);
				cartaSalida=juegomesa.verMesa(j);
					if (cartaEntrante.substr(0,1)==cartaSalida.substr(0,1))
						{
							juegomesa.quitardeMesa(i);
							juegomesa.quitardeMesa(j);
							//cartonPC=cartonPC+2;
							jugadaPC=true;
							if ((j-1==i) && (jugadaPlayer==false))
								{	
									cout<<"Caída!"<<endl;
									players.setpuntajePC(players.getpuntajePC()+2);
									break;
								}
							break;
						}
			}
	}
	if (juegomesa.sizeMesa()==0)
	{	
		cout<<"Limpia!"<<endl;
		players.setpuntajePC(players.getpuntajePC()+2);
	}
	if (players.getpuntajePC()>=40)
	{
	goto WinPC;
	}
}
	cout<<"//--------------------------------------//"<<endl;
	cout<<"Puntaje Player: "<<players.getpuntajePlayer()<<endl;
	cout<<"Puntaje PC: "<<players.getpuntajePC()<<endl;
	cout<<"Mesa:"<<endl;
	for (int i=0; i<juegomesa.sizeMesa(); ++i)
	{
		cout<<i+1<<". "<<juegomesa.verMesa(i)<<endl;
	}
	
}//while mano player
}//while deck mayor a cero
//cout<<"Carton de PC: "<<cartonPC<<endl<<"Carton de "<<players.getPlayername()<<": "<<cartonPlayer<<endl;
}//while puntaje



WinPC:
	players.setPlayerbalance(players.getPlayerbalance()-players.getPCbalance());
	players.setPCbalance(players.getPCbalance()*2);
	cout<<players.getPCname()<<" ha ganado!"<<endl<<"Tu puntaje es: "<<players.getpuntajePlayer()<<", mientras que el de "<<players.getPCname()<<" es de: "<<players.getpuntajePC()<<endl<<"Has perdido por: "<<players.getpuntajePC()-players.getpuntajePlayer()<<" puntos"<<endl<<"Dinero que te queda: "<<players.getPlayerbalance()<<", dinero que le queda a tu adversario: "<<players.getPCbalance()<<endl;
	
	goto End;
WinPlayer:
	players.setPCbalance(players.getPCbalance()-players.getPlayerbalance());
	players.setPlayerbalance(players.getPlayerbalance()*2);
	cout<<players.getPlayername()<<" ha ganado!"<<endl;
	cout<<"¡Has ganado!"<<endl<<"Tu puntaje es: "<<players.getpuntajePlayer()<<", mientras que el de "<<players.getPCname()<<" es de: "<<players.getpuntajePC()<<endl<<"Has ganado por: "<<players.getpuntajePlayer()-players.getpuntajePC()<<" puntos"<<endl<<"Dinero que le queda a tu adversario: "<<players.getPCbalance()<<", dinero que te queda: "<<players.getPlayerbalance()<<endl;

End:
	cout<<"Presiona ENTER para salir del programa"<<endl;
	cin.ignore().get();

}
