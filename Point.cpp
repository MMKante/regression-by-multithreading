#include "Point.h"

Point::Point(float x, float y) : m_x(x), m_y(y) {}

float Point::x() const {
    return m_x;
}

float Point::y() const {
    return m_y;
}

