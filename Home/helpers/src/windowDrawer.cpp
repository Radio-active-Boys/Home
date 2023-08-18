

#include "windowDrawer.h"

#include "main.h"


bool windowDrawer::createWindow() {
    bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);

	
    ImGui::Begin("First");
	bool clicked = ImGui::Button("Close"); 
    ImGui::End();
    if (clicked) {
        try {
            ThreadHandler<int(*)()>::createThreadForNewWindow(mainLoop, "ashu");
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        
        return false;
    }

   
    

    return true;
    
    

}

