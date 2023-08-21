#include "view.h"


bool View::show_window() {
    /*bool* open = new bool();
    *open = true;
    ImGui::ShowDemoWindow(open);*/

    if (ImGui::Begin("Home")) {
        static char search_buffer [300] = ""; 
        bool m_search_button_pressed = false;

       
      
        ImGui::InputText(" ", search_buffer, sizeof(search_buffer));
        ImGui::SameLine(); 

        // Add a search button
        if (ImGui::Button("Search")) {
            m_search_button_pressed = true;
        }

        // Perform search if the button was pressed
        if (m_search_button_pressed) {
            // TODO: Implement your search logic using the search_buffer content
        }
        ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f, 1.0f, 1.0f,1.0f));
        ImGui::SetWindowFontScale(2.0f);
        ImGui::Text("What do you wish to do?");
        ImGui::SetWindowFontScale(1.0f);
        ImGui::PopStyleColor();
    }
       
    ImGui::End();

    
    return true;
}


