#include "system_info.h"
#include <array>

SystemInfo::SystemInfo() {
    GetSystemInfo(&systemInfo);
}

std::string SystemInfo::getProcessorArchitecture() const {
    switch (systemInfo.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_INTEL:
        return "Intel x86";
    case PROCESSOR_ARCHITECTURE_AMD64:
        return "AMD x64";
    case PROCESSOR_ARCHITECTURE_ARM:
        return "ARM";
    default:
        return "Unknown";
    }
}

std::string SystemInfo::getProcessorName() const {
    std::array<char, 0x40> buffer;
    DWORD bufferSize = buffer.size();
    RegGetValueA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "ProcessorNameString", RRF_RT_ANY, nullptr, buffer.data(), &bufferSize);
    return std::string(buffer.data());
}

unsigned int SystemInfo::getNumberOfCores() const {
    return systemInfo.dwNumberOfProcessors;
}


