#include <cstdio>
#include <cstring>
#include <iostream>
#include "engine.h"


Renderer::Renderer(const int width, const int height) : m_Width(width), m_Height(height) {};
const int Renderer::GetWidth() const { return this->m_Width; }
const int Renderer::GetHeight() const { return this->m_Height; }

Renderer::Triangle::Triangle(int x[3], int y[3]) : x(x), y(y) {};

void Renderer::Tri(const int t[2], const int r[2], const int l[2])
{
    this->triangles.push_back(new Triangle(new int[3]{t[0], r[0], l[0]}, new int[3]{t[1], r[1], l[1]}));
}

void Renderer::Draw() const 
{
    const int frameSize = (this->m_Width + 1) * this->m_Height; // We add one to the width for newline
    char* const frame = new char[frameSize];
    memset(frame, ' ', frameSize);
    for(int i = 0; i < this->m_Height; i++)
    {
        frame[this->m_Width + ((this->m_Width + 1) * i)] = '\n';
    }

    
    for (Triangle* const tri : this->triangles)
    {
        for (int i = 0; i < 3; i++)
        {
            frame[tri->x[i] + (this->m_Width + 1) * tri->y[i]] = '+';
        }
    }

    fwrite(frame, sizeof(char), frameSize, stdout);
}