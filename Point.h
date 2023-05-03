#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {
    public:
        Point(float x, float y);
        float x() const;
        float y() const;

    private:
        float m_x = 0;
        float m_y = 0;
};

#endif // POINT_H_INCLUDED
