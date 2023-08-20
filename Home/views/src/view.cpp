#include "view.h"


bool View::show_window() {
    bool* open = new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);


    ImGui::Begin("First");
    bool clicked = ImGui::Button("Close");
    ImGui::End();
    
    return clicked;
}


