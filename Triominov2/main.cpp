//
//  main.cpp
//  Triomino
//
//  Created by Gustavo Ferrufino on 2/1/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>       /* sqrt */
using namespace std;

int tam;
char mat[100][100];
int num=0;
void fillTriomino(int rInf, int rFin, int cInf, int cFin){
    int rMed, cMed;
   
    if ((rInf+1!=rFin)){
        rMed = (rFin - rInf)/2+rInf;
        cMed = (cFin - cInf)/2+cInf;
         fillTriomino(rInf,rMed,cInf,cMed); // 1
         fillTriomino(rInf,rMed,(cMed)+1,cFin); // 2
         fillTriomino((rMed)+1,rFin,cInf,cMed); // 3
         fillTriomino((rMed)+1,rFin,(cMed)+1,cFin); // 4
    } else {
        
        
        
        if (mat[rInf][cInf] != '.' || mat[rInf][cInf] =='-') {
            mat[rInf][cFin]=num+48;
            mat[rFin][cInf]=num+48;
            mat[rFin][cFin]=num+48;
            num++;
            
            
        } else if (mat[rInf][cFin] != '.' || mat[rInf][cFin] =='-'){
            mat[rInf][cInf]=num+48;
            mat[rFin][cInf]=num+48;
            mat[rFin][cFin]=num+48;
            num++;
            
            
        } else if (mat[rFin][cInf] != '.' || mat[rFin][cInf] == '-'){
            mat[rInf][cFin]=num+48;
            mat[rInf][cInf]=num+48;
            mat[rFin][cFin]=num+48;
            num++;
            
            
        } else if (mat[rFin][cFin] != '.' || mat[rFin][cFin] == '-'){
            mat[rInf][cFin]=num+48;
            mat[rFin][cInf]=num+48;
            mat[rInf][cInf]=num+48;
            num++;
            
        }
        
    }
    
}

void triomino(int rInf,int rFin,int cInf,int cFin, int x, int y){
    int rMed, cMed;
    
    // cout<< "Inicio de cuadrado " <<rInf<<" "<<rFin<<" "<<cInf<<" "<<cFin<<endl;
    if ((rInf+1!=rFin)) {
        rMed = (rFin - rInf)/2+rInf;
        cMed = (cFin - cInf)/2+cInf;
        //rmed=tam/2-1
        if ((x<=rMed) && (y<=cMed)) {//1
            
            mat[rMed+1][cMed]=num+48; //Cuadrante 3
            mat[rMed+1][cMed+1]=num+48; //Cuadrante 4
            mat[rMed][cMed+1]=num+48; //Cuadrante 2
            num++;
            triomino(rInf,rMed,cInf,cMed,x,y); // 1
            triomino(rInf,rMed,(cMed)+1,cFin,rMed,cMed+1); // 2
            triomino((rMed)+1,rFin,cInf,cMed,rMed+1,cMed); // 3
            triomino((rMed)+1,rFin,(cMed)+1,cFin,rMed+1,cMed+1); // 4
            
        } else if ((x<=rMed)&&(y>=cMed+1)) {//2
            
            mat[rMed][cMed]=num+48; //1
            mat[rMed+1][cMed+1]=num+48; //4
            mat[rMed+1][cMed]=num+48; //3
            num++;
             triomino(rInf,rMed,cInf,cMed,rMed,cMed); // 1
             triomino(rInf,rMed,(cMed)+1,cFin,x,y); // 2
             triomino((rMed)+1,rFin,cInf,cMed,rMed+1,cMed); // 3
             triomino((rMed)+1,rFin,(cMed)+1,cFin,rMed+1,cMed); // 4
            
        } else if ((x>=rMed+1)&&(y<cMed+1)){ //3
            
            mat[rMed][cMed]=num+48; //1
            mat[rMed][cMed+1]=num+48; //2
            mat[rMed+1][cMed+1]=num+48; //4
            num++;
            triomino(rInf,rMed,cInf,cMed,rMed,cMed); // 1
            triomino(rInf,rMed,(cMed)+1,cFin,rMed,cMed+1); // 2
            triomino((rMed)+1,rFin,cInf,cMed,x,y); // 3
            triomino((rMed)+1,rFin,(cMed)+1,cFin,rMed+1,cMed+1); // 4
            
        } else if ((x>=rMed+1)&&(y>=cMed+1)) { //4
            mat[rMed][cMed]=num+48; //1
            mat[rMed][cMed+1]=num+48; //2
            mat[rMed+1][cMed]=num+48; //3
            num++;
            triomino(rInf,rMed,cInf,cMed,rMed,cMed); // 1
            triomino(rInf,rMed,(cMed)+1,cFin,rMed,cMed+1); // 2
            triomino((rMed)+1,rFin,cInf,cMed,rMed+1,cMed); // 3
            triomino((rMed)+1,rFin,(cMed)+1,cFin, x,y); // 4
        }
        

        
       
       
        
        //cout << "fin de cuadrado "<<rInf<<" "<<rFin<<" "<<cInf<<" "<<cFin<<endl;

    }



}


int main()
{
    cout<<"Introduce el tamaño de i, acuerdate que seria (2^(i)x 2^(i)) :"<<endl;
    int x, y;
    cin>>tam;
    tam=pow(2.0,tam*1.0);
    cout<<"tamaño: "<<tam<<endl;
    srand(time(0));
    x=rand()% tam;
    y=rand()% tam;
    cout<<"X:"<<x<<" Y:"<<y<<endl;
    cout<<"El '-' es la casilla oscura, ya que es una matriz de caracteres se utilizan simbolos y numeros"<<endl;
    for (int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++) {
            mat[i][j]='.';
        }
    }

    mat[x][y]='-';
    triomino(0, tam-1, 0, tam-1, x, y);
    fillTriomino(0, tam-1, 0, tam-1);
    cout<<endl;
    for (int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++) {
            
            cout<<mat[i][j]<<" ";
            
        }
        cout<<endl;
    }
    

}

