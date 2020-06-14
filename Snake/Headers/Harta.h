#ifndef HARTA_H
#define HARTA_H
#include <iostream>
#include <fstream>
#include "../Headers/functii.h"

using namespace std;


class Harta
{
    public:
        Harta();
        Harta(string);
        void displayHarta();
        int width,length;
        bool estePerete(int,int);
    private:
        int n,m;
        bool perete[100][100];
};

#endif // HARTA_H
