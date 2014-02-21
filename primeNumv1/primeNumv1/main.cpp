

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
    for(int i=3; i<=raiz; i+=2)
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
    cin>>a>>b;
    while ((a && b) && !(a<=1) && !(b<=1)) {
        int res=0;
        for(int i=a;i<=b;i++)
        {
            
            if(i==2){
                res++;
                continue;
            }
            else if(i%2==0)
                continue;
            else if((i%3==0)&&(i!=3))
                continue;
            if(checkAmount(i))
            {
                res++;
            }
        }
        
        cout<<res<<endl;
        cin.ignore();
        cin>>a>>b;
        
    }
    
}