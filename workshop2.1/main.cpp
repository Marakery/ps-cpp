#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


using namespace std;
using namespace sf;

constexpr unsigned BALL_SIZE = 50;
constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

struct Ball
{
	Vector2f speed;
	CircleShape shape;
};


void update(vector<Ball>& balls, float &dt)
{

	for (size_t i = 0; i < 4; ++i)
	{
		Vector2f position = balls[i].shape.getPosition();
		position += balls[i].speed * dt;

		if ((position.x + BALL_SIZE >= WINDOW_WIDTH) && (balls[i].speed.x > 0))
		{
			balls[i].speed.x = -balls[i].speed.x;
		}
		if ((position.x < BALL_SIZE) && (balls[i].speed.x < 0))
		{
			balls[i].speed.x = -balls[i].speed.x;
		}
		if ((position.y + BALL_SIZE >= WINDOW_HEIGHT) && (balls[i].speed.y > 0))
		{
			balls[i].speed.y = -balls[i].speed.y;
		}
		if ((position.y < BALL_SIZE) && (balls[i].speed.y < 0))
		{
			balls[i].speed.y = -balls[i].speed.y;
		}

		balls[i].shape.setPosition(position);
	}
}
void init(vector<Ball>& balls)
{

	srand(time(NULL));
	const vector<Vector2f> speed = { { 254.f, 92.f },{ -200.f, 125.f },{ 200.f, 200.f },{ -150.f, 254.f } };
	const vector<Color> colors = { Color(rand() % 254, rand() % 254, rand() % 254), Color(rand() % 254, rand() % 254, rand() % 254), Color(rand() % 254, rand() % 254, rand() % 254), Color(rand() % 254, rand() % 254, rand() % 254) };
	for (size_t i = 0; i < 4; ++i)
	{
		balls[i].shape.setOrigin(BALL_SIZE, BALL_SIZE);
		balls[i].shape.setFillColor(colors[i]);
		balls[i].shape.setRadius(BALL_SIZE);
		balls[i].speed = speed[i];
	}
}





void pollEvents(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
	}

}



void redrawFrame(RenderWindow &window, std::vector<Ball> &balls)
{
	window.clear();
	for (size_t i = 0; i < balls.size(); ++i)
	{
		window.draw(balls[i].shape);
	}
	window.display();
}


int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Balls", Style::Default, settings);

	Clock clock;

	vector<Ball> balls(4);
	init(balls);

	while (window.isOpen())
	{
		pollEvents(window);
		float dt = clock.restart().asSeconds();
		update(balls, dt);
		redrawFrame(window, balls);

	}
}