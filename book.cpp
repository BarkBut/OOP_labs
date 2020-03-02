//
// Created by k3l on 21.02.2020.
//

#include "book.h"

Book::Book(std::string title, std::string author, int pages): title(title),
                                                              mark(0),
                                                              author(author){
    this->pages = pages;
    if (pages < 0){
        std::cout<<"wrong pages value\n";
        this->pages = 0;
    }

}

int Book::getPages(){
    return pages;
}

int Book::getMark() {
    return mark;
}

std::string Book::getAuthor() {
    return author;
}

std::string Book::getTitle() {
    return title;
}

void Book::setMark(int mark) {
    if ((mark > 0) && (mark <= this->pages)) {
        this->mark = mark;
    }
    std::cout << "wrong bookmark\n";
}

Book::~Book() {
    std::cout << this <<" I'm dying " << this->title << "\n";
}

void Book::setTitle(std::string title) {
    this->title = title;

}

void Book::setAuthor(std::string author) {
    this->author = author;

}

void Book::setPages(int pages) {
    this->pages = pages;

}

void Book::printBook(){
std::cout << getTitle() << std::endl << getAuthor() << std::endl << getPages() << std::endl;
}

bool compare_by_title(Book &book1, Book &book2){
    return book1.getTitle() < book2.getTitle();
}





