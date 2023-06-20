#include "storage_info.h"
#include <Windows.h>
#include <winioctl.h>
#include <tchar.h>
#include <iostream>

std::string WideCharToMultiByteString(const std::wstring& wideString) {
    int size = WideCharToMultiByte(CP_UTF8, 0, wideString.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string result(size, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wideString.c_str(), -1, &result[0], size, nullptr, nullptr);
    return result;
}

std::vector<std::string> StorageInfo::getStorageOptions() const {
    std::vector<std::string> storageOptions;
    DWORD drives = GetLogicalDrives();
    int driveNumber = 1;
    for (TCHAR i = _T('A'); i <= _T('Z'); i++) {
        if (drives & 1) {
            TCHAR volumeName[MAX_PATH + 1] = { 0 };
            TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
            DWORD serialNumber = 0;
            DWORD maxComponentLen = 0;
            DWORD fileSystemFlags = 0;

            TCHAR drive[] = { i, _T(':'), _T('\\'), _T('\0') };
            if (GetVolumeInformation(drive, volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName))) {
                std::wstring volumePath = drive;
                std::wstring volumeNameString = volumeName;
                std::wstring volumeInfo;
                if (volumeNameString.empty()) {
                    volumeInfo = volumePath + L" - Local Disk " + std::to_wstring(driveNumber);
                }
                else {
                    volumeInfo = volumePath + L" - " + volumeNameString;
                }
                std::string storageOption = WideCharToMultiByteString(volumeInfo);
                storageOptions.push_back(storageOption);
            }
            driveNumber++;
        }
        drives >>= 1;
    }

    return storageOptions;
}

std::vector<std::string> StorageInfo::getStorageCapacities() const {
    std::vector<std::string> capacities;
    // Get the storage capacity of each drive
    for (const auto& drive : getStorageOptions()) {
        ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes;
        if (GetDiskFreeSpaceExA(drive.substr(0, 2).c_str(), &freeBytesAvailable, &totalNumberOfBytes, nullptr)) {
            double totalBytes = static_cast<double>(totalNumberOfBytes.QuadPart);
            std::string capacity;
            if (totalBytes < 1e12) {
                capacity = std::to_string(static_cast<int>(std::round(totalBytes / 1e9))) + " GB";
            }
            else {
                capacity = std::to_string(static_cast<int>(std::round(totalBytes / 1e12))) + " TB";
            }
            capacities.push_back(drive + ": " + capacity);
        }
    }
    return capacities;
}

