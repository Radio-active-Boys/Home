#pragma once
#include "imgui.h"
#include <vector>
#include  <string>
class  View {
private: 
	enum all_view {
		view1,
		view2,
	};
public:
	static bool show_window();
};