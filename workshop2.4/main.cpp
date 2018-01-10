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
	Color colorArray[9] = { Color(0,204,51), Color(51,0,255), Color(0,0,255), Color(255,153,0), Color(255,255,51), Color(204,153,255), Color(255,51,51), Color(204,51,51), Color(153,255,255) };

	srand(time(NULL));
	const vector<Vector2f> speed = { { -254.f, 92.f },{ 70.f, 125.f },{ 300.f, -170.f },{ 100.f, -250.f } };
	for (size_t i = 0; i < 4; ++i)
	{
		Color first = colorArray[rand() % 9];
		Color second = colorArray[rand() % 9];
		Color modul = Color((first.r + second.r) / 2, (first.g + second.g) / 2, (first.b + second.b) / 2);
		balls[i].shape.setFillColor(modul);
		balls[i].shape.setOrigin(BALL_SIZE, BALL_SIZE);
		balls[i].shape.setRadius(BALL_SIZE);
		/*float randomSpeedX = rand() % 500;
		float randomSpeedY = rand() % 500;
		balls[i].speed = { randomSpeedX, randomSpeedY };*/
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