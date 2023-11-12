#include <iostream>
#include "list.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    /*
    int cases[10][3] = {
        {10,5,5},
        {1,10,100},
        {0,10,5},
        {2,100,200},
        {0,0,0},
        {100,100,0},
        {1000,1000,1000},
        {1000,0,1000},
        {1000,1000,10000},
        {10000,1000,100000}};
    for (int i = 0; i < 10; i++) {
        char fname[200];
        sprintf(fname,"%d.in",i+1);
        ofstream f(fname);
        f<<cases[i][0]<<" "<<cases[i][1]<<" "<<cases[i][2]<<endl;
        for (int j = 0; j < cases[i][0]; j++) {
            f<<rand() % 100000<<" ";
        }
        f<<endl;
        for (int j = 0; j < cases[i][1]; j++) {
            f<<rand() % 100000<<" ";
        }
        f<<endl;
        for (int j = 0; j < cases[i][2]; j++) {
            f<<rand() % 100000<<" ";
        }
        f<<endl;

        f.close();
    }
    return 0;
*/
    map<CP::list<int>::node*, int> m;
    CP::list<int> x, a, b;
    int nx, na, nb;
    cin>>nx>>na>>nb;
    int tmp;
    for (int i = 0; i < nx; i++) {
        cin>>tmp;
        x.push_back(tmp);
    }
    for (int i = 0; i < na; i++) {
        cin>>tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < nb; i++) {
        cin>>tmp;
        b.push_back(tmp);
    }

/*
    x.push_back(1);

    x.push_back(7);

    x.push_back(9);

    x.push_back(10);

    x.push_back(2);
    x.push_back(6);
    x.push_back(3);

    a.push_back(1);
    a.push_back(2);

    b.push_back(3);
    b.push_back(4);
    b.push_back(5);
*/
    x.appendMap(m);
    a.appendMap(m);
    b.appendMap(m);
    x.splitList(a, b);
    cout<<"x is"<<endl;
    x.print();
    cout<<"a is"<<endl;
    a.print();
    cout<<"b is"<<endl;
    b.print();
    if (x.checkInMap((m))) cout<<"daso23324"<<endl;
    if (a.checkInMap((m))) cout<<"3kj23a"<<endl;
    if (b.checkInMap((m))) cout<<"zz3kj23a"<<endl;
    return 0;
}
