#include <iostream>
#include "book.h"

int main() {
    /*
     * Программа запрашивает у пользователя кол-во книг
     * Пользователь вводит кол-во книг с клавиатуры
     * Затем программа предлагает ввести название, автора и кол-во страниц каждой книги
     *
     */

    int number;
    std::cout << "Enter number of books\n";
    std::cin >> number;
    Book* book = new Book[number]();

    for (int i = 0; i < number; i++){
        std::string title;
        std::string author;
        int pages;

        std::cout << "Enter title\n";
        std::cin >> title;
        std::cout << "Enter author\n";
        std::cin >> author;
        std::cout << "Enter number of pages\n";
        std::cin >> pages;

       book[i].setTitle(title);
       book[i].setAuthor(author);
       book[i].setPages(pages);
    }

    for(int i = 0; i < number; i++){
        std::cout << i << " "
        + book[i].getTitle() + " "
        + book[i].getAuthor() + " "
        << book[i].getPages() << "\n";
    }

//    // class-style создание объекта
//    Book book1("Atlas shruggled", "A. Ryend", 1000);
//    // struct-style создание объекта
//    Book book2 = {"A", "B", 10};
//    // Создание объекта в динамической памяти
//    Book* book3 = new Book("C++", "Stroustrup", 2000);
//    // Удаление
//    delete book3;
//    // Создание нового объекта
//    book3 = new Book("new book", "Daria Dontsova", 1000000);
//    // Удаление
//    delete book3;
//    // Создание статического массива (благодаря тому, что у нас есть конструктор по умолчанию
//    // aka конструктор который ничего не делает)
//    Book book[10];
//    // Создание динамического массива (благодаря тому, что у нас есть конструктор по умолчанию
//    // aka конструктор который ничего не делает)
//    Book* books = new Book[10]();
//    // Удаление динамического массива
//    delete [] books; void setAuthor(std::string author);
//
//    {
//        Book book1("X", "Y", 123);
//        Book* book2 = new Book("Z", "Q", 543);
//    }
//
//    int i;
//    std::cin >> i;
//============================================================================================
    
// Пример работы экземпляра класса printBook
    
//Book P

  
    return 0;
}
