

#include "windowDrawer.h"
#include <thread>


bool windowDrawer::createWindow() {
    /*bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);*/

	
    ImGui::Begin("First");
	bool clicked = ImGui::Button("Close"); 
    if (clicked) {
        std::thread thread1(mainLoop, 1);
        thread1.detach();
        return false;
    }
    ImGui::End();
    return true;
    

}