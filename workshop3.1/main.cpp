#include "ball.hpp"
#include "constants.hpp"
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;
void initWindow(RenderWindow &window)
{
	VideoMode videoMode(800, 600);
	const string title = "Name ball";
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(videoMode, title, Style::Default, settings);
}

int main()
{
	RenderWindow window;
	initWindow(window);
	BallWithName Name;
	Name.init();

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
		window.clear(Color::White);
		window.draw(Name);
		window.display();
	}
}