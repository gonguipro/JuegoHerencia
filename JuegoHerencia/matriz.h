#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Matriz
{
private:
    const int celdaSize = 100;
    const int matrizWidth = 1200 / celdaSize;
    const int matrizHeight = 800 / celdaSize;

public:
    Matriz();
    void checkPosition(const Vector2f& position);
    Vector2i getCell(const Vector2f& position);
};
