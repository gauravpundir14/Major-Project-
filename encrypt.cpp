#include <iostream>
#include <fstream>
using namespace std;

void encrypt(string inputFile, string outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = 'A' + ((ch - 'A' + 1) % 26);
            } else {
                ch = 'a' + ((ch - 'a' + 1) % 26);
            }
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();

    cout << "Encryption completed and saved to " << outputFile << endl;
}

int main() {
    string inputFileName = "input.txt"; 
    string outputFileName = "output_encrypted.txt";

    encrypt(inputFileName, outputFileName);

    return 0;
}
