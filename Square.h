#pragma once
#include"Movable.h"
#include"Point.h"
#include"Shape.h"
class Square :public Shape, public Movable
{
	float edge;
public:
	Square(float x, float y, float side) : edge(side), Shape(x, y) {}

	void calculateArea()
	{
		setArea(edge * edge);
	}
	void calculatePerimetre()
	{
		SetPerimetre(edge * 4);
	}
	void calculatePoints()
	{
		//the order should be: leftTop, rightTop, rightBottom and 
		//leftBottom.
		Point left = getLeftTop();
		vector<Point>p;
		p.push_back(left);
		p.push_back(Point(left.getX() + edge, left.getY()));
		p.push_back(Point(left.getX() + edge, left.getY() + edge));
		p.push_back(Point(left.getX(), left.getY() + edge));
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
		res += "Shape is:Square\n";
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