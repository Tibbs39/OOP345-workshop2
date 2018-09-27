// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Sept 17, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <string>

namespace w2 {

    class Text {
        std::string name;
        std::string* lines = nullptr;;
        size_t lnCnt = 0;
        
        public:
            // default & 1-arg constructor
            Text(const std::string& = "");
            // destructor
            ~Text();
            //copy constructor
            Text(const Text&);
            //copy assignment
            Text& operator=(const Text&);    
            //move constructor
            Text(Text&&);
            //move assignment
            Text& operator=(Text&&);
            // return size
            size_t size() const;
    };

}

#endif // W2_TEXT_H