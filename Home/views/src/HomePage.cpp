#include "view.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


bool hidden_showPopup = true;



void View::home()
{   

    



    if (hidden_showPopup) {
        ImGui::OpenPopup("What to do?");
    }



    if (ImGui::BeginPopupModal("What to do?", &hidden_showPopup, ImGuiWindowFlags_AlwaysAutoResize)) {
        
        if (ImGui::Button("Mathematics", ImVec2(200, 200))) {
            hidden_showPopup = false;
            View::activeView = all_view::CALCULATOR;

        }


        ImGui::SameLine();


        if (ImGui::Button("Boolean", ImVec2(200, 200))) {
            hidden_showPopup = false;
            View::activeView = all_view::WINDOW;
        }


        if (ImGui::Button("Machine Learning", ImVec2(200, 200))) {
            hidden_showPopup = false;
            View::activeView = all_view::CLASSIFIER;
        }



        ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - 60.0f);
        if (ImGui::Button("Close",ImVec2(60.0f,25.0f))) {
            ConfigGUI::m_status = ConfigGUI::OFF;
        }
        ImGui::EndPopup();
    }




}