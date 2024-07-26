#include <stdio.h>
#include <string.h>

// Define a structure to hold book information
typedef struct {
    char title[100];
    char author[100];
    int publicationYear;
    int pages;
} Book;

int add(int a, int b);
void setBookDetails(Book *book, const char *title, const char *author, int year, int pages);
void getBookDetails(const Book *book);
void printBookDetails(const Book *book);
