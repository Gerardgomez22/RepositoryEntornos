#include <iostream>
#include "Game.h"

int main()
{
    // Establecer la codificación de consola a UTF-8 para caracteres especiales
    system("chcp 65001");

    // Crear y ejecutar el juego
    Game game;
    game.run();

    std::cout << "\nGracias por jugar. Presiona Enter para salir...";
    std::cin.get();

    return 0;
}