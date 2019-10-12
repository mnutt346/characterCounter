/**************************************************************************************
** Program name: outputLetters.cpp
** Author: Michael Nutt
** Date: 10/10/2019
** Description: Implementation file and definition of the output_letters function. The
** output_letters function takes an outpuy filestream and a pointer to an array,
** iterates through the array and writes the values to an output file.
**************************************************************************************/

#include <fstream>
#include <iostream>
#include "outputLetters.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

/* Summary: Prompts the user for the name of an output file and writes the values of the given
 * array to the newly-created file.
 * Param: ofstream &outFile -> reference to the output filestream created in the main function
 * Param: int *charCounts -> pointer to the charCounts array used to store the occurrence of each
 * character
 * Return: N/A
 */
void output_letters(ofstream &outFile, int *charCounts)
{
    const int LETTERS_IN_ALPHABET = 26;
    string outFileName;

    cout << "Please enter a name for the output file: " << endl;
    cin >> outFileName;
    // Open output filestream
    outFile.open(outFileName);

    for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
    {
        // currentLetter = ASCII code for the current index starting from 'A'
        char currentLetter = (i + 65);
        // Write output to file
        outFile << currentLetter << ": " << charCounts[i] << endl;
    }

    // Reset counts for each letter to 0 for the next paragraph
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
    {
        charCounts[i] = 0;
    }

    // Close the current output filestream
    outFile.close();
}