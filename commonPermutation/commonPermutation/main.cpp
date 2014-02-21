//
//  main.cpp
//  commonPermutation
//
//  Created by Gustavo Ferrufino on 2/20/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{

    int turns;
    string A;
    string B;
    
    int mini;
    char first[26];
    char second[26];
    char ch;
    
    cin>>turns;
    for (int i=0; i<turns; i++) {
        
        cin>>A;
        cin>>B;

        for (int j=0; j<26; j++)
            first[j]=second[j]=0;

        for (int i=0; i<A.length(); i++) {
            first[A[i]-'a']+=1;
        }
        for (int i=0; i<B.length(); i++) {
            second[B[i]-'a']+=1;
        }
        //orden n por orden constante es orden n
        for (int i=0; i<26; i++) {
            mini=min(first[i],second[i]);
            if( mini!= 0){
                 ch='a'+i;
                for (int i=0; i<mini; i++) {
                    cout<<ch;
            }
                
        }
            

    }
        
        cout<<endl;
        
    
        
}
    
    
    
}

