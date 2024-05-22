#include "mainCharacter.h"

Character::Character(const string& path, Matriz* matrizInstancia) : matriz(matrizInstancia) //inicializar puntero
{
    if (!texture.loadFromFile(path))
    {
        cout << "Error al cargar el sprite" << endl;
        return;
    }

    // Obtener w y h del png
    Vector2u sizeCharacter = texture.getSize();
    int width = sizeCharacter.x / 8;
    int height = sizeCharacter.y / 9;

    // Crear los sprites y guardarlos en el array
    for (int i = 0; i < 72; i++)
    {
        int row = i / 8;
        int col = i % 8;

        IntRect rect(col * width, row * height, width, height);
        Sprite modelo(texture, rect);
        modelos.push_back(modelo);
    }

    modeloSeleccionado = 1;
}

void Character::setScale(float scaleX, float scaleY)
{
    for (Sprite& modelo : modelos)
    {
        modelo.setScale(scaleX, scaleY);
    }
}

void Character::setPosition(float positionX, float positionY)
{
    for (Sprite& modelo : modelos)
    {
        modelo.setPosition(positionX, positionY);
    }
}

void Character::moveCharacter(Event event, const RenderWindow& window)
{
    Vector2f currentPosition = modelos[currentSpriteIndex].getPosition();

    if (event.type == Event::KeyPressed)
    {
        bool moved = false; // Añadido para detectar movimiento

        if (event.key.code == Keyboard::D)
        {
            if (currentPosition.x + speedCharacter < window.getSize().x - modelos[currentSpriteIndex].getGlobalBounds().width)
            {
                currentSpriteIndex++;
                if (currentSpriteIndex > 31)
                {
                    currentSpriteIndex = 24;
                }
                modelos[currentSpriteIndex].move(speedCharacter, 0.0f);
                moved = true;
            }
        }
        else if (event.key.code == Keyboard::A)
        {
            if (currentPosition.x - speedCharacter > 0)
            {
                currentSpriteIndex--;
                if (currentSpriteIndex < 24)
                {
                    currentSpriteIndex = 31;
                }
                modelos[currentSpriteIndex].move(-speedCharacter, 0.0f);
                moved = true;
            }
        }
        else if (event.key.code == Keyboard::W)
        {
            if (currentPosition.y - speedCharacter > 0)
            {
                currentSpriteIndex++;
                if (currentSpriteIndex > 31)
                {
                    currentSpriteIndex = 24;
                }
                modelos[currentSpriteIndex].move(0.0f, -speedCharacter);
                moved = true;
            }
        }
        else if (event.key.code == Keyboard::S)
        {
            if (currentPosition.y + speedCharacter < window.getSize().y - modelos[currentSpriteIndex].getGlobalBounds().height)
            {
                currentSpriteIndex--;
                if (currentSpriteIndex < 24)
                {
                    currentSpriteIndex = 31;
                }
                modelos[currentSpriteIndex].move(0.0f, speedCharacter);
                moved = true;
            }
        }

        if (moved)
        {
            // Actualizar la posición de todos los sprites para evitar parpadeos
            for (int i = 24; i <= 31; ++i)
            {
                if (i != currentSpriteIndex)
                {
                    modelos[i].setPosition(modelos[currentSpriteIndex].getPosition());
                }
            }
            matriz->checkPosition(modelos[currentSpriteIndex].getPosition()); // Llama a la función para comprobar la posición 
        }
    }
}


void Character::drawCharacter(RenderWindow& window)
{
    window.draw(modelos[currentSpriteIndex]);
}
