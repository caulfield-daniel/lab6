#include <iostream>
#include <string>
#include <map>
#include <fstream>

void loadDictionary(std::map<std::string, std::string>& engToRus, std::map<std::string, std::string>& rusToEng) {
    std::ifstream file("dictionary.txt");

    if (file.is_open()) {
        std::string engWord, rusWord;
        while (file >> engWord >> rusWord) {
            engToRus[engWord] = rusWord;
            rusToEng[rusWord] = engWord;
        }
        file.close();
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }
}

void englishToRussian(const std::map<std::string, std::string>& engToRus) {
    std::string word;
    std::cout << "Enter English word: ";
    std::cin >> word;

    if (engToRus.find(word) != engToRus.end()) {
        std::cout << "Translations: " << engToRus.at(word) << std::endl;
    }
    else {
        std::cout << "Translation not found." << std::endl;
    }
}

void russianToEnglish(const std::map<std::string, std::string>& rusToEng) {
    std::string word;
    std::cout << "Enter Russian word: ";
    std::cin >> word;

    if (rusToEng.find(word) != rusToEng.end()) {
        std::cout << "Translations: " << rusToEng.at(word) << std::endl;
    }
    else {
        std::cout << "Translation not found." << std::endl;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    std::map<std::string, std::string> engToRus;
    std::map<std::string, std::string> rusToEng;

    loadDictionary(engToRus, rusToEng);

    int choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. English to Russian" << std::endl;
        std::cout << "2. Russian to English" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            englishToRussian(engToRus);
            break;
        case 2:
            russianToEnglish(rusToEng);
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
