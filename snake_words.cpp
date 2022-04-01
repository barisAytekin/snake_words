#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

bool checkfunc(vector<vector<char>>& mat, int& row, int& col, int& counter, string word) {  //checks whether the given position in the matrix is eligible or not
    if (row >= mat.size() || col >= mat[0].size() || row < 0 || col < 0) {  // checks if the position is inside the matrix
        return false;
    }
    else if (counter >= word.length() || mat[row][col] != '-') {  //checks whether the given position is vacant or not
        return false;
    }
    else {
        return true;
    }
}

void rfunc(vector<vector<char>>& mat, int& row, int& col, int& counter, string word) { //places a character to the right of the initial position
    int dummy = col + 1;
    if (checkfunc(mat, row, dummy, counter, word)) {
        col++;
        mat[row][col] = word[counter];
        counter++;
    }
}

void lfunc(vector<vector<char>>& mat, int& row, int& col, int& counter, string word) { //places a character to the left of the initial position
    int dummy = col - 1;
    if (checkfunc(mat, row, dummy, counter, word)) {
        col--;
        mat[row][col] = word[counter];
        counter++;
    }
}
void dfunc(vector<vector<char>>& mat, int& row, int& col, int& counter, string word) { //places a character to the bottom of the initial position
    int dummy = row + 1;
    if (checkfunc(mat, dummy, col, counter, word)) {
        row++;
        mat[row][col] = word[counter];
        counter++;
    }
}
void ufunc(vector<vector<char>>& mat, int& row, int& col, int& counter, string word) { //places a character to the top of the initial position
    int dummy = row - 1;
    if (checkfunc(mat, dummy, col, counter, word)) {
        row--;
        mat[row][col] = word[counter];
        counter++;
    }
}
bool wordPlacer(vector<vector<char>>& mat, int& row, int& col, int& counter, string word, string dir, string orient) { //since the matrix parameter is a reference parameter the function will return a boolean value while also doing word placement operations on the matrix
    if (orient == "CW") {
        if (checkfunc(mat, row, col, counter, word)) { // check for the first character of thw word
            mat[row][col] = word[counter]; // place the first character if the conditions are met
            counter++;
            if (dir == "r") { // direction is right

                while (counter < word.length()) { // till the counter surpasses the last index the characters are placed
                    int counter2 = counter;
                    rfunc(mat, row, col, counter, word); 
                    if (counter2 == counter) { //if no character has been placed
                        dfunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            lfunc(mat, row, col, counter, word); //if no character has been placed
                            if (counter2 == counter) {
                                ufunc(mat, row, col, counter, word); //if no character has been placed
                                if (counter2 == counter) { break; } //all possible directions are blocked thus the loop is broken
                            }
                        }
                    }
                }
            }
            if (dir == "d") { // the same steps but beginning with direction "down"
                while (counter < word.length()) {
                    int counter2 = counter;
                    dfunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        lfunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            ufunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                rfunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }


            }
            if (dir == "l") { // the same steps but beginning with direction "left"
                while (counter < word.length()) {
                    int counter2 = counter;
                    lfunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        ufunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            rfunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                dfunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }
            }
            if (dir == "u") { // the same steps but beginning with direction "up"
                while (counter < word.length()) {
                    int counter2 = counter;
                    ufunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        rfunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            dfunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                lfunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }
            }
        }
    }
    if (orient == "CCW") { // the same steps but with orientation reversed
        if (checkfunc(mat, row, col, counter, word)) {
            mat[row][col] = word[counter];
            counter++;
            if (dir == "r") {
                while (counter < word.length()) {
                    int counter2 = counter;
                    rfunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        ufunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            lfunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                dfunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }
            }
            if (dir == "d") {
                while (counter < word.length()) {
                    int counter2 = counter;
                    dfunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        rfunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            ufunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                lfunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }


            }
            if (dir == "l") {
                while (counter < word.length()) {
                    int counter2 = counter;
                    lfunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        dfunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            rfunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                ufunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }
            }
            if (dir == "u") {
                while (counter < word.length()) {
                    int counter2 = counter;
                    ufunc(mat, row, col, counter, word);
                    if (counter2 == counter) {
                        lfunc(mat, row, col, counter, word);
                        if (counter2 == counter) {
                            dfunc(mat, row, col, counter, word);
                            if (counter2 == counter) {
                                rfunc(mat, row, col, counter, word);
                                if (counter2 == counter) { break; }
                            }
                        }
                    }
                }
            }
        }
    }
    if (counter == word.length()) { //if the counter surpasses the length of the word it means all of the letters have been placed
        return true;
    }
    return false; // some of the letters was not possible to place so the word can't be placed
}

int main()
{
    string filename; ifstream fileread;
    cout << "Please enter the name of the file: "; 
    cin >> filename;
    fileread.open(filename.c_str());
    while (fileread.fail()) { // file input check
        cout << "File name is incorrect, please enter again: ";
        cin >> filename;
        fileread.open(filename.c_str());
    }
    string line;
    getline(fileread, line); // read the first line which includes the size of the matrix
    istringstream linereader(line);
    int row, col;
    int rowindex, colindex;
    string word, dir, orient, mustbeempty, lineword;
    int counter; int wordcount;
    linereader >> row >> col; // read the row and column sizes
    if (row > 0 && col > 0) {// row and column size check
        vector<vector<char>> mat(row, vector<char>(col, '-')); // the matrix which will be operated upon
        vector<vector<char>> copymat(row, vector<char>(col, '-')); // copy of the matrix, this will be needed when we need to go to the previous state of the matrix
        while (getline(fileread, line)) { // read the lines starting with line 2
            wordcount = 0;
            istringstream linereader2(line); // this stringstream object will be used to count the words in a line
            while (linereader2 >> lineword) {
                wordcount++;
            }
            if (wordcount != 5) { // check for the number of words
                cout << "Invalid line! Number of values is different than 5." << endl;
            }
            else {
                istringstream linereader3(line); //reading the line for the second timw in order to obtain the necessary input
                linereader3 >> word >> rowindex >> colindex >> dir >> orient;
                if (rowindex < 0 || colindex < 0 || rowindex > row - 1 || colindex > col - 1) { // starting point check
                    cout << "Starting point is out of range! Point: " << rowindex << "," << colindex << endl;
                }
                else if (dir != "r" && dir != "l" && dir != "d" && dir != "u") { // direction check
                    cout << "Invalid input for direction! Direction: " << dir << endl;
                }
                else if (orient != "CW" && orient != "CCW") { // orientation check
                    cout << "Invalid input for orientation! Orientation: " << orient << endl;
                }
                else { // if all of the inputs are valid
                    counter = 0; // counter starts from 0 aka the first index
                    if (wordPlacer(mat, rowindex, colindex, counter, word, dir, orient)) { //if the word was possible to place
                        cout << "\"" << word << "\"" << " was put into the matrix with given starting point: " << rowindex << "," << colindex << " direction: " << dir << " orientation : " << orient << endl;
                        for (int i = 0; i < mat.size(); i++) {
                            for (int k = 0; k < mat[0].size(); k++) { // print the matrix
                                cout << left << setw(8) << mat[i][k];
                            }
                            cout << endl;
                        }
                        copymat = mat; // copy the matrix for later use
                    }
                    else { //if the word was not possible to place
                        cout << "\"" << word << "\"" << " could not be put into the matrix with given starting point: " << rowindex << "," << colindex << " direction: " << dir << " orientation : " << orient << endl;
                        for (int i = 0; i < copymat.size(); i++) {
                            for (int k = 0; k < copymat[0].size(); k++) { // print the copied version of the matrix since the original one contains letters from the word which was not possible to place
                                cout << left << setw(8) << copymat[i][k];             
                                mat = copymat; // change the original matrix to the copied version since the copied one does not include the unnecessary letters
                            }
                            cout << endl;
                        }
                    }

                }
            }
            
        }
    }
    else {
        cout << "Invalid number for row and/or column!"; 
    }
    return 0;
}




