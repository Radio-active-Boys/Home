#pragma once
#include "imgui.h"
#include "Coordinate_Math_2D.h"

class Node {

public:
	static void drawLine();
	Node();
	void lock();
	void unlock();
	void draw();
	void move();
	bool is_locked();

private:
	unsigned int				height;
	unsigned int				width;
	unsigned int				numberOfParameters;
	bool						locked				{ true };
	float						borderThickness		{ 1.0f };
	float						borderRounding		{ 20.0f };
	float						nodeRounding		{ 20.0f };
	double						rateOfFloat			{ 1.0 };
	unsigned int				colInactive			{ IM_COL32(0x00,0x66,0xcc,0xff) };
	unsigned int				colActive			{ IM_COL32(0x00, 0x66, 0xcc, 0xaa) };
	unsigned int				borderCol			{ IM_COL32(0x00, 0x00, 0x00, 0xff) };
	bool						moveable			{ true };
	Point						begin;
	Point						end;

};