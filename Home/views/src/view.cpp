#include "View.h"

std::vector<std::string> params{"Node","In", "Out", "Process","Hi","Hello","Kaha"};
Node newnode{6,3,ImVec2(100,100),&params};
std::vector<std::string> params1{"AND", "A", "B", "Out"};
Node ad{ 3,2,ImVec2(100,100),&params1 };
void View::show_window()
{
	ImGui::Begin("New");
    
    newnode.draw();
    /*ad.draw();
    Node::drawLine();*/

	ImGui::End();



}

