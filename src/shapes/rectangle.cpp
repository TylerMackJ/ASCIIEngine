#include "../engine.h"

Renderer::Rectangle::Rectangle(struct Renderer::coordinate* t1Points, struct Renderer::coordinate* t2Points)
{
    this->tri[0] = new Triangle(t1Points);
    this->tri[1] = new Triangle(t2Points);

}

Renderer::Rectangle::~Rectangle()
{
    delete this->tri[0];
    delete this->tri[1];
}

void Renderer::Rectangle::changePoint(const int point, const struct coordinate pos)
{
    int t1Point;
    int t2Point;
    switch(point)
    {
    case 0:
        t1Point = 0;
        t2Point = -1;
        break;
    case 1:
        t1Point = 1;
        t2Point = 0;
        break;
    case 2:
        t1Point = -1;
        t2Point = 1;
        break;
    case 3:
        t1Point = 2;
        t2Point = 2;
    }

    this->tri[0]->changePoint(t1Point, pos);
    this->tri[1]->changePoint(t2Point, pos);
}

void Renderer::Rectangle::rotateAround(const struct coordinate point, const double radian)
{
    this->tri[0]->rotateAround(point, radian);
    this->tri[1]->rotateAround(point ,radian);
}

struct Renderer::coordinate Renderer::Rectangle::getCenter()
{
    return {(this->tri[0]->point[0].x + this->tri[1]->point[1].x) / 2.0, (this->tri[0]->point[0].y + this->tri[1]->point[1].y) / 2.0};
}