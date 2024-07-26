#include "CUnit/Automated.h"
#include "CUnit/AutomatedJUnitXml.h"
#include "CUnit/Basic.h"
#include "CUnit/MessageHandlers.h"
#include "CUnit/Util.h"
#include <stdio.h>

void test_add(void);

/* run at the start of the suite */
int setup_env(void)
{
	/* do intialization if any */
	return CUE_SUCCESS;
}

/* run at the end of the suite */
int cleanup_env(void)
{
	/* do de-intialization if any */
	return CUE_SUCCESS;
}

CU_TestInfo test_array[] = {
	{ "test_add", test_add },
	CU_TEST_INFO_NULL,
};


CU_SuiteInfo suites[] = {
	{ "Set Up the Env ", setup_env, cleanup_env, NULL, NULL, test_array },
	CU_SUITE_INFO_NULL,
};

int main(int argc, char **argv)
{
	CU_ErrorCode error;
	/* initialize the CUnit test registry */
	if (CU_initialize_registry() != CUE_SUCCESS)
		return CU_get_error();
	error = CU_register_suites(suites);
	CU_set_output_filename(CU_get_basename(argv[0]));

	CU_automated_enable_junit_xml(CU_TRUE);
	CCU_automated_add_handlers();
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
