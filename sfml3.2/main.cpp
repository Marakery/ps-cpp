#include <SFML/Graphics.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace sf;

struct Eye
{
	ConvexShape pupil;
	ConvexShape whiteEye;

	Vector2f position;

	float rotation = 0;
};


// ѕереводит пол€рные координаты в декартовы
Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
	return{ radiusX * cos(angle), radiusY * sin(angle) };
}

// ќбновл€ет состо€ние глаза
void updateEye(Eye &eye)
{
	const Vector2f whiteOffset = toEuclidean(20, 40, eye.rotation);
	eye.pupil.setPosition(eye.position + whiteOffset);
	eye.whiteEye.setPosition(eye.position);
}



// »нициализирует зрачок
void initWhite(Eye &eye)
{
	eye.pupil.setFillColor(Color::Black);

	constexpr float pointCount = 200;
	Vector2f ellipseRadius = { 10.f, 15.f };
	eye.pupil.setPointCount(pointCount);
	for (int pointNo = 0; pointNo < pointCount; ++pointNo)
	{
		float angle = float(2 * M_PI * pointNo) / float(pointCount);
		Vector2f point = {
			ellipseRadius.x * cos(angle),
			ellipseRadius.y * sin(angle)
		};
		eye.pupil.setPoint(pointNo, point);
	}
}

// »нициализирует глаз
void initEye(Eye &eye, const float x, const float y)
{
	eye.position = { x, y };

	eye.whiteEye.setFillColor(Color(0xFF, 0xFF, 0xFF));

	constexpr int pointCount = 200;
	Vector2f ellipseRadius = { 50.f, 100.f };
	eye.whiteEye.setPointCount(pointCount);
	for (int pointNo = 0; pointNo < pointCount; ++pointNo)
	{
		float angle = float(2 * M_PI * pointNo) / float(pointCount);
		Vector2f point = {
			ellipseRadius.x * cos(angle),
			ellipseRadius.y * sin(angle)
		};
		eye.whiteEye.setPoint(pointNo, point);
	}
	initWhite(eye);
	updateEye(eye);
}

void onMouseMove(const  Event::MouseMoveEvent &event, Vector2f &mousePosition)
{
	std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
	mousePosition = { float(event.x), float(event.y) };
}

void pollEvents(RenderWindow &window, Vector2f &mousePosition)
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case  Event::Closed:
			window.close();
			break;
		case  Event::MouseMoved:
			onMouseMove(event.mouseMove, mousePosition);
			break;
		default:
			break;
		}
	}
}
void update(const Vector2f &mousePosition, Eye &LeftEye, Eye &RightEye)
{
	Vector2f delta = mousePosition - LeftEye.position;
	LeftEye.rotation = atan2(delta.y, delta.x);
	updateEye(LeftEye);

	delta = mousePosition - RightEye.position;
	RightEye.rotation = atan2(delta.y, delta.x);
	updateEye(RightEye);
}

// –исует и выводит один кадр
void redrawFrame(RenderWindow &window, Eye &LeftEye, Eye &RightEye)
{
	window.clear();
	window.draw(LeftEye.whiteEye);
	window.draw(LeftEye.pupil);
	window.draw(RightEye.whiteEye);
	window.draw(RightEye.pupil);
	window.display();
}

int main()
{
	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;

	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(
		VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
		"Eyes follows mouse", Style::Default, settings);


	Eye LeftEye;
	Eye RightEye;

	Vector2f mousePosition;

	initEye(LeftEye, 300, 300);
	initEye(RightEye, 450, 300);


	while (window.isOpen())
	{
		pollEvents(window, mousePosition);
		update(mousePosition, LeftEye, RightEye);
		redrawFrame(window, LeftEye, RightEye);
	}
}

