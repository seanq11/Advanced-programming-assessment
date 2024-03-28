#pragma once
#include"Movable.h"
#include"Point.h"
#include"Shape.h"
class Rectangle :public Shape, public Movable
{
	float height;
	float width;
public:
	Rectangle(float x, float y, float h, float w) : height(h), width(w), Shape(x, y) {}
	void calculateArea()
	{
		setArea(height * width);
	}
	void calculatePerimetre()
	{
		SetPerimetre(2 * (height + width));
	}
	void calculatePoints()
	{
		//the order should be : leftTop, rightTop, rightBottom and
			//leftBottom.
		Point left = getLeftTop();
		vector<Point>p;
		p.push_back(left);
		p.push_back(Point(left.getX() + width, left.getY()));
		p.push_back(Point(left.getX() + width, left.getY() + height));
		p.push_back(Point(left.getX(), left.getY() + height));
		setPoints(p);
	}
	void scale(float scaleX, float scaleY)
	{
		Point p = getLeftTop();
		setLeftTop(Point(p.getX() + scaleX, p.getY() + scaleY));
		calculateArea();
		calculatePerimetre();
		calculatePoints();
	}
	void move(int newX, int newY)
	{
		setLeftTop(Point((float)newX, (float)newY));
		calculateArea();
		calculatePerimetre();
		calculatePoints();
	}
	string toString()
	{
		calculateArea();
		calculatePerimetre();
		calculatePoints();
		string res = "";
		char buffer[10];
		snprintf(buffer, 10, "%.1f", getArea());
		string s = buffer;
		res += "Shape is:Rectangle\n";
		res += "Area is:" + s + "\n";
		snprintf(buffer, 10, "%.1f", GetPerimetre());
		s = buffer;
		res += "Perimetre is:" + s + "\n";
		snprintf(buffer, 10, "%.1f", getLeftTop().getX());
		s = buffer;
		s += ",";
		snprintf(buffer, 10, "%.1f", getLeftTop().getY());
		s += buffer;
		res += "Left top point is:" + s + "\n";
		return res;
	}
};
