

#include "windowDrawer.h"
#include <iostream>
#include <thread>


bool windowDrawer::createWindow() {
    /*bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);*/

	
    ImGui::Begin("First");
	bool clicked = ImGui::Button("Close"); 
    if (clicked) {

        std::thread thread1(mainLoop, 1);
        try {
            thread1.detach();
        }
        catch(const std::exception& a) {
            std::cout << a.what() << std::endl;
        }
        
        return false;
    }
    ImGui::End();
    return true;
    

}