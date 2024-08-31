#include "test.h"
#include<iostream>
#include<cassert>
#include "math.h"

using std::cout;
using std::endl;

void TestNameSpace::TestExample(){
    struct TestCase{
        double a;
        double b;
        double c;
        double x_1;
        double x_2;
    }testCases[]{
        {1, -3, 2, 2.0, 1.0},
        {1, -5, 6, 3.0, 2.0},
        {1, 0, -4, 2.0, -2.0},
        {2, -8, 6, 3.0, 1.0},
        {1, -7, 12, 4.0, 3.0},
        {1, 10, -24, 2.0, -12.0},
        {1, -10, 25, 5.0, 5.0},
    };
    
    const size_t teseCount=sizeof(testCases)/sizeof(testCases[0]);
    for(size_t i=0;i<teseCount;++i){
        const TestCase & testcase=testCases[i];
        auto [expectedx_1,expectedx_2]=mathSpace::getAnswer(testcase.a,testcase.b,testcase.c);
        assert(expectedx_1==testcase.x_1);
        assert(expectedx_2==testcase.x_2);
    }
}