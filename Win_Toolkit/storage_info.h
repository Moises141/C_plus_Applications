#pragma once

#include <string>
#include <vector>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

class StorageInfo {
public:
    std::vector<std::string> getStorageOptions() const;
    std::vector<std::string> getStorageCapacities() const;
};

