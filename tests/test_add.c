#include <stdio.h>
#include <CUnit/CUnit.h>

void test_add(void) {
    CU_ASSERT(add(2, 3) == 5);
    CU_ASSERT(add(-1, 1) == 0);
    CU_ASSERT(add(0, 0) == 0);
}

