#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode({400, 400}), "EAI", Style::Default, settings);

    RectangleShape E1;
    E1.setSize({15, 80});
    E1.setPosition({115, 150});
    E1.setFillColor(Color::White);
    E1.setRotation(90);

    RectangleShape E2;
    E2.setSize({15, 80});
    E2.setPosition({110, 200});
    E2.setFillColor(Color::White);
    E2.setRotation(90);

    RectangleShape E3;
    E3.setSize({15, 80});
    E3.setPosition({115, 255});
    E3.setFillColor(Color::White);
    E3.setRotation(90);

    RectangleShape E4;
    E4.setSize({15, 120});
    E4.setPosition({25, 150});
    E4.setFillColor(Color::White);

    RectangleShape A1;
    A1.setSize({15, 130});
    A1.setPosition({216, 157});
    A1.setFillColor(Color::White);
    A1.setRotation(330);

    RectangleShape A2;
    A2.setSize({15, 130});
    A2.setPosition({220, 150});
    A2.setFillColor(Color::White);
    A2.setRotation(30);

    RectangleShape A3;
    A3.setSize({15, 78});
    A3.setPosition({261, 220});
    A3.setFillColor(Color::White);
    A3.setRotation(90);

    RectangleShape I1;
    I1.setSize({15, 120});
    I1.setPosition({350, 150});
    I1.setFillColor(Color::White);

    RectangleShape I2;
    I2.setSize({15, 30});
    I2.setPosition({372, 150});
    I2.setFillColor(Color::White);
    I2.setRotation(90);

    RectangleShape I3;
    I3.setSize({15, 30});
    I3.setPosition({372, 255});
    I3.setFillColor(Color::White);
    I3.setRotation(90);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(E1);
        window.draw(E2);
        window.draw(E3);
        window.draw(E4);
        window.draw(A1);
        window.draw(A2);
        window.draw(A3);
        window.draw(I1);
        window.draw(I2);
        window.draw(I3);
        window.display();
    }
}