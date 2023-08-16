

#include "windowDrawer.h"


bool windowDrawer::createWindow() {
    /*bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);*/

	
    ImGui::Begin("First");
	bool clicked = ImGui::Button("Close"); 
    if (clicked) {
        mainLoop(5);
        return false;
    }
    ImGui::End();
    return true;
    

}