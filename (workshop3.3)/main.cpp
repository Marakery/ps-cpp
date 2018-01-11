#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdio>

using namespace std;

void onMouseMove(sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition)
{
	mousePosition = { float(event.x), float(event.y) };

}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition)
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

void initLine(sf::VertexArray& triangle, sf::Vector2f mousePosition)
{


	// define the position of the triangle's points
	triangle[0].position = sf::Vector2f(0, 0);
	triangle[1].position = sf::Vector2f(800, 0);
	triangle[2].position = mousePosition;

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;


}

void redrawFrame(sf::RenderWindow& window, sf::VertexArray& triangle)
{
	window.clear(sf::Color::Black);
	window.draw(triangle);
	window.display();
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Line", sf::Style::Default, settings);

	sf::Vector2f mousePosition;

	//sf::VertexArray line(sf::Lines, 2);
	sf::VertexArray triangle(sf::Triangles, 3);
	while (window.isOpen())
	{
		pollEvents(window, mousePosition);
		redrawFrame(window, triangle);
		initLine(triangle, mousePosition);
	}
}