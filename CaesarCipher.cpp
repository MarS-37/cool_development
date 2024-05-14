//+------------------------------------------------------------------+
//|                                                                  |
//|                 Пример реализации шифра цезаря                   |
//|                                                                  |
//+------------------------------------------------------------------+


#include <iostream>
#include <string>
#include <cstring>

class CaesarCipher {
public:
    // Метод для шифрования std::string
    std::string encrypt(const std::string &input, int shift) {
        std::string result = input;
        shift = shift % 26; // Ограничение смещения до 26

        for (char &c : result) {
            if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' + shift) % 26;
            } else if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + shift) % 26;
            }
        }
        return result;
    }

    // Метод для шифрования char*
    void encrypt(char* str, int shift) {
        shift = shift % 26; // Ограничение смещения до 26
        int length = std::strlen(str);

        for (int i = 0; i < length; ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = 'A' + (str[i] - 'A' + shift) % 26;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = 'a' + (str[i] - 'a' + shift) % 26;
            }
        }
    }
};

int main() {
    CaesarCipher cipher;
    int shift;

    std::cout << "Enter shift amount: ";
    std::cin >> shift;
    std::cin.ignore(); // Игнорируем оставшийся символ новой строки

    std::string inputString;
    std::cout << "Enter a std::string: ";
    std::getline(std::cin, inputString);
    std::string encryptedString = cipher.encrypt(inputString, shift);
    std::cout << "Encrypted std::string: " << encryptedString << std::endl;

    char inputCStr[100];
    std::cout << "Enter a C-style string: ";
    std::cin.getline(inputCStr, 100);
    cipher.encrypt(inputCStr, shift);
    std::cout << "Encrypted C-style string: " << inputCStr << std::endl;

    return 0;
}
