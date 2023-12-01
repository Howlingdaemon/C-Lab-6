#include <iostream>
#include <fstream>

int binaryToDecimal(const std::string& binary) {
    int decimal = 0;

    for (char digit : binary) {
        if (digit == '0') {
            decimal = decimal * 2;
        }
        else if (digit == '1') {
            decimal = decimal * 2 + 1;
        }
        else {
            std::cout << "Bad digit on input." << std::endl;
            return -1;
        }
    }

    return decimal;
}

int main() {
    std::ifstream inputFile("BinaryIn.dat");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    std::cout << "Binary\t\tDecimal" << std::endl;
    std::cout << "-------------------------" << std::endl;

    while (!inputFile.eof()) {
        char ch;
        std::string binaryNumber;

        // Read characters until newline
        while ((ch = inputFile.get()) != '\n' && !inputFile.eof()) {
            // Skip spaces
            if (ch != ' ' && ch != '_') {
                binaryNumber.push_back(ch);
            }
        }

        // Convert binary to decimal and output
        int decimalNumber = binaryToDecimal(binaryNumber);
        if (decimalNumber != -1) {
            std::cout << binaryNumber << "\t\t" << decimalNumber << std::endl;
        }
    }

    inputFile.close();

    return 0;
}