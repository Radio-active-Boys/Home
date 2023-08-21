#pragma once
#include "imgui.h"
#include <vector>
#include  <string>
#include <cstring>
#include <cmath> 
#include <stack>
#include <sstream>
# 


class View {
private: 
	enum all_view {
		view1,
		view2,
	};
public:
	static void show_window();
	static void calculator();
	static void basic_calculator();
	static void sci_calculator();
};