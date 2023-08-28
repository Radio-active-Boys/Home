#include "Node.h"
#include "Coordinate_Math_2D.h"



void Node::drawLine()
{
	float len = 100.0;
	std::vector<double> vec;
	int k = 0;
	for (double i{}; i < 1; i += (1.0 / len)) {
		vec.push_back(i);
		k++;
	}
	BezierCurveCubic bc(Point(100, 100), Point(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
	Point prev(100, 100);
	Point curr(100, 100);
	for (size_t i{}; i < len; i++) {
		curr = bc.interpolate(vec[i]);
		ImGui::GetWindowDrawList()->AddLine(curr.Vec2(), prev.Vec2(), IM_COL32(255, 0, 0, 255),3.0);
		prev = curr;
	}

}

Node::Node()
{	
	height = 200;
	width = 100;
	this->begin =Point(200,200) ;
	this->end = Point(300,400);
	

}

void Node::lock()
{
	this->locked = true;
}

void Node::unlock()
{
	this->locked = true;
}


void Node::draw()
{
	this->move();
	if (!this->is_locked())
		ImGui::GetWindowDrawList()->AddRectFilled(this->begin.Vec2(), this->end.Vec2(), this->colActive,this->nodeRounding);
	else
		ImGui::GetWindowDrawList()->AddRectFilled(this->begin.Vec2(), this->end.Vec2(), this->colInactive,this->nodeRounding);

	ImGui::GetWindowDrawList()->AddRect(this->begin.Vec2(), this->end.Vec2(), this->borderCol,this->borderRounding,0,this->borderThickness);
	
}

void Node::move()
{
	ImVec2 boxPos = this->begin.Vec2();
	ImVec2 mousePos = ImGui::GetMousePos();
	ImVec2 boxSize(this->width, this->height);
	ImVec2 boxMax = ImVec2(boxPos.x + boxSize.x, boxPos.y + boxSize.y);
	bool isHovering = ImGui::IsMouseHoveringRect(this->begin.Vec2(), this->end.Vec2());



	if (isHovering && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
		this->locked = !this->locked;
	}

	if (this->is_locked() && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
		this->locked = true;
	}

	if (!this->is_locked()) {
		boxPos.x += ImGui::GetIO().MouseDelta.x * this->rateOfFloat;
		boxPos.y += ImGui::GetIO().MouseDelta.y * this->rateOfFloat;
	}

	this->begin = Point(boxPos.x, boxPos.y);
	this->end =Point(begin.get_x()+width,begin.get_y()+ height);
}

bool Node::is_locked()
{
	return this->locked;
}
