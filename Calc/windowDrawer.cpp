#include "pch.h"

#include "windowDrawer.h"



void windowDrawer::createWindow() {
    bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);

	
    ImGui::Begin("Second");
    ImGui:: Text("Hello");
    ImGui::End();

}