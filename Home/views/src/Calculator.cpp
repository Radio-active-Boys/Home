#include "View.h"


 
// Evaluate expression  
double evaluateExpression(const std::string& expression) {
    

    return  6.0;
}

 


static std::string enteredText = "";
double result = 0.0;

char txt[555] = "";
void View::basic_calculator() {



    //  ImGui::Begin("calculator");

    // ImGuiIO& io = ImGui::GetIO();

    //// ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Scaled Heading").x) * 0.5f);
    // ImGui::Text("Scaled Heading");

    //

    // // Get the current window size
    // ImVec2 currentSize = ImGui::GetWindowSize();

    // // Limit the window size within the defined constraints
    // if (currentSize.x < minSize.x)
    //     currentSize.x = minSize.x;
    // if (currentSize.y < minSize.y)
    //     currentSize.y = minSize.y;
    // if (currentSize.x > maxSize.x)
    //     currentSize.x = maxSize.x;
    // if (currentSize.y > maxSize.y)
    //     currentSize.y = maxSize.y;

    // // Update the window size
    // ImGui::SetWindowSize(currentSize);
    //
    //  // End the window
    //  ImGui::End();




    ImGui::Begin("Basic Calculator");

    ImGuiIO& io = ImGui::GetIO();

    // ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Scaled Heading").x) * 0.5f);
    ImGui::Text("Scaled Heading");

    // Get the current window size
    ImVec2 currentSize = ImGui::GetWindowSize();

    // Limit the window size within the defined constraints
    if (currentSize.x < 400 || currentSize.y < 500) {
        currentSize.x = 400;
        currentSize.y = 500;
    }

    // Update the window size
    ImGui::SetWindowSize(currentSize);


    // Set text color based on the current theme
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_IsSRGB) {
        // Dark theme
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f)); // Dark gray background
    }
    else {
        // Light theme
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.9f, 0.9f, 0.9f, 1.0f)); // Light gray background
    }



    // Display entered text
    // Stores entered text
    ImVec2 windowSize1 = ImGui::GetWindowSize();
    float inputTextWidth = enteredText.length() * 7;
    float posX = (windowSize1.x - 40 - inputTextWidth);
    ImGui::SetCursorPosX(posX);

    ImGui::InputText("##InputText", txt, sizeof(txt), (ImGuiInputTextFlags_EnterReturnsTrue));

    //// Display the entered text using the adjusted font and color
    //ImGui::Text("Entered Text: %s", enteredText);

    //// Pop text color
    ImGui::PopStyleColor();






    // Calculate grid properties
    const int numColumns = 4;
    const int numRows = 5;
    const ImVec2 windowSize = ImGui::GetWindowSize();
    ImVec2 buttonSize(windowSize.x * 0.2f, windowSize.y * 0.1f);

    // Calculate the total width and height occupied by buttons and spacing
    const float totalWidth = (buttonSize.x + ImGui::GetStyle().ItemSpacing.x) * numColumns - ImGui::GetStyle().ItemSpacing.x;
    const float totalHeight = (buttonSize.y + ImGui::GetStyle().ItemSpacing.y) * numRows - ImGui::GetStyle().ItemSpacing.y;

    // Calculate the starting position to center the grid both horizontally and at the bottom
    const float startX = (windowSize.x - totalWidth) * 0.5f;
    const float startY = windowSize.y - totalHeight;

    const std::vector<std::vector<std::string>> symbols = { {"C","%","Back","/"},
                                                                {"7","8","9","x"},
                                                                {"4","5","6","-"},
                                                                {"1","2","3","+"},
                                                                {"00","0",".","="} };

    const std::string operators{ "x%-/+" };

    // Create buttons in a centered grid layout
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numColumns; ++col) {
            // Calculate the position for the current button
            ImVec2 buttonPos(startX + col * (buttonSize.x + ImGui::GetStyle().ItemSpacing.x),
                startY + row * (buttonSize.y + ImGui::GetStyle().ItemSpacing.y));

            // Set the cursor position to position the button
            ImGui::SetCursorPos(buttonPos);

            // Create the button with calculated size
            char buttonText[64];
            strcpy_s(buttonText, symbols[row][col].c_str());





            // Check if the button is pressed and display entered text
            if (ImGui::Button(buttonText, buttonSize)) {
                // Append the entered text to the display
                if (row == 0 && col == 2) {

                    if (enteredText.length() > 0)
                        enteredText.pop_back();

                }
                else if (row == 0 && col == 0) {
                    enteredText = "";

                }
                else if (row == 4 && col == 2) {
                    if (!(enteredText.find('.') != std::string::npos)) {
                        enteredText += buttonText, symbols[row][col];
                    }
                }
                else if (enteredText.length() > 0 && operators.find(enteredText.back()) != std::string::npos && operators.find(symbols[row][col].back()) != std::string::npos) {

                }
                else if (row == 4 && col == 3) {
                    result =  evaluateExpression(enteredText) ;
                    enteredText = std::to_string(result);
                }
                else {


                    enteredText += buttonText , symbols[row][col];


                }
                strcpy_s(txt, enteredText.c_str());

            }
        }
    }
    // End the window
    ImGui::End();



}

void View::sci_calculator() {

    //  ImVec2 minSize(400, 300);
    //  ImVec2 maxSize(800, 600);


    //  ImGui::Begin("calculator");

    // ImGuiIO& io = ImGui::GetIO();

    //// ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Scaled Heading").x) * 0.5f);
    // ImGui::Text("Scaled Heading");

    //

    // // Get the current window size
    // ImVec2 currentSize = ImGui::GetWindowSize();

    // // Limit the window size within the defined constraints
    // if (currentSize.x < minSize.x)
    //     currentSize.x = minSize.x;
    // if (currentSize.y < minSize.y)
    //     currentSize.y = minSize.y;
    // if (currentSize.x > maxSize.x)
    //     currentSize.x = maxSize.x;
    // if (currentSize.y > maxSize.y)
    //     currentSize.y = maxSize.y;

    // // Update the window size
    // ImGui::SetWindowSize(currentSize);
    //
    //  // End the window
    //  ImGui::End();




    ImGui::Begin("sci_calculator");

    ImGuiIO& io = ImGui::GetIO();

    // ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Scaled Heading").x) * 0.5f);
    ImGui::Text("Scaled Heading");



    // Get the current window size
    ImVec2 currentSize = ImGui::GetWindowSize();

    // Limit the window size within the defined constraints

    if (currentSize.x < 400 || currentSize.y < 400) {
        currentSize.x = 400;
        currentSize.y = 400;
    }




    // Update the window size
    ImGui::SetWindowSize(currentSize);

    // End the window
    ImGui::End();




}

