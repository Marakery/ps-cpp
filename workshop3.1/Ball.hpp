#pragma once
#include <SFML/Graphics.hpp>
#include "constants.hpp"
 
using namespace sf;
class BallWithName : public Drawable
{
public:
	void init();

private:
	void draw(RenderTarget &target, RenderStates states) const override;
	ConvexShape ball;
	Text name;
	Font font;
};