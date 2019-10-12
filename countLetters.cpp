/**************************************************************************************
** Program name: countLetters.cpp
** Author: Michael Nutt
** Date: 10/10/2019
** Description: Implementation file and definition of the count_letters function. The
** count_letters function takes an input file stream and a pointer to an array, reads
** from the file stream, and stores the frequencies of each letter in the array.
**************************************************************************************/

#include <fstream>
#include <iostream>
#include "countLetters.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/* Summary: Gets the next line of a given filestream, converts all characters to uppercase,
 * and counts the occurrence of each character
 * Param: ofstream &inFile -> reference to the input filestream created in the main function
 * Param: int *charCounts -> pointer to the charCounts array used to store the occurrence of each
 * character
 * Return: N/A
 */
void count_letters(ifstream &fileIn, int *charCounts)
{
    string currentParagraph;
    string outputParagraph;

    getline(fileIn, currentParagraph);

    // For each character in the current line:
    for (int i = 0; i < currentParagraph.length(); i++)
    {
        // Convert each character to upper and concatinate to the output
        outputParagraph += toupper(currentParagraph[i]);
    }

    // For each character in the current line:
    for (int i = 0; i < outputParagraph.length(); i++)
    {
        // Increment the corresponding index in charCounts
        charCounts[((outputParagraph[i]) - 'A')]++;
    }
}