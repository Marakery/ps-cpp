#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

using namespace sf;

int main()
{

    constexpr float BALL_SIZE = 40;

    RenderWindow window(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "moving Ball");

    CircleShape ball(BALL_SIZE);
    ball.setFillColor(Color::White);

    Clock clock;
    const Vector2f position = {0, 250}; 
    float speed_X = 200.f;               
    float time = 0;

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

        constexpr float amplitudeY = 150.f;
        constexpr float periodY = 2;

        const float dt = clock.restart().asSeconds();

        time = time + dt;

        const float wavePhase = time * float (3 * M_PI);
        const float x = x + speed_X * dt;
        const float y = amplitudeY * cos(wavePhase / periodY);
        const Vector2f offset = {x, y};

       if ((x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speed_X > 0))
        {
            speed_X = -speed_X;
        }
        if ((x < 0) && (speed_X < 0))
        {
            speed_X = -speed_X;
        }

        ball.setPosition(position + offset);
        window.clear();
        window.draw(ball);
        window.display();
    }
}
