// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Sept 17, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace w2;
using namespace std;

// default & 1-arg constructor
Text::Text(const string& file) {
    if (!file.empty()) { // check empty string
        ifstream fin(file); // open file
        if (fin.good()) { // does file exist?
            // copy name of file
            name.assign(file);
            // check number of lines in file
            size_t ln_cnt = 0;
            while (!fin.eof()) {
                std::string line;
                getline(fin, line);
                ++ln_cnt;
            }

            // allocate new array based on ln_cnt
            lines = new std::string[ln_cnt];
            
            fin.close();

            // copy lines into array
            fin.open(file);
            for (size_t i = 0; i < ln_cnt; i++) {
                getline(fin, lines[i]);
            }
            lnCnt = ln_cnt;
            fin.close();
        }
    } 
}

// destructor
Text::~Text() {
    delete [] lines;
}

//copy constructor
Text::Text(const Text& other) {
    *this = other;
}

//copy assignment
Text& Text::operator=(const Text& other) {
    if (this != &other) {
        // shallow copy
        lnCnt = other.lnCnt;
        name.assign(other.name);

        // deep copy
        delete [] lines;
        lines = new std::string[lnCnt];
        for (size_t i = 0; i < lnCnt; i++) {
            lines[i] = other.lines[i];
        }
    }

    return *this;
}

//move constructor
Text::Text(Text&& other) {
    *this = std::move(other);
}
//move assignment
Text& Text::operator=(Text&& other) {
    if (this != &other) {
        // shallow copy
        lnCnt = other.lnCnt;
        name.assign(other.name);
        // transfer ownership of addresses
        delete [] lines; // delete the original
        lines = other.lines;
        other.lines = nullptr;
    }

    return *this;
}

size_t Text::size() const {
    return lnCnt;
}