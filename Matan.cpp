#include "Matan.h"

int getRandomNumber(int min, int max)
{
    if (min > max)
    {
        std::cout << "Warning min greater max!" << std::endl;
        int temp = max;
        max = min;
        min = temp;
    }
    std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    return min + rand() % (max - min + 1); //+1 need because include max number in range
}

float sinWave(float x, float a, float b, float c) {
    return a * sin(b * x + c);
}

sf::Vector2f circleVector(sf::Vector2f center, float velocity, float radius, float time) {
    float x = center.x + radius * cos(velocity * time);
    float y = center.y + radius * sin(velocity * time);
    return sf::Vector2f(x, y);
}

sf::Vector2f curveBezier(float t, sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3) { 
    if (t > 1)
        t = 1;
    if (t < 0)
        t = 0;

    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    sf::Vector2f p = uuu * p0; 
    p += 3 * uu * t * p1;     
    p += 3 * u * tt * p2;     
    p += ttt * p3;             

    return p;
}

