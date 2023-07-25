#include <iostream>
#include <cmath>
#include <limits>

// Function to calculate Greatest Common Factor (GCF)
int findGCF(int a, int b) {
    if (b == 0)
        return a;
    return findGCF(b, a % b);
}

// Function to calculate Least Common Multiple (LCM)
int findLCM(int a, int b) {
    return (a * b) / findGCF(a, b);
}

int main() {
    std::cout << "Welcome to the Number Analysis Program!\n";
    std::cout << "This program was made by Mr. C.\n";

    int userInput;
    std::cout << "Please enter an integer number: ";

    // Error handling for invalid input
    while (!(std::cin >> userInput)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer number: ";
    }

    // Check if the number is even or odd
    if (userInput % 2 == 0)
        std::cout << userInput << " is an even number.\n";
    else
        std::cout << userInput << " is an odd number.\n";

    // Calculate and display all possible square root numbers connecting to the input number
    std::cout << "Square roots connecting to " << userInput << " are:\n";
    int maxSquareRoot = static_cast<int>(std::sqrt(userInput));
    for (int i = 1; i <= maxSquareRoot; ++i) {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    // Find GCF and LCM for each of the square roots
    std::cout << "Greatest Common Factor (GCF) and Least Common Multiple (LCM) with each square root:\n";
    for (int i = 1; i <= maxSquareRoot; ++i) {
        int gcf = findGCF(userInput, i);
        int lcm = findLCM(userInput, i);
        std::cout << "With " << i << ": GCF = " << gcf << ", LCM = " << lcm << "\n";
    }

    return 0;
}
