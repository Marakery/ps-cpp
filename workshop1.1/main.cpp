#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

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

}

void redrawFrame(RenderWindow &window, ConvexShape &arrow)
{
	window.clear(Color::White);
	window.draw(arrow);
	window.display();
}

int main()
{
	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;

	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Yellow arrow", Style::Default, settings);
	ConvexShape arrow;

	init(arrow);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		redrawFrame(window, arrow);
	}
}
