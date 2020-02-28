//
// Created by k3l on 21.02.2020.
//

#ifndef LAB1_BOOK_H
#define LAB1_BOOK_H

#include <iostream>

class Book {
    std::string title;
    std::string author;
    int pages;
    int mark;

public:

    Book(std::string title, std::string author, int pages);
    Book(){};
    int getPages();
    int getMark();
    void setMark(int mark);
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setPages(int pages);
    std::string getTitle();
    std::string getAuthor();
    ~Book();


};


#endif //LAB1_BOOK_H
