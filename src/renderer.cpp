#include <cstdio>
#include <cstring>
#include <iostream>
#include "engine.h"


Renderer::Renderer(const int width, const int height, const uint8_t newline) : m_Width(width), m_Height(height), m_Newline(newline) {}
Renderer::~Renderer()
{
    for (Triangle* const tri : this->triangles)
    {
        delete tri;
    }
}

const int Renderer::getWidth() const { return m_Newline ? this->m_Width + 1 : this->m_Width; }
const int Renderer::getHeight() const { return this->m_Height; }

Renderer::Triangle& Renderer::tri(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3)
{
    struct coordinate* coords = new struct coordinate[3] { c1, c2, c3 };
    Triangle* t = new Triangle(coords);
    this->triangles.push_back(t);
    return *t;
}

Renderer::Rectangle& Renderer::rect(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3, const struct coordinate c4)
{
    struct coordinate* t1Points = new struct coordinate[3] { c1, c2, c4 };
    struct coordinate* t2Points = new struct coordinate[3] { c2, c3, c4 };

    Rectangle* r = new Rectangle(t1Points, t2Points);

    this->triangles.push_back(r->tri[0]);
    this->triangles.push_back(r->tri[1]);

    return *r;
}

void Renderer::draw() const 
{
    const int frameSize = this->getHeight() * this->getWidth();

    static char* const frame = new char[frameSize];

    memset(frame, ' ', frameSize);

    // Draw newlines on frame edge
    if (this->m_Newline)
    {
        for(int i = 0; i < this->m_Height; i++)
        {
            frame[(this->getWidth() - 1) + (this->getWidth() * i)] = '\n';
        }
    }

    // Draw triangles
    for (Triangle* const tri : this->triangles)
    {
        for(int x = tri->minX > 0 ? tri->minX : 0; x <= tri->maxX && x < this->getWidth(); x++) 
        {
            for(int y = tri->minY > 0 ? tri->minY : 0; y <= tri->maxY && y < this->getHeight(); y++)
            {
                if (Renderer::Triangle::inside({(double)x, (double)y}, tri->point[0], tri->point[1], tri->point[2]))
                {
                    frame[x + (this->getWidth() * y)] = '#';
                }
            }
        }

        // Draw triangle vertices for debug
        /*
        for (int i = 0; i < 3; i++)
        {
            frame[tri->point[i].x + (this->getWidth() * tri->point[i].y)] = '+';
        }
        */
        // Draw triangle center for debug
        /*
        struct coordinate center = tri->getCenter();
        if (center.x >= 0 && center.x < this->getWidth() && center.y >= 0 && center.y < this->getHeight())
            frame[(int)tri->getCenter().x + (this->getWidth() * (int)tri->getCenter().y)] = '*';  if (tri->getCenter().x >= 0 && )
        */
    }

    // Draw frame
    fwrite(frame, sizeof(char), frameSize, stderr);
}