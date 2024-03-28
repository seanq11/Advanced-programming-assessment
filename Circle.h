#pragma once
#include"Movable.h"
#include"Point.h"
#include"Shape.h"
class Circle :public Shape, public Movable
{
	float radius;
public:
	Circle(float x, float y, float r) : radius(r), Shape(x, y) {}
	void calculateArea()
	{
		setArea(3.14159 * pow(radius, 2));
	}
	void calculatePerimetre()
	{
		SetPerimetre(2 * 3.141592653 * radius);
	}
	void calculatePoints()
	{
		Point left = getLeftTop();
		vector<Point>p;
		p.push_back(left);
		p.push_back(Point(left.getX() + 2 * radius, left.getY() + 2 * radius));
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
		res += "Shape is:Circle\n";
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
