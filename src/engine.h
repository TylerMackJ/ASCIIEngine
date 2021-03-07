#ifndef ENGINE
#define ENGINE

#include <vector>

class Renderer 
{
private:
    class Triangle
    {
    public:
        int* x;
        int* y;

        Triangle(int x[3], int y[3]);
    };

    const int m_Width, m_Height;
    std::vector<Triangle*> triangles = std::vector<Triangle*>();
public:
    Renderer(const int width, const int height);
    const int GetWidth() const;
    const int GetHeight() const;

    void Tri(const int t[2], const int r[2], const int l[2]);

    void Draw() const;
};
#endif