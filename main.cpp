#include <iostream>
#include <algorithm>
#include "book.h"

int main() {
    /*
     * Программа запрашивает у пользователя кол-во книг
     * Пользователь вводит кол-во книг с клавиатуры
     * Затем программа предлагает ввести название, автора и кол-во страниц каждой книги
     *
     *
     */

    int number;
    std::cout << "Enter number of books\n";
    std::cin >> number;
    Book* books = new Book[number]();

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

       books[i].setTitle(title);
       books[i].setAuthor(author);
       books[i].setPages(pages);
    }

    std::sort(books, books + number, compare_by_title);

    for(int i = 0; i < number; i++){
        std::cout << i << " "
        + books[i].getTitle() + " "
        + books[i].getAuthor() + " "
        << books[i].getPages() << "\n";
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
