#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>


void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
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

	if (angle < 0)
	{
		angle = angle + 2 * M_PI;
	}

	const float arrowRotation = arrow.getRotation();
	const float mouseRotation = toDegrees(angle);
	const float arrowSpeed = 15;
	const float maxRotation = arrowSpeed * dt;
	float nextRotation = ((mouseRotation - maxRotation), maxRotation);


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

	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(900, 600), "Arrow folow mouse", sf::Style::Default, settings);
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


