#pragma once
#include "imgui.h"
#include "Coordinate_Math_2D.h"

class Node {

public:
	//static void drawLine();
	Node();
	void draw();

private:
	unsigned int height;
	unsigned int width;
	unsigned int numberOfParameters;
	Point begin;
	Point end;

};