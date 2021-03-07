#include "engine.h"

int main()
{
    Renderer r = Renderer(25,10);
    r.Tri(new int[2]{5, 5}, new int[2]{21, 7}, new int[2]{20, 3});
    for(int i = 0; i < 1; i++)
    {
        r.Draw();
    }
}