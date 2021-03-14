#include <cstdio>
#include <cstring>
#include <iostream>
#include "engine.h"


Renderer::Renderer(const int width, const int height, const uint8_t newline) : m_Width(width), m_Height(height), m_Newline(newline) {}
const int Renderer::GetWidth() const { return m_Newline ? this->m_Width + 1 : this->m_Width; }
const int Renderer::GetHeight() const { return this->m_Height; }

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
    printf("%d, %d, %d, %d\n", maxX, minX, maxY, minY);
}

void Renderer::Tri(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3)
{
    struct coordinate* coords = new (struct coordinate[3]){ c1, c2, c3 };
    this->triangles.push_back(new Triangle(coords));
}

void Renderer::Draw() const 
{
    const int frameSize = this->GetHeight() * this->GetWidth();

    char* const frame = new char[frameSize];
    memset(frame, ' ', frameSize);

    if (this->m_Newline)
    {
        for(int i = 0; i < this->m_Height; i++)
        {
            frame[(this->GetWidth() - 1) + (this->GetWidth() * i)] = '\n';
        }
    }

    
    for (Triangle* const tri : this->triangles)
    {
        for (int i = 0; i < 3; i++)
        {
            frame[tri->point[i].x + (this->GetWidth() * tri->point[i].y)] = '+';
        }
        frame[tri->maxX + (this->GetWidth() * tri->maxY)] = '*';
        frame[tri->minX + (this->GetWidth() * tri->minY)] = '*';
        
    }

    fwrite(frame, sizeof(char), frameSize, stdout);
}