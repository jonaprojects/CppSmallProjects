#include "Point.h"
#include <iostream>
#include <string>
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}
float Point::get_x() {
	return this->x;
}
float Point::get_y() {
	return this->y;
}
void Point::set_x(int x) {
	this->x = x;
}
void Point::set_y(int y) {
	this->y = y;
}
std::string Point::to_string() {
	return "X: " + std::to_string(this->x) + " Y: " + std::to_string(this->y);
}

