#ifndef LAB1_PRINT_BOOK_H
#define LAB1_PRINT_BOOK_H

#include <iostream>
#include <string.h>
#include "book.h"

class PrintBook : public Book {     // класс печатнаяКнига наследует поля и методы обычной Книгги
	private:                       // но у него есть своё приватное поле печатныеСтраницы
		int printPages;
		
    public:
        /*
         * конструктор создает обычную книгу, но
         * страницы бумажной книги в 16 раз больше экрана телефона
         * (ну например)
         */
        PrintBook(std::string title, std::string author, int pages) : Book(title, author, pages)
        {
            printPages = pages/16;
        }

        int getPages(){            // в этом методе мы возвращаем уже другие страницы,
            return printPages;    //поэтому используем новый метод
        }
};

#endif