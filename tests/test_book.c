#include <stdio.h>
#include <CUnit/CUnit.h>
#include "app.h"

void test_setBookDetails(void) {
	Book book;
	setBookDetails(&book, "1984", "George Orwell", 1949, 328);

	CU_ASSERT_STRING_EQUAL(book.title, "1984");
	CU_ASSERT_STRING_EQUAL(book.author, "George Orwell");
	CU_ASSERT_EQUAL(book.publicationYear, 1949);
	CU_ASSERT_EQUAL(book.pages, 328);
}

void test_getBookDetails(void) {
	Book book;
	setBookDetails(&book, "Brave New World", "Aldous Huxley", 1932, 311);

	// Redirecting output to a buffer
	char buffer[256];
	FILE *output = fmemopen(buffer, sizeof(buffer), "w");
	if (output == NULL) {
		CU_FAIL("Failed to create output buffer");
		return;
	}
	getBookDetails(&book);
	fclose(output);

	CU_ASSERT_STRING_EQUAL(buffer, "Title: Brave New World\nAuthor: Aldous Huxley\nPublication Year: 1932\nNumber of Pages: 311\n");
}

