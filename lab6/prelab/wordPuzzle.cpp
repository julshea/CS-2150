//Filename: wordPuzzle.cpp
//Julia Shea - jts6mq - lab6 - 10/20/2019

/**
The big-theta running time of my word search program is linear, because the worst case scenario would be that every word hashes to the same bucket in my vector data structure, in which case one would have to iterate through every spot in the underlying list data structure to get to the right element (and this is linear time).
 

Actual running time with words.txt:
3x3: 7.8 x 10^-5 seconds.
4x7: 0.00037 seconds.
50x50: 0.327231 seconds.
140x70: 1.22292
Actual running time with words2.txt:
300x300: 2.36317 seconds.
 **/

#include "hashTable.h"
#include "timer.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

//forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
int getNextPrime(unsigned int n);
bool checkPrime(unsigned int p);

int main(int argc, char *argv[]){

  //variables for storing the dictionary in a hashtable
  string line;
  int tableSize = 0;
  string longestWord;

  //variables for manipulating and printing the grid file
  int rows, cols;
  int numWordsFound = 0;
  string direction;
  string finalWordsCoordinates;
  
  //timer variable
  timer t;
  int totalTimeMilliseconds;

  //read in the dictionary file and inserts it into a hashtable
  ifstream dictionary (argv[1]);
  //first iteration through dictionary, calculates size for array
  if (dictionary.is_open()){
    //getline(dictionary, longestWord);
    longestWord = "w";
    while(getline(dictionary, line)){
      if(line.length() >= longestWord.length()){
	 longestWord = line;
      }
    tableSize++;
    }
  }
  dictionary.close();

  hashTable *h = new hashTable(tableSize*5);

  ifstream dictionaryAdd (argv[1]);
    //second iteration through dictionary, adds all words to hashtable
  if (dictionaryAdd.is_open()){
     while(getline(dictionaryAdd, line)){
       h->insert(line);
     }
     dictionaryAdd.close();
  }
  //displays appropriate error message if dictionary doesn't open
  else {cout << "Unable to open dictionary file."<< endl;}

  
  //error checking before iterating through grid file
  bool result = readInGrid (argv[2], rows, cols);
    if ( !result ) { // if there is an error, report it
        cout << "Error reading in file!" << endl;
        exit(1);
    }

    
   //nested for loop to iterate through the grid and find english words
    t.start();
    for(int row = 0; row < rows; row++){
      for(int column = 0; column < cols; column++){
	for(int dir = 0; dir < 8; dir++){
	  for(int length = 3; length < longestWord.length(); length++){
	    string word = getWordInGrid(row, column, dir, length, rows, cols);
	    if(word.length() < length){break;}
	    if(h->contains(word)){
	      numWordsFound++;
	      if (dir == 0){
		direction = "N";
	      }
	      if (dir == 1){
		direction = "NE";
	      }
	      if (dir == 2){
		direction = "E";
	      }
	      if (dir == 3){
		direction = "SE";
	      }
	      if (dir == 4){
		direction = "S";
	      }
	      if (dir == 5){
		direction = "SW";
	      }
	      if (dir == 6){
		direction = "W";
	      }
	      if (dir == 7){
		direction = "NW";
	      }
	        stringstream stream;
		stream << direction << " (" << row << ", " << column << "): " << word<< endl;
		finalWordsCoordinates += stream.str();
	      }
	  }
	}
      }
    }
    t.stop();
    double runTime = t.getTime();
    cout << finalWordsCoordinates;
    cout << numWordsFound << " words found." << endl;
    cout << "Found words in: " << runTime << " seconds."<< endl;

    totalTimeMilliseconds = t.getTime() * 1000;
    //cout << totalTimeMilliseconds << endl;

    return 0;
  
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; 
}
