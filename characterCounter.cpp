/**************************************************************************************
** Program name: countLetters.cpp
** Author: Michael Nutt
** Date: 10/10/2019
** Description: Implementation of the main() function for the Character Counter program.
**************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "countLetters.hpp"
#include "outputLetters.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
    const int LETTERS_IN_ALPHABET = 26;
    string fileName;
    ifstream fileIn;
    int charCounts[LETTERS_IN_ALPHABET];
    string currentParagraph;
    string outputParagraph;

    // Initialize 26-element array filled with zeros. Each element represents the number of occurrences of the nth letter in the alphabet.
    // charCounts[0] = occurrences of 'A', charCounts[1] = occurrences of 'B',...
    memset(charCounts, 0, sizeof(charCounts));

    // Prompt user for file name
    cout << "Enter file name: " << endl;
    cin >> fileName;

    // Open the input file as long as the file exists
    do
    {
        fileIn.open(fileName);

        // If the file does not exist, prompt the user for a different name
        if (!fileIn.is_open())
        {
            cout << "File not found. Please try again." << endl;
            cin >> fileName;
        }

        // While the next character is not the end of the input file:
        while (fileIn.peek() != EOF)
        {
            // Count the letters in the file
            count_letters(fileIn, charCounts);

            bool isBlankLine = true;

            // For each letter in charCounts:
            for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
            {
                // If a character exists in the current line
                if (charCounts[i] != 0)
                {
                    // The line is not blank
                    isBlankLine = false;
                }
            }

            // If the line is not blank
            if (!isBlankLine)
            {
                // Create output filestream
                ofstream fileOut;
                output_letters(fileOut, charCounts);
            }
        }

    } while (!fileIn.is_open());

    return 0;
}