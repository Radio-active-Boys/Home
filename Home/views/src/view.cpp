#include "view.h"

static std::string inputExpression = "";


 
void view::basic_calculator() {

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




    ImGui::Begin("basic_calculator");

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

    // End the window




    // Display buttons with text

    //ImVec2 windowSize = ImGui::GetWindowSize();

   
    //float buttonWidth = windowSize.x * 0.2f;
    //float buttonHeight = windowSize.y * 0.1f;

    //// First row of buttons
    //if (ImGui::Button("1", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("2", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("3", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("+", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}

    //// Second row of buttons
    //ImGui::NewLine(); // Move to a new line
    //if (ImGui::Button("4", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("5", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("6", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("-", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}

    //// third row of buttons
    //ImGui::NewLine(); // Move to a new line
    //if (ImGui::Button("7", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("8", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("9", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("/", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}

    //// third row of buttons
    //ImGui::NewLine(); // Move to a new line
    //if (ImGui::Button("C", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("0", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("=", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}
    //ImGui::SameLine(); // Move to the next position
    //if (ImGui::Button("*", ImVec2(buttonWidth, buttonHeight))) {
    //    // Handle button click
    //}

    //// ... Add more rows of buttons as needed ...

    //// End the window



    // Calculate grid properties
    const int numColumns = 4;
    const int numRows = 5;
    const ImVec2 windowSize = ImGui::GetWindowSize();
    ImVec2 buttonSize(windowSize.x * 0.15f, windowSize.y * 0.1f);

    // Calculate the total width and height occupied by buttons and spacing
    const float totalWidth = (buttonSize.x + ImGui::GetStyle().ItemSpacing.x) * numColumns - ImGui::GetStyle().ItemSpacing.x;
    const float totalHeight = (buttonSize.y + ImGui::GetStyle().ItemSpacing.y) * numRows - ImGui::GetStyle().ItemSpacing.y;

    // Calculate the starting position to center the grid both horizontally and at the bottom
    const float startX = (windowSize.x - totalWidth) * 0.5f;
    const float startY = windowSize.y - totalHeight;

    // Create buttons in a centered grid layout
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numColumns; ++col) {
            // Calculate the position for the current button
            ImVec2 buttonPos(startX + col * (buttonSize.x + ImGui::GetStyle().ItemSpacing.x),
                startY + row * (buttonSize.y + ImGui::GetStyle().ItemSpacing.y));

            // Set the cursor position to position the button
            ImGui::SetCursorPos(buttonPos);

            // Create the button with calculated size
            char buttonText[32];
            snprintf(buttonText, sizeof(buttonText), "Button %d,%d", row, col);
            ImGui::Button(buttonText, buttonSize);
        }
    }

    // ... Add your UI elements here ...

    // End the window

    

    // ... Add your UI elements here ...

    // End the window
   
    ImGui::End();




}

void view::sci_calculator()  {

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

