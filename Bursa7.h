#ifndef BURSA7_H
#define BURSA7_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <Eigen/Dense>//矩阵库

using namespace Eigen;
using namespace std;
#define PI 3.1415926//定义PI值大小

void Bursa_7(  double ox1,double ox2,double ox3,double ox4,
               double oy1,double oy2,double oy3,double oy4,
               double oz1,double oz2,double oz3,double oz4,

               double tx1,double tx2,double tx3,double tx4,
               double ty1,double ty2,double ty3,double ty4,
               double tz1,double tz2,double tz3,double tz4,

               double para[7])
{
    //设置矩阵
    Eigen::Matrix<double, 12, 7> A;
    Eigen::Matrix<double, 12, 1> L;
    Eigen::Matrix<double,  7, 1> outpara;
    A <<          1   , 0  , 0  , ox1, 0  ,-oz1, oy1,
                  0   , 1  , 0  , oy1, oz1, 0  ,-ox1,
                  0   , 0  , 1  , oz1,-oy1, ox1, 0  ,
                  1   , 0  , 0  , ox2, 0  ,-oz2, oy2,
                  0   , 1  , 0  , oy2, oz2, 0  ,-ox2,
                  0   , 0  , 1  , oz2,-oy2, ox2, 0  ,
                  1   , 0  , 0  , ox3, 0  ,-oz3, oy3,
                  0   , 1  , 0  , oy3, oz3, 0  ,-ox3,
                  0   , 0  , 1  , oz3,-oy3, ox3, 0  ,
                  1   , 0  , 0  , ox4, 0  ,-oz4, oy4,
                  0   , 1  , 0  , oy4, oz4, 0  ,-ox4,
                  0   , 0  , 1  , oz4,-oy4, ox4, 0  ;


    L <<          tx1,
                  ty1,
                  tz1,

                  tx2,
                  ty2,
                  tz2,

                  tx3,
                  ty3,
                  tz3,

                  tx4,
                  ty4,
                  tz4;

    //公式：X=(( A_T * A )^-1) *  A_T * L

    outpara=(A.transpose()*A).inverse()*A.transpose()*L;

    para[1] = outpara(1, 1);
    para[2] = outpara(2, 1);
    para[3] = outpara(3, 1);

    double a;
    double b;
    double c;
    double d;

    a=outpara(4,0);
    b=outpara(5,0);
    c=outpara(6,0);
    d=outpara(7,0);

    para[4] = b/a*180/PI*3600;
    para[5] = c/a*180/PI*3600;
    para[6] = d/a*180/PI*3600;
    para[7] = a;
}

#endif // BURSA7_H
