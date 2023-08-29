#pragma once
#include "imgui.h"
#include "Coordinate_Math_2D.h"
#include<string>




class Node {

public:
	//static void drawLine();
	Node();
	Node(unsigned int numOfParam, unsigned int input, ImVec2 start, std::vector<std::string> *params);
	void lock();
	void unlock();
	void draw();
	void move();
	bool is_locked();

private:
	//static BezierCurveCubic* activeConnection;
	unsigned int				height;
	unsigned int				width						{100 };
	unsigned int				numberOfParameters			{ 0 };
	unsigned int				numberOfInputParameters		{ 0 };
	unsigned int				offsetX						{ 10 };
	unsigned int				circleRadius				{ 5 };
	std::vector<std::string>	paramName					{};
	unsigned int				heightPerParameter			{ 36 };
	bool						locked						{ true };
	float						borderThickness				{ 1.0f };
	float						borderRounding				{ 20.0f };
	float						nodeRounding				{ 20.0f };
	double						rateOfFloat					{ 1.0 };
	unsigned int				colInactive					{ IM_COL32(0xff,0xb3,0xff,0xff) };
	unsigned int				colActive					{ IM_COL32(0xff, 0xb3, 0xff, 0xaa) };
	unsigned int				borderCol					{ IM_COL32(0x00, 0x00, 0x00, 0xff) };
	unsigned int				colIn						{ IM_COL32(0x00, 0x00, 0xff, 0xff) };
	unsigned int				colOut						{ IM_COL32(0x00, 0x66, 0x00, 0xff) };
	bool						moveable					{ true };
	ImVec2						shift						{ 0, 0 };
	Point						begin;
	Point						end;

};