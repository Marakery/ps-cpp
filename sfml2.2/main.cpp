#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    const Vector2f center = {400, 300};
    constexpr int pointCount = 800;
    constexpr int radius = 100;
    constexpr float period = 2.f;
    Vector2f position;
    const float speed = 20.f;

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Polar Rose", Style::Default, settings);
    
    Clock clock;

    ConvexShape rose;
    rose.setFillColor(Color(220, 20, 60));
    rose.setPointCount(800);

    for (int i = 0; i < 800; ++i)
    {
        float angle = 2 * M_PI * i / 800;
        float radiusRose = 200 * sin(6 * angle);
       Vector2f point = {
            radiusRose * sin(angle),
            radiusRose * cos(angle)};

        rose.setPoint(i, point);
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        float time = clock.getElapsedTime().asSeconds();
		float phase = time * 2 * M_PI;

        position.x = radius * cos((phase) / period);
        position.y = radius * sin((phase) / period);


        rose.setPosition(center + position);

        window.clear();
        window.draw(rose);
        window.display();
    }
}

