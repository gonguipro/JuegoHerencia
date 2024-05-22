#include "mainCharacter.h"
#include "matriz.h"

int main() {
    RenderWindow window(VideoMode(1200, 800), "Juego Herencia");

    //instancia de la clase Matriz y Character
    Matriz matrizInstancia;
    Character personaje("imagenes/personaje.png", &matrizInstancia);
    personaje.setScale(3.0f, 3.0f);
    personaje.setPosition(550.0f, 350.0f);

    while (window.isOpen())
    {
        // Procesar eventos
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            personaje.moveCharacter(event, window);
        }
        window.clear(Color::White);
        personaje.drawCharacter(window);
        window.display();
    }

    return 0;
}
