#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encryptText(const string& inputText) {
    string encryptedText = "";
    for (int index = 0; index < inputText.length(); ++index) {
        int asciiValue = static_cast<int>(inputText[index]);
        char encryptedChar = static_cast<char>(asciiValue + index + 1);
        encryptedText += encryptedChar;
    }
    return encryptedText;
}


string decryptText(const string& encryptedText) {
    string decryptedText = "";
    for (int index = 0; index < encryptedText.length(); ++index) {
        
        int asciiValue = static_cast<int>(encryptedText[index]);
        
        char decryptedChar = static_cast<char>(asciiValue - index - 1);
        decryptedText += decryptedChar;
    }
    return decryptedText;
}

int main() {
    string inputText;
    
    cout << "Enter String = ";
    getline(cin, inputText);
    
    cout << "Normal Text: " << inputText << endl;

    string encryptedText = encryptText(inputText);
    cout << "Encrypted text inserted in file" << endl;

    
    ofstream outFile("encrypted_text.txt");
    if (outFile.is_open()) {
        outFile << encryptedText;
        outFile.close();
    } else {
        cerr << "Error writing to file." << endl;
        return 1;
    }


    ifstream inFile("encrypted_text.txt");
    string encryptedTextFromFile;
    if (inFile.is_open()) {
        getline(inFile, encryptedTextFromFile);
        inFile.close();
    } else {
        cerr << "Error reading from file." << endl;
        return 1;
    }

   
    string decryptedText = decryptText(encryptedTextFromFile);

    cout << "Encrypted text: " << encryptedTextFromFile << endl;
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decryptedText << endl;

    return 0;
}
