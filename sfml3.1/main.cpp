#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

struct Eye1
{
	sf::ConvexShape whiteEye;
	sf::ConvexShape appleEye;



	sf::Vector2f position;

	float rotation = 0;
};
/*struct Eye2
{
	sf::ConvexShape whiteEye2;
	sf::ConvexShape appleEye2;


	sf::Vector2f position;

	float rotation = 0;
};*/


sf::Vector2f toEuclidian(float radiusX, float radiusY, float angle)
{
	return{
		radiusX * float(cos(angle)),
		radiusY * float(sin(angle)) };
}

float toGrees(float radians) { return float(double(radians) * 180.0 / M_PI); }
sf::Vector2f relativePos(sf::Vector2f posRoot, sf::Vector2f absolPos) {
	return absolPos - posRoot;
}

void updateEyesElements(Eye1 &eye1/*, Eye2 &eye2*/)
{
	constexpr float rotationRadiusX = 50.f;
	constexpr float rotationRadiusY = 100.f;

	const sf::Vector2f whiteOfTheEye1Offset = toEuclidian(rotationRadiusX, rotationRadiusY, eye1.rotation);
	eye1.appleEye.setPosition(eye1.position + whiteOfTheEye1Offset);




}

void initEyes(Eye1& eye1)
{
	const sf::Vector2f whiteRadius = { 80.f, 150.f };
	const sf::Vector2f appleRadius = { 10.f, 15.f };
	constexpr int pointCount = 200;

	eye1.position = {200, 200 };

	eye1.whiteEye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
	eye1.whiteEye.setPointCount(pointCount);
	eye1.whiteEye.setPosition(eye1.position);

	eye1.appleEye.setFillColor(sf::Color::Black);
	eye1.appleEye.setPointCount(pointCount);
	eye1.appleEye.setPosition(eye1.position);
	
	for (int pointNo = 0; pointNo < pointCount; ++pointNo)
	{
		float angle = float(2 * M_PI * pointNo) / float(pointCount);
		sf::Vector2f point = {
			whiteRadius.x * std::sin(angle),
			whiteRadius.y * std::cos(angle) };

	
		eye1.whiteEye.setPoint(pointNo, point);

	}

	
	for (int pointNo = 0; pointNo < pointCount; ++pointNo)
	{
		float angle = float(2 * M_PI * pointNo) / float(pointCount);
		sf::Vector2f point = {
			appleRadius.x * std::sin(angle),
			appleRadius.y * std::cos(angle) };

		eye1.appleEye.setPoint(pointNo, point);
	}

	//eye1.appleEye.setRadius(15);
	//eye1.appleEye.setOrigin(sf::Vector2f(0, 15));
	//eye1.appleEye.setPosition(eye1.position);
	//eye1.appleEye.setFillColor(sf::Color::Black);


	updateEyesElements(eye1);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
	std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
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

void updateEyes(const sf::Vector2f &mousePosition, Eye1 &eye1)
{

	const sf::Vector2f firstEyeDelta = mousePosition - eye1.position;
	eye1.rotation = atan2(firstEyeDelta.y, firstEyeDelta.x);


	updateEyesElements(eye1);
}

void redrawFrame(sf::RenderWindow &window, Eye1 &eye1)
{
	window.clear();
	window.draw(eye1.whiteEye);
	window.draw(eye1.appleEye);
	window.display();
}

int main()
{
	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(
		sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
		"Eyes follows mouse", sf::Style::Default, settings);


	Eye1 eye1;
	sf::Vector2f mousePosition;

	initEyes(eye1);
	while (window.isOpen())
	{
		pollEvents(window, mousePosition);
		updateEyes(mousePosition, eye1);
		redrawFrame(window, eye1);
	}
}

