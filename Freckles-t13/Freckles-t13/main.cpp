//
//  main.cpp
//  Freckles-t13
//
//  Created by Gustavo Ferrufino on 3/13/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

///UTILIZA ALGORITMO PRIM




#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int tam=0;
double parent[10000];
double arcos[10000];





double distancia (double x1, double x2, double y1, double y2){
    
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    
    
}

double minKey(double key[], int arr[]){
    double min = 100000, min_index;
    
    for(int i=0; i<tam; i++){
        if(!(arr[i]) && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
double AcumOfPaths(double cost[][1000]) {
    double acum;
    int x;
    for(int i=1; i<tam; i++){
        x=parent[i];
        acum+=cost[i][x];
    }
    return acum;


}
/*
 http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
 */
double prim(double MAdj[][1000], int a[]){
   
    int indicePeq;

        ////Inicio de operacion
    for(int i=0; i<tam-1; i++){
        
            indicePeq=minKey(arcos, a);
            a[indicePeq]=1;
        
        for(int j=0; j<tam; j++){
            
            if((MAdj[indicePeq][j]!=0) && !(a[j])){
                if ( MAdj[indicePeq][j]<arcos[j]) {
                    //cout<<indicePeq<<endl;
                    parent[j]=indicePeq;
                    //cout<<MAdj[indicePeq][j]<<endl;
                    arcos[j]=MAdj[indicePeq][j];

                }
            }
        }
    }
    return AcumOfPaths(MAdj);

}




int main()
{
    
    cin>>tam;
    if (tam <= 100 && tam >0) {
    int a[10000];
    
    for (int i = 0; i < tam; i++)
    {
        a[i] = 0;
         arcos[i]=100000;
    }

    arcos[0]=0;
    parent[0]=0;
        bool check=false;
    double cost[1000][1000];
    double puntos[1000][2];
    for (int i = 0; i < tam; i++){
        cin >> puntos[i][0] >> puntos[i][1];
        if (puntos[i][0] < 0 || puntos[i][1] < 0) {
                check=true;
        }
    }
    if (!check) {
   //Creo matriz de adyacencias
    for (int i = 0; i < tam; i++){
        cost[i][i]=0;
        for (int j = i+1; j < tam; j++){
            double dist = distancia(puntos[i][0],puntos[j][0], puntos[i][1],puntos[j][1]);
            cost[i][j] = dist;
            cost[j][i] = dist;
        }
    }
 
    cout << fixed << setprecision(2) << prim(cost, a)<< endl;
    }
    }

    
}
/*
 
 3
 1.0 1.0
 2.0 2.0
 2.0 4.0
 */

