#pragma once
#include "imgui.h"
#include <vector>
#include  <string>
#include <cstring>
#include <cmath> 
#include <stack>
#include <sstream>

#include "Node.h"

#include "Config.h"
#include <iostream>
#include <cctype>

#include <filesystem>
#include "homeGUI.h"

#include <thread> 



class View {
private: 
	
public:

	enum all_view {
		HOME,
		CALCULATOR,
		WINDOW,
		CLASSIFIER
	};

	static all_view activeView;
	static void show_window();
	static void home();
	static void basic_calculator();
	static void sci_calculator();
	static void ml_window();
};
