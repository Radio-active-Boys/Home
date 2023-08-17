

#include "windowDrawer.h"




bool windowDrawer::createWindow() {
    /*bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);*/

	
    ImGui::Begin("First");
	bool clicked = ImGui::Button("Close"); 
    
    ImGui::End();
    if (clicked)return false;
    return true;
    

}