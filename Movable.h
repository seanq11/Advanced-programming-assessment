#pragma once
class Movable
{
public:
	virtual void scale(float scaleX, float scaleY) = 0;
	virtual void move(int newX, int newY) = 0;
};
