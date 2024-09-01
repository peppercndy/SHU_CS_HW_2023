#include "math.h"
#include<math.h>
using std::pair;
#include "all.h"

pair<double,double> mathSpace::getAnswer(const double &a,const double &b,const double &c){
    double lambda=pow(pow(b,2)-4*a*c,0.5);
    double x_1=(0-b+lambda)/(2*a);
    double x_2=(0-b-lambda)/(2*a);
    return {x_1,x_2};
}

pair<double,double> mathSpace::getAnswerWithValue(double a,double b,double c){
    double lambda=pow(pow(b,2)-4*a*c,0.5);
    double x_1=(0-b+lambda)/(2*a);
    double x_2=(0-b-lambda)/(2*a);
    return {x_1,x_2};
}

pair <double*,double*> mathSpace::getAnswerWithPointer(double *a,double *b,double *c){
    double lambda=pow(pow(*b,2)-4*(*a)*(*c),0.5);
    double x_1=((0-(*b)+lambda)/(2*(*a)));
    double x_2=(0-*b-lambda)/(2*(*a));
    *a=x_1;
    *b=x_2;
    return {a,b};
}
