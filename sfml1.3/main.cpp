#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode({800, 700}), "Home", Style::Default, settings);

    RectangleShape Rectangle;
    Rectangle.setSize({350, 230});
    Rectangle.setPosition({200, 450});
    Rectangle.setFillColor(Color(139, 69, 19));

    RectangleShape window1;
    window1.setSize({90, 80});
    window1.setPosition({395, 520});
    window1.setFillColor(Color(210, 180, 140));
    window1.setOutlineThickness(5);
    window1.setOutlineColor(Color::Black);

    RectangleShape line(sf::Vector2f(90, 5));
    line.setPosition({395, 560});
    line.setFillColor(Color::Black);
    RectangleShape line1(sf::Vector2f(5, 80));
    line1.setPosition({438, 520});
    line1.setFillColor(Color::Black);

    RectangleShape door;
    door.setSize({70, 170});
    door.setPosition({240, 510});
    door.setFillColor(Color(210, 180, 140));
    door.setOutlineThickness(1);
    door.setOutlineColor(Color::Black);

    CircleShape circledoor(5);
    circledoor.setPosition({250, 590});
    circledoor.setFillColor(Color(105, 105, 105));
    circledoor.setOutlineThickness(1);
    circledoor.setOutlineColor(Color::Black);

    ConvexShape convex;
    convex.setFillColor(Color(128, 0, 0));
    convex.setPointCount(4);
    convex.setOutlineThickness(1);
    convex.setOutlineColor(Color::Black);
    convex.setPoint(0, Vector2f(270, 350));
    convex.setPoint(1, Vector2f(490, 350));
    convex.setPoint(2, Vector2f(610, 450));
    convex.setPoint(3, Vector2f(140, 450));

    CircleShape circle1(13);
    circle1.setPosition({450, 270});
    circle1.setFillColor(Color(169, 169, 169));

    CircleShape circle2(15);
    circle2.setPosition({458, 250});
    circle2.setFillColor(Color(169, 169, 169));

    CircleShape circle3(18);
    circle3.setPosition({462, 230});
    circle3.setFillColor(Color(169, 169, 169));

    CircleShape circle4(20);
    circle4.setPosition({469, 200});
    circle4.setFillColor(Color(169, 169, 169));

    RectangleShape chimney;
    chimney.setSize({30, 60});
    chimney.setPosition({440, 330});
    chimney.setFillColor(Color(139, 69, 19));
    chimney.setOutlineThickness(1);
    chimney.setOutlineColor(Color::Black);

    RectangleShape chimney1;
    chimney1.setSize({60, 40});
    chimney1.setPosition({425, 290});
    chimney1.setFillColor(Color(139, 69, 19));
    chimney1.setOutlineThickness(1);
    chimney1.setOutlineColor(Color::Black);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(Rectangle);
        window.draw(door);
        window.draw(convex);
        window.draw(circledoor);
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(circle4);
        window.draw(chimney);
        window.draw(chimney1);
        window.draw(window1);
        window.draw(line1);
        window.draw(line);
        window.display();
    }
}