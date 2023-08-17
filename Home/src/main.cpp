// Dear ImGui: standalone example application for DirectX 12
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

// Important: to compile on 32-bit systems, the DirectX12 backend requires code to be compiled with '#define ImTextureID ImU64'.
// This is because we need ImTextureID to carry a 64-bit value and by default ImTextureID is defined as void*.
// This define is set in the example .vcxproj file and need to be replicated in your app or by adding it to your imconfig.h file.

#pragma once

#include "homeGUI.h"


#include "Log.h"

#include <iostream>
#include "ThreadHandler.h"



int main() {

	homeGUI hmgui = homeGUI();

	hmgui.run();

	
	
	


	/*int i{};
	ThreadHandler<int(*)()> handler{};

	for (const auto& threadPair : handler.getAllThreads()) {

		i++;
		const std::string& threadName = threadPair.first;
		const std::thread& thread = threadPair.second;
		ThreadHandler<int(*)()>::destroyThread(threadName);
		Log::log(threadName.c_str());
		
		
	}*/






	return 0;
}
