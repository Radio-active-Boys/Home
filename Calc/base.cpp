#include "pch.h"
#include "base.h"
#include "imgui.h"

MYDLL_API int Add(int a, int b)
{
    ImGui::Begin("fgui");
    ImGui::End();
    return a + b;
}
