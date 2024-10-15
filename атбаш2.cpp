#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

std::string atbash(const std::string& inputString) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string reversedAlphabet = std::string(alphabet.rbegin(), alphabet.rend());
    std::string upperAlphabet = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
    std::string reversedUpperAlphabet = std::string(upperAlphabet.rbegin(), upperAlphabet.rend());

    std::unordered_map<char, char> translationMap;

    for (size_t i = 0; i < alphabet.size(); ++i) {
        translationMap[alphabet[i]] = reversedAlphabet[i];
        translationMap[upperAlphabet[i]] = reversedUpperAlphabet[i];
    }

    std::string translatedString;
    for (char character : inputString) {
        if (translationMap.find(character) != translationMap.end()) {
            translatedString += translationMap[character];
        }
        else {
            translatedString += character; 
        }
    }

    return translatedString;
}

int main() {
    std::cout << atbash("Helloy new word") << std::endl;
    return 0;
}