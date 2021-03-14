#include <cstdio>
#include <cstring>
#include <iostream>
#include "engine.h"


Renderer::Renderer(const int width, const int height, const uint8_t newline) : m_Width(width), m_Height(height), m_Newline(newline) {}
const int Renderer::getWidth() const { return m_Newline ? this->m_Width + 1 : this->m_Width; }
const int Renderer::getHeight() const { return this->m_Height; }

void Renderer::tri(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3)
{
    struct coordinate* coords = new (struct coordinate[3]){ c1, c2, c3 };
    this->triangles.push_back(new Triangle(coords));
}

void Renderer::draw() const 
{
    const int frameSize = this->getHeight() * this->getWidth();

    char* const frame = new char[frameSize];
    memset(frame, ' ', frameSize);

    if (this->m_Newline)
    {
        for(int i = 0; i < this->m_Height; i++)
        {
            frame[(this->getWidth() - 1) + (this->getWidth() * i)] = '\n';
        }
    }

    
    for (Triangle* const tri : this->triangles)
    {
        for(int x = tri->minX; x <= tri->maxX; x++) 
        {
            for(int y = tri->minY; y <= tri->maxY; y++)
            {
                if (Renderer::Triangle::inside({x, y}, tri->point[0], tri->point[1], tri->point[2]))
                {
                    frame[x + (this->getWidth() * y)] = '#';
                }
            }
        }

        /*
        for (int i = 0; i < 3; i++)
        {
            frame[tri->point[i].x + (this->getWidth() * tri->point[i].y)] = '+';
        }
        */
    }

    fwrite(frame, sizeof(char), frameSize, stdout);
}