#include<iostream>
#include<sstream>
//#include "all.h"
#include "math.h"
#include "test.h"
//#include "i_o.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::cin;

void printAnswer(const double &x_1,const double &x_2){
        cout<<"此方程的两个解为：x1="<<x_1<<"  x2="<<x_2<<endl;
    }

//这个函数是给你解决读取问题：
//例子：
//请输入方程的系数，用空格分开：(例子1，-3，2)
//1 -3 2
//此方程的两个解为：x1=2  x2=1
void solveYourQuesetion(){
    cout<<"请输入方程的系数，用空格分开：(例子1，-3，2)"<<endl;
    string line;
    getline(cin,line);
    istringstream iss(line);
    double a,b,c;
    iss>>a>>b>>c;
    auto [x_1,x_2]=mathSpace::getAnswer(a,b,c);
    printAnswer(x_1,x_2);
}


int main(){
    while(true){
        solveYourQuesetion();

        //判断是否要退出
        cout<<"是否退出？(按1退出，按任意键继续解答)"<<endl;
        int signal;
        cin>>signal;
        cin.ignore();
        if(signal==1){
            break;
        }
    }
    cout<<endl;
    //下面是测试
    //有7组数据，使用了cassert库
    TestNameSpace::TestExample();
    cout<<"测试通过"<<endl;
    return 0;
}