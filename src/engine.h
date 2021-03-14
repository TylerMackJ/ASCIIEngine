#ifndef ENGINE
#define ENGINE

#include <vector>
#include <cstdint>

class Renderer 
{
public:
    struct coordinate
    {
        int x, y;
    };
private:
    class Triangle
    {
    public:
        struct coordinate* point;

        int maxX, minX, maxY, minY;

        Triangle(struct coordinate* points);
    };

    const int m_Width, m_Height;
    const uint8_t m_Newline;
    std::vector<Triangle*> triangles = std::vector<Triangle*>();
public:
    Renderer(const int width, const int height, const uint8_t newline);
    const int GetWidth() const;
    const int GetHeight() const;

    void Tri(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3);

    void Draw() const;
};
#endif