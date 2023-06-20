#include <iostream>
#include <string>
#include <cstdlib> // Added for system("cls") function
#include "system_info.h"
#include "user_info.h"
#include "graphics_info.h"
#include "storage_info.h"

int main()
{
    try {

        std::string userInput;
        std::cout << "Would you like to see system information? (y/n): ";
        std::getline(std::cin, userInput);

        if (userInput == "y" || userInput == "Y") {
            // Clear the screen
            system("cls");

            SystemInfo systemInfo;
            std::string programBuild = "1.0.0";
            std::string Name = "Moises Beleche";

            std::cout << "Created by: " << Name << '\n';
            std::cout << "Program Build: " << programBuild << '\n';

            std::cout << "Processor Architecture: " << systemInfo.getProcessorArchitecture() << '\n';
            std::cout << "Processor Name: " << systemInfo.getProcessorName() << '\n';
            std::cout << "Number of Cores: " << systemInfo.getNumberOfCores() << '\n';

            UserInfo userInfo;
            auto userAccounts = userInfo.getUserAccounts();
            std::cout << "User Accounts:\n";
            for (const auto& account : userAccounts) {
                std::wcout << account << '\n';
            }

            GraphicsInfo graphicsInfo;
            std::wcout << L"Graphics Card: " << graphicsInfo.getGraphicsCardInformation() << '\n';
            std::cout << "Graphics Card VRAM: " << graphicsInfo.getVRAM() << " GB\n";

            StorageInfo storageInfo;
            auto storageCapacities = storageInfo.getStorageCapacities();
            std::cout << "Storage Capacities:\n";
            for (const auto& capacity : storageCapacities) {
                std::cout << capacity << '\n';
            }

            // Add more features here
        }
        else {
            return 0; // Close the program
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "An error occurred: " << ex.what() << '\n';
        return 1; // Return a non-zero value to indicate an error
    }
    std::cin.get();
    return 0;
}







