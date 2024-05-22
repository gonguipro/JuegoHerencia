#include "matriz.h"

Matriz::Matriz()
{
    // Constructor, inicializa la matriz si es necesario
}

void Matriz::checkPosition(const Vector2f& position)
{
    Vector2i cell = getCell(position);
    cout << "El personaje está en la celda (" << cell.x << ", " << cell.y << ")" << endl;
}

Vector2i Matriz::getCell(const Vector2f& position)
{
    int cellX = static_cast<int>(position.x) / celdaSize;
    int cellY = static_cast<int>(position.y) / celdaSize;
    return Vector2i(cellX, cellY);
}
