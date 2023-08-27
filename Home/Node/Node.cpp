#include "Node.h"
#include "Coordinate_Math_2D.h"

//
//void Node::drawLine()
//{
//	float len = 100.0;
//	std::vector<double> vec;
//	int k = 0;
//	for (double i{}; i < 1; i += (1.0 / len)) {
//		vec.push_back(i);
//		k++;
//	}
//	BezierCurveCubic bc(Point(100, 100), Point(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
//	Point prev(100, 100);
//	Point curr(100, 100);
//	for (size_t i{}; i < len; i++) {
//		curr = bc.interpolate(vec[i]);
//		ImGui::GetWindowDrawList()->AddLine(curr.Vec2(), prev.Vec2(), IM_COL32(255, 0, 0, 255),3.0);
//		prev = curr;
//	}
//
//}


Node::Node()
{	
	Point mouse_temp(100, 100);
	Point size(200, 200);
	this->begin = mouse_temp;
	this->end = mouse_temp + size;
	height = 200;
	width = 200;

}

void Node::draw()
{
	ImGui::GetWindowDrawList()->AddRectFilled(this->begin.Vec2(), this->end.Vec2(), IM_COL32(200, 40, 100, 255),0.1);
}
