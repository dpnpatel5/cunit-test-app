#include "app.h"

// Function implementations
void setBookDetails(Book *book, const char *title, const char *author, int year, int pages) {
	strncpy(book->title, title, sizeof(book->title) - 1);
	book->title[sizeof(book->title) - 1] = '\0'; // Ensure null-termination
	strncpy(book->author, author, sizeof(book->author) - 1);
	book->author[sizeof(book->author) - 1] = '\0'; // Ensure null-termination
	book->publicationYear = year;
	book->pages = pages;
}

void getBookDetails(const Book *book) {
	printf("Title: %s\n", book->title);
	printf("Author: %s\n", book->author);
	printf("Publication Year: %d\n", book->publicationYear);
	printf("Number of Pages: %d\n", book->pages);
}

void printBookDetails(const Book *book) {
	printf("Book Details:\n");
	getBookDetails(book);
}

int add(int a, int b) {
	return a + b;
}

#ifndef CUNIT_ENABLE
int main() {
	int result = add(2, 3);
	printf("2 + 3 = %d\n", result);
	Book myBook;

	// Set book details
	setBookDetails(&myBook, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 180);
	printBookDetails(&myBook);

	// Additional book
	printf("\nAdditional Book Details:\n");
	Book anotherBook;
	setBookDetails(&anotherBook, "To Kill a Mockingbird", "Harper Lee", 1960, 281);
	printBookDetails(&anotherBook);
	return 0;
}
#endif
