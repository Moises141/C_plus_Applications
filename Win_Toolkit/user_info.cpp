#include "user_info.h"

std::vector<std::wstring> UserInfo::getUserAccounts() const {
    NET_API_STATUS status;
    DWORD entriesRead;
    DWORD totalEntries;
    USER_INFO_0* userInfo;

    status = NetUserEnum(nullptr, 0, FILTER_NORMAL_ACCOUNT, (LPBYTE*)&userInfo,
        MAX_PREFERRED_LENGTH, &entriesRead, &totalEntries, nullptr);

    std::vector<std::wstring> userAccounts;

    if (status == NERR_Success) {
        for (DWORD i = 0; i < entriesRead; i++) {
            userAccounts.push_back(userInfo[i].usri0_name);
        }

        NetApiBufferFree(userInfo);
    }

    return userAccounts;
}