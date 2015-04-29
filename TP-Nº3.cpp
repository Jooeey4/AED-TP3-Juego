/*
 *	Autor: Mato, Joan Uriel
 *	Curso: K1091
 *	Descripción: Programa TP Nº 3 "Juego de Preguntas y Respuestas"
 */
 
#include <cctype> 
#include <iostream>
#include<stdlib.h>
#include <conio.h>

using namespace std;

//Declaracion de variables globales
bool seguir;
string respuesta, nombre, reiniciar;
int tema, pregunta, puntos, aux, vidas;
string preguntas[4][6], respuestas[4][6];	

void incorrecto();
void correcto();
void cargarPreguntas();
void cargarRespuestas();
void parpadear();
void preguntar();
void gameOver();

int main() {
	
	cargarPreguntas ();
	cargarRespuestas ();
	
	
	
	do
	{
		system("cls");
		cout << "Ingrese su nombre: ";
		cin >> nombre;
		system("cls");
		vidas = 3;
		puntos = 0;
		do
		{
			
			cout << "Jugador: " << nombre << "\tVidas ";
			for (int i=0; i<vidas; i++)
			{
				cout << "*";
			}
			cout << "\tPuntos: " << puntos << "\n";
			
			
			cout << "Menu: \n";
			cout << "\t1- Deporte";
			cout << "\n\t2- Ciencia";
			cout << "\n\t3- Geografia";
			cout << "\n\t4- Salir\n";
			cout << "Ingrese el tema de las preguntas: ";
			cin >> tema;
			pregunta = 1;
			switch(tema)
			{
				case 1:
					preguntar();
					break;
				case 2:
					preguntar();
					break;
				case 3:
					preguntar();
					break;
				case 4:
					
					break;	
				default:
					
					break;
			}
			
			system("cls");
		}
		while ((tema != 4) and (vidas>0));
		gameOver();
		cout << "Jugador --> " << nombre << "\nPuntaje final --> " << puntos;
		cout << "\n\nSi desea volver a jugar ingrese la letra R";
		cin >> reiniciar;
	}
	while (reiniciar.compare("R")==0);

} 
 
void preguntar() {
	do 
	{
		system("cls");
		cout << preguntas[tema][pregunta];//muestra pregunta
		cout << "\nRespuesta: ";
		cin >> respuesta;//ingresa respuesta
		if (respuesta.compare(respuestas[tema][pregunta])==0)//verifica respuesta
		{
			correcto();
			puntos += 10; //suma puntaje
		}
			
		else
		{
			incorrecto();
			vidas--;//resta vida
		}
			
		
		pregunta++;//siguiente pregunta
		if (pregunta==6)//bonus
		{
			puntos += 50*vidas;
			vidas++;
		}
		
		if (vidas>0)
		{
			cout << "¿Desea salir? Si=1/No=2";//pregunta si desea continuar
			cin >> aux;
			if (aux == 1)
				seguir = false;
			else
				seguir = true;
		}
		system("cls");	
	}
	while ( (pregunta<=5) and (seguir) and (vidas>0));
} 
 
void cargarPreguntas() {
	//Deporte
	preguntas[1][1] = "¿Cual es el equipo mas campeon del torneo argentino?"; 
	preguntas[1][2] = "¿En que equipo juega Higuain?";
	preguntas[1][3] = "¿Cual es el corredor de F1 mas ganador?";
	preguntas[1][4] = "¿En que equipo juega Ginobili?";
	preguntas[1][5] = "¿cuantos Grand Slam tiene Nadal?";
	//Ciencia
	preguntas[2][1] = "¿Cual es la temperatura de ebullicion del agua en condiciones normales?"; 
	preguntas[2][2] = "¿A que clase de triangulos se le puede aplicar Pitagoras?";
	preguntas[2][3] = "¿Todas las serpientes son venenosas?";
	preguntas[2][4] = "¿Las ranas son anfibios?";
	preguntas[2][5] = "¿Que es el modulo de una fuerza en fisica?";
	//Geografia
	preguntas[3][1] = "¿En que continente esta India?"; 
	preguntas[3][2] = "¿Argentina limita con Uruguay?";
	preguntas[3][3] = "¿Chile limita con Paraguay?";
	preguntas[3][4] = "¿En que continente esta el desierto de Sahara?";
	preguntas[3][5] = "¿como se llama la unica estrella del Sistema Solar?";
} 

void cargarRespuestas() {
	respuestas[1][1] = "RIVER";
	respuestas[1][2] = "NAPOLI";
	respuestas[1][3] = "SCHUMACHER";
	respuestas[1][4] = "SPURS";
	respuestas[1][5] = "14";
	respuestas[2][1] = "100";
	respuestas[2][2] = "RECTANGULOS";
	respuestas[2][3] = "NO";
	respuestas[2][4] = "SI";
	respuestas[2][5] = "INTENSIDAD";
	respuestas[3][1] = "ASIA";
	respuestas[3][2] = "SI";
	respuestas[3][3] = "NO";
	respuestas[3][4] = "AFRICA";
	respuestas[3][5] = "SOL";
} 
 
void correcto() {
	system("cls");
	
	cout << "\n\n ###   ###   ####   ####   #####   ###  #####   ###  \n";
	cout << "#     #   #  #   #  #   #  #      #       #    #   # \n";
	cout << "#     #   #  ####   ####   ###    #       #    #   # \n";
	cout << "#     #   #  #  #   #  #   #      #       #    #   # \n";
	cout << " ###   ###   #   #  #   #  #####   ###    #     ###  \n";
	parpadear(); 
	
}

void incorrecto() {
	system("cls");
	
	cout << "\n\n#####  #   #   ###   ###   ####   ####   #####   ###  #####   ###  \n";
	cout << "  #    ##  #  #     #   #  #   #  #   #  #      #       #    #   # \n";
	cout << "  #    # # #  #     #   #  ####   ####   ###    #       #    #   # \n";
	cout << "  #    #  ##  #     #   #  #  #   #  #   #      #       #    #   # \n";
	cout << "#####  #   #   ###   ###   #   #  #   #  #####   ###    #     ###  \n";
	parpadear();
} 

void gameOver()
{
	system("cls");
	cout << "\n\n ####   ###   #   #  #####     ###   #   #  #####  ####   \n";
	cout << "#      #   #  ## ##  #        #   #  #   #  #      #   #  \n";
	cout << "#  ##  #   #  # # #  ###      #   #  #   #  ###    ####   \n";
	cout << "#   #  #####  #   #  #        #   #   # #   #      #  #   \n";
	cout << " ####  #   #  #   #  #####     ###     #    #####  #   #  \n\n\n";
	parpadear();
}
 
void parpadear() {
	cout << "\a";
	for (int j=0; j<5; j++)
	{
		system ("color A");
		system ("color B");
		system ("color C");
		system ("color D");
		system ("color E");
		system ("color F");		
	}
	
}
