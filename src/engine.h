#ifndef ENGINE
#define ENGINE

#include <vector>
#include <cstdint>

class Renderer 
{
public:
    struct coordinate
    {
        double x, y;
    };
public:
    class Triangle
    {
    public:
        struct coordinate* point;

        double maxX, minX, maxY, minY;

        Triangle(struct coordinate* points);
        ~Triangle();

        void changePoint(const int point, const struct coordinate pos);
        void rotateAround(const struct coordinate point, const double radian);

        struct coordinate getCenter();

        static float area(const struct coordinate a, const struct coordinate b, const struct coordinate c);
        static uint8_t inside(const struct coordinate p, const struct coordinate a, const struct coordinate b, const struct coordinate c);
    };

    class Rectangle
    {
    public:
        Triangle* tri[2];

        Rectangle(struct Renderer::coordinate* t1Points, struct Renderer::coordinate* t2Points);
        ~Rectangle();

        void changePoint(const int point, const struct coordinate pos);
        void rotateAround(const struct coordinate point, const double radian);
        
        struct coordinate getCenter();
    };

    const int m_Width, m_Height;
    const uint8_t m_Newline;
    std::vector<Triangle*> triangles = std::vector<Triangle*>();
public:
    Renderer(const int width, const int height, const uint8_t newline);
    ~Renderer();

    const int getWidth() const;
    const int getHeight() const;

    Triangle& tri(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3);
    Rectangle& rect(const struct coordinate c1, const struct coordinate c2, const struct coordinate c3, const struct coordinate c4);

    void draw() const;
};
#endif