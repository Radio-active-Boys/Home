#include "View.h"

float f = 1.0f;
bool active = false;


auto colorNotSelected = IM_COL32(255, 0, 0, 255);
auto colorSelected = IM_COL32(0, 255, 0, 255);

void View::show_window()
{
	ImGui::Begin("New");

    static ImVec2 boxPos(100, 100);

    ImGui::Text("Drag me!");
    ImGui::Separator();

    // Get mouse position
    ImVec2 mousePos = ImGui::GetMousePos();

    // Calculate the bounding box for the draggable area
    ImVec2 boxSize(100, 100);
    ImVec2 boxMax = ImVec2(boxPos.x + boxSize.x, boxPos.y + boxSize.y);

    // Check if the mouse is within the bounding box
    bool isHovering = ImGui::IsMouseHoveringRect(boxPos, boxMax);

    // If mouse is hovering the box, update its position
    if (isHovering && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
        /*boxPos.x += ImGui::GetIO().MouseDelta.x*f;
        boxPos.y += ImGui::GetIO().MouseDelta.y*f;*/
        active = !active;
    }
    
    if (active) {
        boxPos.x += ImGui::GetIO().MouseDelta.x*f;
        boxPos.y += ImGui::GetIO().MouseDelta.y*f;
    }



    // Draw the box
    if(active)
        ImGui::GetWindowDrawList()->AddRectFilled(boxPos, boxMax, colorSelected);
    else
        ImGui::GetWindowDrawList()->AddRectFilled(boxPos, boxMax, colorNotSelected);

    Node node;
    node.draw();


    //Node::drawLine();
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


