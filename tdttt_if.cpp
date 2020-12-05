#include <iostream>
using namespace std;
#include "tdttt_if.h"
#include "tdttt.h"

//Inicializacion del juego y el menu
void tdttt_if_init(void)
{
    tdttt_init();
    print_if();

}

//printf_if imprime el menu de seleccion de dificultad
void print_if(void)
{
    cout << "Estos son los cuatro posibles niveles: "<< endl;
    cout << "1. Nivel basico" << endl;
    cout << "2. Nivel intermedio" << endl;
    cout << "3. Nivel avanzado" << endl;
    cout << "4. Nivel master" << endl;
}

//Se llama a esta funcion para que el jugador elija la dificultad a la que desea jugar
void tdttt_if_training(void)
{
    int level;
    do
    {
        cout << "Introduce el nivel con el que se quiere jugar: " << endl;
        cin >> level;
    }while ((level <= 0) || (level > 4)); //Comprobar si el numero introducido es un nivel de dificultad disponible
    check_strategy(level);
}

//A partir de la dificultad elegida, se entrena a la IA utilizando la estrategia correcta
void check_strategy(int level)
{
    //En caso de que el jugador seleccione dificultad 1 no se entrenara a la IA
    switch (level)
    {
        //estrategia de menor dificultad
        case 2:
            tdttt_train_agent(STRATEGY_3);
            break;
        //estrategia de dificultad intermedia
        case 3:
            tdttt_train_agent(STRATEGY_1);
            break;
        //estrategia de dificultad maxima
        case 4:
            tdttt_train_agent(STRATEGY_2);
            break;
    }
}

//tdttt_if_play_against_human permite al usuario establecer el numero de partidas que se van a jugar
void tdttt_if_play_against_human(void)
{
    int matches;
    do
    {
        cout << "Introduce el numero de partidas que quiere jugar: " << endl;
        cin >> matches;

    }while (matches <= 0); //El numero de partidas a jugar debe ser mayor a 0
    tdttt_play_against_human(matches);
}
