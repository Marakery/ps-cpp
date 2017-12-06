#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
	std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

	mousePosition = { float(event.x), float(event.y) };
}

void init(sf::ConvexShape& arrow)
{
	arrow.setPointCount(3);
	arrow.setPoint(0, { 40, 0 });
	arrow.setPoint(1, { -20, -20 });
	arrow.setPoint(2, { -20, 20 });
	arrow.setPosition({ 400, 300 });
	arrow.setFillColor(sf::Color::Blue);

}
float toDegrees(float radians)
{
	return float(double(radians) * 180.0 / M_PI);
}

void update(const sf::Vector2f& mousePosition, sf::ConvexShape& arrow, float& dt)
{
	const sf::Vector2f delta = mousePosition - arrow.getPosition();
	float angle = atan2(delta.y, delta.x);
	const float arrowSpeed = 20;
	if (angle < 0) 
	{
		angle = angle + 2 * M_PI;
	}
	const float arrowRotation = arrow.getRotation();
	const float mouseRotation = toDegrees(angle);
	const float maxRotation = arrowSpeed * dt;
	float nextRotation = std::min((mouseRotation - maxRotation), maxRotation);
	if (mouseRotation < arrowRotation)
	{
		if ((mouseRotation + 180) < arrowRotation)
		{
			arrow.setRotation(arrowRotation + nextRotation);
		}
		else
		{
			arrow.setRotation(arrowRotation - nextRotation);
		}
	}
	else
	{
		if ((mouseRotation - 180) > arrowRotation)
		{
			arrow.setRotation(arrowRotation - nextRotation);
		}
		else
		{
			arrow.setRotation(arrowRotation + nextRotation);
		}
	}
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

void redrawFrame(sf::RenderWindow& window, sf::ConvexShape& arrow)
{
	window.clear();
	window.draw(arrow);
	window.display();
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 600), "Arrow follow mouse");

	sf::ConvexShape arrow;
	sf::Vector2f mousePosition;
	sf::Clock clock;

	init(arrow);
	while (window.isOpen())
	{
		pollEvents(window, mousePosition);
		float dt = clock.restart().asSeconds();
		update(mousePosition, arrow, dt);
		redrawFrame(window, arrow);
	}
}



