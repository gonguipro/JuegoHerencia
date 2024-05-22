#include <iostream>
#include <SFML/Graphics.hpp>
#include "matriz.h"

using namespace std;
using namespace sf;

class Character
{
private:
    int modeloSeleccionado;
    int health;
    int attck;
    Texture texture;
    vector<Sprite> modelos;
    int currentSpriteIndex = 24; // Iniciar en el sprite 24
    float speedCharacter = 10.0f; 


    Matriz* matriz;

public:
    Character(const string&, Matriz*);

    // setScale
    void setScale(float, float);

    // setPosition
    void setPosition(float, float);

    // moveCharacter
    void moveCharacter(Event, const RenderWindow&);

    // checkPosition
    void checkPosition();

    // drawCharacter
    void drawCharacter(RenderWindow&);

};
