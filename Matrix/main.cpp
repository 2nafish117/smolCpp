#include "SquareMat.h"
#include "Tests.h"

using namespace tf;

s32 main()
{
	SquareMat m;


	for(u32 test = 0;test < NUM_TESTS;++test)
	{
		SquareMat_Create(&m, tests_dim[test]);
		SquareMat_Fill(&m, tests[test], tests_dim[test] * tests_dim[test]);

		//SquareMat_Print(&m);

		f32 det = SquareMat_Determinant(&m);

		printf("Test %u %s\n", test, det == tests_sol[test] ? "Passed" : "Failed");

		//printf("det = %f\n", det);
	}

    return 0;
}