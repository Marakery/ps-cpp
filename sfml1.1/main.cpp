#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{

    RenderWindow window(VideoMode({176, 473}), "trafic light");

    RectangleShape shape1;
    shape1.setSize({170, 465});
    shape1.setPosition({3, 5});
    shape1.setFillColor(Color(105, 105, 105));

    CircleShape shape2(70);
    shape2.setPosition({20, 20});
    shape2.setFillColor(Color::Green);

    CircleShape shape4(70);
    shape4.setPosition({20, 170});
    shape4.setFillColor(Color::Yellow);

    CircleShape shape3(70);
    shape3.setPosition({20, 320});
    shape3.setFillColor(Color::Red);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.draw(shape4);

        window.display();
    }
}