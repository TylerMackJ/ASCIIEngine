#include "engine.h"

int main()
{
    Renderer r = Renderer(25, 10, 1);
    r.Tri( {5, 5}, {20, 3}, {15, 7} );
    for(int i = 0; i < 1; i++)
    {
        r.Draw();
    }
}