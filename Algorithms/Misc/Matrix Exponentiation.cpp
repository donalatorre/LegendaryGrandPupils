#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip>
#define FIRST first
#define SECOND second.first
#define THIRD second.second

using namespace std;
typedef pair<int, int> ii;
typedef vector<double> vd;
typedef vector<vd> Matrix;
typedef long long ll;

const int maxN = 100;

Matrix operator *(const Matrix &first, const Matrix &second){
    Matrix ret(first.size(), vd(second[0].size(), 0.0));
    for(int i = 0; i < first.size(); i++)
        for(int j = 0; j < second[0].size(); j++)
            for(int k = 0; k < second.size(); k++)
                ret[i][j] += first[i][k] * second[k][j];
    return ret;
}
Matrix operator^(Matrix mat, int coef){
    Matrix ret(mat.size(), vd(mat.size(), 0.0));
    for(int i = 0; i < mat.size(); i++) ret[i][i] = 1.0;
    while(coef){
        if(coef & 1)
            ret = ret * mat;
        coef >>= 1, mat = mat * mat;
    }
    return ret;
}