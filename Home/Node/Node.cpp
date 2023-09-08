#include "Node.h"
#include "Coordinate_Math_2D.h"


#ifdef _DEBUG
#include<iostream>
#endif



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

Node::Node(unsigned int numOfParam, unsigned int input, ImVec2 start, std::vector<std::string> *params)
{	
	unsigned int out = numOfParam - input;
	unsigned int max = input > out ? input : out;
	this->height = max * (this->heightPerParameter);

	//this->activeConnection = nullptr;

	this->begin = Point(start);
	this->numberOfInputParameters = input;


	try {
		if (numOfParam + 1 > params->size())
			throw("Insufficient parameters");
	}
	catch (std::exception) {
	
	}
	this->paramName = *params;
	this->numberOfParameters = numOfParam;
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




	ImVec2 pos = this->begin.Vec2();
	unsigned int font = 18;
	pos.x += this->width / 2 -  font * this->paramName[0].length() / 4;
	ImGui::GetWindowDrawList()->AddText(pos, IM_COL32(0, 0, 0, 255), this->paramName[0].c_str());

	unsigned int verticleOffsetForConnectors = font/2;

	for (size_t i{1}; i <= this->numberOfInputParameters; i++) {
		ImVec2 pos = this->begin.Vec2();
		pos.y +=(float) i * 30*0.8;
		pos.x += this->offsetX;
		ImGui::GetWindowDrawList()->AddText(pos, IM_COL32(0, 0, 0, 255), this->paramName[i].c_str());
		ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(this->begin.get_x(), pos.y+verticleOffsetForConnectors), this->circleRadius, this->colIn);
	}


	for (size_t i{ numberOfInputParameters+1}; i <= this->numberOfParameters; i++) {
		ImVec2 pos = this->begin.Vec2();
		pos.y += (float)(i - numberOfInputParameters ) * 30 * 0.8;
		unsigned int rightOff = font * (this->paramName[i].length() / 4 + 0.5f);
		pos.x += this->width - this->offsetX - rightOff;
		ImGui::GetWindowDrawList()->AddText(pos, IM_COL32(0, 0, 0, 255), this->paramName[i].c_str());
		ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(this->begin.get_x()+this->width, pos.y+verticleOffsetForConnectors), this->circleRadius, this->colOut);
	}
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
		this->shift.x = boxPos.x - mousePos.x;
		this->shift.y = boxPos.y - mousePos.y;
	}

	if (this->is_locked() && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
		this->locked = true;
	}

	if (!this->is_locked()) {
		boxPos.x = mousePos.x + this->shift.x;
		boxPos.y = mousePos.y + this->shift.y;
	}

	this->begin = Point(boxPos.x, boxPos.y);
	this->end =Point(begin.get_x()+width,begin.get_y()+ height);
}

bool Node::is_locked()
{
	return this->locked;
}
