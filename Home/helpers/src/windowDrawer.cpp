

#include "windowDrawer.h"



void windowDrawer::createWindow() {
    bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);

	
    ImGui::Begin("PK");
    ImGui::End();
}