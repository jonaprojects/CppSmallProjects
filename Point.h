#pragma once
#include <iostream>
class Point
{
private:
	float x, y;
public:
	Point(float x, float y);
	float get_x();
	float get_y();
	void set_x(int x);
	void set_y(int y);
	std::string to_string();
};

