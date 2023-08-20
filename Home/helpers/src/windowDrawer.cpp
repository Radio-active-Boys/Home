

#include "WindowDrawer.h"

 


bool windowDrawer::createWindow() {

    //bool* open = new bool();
    //*open = true;
    //ImGui::ShowDemoWindow(open);


 
    view::sci_calculator();
    view::basic_calculator();
	
	

    View::show_window();
    return true;


}

