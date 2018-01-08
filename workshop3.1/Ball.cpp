#include "ball.hpp"
#include "constants.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace sf;
void BallWithName::init()
{
	int pointCount = 200;
	ball.setPosition(startPosition);
	ball.setFillColor(Color(255, 255, 0));
	ball.setPointCount(pointCount);

	for (int pointNo = 0; pointNo < pointCount; ++pointNo)
	{
		float angle = float(2 * M_PI * pointNo) / float(pointCount);
		float nameRadius = 100;
		Vector2f point = Vector2f{ nameRadius * std::sin(angle), nameRadius * std::cos(angle) };
		ball.setPoint(pointNo, point);
	}
	ball.setOutlineThickness(outlineThickness);
	ball.setOutlineColor(Color::Blue);

	font.loadFromFile("arial.ttf");
	name.setFont(font);
	name.setCharacterSize(fontSize);
	name.setFillColor(Color::Black);
	name.setString("Aleksandr");
	name.setPosition(startName);
}

void BallWithName::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(ball, states);
	target.draw(name, states);
}