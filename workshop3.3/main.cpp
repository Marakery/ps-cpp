#include "main.hpp"

using namespace std;
using namespace sf;

void pollEvents(RenderWindow &window, Vector2f &mousePosition)
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::MouseMoved:
			onMouseMove(event.mouseMove, mousePosition);
			break;
		default:
			break;
		}
	}
}

void onMouseMove(Event::MouseMoveEvent &event, Vector2f &mousePosition)
{
	mousePosition = { float(event.x), float(event.y) };
	Vector2f distance = Vector2f{ WINDOW_WIDTH / 2 - mousePosition.x, WINDOW_HEIGHT / 2 - mousePosition.y };
	float length = sqrt(pow(distance.x, 2.0) + pow(distance.y, 2.0));
	cout << "length: " << length << endl;
}

void redrawFrame(RenderWindow &window, VertexArray(&lines))
{
	window.clear(Color::White);
	window.draw(lines);
	window.display();
}

void   createLine(VertexArray(&line), Vector2f mousePosition)
{
	line[0].position = mousePosition;
	line[1].position = Vector2f(400, 300);

	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
}

int main()
{
	VertexArray line(Lines, 2.0);

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Draw line");

	Vector2f mousePosition;

	while (window.isOpen())
	{
		createLine(line, mousePosition);
		pollEvents(window, mousePosition);
		redrawFrame(window, line);
	}
}