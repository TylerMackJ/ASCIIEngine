#include <chrono>
#include <thread>

#define M_PI 3.14159265358979323846

#include "engine.h"

int main()
{
    Renderer r = Renderer(90, 29, 1);
    Renderer::Triangle& t = r.tri( {500, 500}, {-500, -500}, {0, 25} );
    for(int i = 0; i < 200; i++)
    {
        const std::chrono::high_resolution_clock::time_point frameStart = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(16);

        r.draw();


        t.rotateAround({40, 20}, -M_PI / 100);

        std::this_thread::sleep_until(frameStart);

    }
}