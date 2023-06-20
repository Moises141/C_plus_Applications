#pragma once

#include <windows.h>
#include <string>


class GraphicsInfo {
public:
    std::wstring getGraphicsCardInformation() const;
    int getVRAM();
};


