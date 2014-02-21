//
//  main.cpp
//  basado en primeNum
//
//  Created by Gustavo Ferrufino on 20-jan-2014
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
//Sieve of Eratosthenes

bool checkAmount(int num)
{
    int raiz = sqrt(num*1.0);
    if ((num %5 == 0) || (num %3 == 0) || (num %7 ==0) ||(num%2==0)) {
        return false;
    }
    for(int i=11; i<=raiz; i+=2)
    {
        if(num%i==0)
        return false;
    }
    
    return true;
}

int main()
{
    int var, loop;
    int a,b;
    int arr[1000000];
    arr[0]=0;
    arr[1]=0;
    arr[2]=2;//
    arr[3]=3;//
    arr[4]=0;
    arr[5]=5;//
    arr[6]=0;
    arr[7]=7;//
    arr[8]=0;
    arr[9]=0;
    arr[10]=0;
    arr[11]=11;//
    
   // int cantidad=5;
    for (int i=12; i<=(1000000); i++) {
        
        if (checkAmount(i)) {
            
            arr[i]=i;
        }
        else{
            arr[i]=0;
        }
    }
    cin>>loop;

    //cin.ignore();
    while ((loop>=1)&&(loop<=100)) {
            cin>>var;
            //ignore;
        if (arr[var]!=0) {
            cout<<var<<" "<<var<<endl;
           // cin.ignore();
        } else {
            a=b=var;
            while (arr[a]==0) {
                a--;
            }
            while (arr[b]==0) {
                b++;
            }
            cout<<a<<" "<<b<<endl;
           // cin.ignore();
        }
        

       //cin.ignore();
        loop--;
    }
    return 0;
}