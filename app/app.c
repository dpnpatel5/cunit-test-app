#include <stdio.h>
#include "app.h"

// Function to be tested
int add(int a, int b) {
    return a + b;
}
#ifndef CUNIT_ENABLE

int main() {
    int result = add(2, 3);
    printf("2 + 3 = %d\n", result);
    return 0;
}
#endif
