#include "Vector2.h"

bool operator==(Vector2& lhs, Vector2& rhs)
{
    if (lhs._x == rhs._x && lhs._y == rhs._y)
    {
        return true;
    }

    return false;
}
