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
        TestCase & testcase=testCases[i];
        auto [expectedx_1,expectedx_2]=mathSpace::getAnswer(testcase.a,testcase.b,testcase.c);
        assert(expectedx_1==testcase.x_1);
        assert(expectedx_2==testcase.x_2);
        auto [expectedxv_1,expectedxv_2]=mathSpace::getAnswerWithValue(testcase.a,testcase.b,testcase.c);
        assert(expectedxv_1==testcase.x_1);
        assert(expectedxv_2==testcase.x_2);
        auto [expectedxp_1,expectedxp_2]=mathSpace::getAnswerWithPointer(&(testcase.a),&testcase.b,&testcase.c);
        double expectedxpv_1=*expectedxp_1;
        double expectedxpv_2=*expectedxp_2;
        //cout<<expectedxpv_1<<"-->"<<expectedxpv_1<<endl;
        //cout<<expectedx_1<<"-->"<<expectedxpv_1<<"-->"<<testcase.x_1<<*expectedxp_1<<endl;
        assert(expectedxpv_1==testcase.x_1);
        assert(expectedxpv_2==testcase.x_2);
    }
    cout<<"----------"<<endl;
    cout<<"引用传递测试通过"<<endl;
    cout<<"值传递测试通过"<<endl;
    cout<<"指针传递测试通过"<<endl;
    cout<<"----------"<<endl;
}