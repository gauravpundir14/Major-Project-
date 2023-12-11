#include <iostream>
#include <fstream>
using namespace std;

void decrypt(string inputFile, string outputFile) {
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
                ch = 'A' + ((ch - 'A' - 1 + 26) % 26);
            } else {
                ch = 'a' + ((ch - 'a' - 1 + 26) % 26);
            }
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();

    cout << "Decryption completed and saved to " << outputFile << endl;
}

int main() {
    string inputFileName = "output_encrypted.txt"; // Change this to the encrypted file name
    string outputFileName = "output_decrypted.txt"; // Change this to your decrypted output file name

    decrypt(inputFileName, outputFileName);

    return 0;
}
