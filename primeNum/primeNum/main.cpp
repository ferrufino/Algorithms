//
//  main.cpp
//  primeNum
//
//  Created by Gustavo Ferrufino on 1/15/14.
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
    int a;
    int b;
    int arr[1000000];
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    arr[3]=2;
    arr[4]=2;
    arr[5]=3;
    arr[6]=3;
    arr[7]=4;
    arr[8]=4;
    arr[9]=4;
    arr[10]=4;
    arr[11]=5;
    
    int cantidad=5;
    for (int i=12; i<=(1000000); i++) {
        
        if (checkAmount(i)) {
            
            arr[i]=++cantidad;
        }
        else{
            arr[i]=cantidad;
        }
    }
    cin>>a>>b;
    int temp;
    while ((a && b)&& (a>=2) && (b<=1000000)) {
        temp=arr[b]-arr[a-1];
        cout<<temp<<endl;
        cin.ignore();
        cin>>a>>b;
        cin.ignore();
    }
    return 0;
}

