

#include "WindowDrawer.h"

View::all_view View::activeView = View::HOME;


bool WindowDrawer::create_window() {

    //bool* open = new bool();
    //*open = true;
    //ImGui::ShowDemoWindow(open);


    if(!View::activeView)
        View::home();
    else if(View::activeView == View::CALCULATOR)
        View::basic_calculator();
    else if (View::activeView == View::WINDOW)
        View::show_window();
    else if (View::activeView == View::CLASSIFIER)
        View::ml_window();
    //View::show_window();
	

    
    return true;


}

