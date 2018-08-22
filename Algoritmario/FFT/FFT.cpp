//
//  main.cpp
//  FFTopt
//
//  Created by Adán López Alatorre on 4/10/17.
//  Copyright © 2017 Adán López Alatorre. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>
#include <bitset>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <complex>

using namespace std;

typedef long long ll;
#define SECOND second.first
#define THIRD second.second

struct Complex{
    double real, imag;
    Complex(){}
    Complex(const complex<double> &a): real(a.real()), imag(a.imag()){}
    Complex(double real, double imag): real(real), imag(imag){}
    Complex operator*(const Complex & a){
        return Complex(real * a.real - imag * a.imag, real * a.imag + a.real * imag);
    }
    Complex operator+(const Complex & a){return Complex(real + a.real, imag + a.imag);}
};
Complex conj(const Complex & a){return Complex(a.real, -a.imag);}

const int maxN = 1e6;
int maxL;

int reverses[maxN << 2];
bool v[maxN << 2];
Complex steps[30], unityRoots[maxN << 2], first[maxN << 2], second[maxN << 2];
ll sums[maxN << 2];

int reverse(int num, int exp){
    int reverse = 0, pot = 1, inv = 1 << (exp - 1);
    while(inv >= 1){
        if(num & pot) reverse |= inv;
        inv >>= 1, pot <<= 1;
    }
    return reverse;
}

void sqRoot(Complex *vec, int len, int loog){
    for(int i = len - 1; i >= 0; i--){
        vec[i << 1] = vec[i];
        vec[(i << 1) + 1] = vec[i] * steps[loog];
    }
}

void FFT(Complex *coef, int arrS){
    const int saiz = ceil(log2(arrS));
    
    memset(v, false, sizeof(v));
    for(int i = 0; i < (1 << saiz); i++)
        if(!v[reverses[i] >> (maxL - saiz)])
            swap(coef[i], coef[reverses[i] >> (maxL - saiz)]), v[i] = true;
    unityRoots[0] = Complex(1, 0);
    
    //DIVIDE AND CONQUER...
    for(int T = 1, u = 0; T < (1 << saiz); T <<= 1, u++){
        sqRoot(unityRoots, T, u);
        for(int i = 0; i < (1 << saiz); i += (T << 1)){
            for(int j = 0; j < T; j++){
                Complex lTmp = coef[i + j], rTmp = coef[i + j + T];
                
                coef[i + j] = lTmp + rTmp * unityRoots[j];
                coef[i + j + T] = lTmp + rTmp * unityRoots[j + T];
            }
        }
    }
}

//one & two = coefficient arrays w/sizes, res is where results are stored
void polynomMultiplication(int *one, int *two, int *res, int oS, int tS){
    const int saiz = 1 << int(ceil(log2(oS + tS)));
    
    for(int i = 0; i < saiz; i++)
        first[i] = Complex(i < oS? double(one[i]): 0.0, 0.0);
    for(int i = 0; i < saiz; i++)
        second[i] = Complex(i < tS? double(two[i]): 0.0, 0.0);
    
    //FFT
    FFT(first, saiz), FFT(second, saiz);
    
    //INVERSE FFT = FFT(conj(C1 * C2) / N)
    for(int i = 0; i < saiz; i++)
        first[i] = conj(first[i] * second[i]);
    FFT(first, saiz);
    
    for(int i = 0; i < saiz; i++)
        res[i] = int(round(first[i].real / saiz));
}