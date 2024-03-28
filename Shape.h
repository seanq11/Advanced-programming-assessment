#pragma once
#include<iostream>
using namespace std;
#include"Point.h"
#include<vector>
#include <cmath>
#include<string>
class Shape
{

	float area;
	bool isCircular;
	Point leftTop;
	float perimetre;
	vector<Point>points;
public:
	Shape(float x,float y)
	{
		isCircular = false;
		area = perimetre = 0;
		leftTop.setX(x);
		leftTop.setY(y);
	}
	virtual void calculateArea() = 0;
	virtual void calculatePerimetre() = 0;
	virtual void calculatePoints() = 0;
	virtual string toString() = 0;
	void setArea(float area) { this->area = area; }
	float getArea() { return area; }
	 bool GetIsCircular()
	{
		return isCircular;
	}

	 void SetIsCircular(bool value)
	{
		isCircular = value;
	}
	 float GetPerimetre()
	{
		return perimetre;
	}
	 void SetPerimetre(float value)
	{
		perimetre = value;
	}
	 void setLeftTop(Point p) { leftTop = p; }
	 Point getLeftTop() { return leftTop; }
	 vector<Point> getPoints() { return points; }
	 void setPoints(vector<Point>p) { points = p; }

};






