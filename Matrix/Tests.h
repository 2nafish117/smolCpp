#pragma once

#define NUM_TESTS 6

u32 test1_dim = 3;
f32 test1[9] = {
    10, 0, -3,
    -2, -4, 1,
    3, 0, 2
};

u32 test2_dim = 2;
f32 test2[4] = {
    3, 8, 
    4, 6
};

u32 test3_dim = 3;
f32 test3[9] = {
    1, 3, 1,
    2, -6, -3,
    4, -9, 3
};

u32 test4_dim = 1;
f32 test4[1] = {
    1.0
};

u32 test5_dim = 3;
f32 test5[9] = {
    1.0, 0, 0,
    0, 1, 0,
    0, 0, 1
};

u32 test6_dim = 4;
f32 test6[16] = {
    3, 2, -1, 4,
    2, 1, 5, 7,
    0, 5, 2, -6,
    -1, 2, 1, 0
};

f32* tests[NUM_TESTS] = {test1, test2, test3, test4, test5, test6};
u32 tests_dim[NUM_TESTS] = {test1_dim, test2_dim, test3_dim, test4_dim, test5_dim, test6_dim};
f32 tests_sol[NUM_TESTS] = {-116.0, -14.0, -93.0, 1.0, 1.0, -418};