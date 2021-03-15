#include <chrono>
#include <thread>

#define M_PI 3.14159265358979323846

#include "engine.h"

int main()
{
    Renderer r = Renderer(90, 30, 1);
    Renderer::Rectangle& rec = r.rect( {10, 10}, {10, 20}, {20, 20}, {20, 10} );
    for(int i = 0; i < 200; i++)
    {
        const std::chrono::high_resolution_clock::time_point frameStart = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(16);

        r.draw();

        rec.rotateAround(rec.getCenter(), M_PI / 100);

        std::this_thread::sleep_until(frameStart);

    }
}