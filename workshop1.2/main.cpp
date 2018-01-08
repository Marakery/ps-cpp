#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace sf;

void init(ConvexShape &arrow)
{
	arrow.setPosition({ 300, 300 });
	arrow.setPointCount(7);
	arrow.setPoint(0, { 70, 10 });
	arrow.setPoint(1, { 20, -30 });
	arrow.setPoint(2, { 20, -10 });
	arrow.setPoint(3, { -30, -10 });
	arrow.setPoint(4, { -30, 30 });
	arrow.setPoint(5, { 20, 30 });
	arrow.setPoint(6, { 20, 50 });
	arrow.setFillColor(Color::Yellow);
	arrow.setOutlineColor(Color::Black);
	arrow.setOutlineThickness(3);
	arrow.setRotation(-20);

}

float toDegrees(float radians)
{
	return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
	mousePosition = { float(event.x), float(event.y) };
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseMoved:
			onMouseMove(event.mouseMove, mousePosition);
			break;
		default:
			break;
		}
	}
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
	window.clear(Color::White);
	window.draw(arrow);
	window.display();
}

int main()
{
	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Yellow arrow", sf::Style::Default, settings);
	sf::ConvexShape arrow;

	init(arrow);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		redrawFrame(window, arrow);
	}
}