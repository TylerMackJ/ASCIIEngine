#include <chrono>
#include <thread>

#include "engine.h"

int main()
{
    Renderer r = Renderer(90, 29, 1);
    r.tri( {5, 5}, {35, 3}, {15, 7} );
    for(int i = 0; i < 120; i++)
    {
        const std::chrono::high_resolution_clock::time_point frameStart = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(16);

        r.draw();

        if(i % 6 == 0)
        {
            struct Renderer::coordinate p = r.triangles.at(0)->point[2];
            p.y++;
            r.triangles.at(0)->changePoint(2, p);
        }

        std::this_thread::sleep_until(frameStart);

    }
}