#pragma once

#include <windows.h>
#include <string>


class SystemInfo {
public:
    SystemInfo();
    std::string getProcessorArchitecture() const;
    std::string getProcessorName() const;
    unsigned int getNumberOfCores() const;

private:
    SYSTEM_INFO systemInfo;
};

