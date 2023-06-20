#pragma once

#include <windows.h>
#include <lm.h>
#include <vector>
#include <string>

class UserInfo {
public:
    std::vector<std::wstring> getUserAccounts() const;
};
