#include "shelf.h"
#include <vector>
#include <exception>

// Это файл с исходным кодом. Он содержит определение того, что мы обьявляли в заголовочном файле shelf.h

/*
 * Определение конструктора
 * Имя_класса::Конструктор(принимаемые на вход параметры номер и размер): поле_класса(переданный параметр)
 * много дублируется названий, но означают они разные структуры!
 */

Shelf::Shelf(unsigned int shelf_number, unsigned int shelf_size) : shelf_number(shelf_number),
                                                                   shelf_size(shelf_size) {}

void Shelf::setNumber(unsigned int number) {       // этот метод присваивает полке номер
    this->shelf_number = number;                  // this является указателем на ту полку, для которой вызвали метод
    // поле_текущей_полки = переданное значение
}


void Shelf::setSize(unsigned int size) {      // этот метод присваивает полке размер
    this->shelf_size = size;                 // все как в предыдущем методе
}


void Shelf::addBook(PrintBook new_book) {           // этот метод добавляет книгу на полку
    if (books_list.size() < this->shelf_size) {           // проверка того, что вектор книг не больше размера полки
        this->books_list.push_back(new_book);     // push back добавляет элемент в конец списка
    } else std::cout << "На полке нет места для новой книги\n";
}



/*
 * метод ниже выводит содержимое полки
 * в нем есть цикл, который перебирает все элементы вектора
 * for (класс экземпляр_класса : вектор экземпляров класса)
 * при этом вектору не важно, что именно в нем лежит
 * для вывода используем метод класса PrintBook, выводящий книгу
 */
void Shelf::writeShelf() {
    for (PrintBook wbook : books_list) {
        wbook.writeBook();
    }
}

unsigned int Shelf::getNumber() {        // этот метод возвращает номер заданной полки
    return this->shelf_number;
}

unsigned int Shelf::getSize() {      // этот метод возвращает размер заданной полки
    return this->shelf_size;
}


bool Shelf::findBook(std::string title, std::string author) { // этот метод проверяет, есть ли книга с таким названием
    // и автором на полке
    for (int i = 0; i < books_list.size(); i++) {              // цикл перебирает все места на полке
        if ((title == books_list[i].getTitle()) &&          // и сравнивает книгу
        (author == books_list[i].getAuthor()))
        {           // с каждого места с искомой книгой
            return true; // если нашли
        }
    }
    return false; // если нет
}

/*
 * ура, сейчас нам пригодится та страшная штука, которую мы писали в Book
 * переопределение оператора ==
 * засчет этого, метод ниже чуть менее страшный, чем другие методы в этом файле :..)
 */

int Shelf::getPlace(PrintBook gbook) {           // этот метод возвращает место на полке для книги gbook
    for (int i = 0; i < books_list.size(); i++) {  // перебираем все места по порядку
        if (gbook == books_list[i])            // сравниваем наш gbook с книгой на i-том месте
            return i;                        // при равенстве возвращаем i-тое место
    }
    return -1;  // если ничего не нашли, возвращаем -1 (потом станет ясно, зачем)
}


PrintBook Shelf::getBook(std::string title, std::string author) { // эта функция очень похожа на findBook, но она
    for (int i = 0; i < books_list.size(); i++) {                   // возвращает книгу, а не просто да или нет
        if ((title == books_list[i].getTitle()) &&
        (author == books_list[i].getAuthor()))
        {
            return books_list[i];
        }
    }
    throw std::domain_error("Книга не найдена"); // если книги нет, используем исключение
}

/*
 * исключение -- специальная команда, возвращаемая функцией,
 * если что-то пошло не так и функция не знает, что ей вернуть
 * она возвращает исключение туда, где её вызвали
 * там должна быть написана обработка этого исключения,
 * т е че делать в этой ситуации
 * исключения защищают программу от неправильного ввода данных
 * я больше не могу помогите
 * но вроде понятно
 */

PrintBook Shelf::getBook(unsigned int place) {       // тоже getBook, но уже по месту на полке
    if (place < books_list.size()) {                 // проверяем, не выходит ли переданное место за границы полки
        return books_list[place];                  // возвращаем книгу, лежащую на переданном месте
    }
    throw std::domain_error("Нет такого места на полке"); // снова исключение -- только теперь у нас
    // неправильное место
}


void Shelf::putBook(PrintBook afterbook, PrintBook putbook) {    // этот метод ставит книгу после заданной книги
    if (this->shelf_size == this->books_list.size()) {    // проверяет, есть ли место на полке
        std::cout << "На полке нет места для новой книги\n";
        return;                                             // если места нет, сообщает об этом и завершается
    }
    int place = this->getPlace(afterbook);    // в переменной place сохраняем позицию той книги, после которой добавляем
    if (place == -1) {                        // значение -1 будет в place, если afterbook отсутствует на этой полке
        this->books_list.push_back(putbook); // в таком случае книга просто добавится в конец
    } else {
        this->books_list.insert(books_list.begin() + place + 1, putbook);  // если же все ок, место есть и afterbook тоже есть,
        // то книга добавляется после afterbook
        // на место, равное сумме первого места в векторе (begin)
        // + место afterbook'а + 1 т к ставим после afterbook'a
    }
}


void Shelf::removeBook(unsigned int rbook_place) {      // этот метод убирает книгу на заданном месте с полки
    if (rbook_place >= books_list.size()) {        // проверяем, не выходит ли место книги за пределы полки
        return;                               // если да, то выходим, ничего не делая
    }                                                  // если вы читаете это, я вас уважаю
    books_list.erase(books_list.begin() + rbook_place); // если все ок, командой erase удаляем книгу с места
    // которое отсчитываем от начала полки
}


Shelf::~Shelf() {}                   // деструктор -- удаляет всю полку. Он сам знает, как.)

