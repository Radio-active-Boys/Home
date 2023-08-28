#include "View.h"

Node newnode{};
void View::show_window()
{
	ImGui::Begin("New");
    
    newnode.draw();


	ImGui::End();



}



//ImGui::GetWindowDrawList()->AddLine(ImVec2(50, 50), ImVec2(150, 50), IM_COL32(255, 0, 0, 255));

    //// Draw a filled rectangle
    //ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(200, 50), ImVec2(300, 150), IM_COL32(0, 255, 0, 255));

    //// Draw a circle
    //ImGui::GetWindowDrawList()->AddCircle(ImVec2(450, 100), 50, IM_COL32(0, 0, 255, 255));

    //// Draw a filled triangle
    //ImGui::GetWindowDrawList()->AddTriangleFilled(ImVec2(550, 50), ImVec2(650, 50), ImVec2(600, 150), IM_COL32(255, 255, 0, 255));

    //// Draw an open polyline
    //ImVec2 points[] = { ImVec2(700, 50), ImVec2(750, 100), ImVec2(800, 50) };
    //ImGui::GetWindowDrawList()->AddPolyline(points, 3, IM_COL32(255, 0, 255, 255), false, 3.0f);

    //// Draw text
    //ImGui::GetWindowDrawList()->AddText(ImVec2(50, 200), IM_COL32(255, 255, 255, 255), "Hello, ImGui Shapes!");


