#include "View.h"

using namespace std;
// Function to find precedence of
// operators.
double precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

// Evaluate expression  
double evaluateExpression(const std::string& expression) {

    int i;

    // stack to store integer values.
    stack <double> values;

    // stack to store operators.
    stack <char> ops;

    for (i = 0; i < expression.length(); i++) {

        // Current expression is a whitespace,
        // skip it.
        if (expression[i] == ' ')
            continue;

        // Current expression is an opening
        // brace, push it to 'ops'
        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        // Current expression is a number, push
        // it to stack for numbers.
        else if (isdigit(expression[i])) {
            double val = 0;
            bool decimalArrive = false;
            int j = 0;
            // There may be more than one
    // digits in number.
            while (i < expression.length() &&
                (isdigit(expression[i]) || (expression[i] == '.')))
            {
                if (expression[i] == '.' && !decimalArrive ){
                    i++;
                    decimalArrive = true;
                }
                   if (decimalArrive){ j--;
                    val +=  (expression[i] - '0')*pow(10,j);
                    i++;
                }
                else {
                    val = (val * 10) + (expression[i] - '0');
                    i++;
                }
            }
            values.push(val);

            // right now the i points to
            // the character next to the digit,
            // since the for loop also increases
            // the i, we would skip one
            //  expression position; we need to
            // decrease the value of i by 1 to
            // correct the offset.
            i--;
        }
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            if (!ops.empty())
                ops.pop();
        }
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current expression, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!ops.empty() && precedence(ops.top())
                >= precedence(expression[i])) {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current expression to 'ops'.
            ops.push(expression[i]);
        }
    }
        // Entire expression has been parsed at this
// point, apply remaining ops to remaining
// values.
        while (!ops.empty()) {
            double val2 = values.top();
            values.pop();

           double val1 = values.top();
            values.pop();

            char op = ops.top();
            ops.pop();

            values.push(applyOp(val1, val2, op));
        }

        // Top of 'values' contains result, return it.
    
        return values.top();
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
    float inputTextWidth =(float) (enteredText.length() * 7);
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
                                                                {"7","8","9","*"},
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

                    //char targetChar = '.';
                    //size_t startPos = i;  // Start position
                    //size_t endPos = enteredText.length()-1;   // End position

                    //// Find the targetChar between startPos and endPos
                    //size_t foundPos = text.find(targetChar, startPos);

                    //if (foundPos != std::string::npos && foundPos < endPos) {
                    //    std::cout << "Found '" << targetChar << "' at position " << foundPos << std::endl;
                    //}
                    //else {
                    //    std::cout << "'" << targetChar << "' not found between positions " << startPos << " and " << endPos << std::endl;
                    //}

                    //int i = enteredText.length();
                    
                        if (!(enteredText.find('.') != std::string::npos)) {
                            enteredText += buttonText; //symbols[row][col];

                        
                    }
                }
                else if (enteredText.length() > 0 && operators.find(enteredText.back()) != std::string::npos && operators.find(symbols[row][col].back()) != std::string::npos) {

                }
                else if (row == 4 && col == 3) {
                    result =  evaluateExpression(enteredText) ;
                    enteredText = std::to_string(result);
                }
                else {


                    enteredText += buttonText; //symbols[row][col];


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

