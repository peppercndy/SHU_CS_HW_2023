#ifndef MATH_H
#define MATH_H

#include<utility>

using std::pair;
namespace mathSpace{
    pair<double,double> getAnswer(const double &a,const double &b,const double &c);
    pair<double,double> getAnswerWithValue(double a,double b,double c);
    pair <double *,double *> getAnswerWithPointer(double *a,double *b,double * c);
}
#endif