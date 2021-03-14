#include <cmath>

#include "engine.h"

Renderer::Triangle::Triangle(struct coordinate* points) : point(points)
{
    maxX = points[0].x;
    minX = points[0].x;
    maxY = points[0].y;
    minY = points[0].y;
    for(int i = 1; i < 3; i++)
    {
        if (maxX < points[i].x)
            maxX = points[i].x;
        else if (minX > points[i].x)
            minX = points[i].x;

        if (maxY < points[i].y)
            maxY = points[i].y;
        else if (minY > points[i].y)
            minY = points[i].y;
        
    }
}

Renderer::Triangle::~Triangle()
{
    delete[] point;
}

void Renderer::Triangle::changePoint(const int point, const struct coordinate pos)
{
    this->point[point] = pos;
    
    if (maxX < pos.x)
        maxX = pos.x;
    else if (minX > pos.x)
        minX = pos.x;

    if (maxY < pos.y)
        maxY = pos.y;
    else if (minY > pos.y)
        minY = pos.y;
}


float Renderer::Triangle::area(const struct coordinate a, const struct coordinate b, const struct coordinate c)
{
    return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}
uint8_t Renderer::Triangle::inside(const struct coordinate p, const struct coordinate a, const struct coordinate b, const struct coordinate c)
{
    float a0 = Renderer::Triangle::area(a, b, c);
    float a1 = Renderer::Triangle::area(p, b, c);
    float a2 = Renderer::Triangle::area(a, p, c);
    float a3 = Renderer::Triangle::area(a, b, p);

    return (.1 > a1 + a2 + a3 - a0);
}