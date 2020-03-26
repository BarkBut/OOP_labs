#include "book.h"

// Это файл с исходным кодом. Он содержит определение того, что мы обьявляли в заголовочном файле book.h

/*
 * Определение конструктора
 * Имя_класса::Конструктор(принимаемые на вход параметры номер и размер): поле_класса(переданный параметр)
 * много дублируется названий, но означают они разные структуры /\
 * очень непонятно, по крайней мере мне сначала,
 * но это рили удобно
 * закладка всегда равна нулю по умолчанию, если не передали ее значение при создании книги
 */

Book::Book(std::string title, std::string author, unsigned int pages) : title(title),
                                                                        mark(0),
                                                                        author(author) {
    this->pages = pages;
}

// конструктор по умолчанию (создающий пустую книгу) уже определён в заголовочном файле {}

unsigned int Book::getPages() {          // этот метод возвращает количество страниц заданной книги
    return pages;
}

unsigned int Book::getMark() {          // этот метод возвращает страницу закладки заданной книги
    return mark;
}

std::string Book::getAuthor() {         // этот метод возвращает автора заданной книги
    return author;
}

std::string Book::getTitle() {          // этот метод возвращает название заданной книги
    return title;
}

void Book::setMark(unsigned int mark) {          // этот метод устанавливает закладку на заданной странице
    if (mark <= this->pages) {                  // проверяет, не выходит ли закладка за границы книги
        this->mark = mark;
    } else std::cout << "wroong bookmaark\n"; // если выходит, пишет это
}

void Book::setTitle(std::string title) {        // этот метод добавляет книге название
    this->title = title;
}

void Book::setAuthor(std::string author) {      // этот метод добавляет книге автора
    this->author = author;
}

void Book::setPages(unsigned int pages) {       // этот метод устанавливает количество страниц
    this->pages = pages;
}

void Book::writeBook() {     // этот метод выводит книгу на экран
    std::cout << getTitle() << ",   " << getAuthor() << ",   " << getPages() << std::endl;
}


bool Book::operator==(const Book &rhs) const {
    return ((title == rhs.title) &&            // проверка совпадения названий
            (author == rhs.author) &&         // проверка совпадения авторов
            (pages == rhs.pages));           // проверка совпадения количества страниц
    // если все поля одинаковые, то книги совпадают, возвращается true, иначе false
}

Book::~Book() {}


// деструктор





