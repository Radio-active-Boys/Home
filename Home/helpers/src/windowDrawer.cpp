

#include "windowDrawer.h"
#include "Main.h"


void windowDrawer::createWindow() {
    bool* open= new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);

	_dll_main();
    ImGui::Begin("PK");
    ImGui::End();
}