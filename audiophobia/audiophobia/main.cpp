//
//  main.cpp
//  audiophobia
//
//  Created by Gustavo Ferrufino on 2/23/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000

int main()
{
    int cantNodos, cantArcos, numPreguntas;
    cantNodos=0;
    cantArcos=numPreguntas=0;
    int arr[101][101];
    int cases;
    int nodo1, nodo2, valor;
    cin>>cases;
    int q1, q2;
    int num=1;
    
    while (cases>0) {
        
        cin>>cantNodos; //1 - 100
        cin>>cantArcos; // 1-1000
        cin>>numPreguntas; //1-999
        
        if (cantNodos<=0 || cantNodos>100) {
            cases = -1;
            
        } else if (cantArcos <= 0 || cantNodos>1000) {
            cases = -1;
        } else if (numPreguntas <= 0 || numPreguntas>=1000) {
            cases = -1;
        } else {
            
            for (int i = 0; i<cantNodos; i++) {
                for (int j=0; j<cantNodos; j++) {
                    if (i==j) {
                        arr[i][i]=0;
                    } else {
                        
                        arr[i][j]=MAX;
                    }
                }
            }
            
            for (int i=0; i<cantArcos; i++) {
                cin>>nodo1>>nodo2>>valor;
                arr[nodo1-1][nodo2-1]=arr[nodo2-1][nodo1-1]=valor;
            }
      
            
            
            for (int i=0; i<cantNodos; i++) {
                for (int j=0; j<cantNodos; j++) {
                    for (int k=0; k<cantNodos; k++) {
                        
                        arr[j][k] = min(arr[j][k],max(arr[j][i],arr[i][k]));
                        
                    }
                }
            }
            
            cout<<"Case "<<num++<<":"<<endl;
            cin.ignore();
            for (int i=0; i<numPreguntas; i++) {
                cin>>q1>>q2;
             
                if (arr[q1-1][q2-1]==MAX || arr[q1-1][q2-1] == 0) {
                    cout<<"no path"<<endl;
                } else {
                
                    cout<<arr[q1-1][q2-1]<<endl;
                }
                
            }
            
           
        }//salgo del else
        cases--;
    } //salgo del while
    
    return 0;
    
}

