#pragma once
#include "imgui.h"
#include <vector>
#include  <string>
#include <cstring>
#include <cmath> 
#include <stack>
#include <sstream>
<<<<<<< HEAD
#include "Node.h"
=======

#include <iostream>
#include <cctype>


>>>>>>> 125e0ce4344adeb6380acc8aabc89903470acd31
#include <thread> 



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