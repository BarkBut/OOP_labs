#ifndef LAB1_BOOK_H
#define LAB1_BOOK_H

#include <iostream>
#include <string.h>

class printBook : public Book {
	private:
		int printPages;
		
	public	
	PrintBook(std::string title, std::string author, int pages) : Book(title, author, pages)  // ����� ����� �������� ����� ��������� �������� ��������, �����, ��������
	{
		printPages = pages / 16;
	}
	
	int getPages()
	{
		return printPages;
	}
};
