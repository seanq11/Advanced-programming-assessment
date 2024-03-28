#pragma once
#include<iostream>
using namespace std;
class Point
{
    float x;
    float y;
public:
    Point() { x = y = 0; }
    Point(float x_init, float y_init) {
        x = x_init;
        y = y_init;
    }

    void display() {
       cout<<"(" << x <<", " << y << ")";
    }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    float getX() { return x; }
    float getY() { return y; }
};