#ifndef LAB1_BOOKSHELF_H
#define LAB1_BOOKSHELF_H
#include "shelf.h"

// Это заголовочный файл класса Книжныйшкаф. Тут будут комментарии только о новых штуках, подробнее см. классы Полка и Книга

const int n = 10;       // постоянное количество полок
    class Bookshelf {
        Shelf shelves[n];      // это поле -- массив 10 элементов типа Полка

    public:
        Bookshelf(Shelf shelves[n]);    // здесь ничего пустым не создается, конструктора по умолчанию нет

        void addBook(unsigned int shelf_number, PrintBook abook); // этот метод добавляет переданную книгу на полку с номером н
        void writeShelf(unsigned int shelf_number);

       // PrintBook getBook(std::string title, std::author);     // этот метод возвращает книгу по названию и автору
       // PrintBook removeBook(std::string title, std::author); // этот метод возвращает книгу, убирая ее оттуда, где она лежит



        ~Bookshelf(); // деструктор
    };


#endif
    