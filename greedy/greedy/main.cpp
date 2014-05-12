//
//  main.cpp
//  greedy
//
//  Created by Gustavo Ferrufino on 3/24/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <stdio.h>

#define Max 1000000

using namespace std;

double distancia(double x1, double y1, double x2, double y2){
    
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}


void llenarMatriz(double cost[100][100], int n, double puntos[100][2]){
    for (int i = 0; i < n; i++){
        cost[i][i]=0;
        for (int j = i+1; j < n; j++){
            double dist = distancia(puntos[i][0], puntos[i][1], puntos[j][0], puntos[j][1]);
            cost[i][j] = dist;
            cost[j][i] = dist;
        }
    }
}

double minLlave(double llave[], bool minSet[], int n){
    double min = Max, min_index;
    for(int i=0; i<n; i++){
        if(minSet[i]==false && llave[i]<min){
            min=llave[i];
            min_index=i;
        }
    }
    return min_index;
}


double prim(double cost[100][100], int n){
    double padre[100];
    double llave[100];
    bool minSet[100];
    
    for(int i=0; i<n; i++){
        llave[i]=Max;
        minSet[i]=false;
    }
    llave[0]=0;
    padre[0]=-1;
    for(int i=0; i<n-1; i++){
        int u=minLlave(llave, minSet, n);
        minSet[u]=true;
        for(int j=0; j<n; j++){
            if(cost[u][j]!=0 && minSet[j]==false && cost[u][j]<llave[j]){
                padre[j]=u;
                llave[j]=cost[u][j];
            }
        }
    }
    double tinta=0;
    for(int i=1; i<n; i++){
        int x=padre[i];
        tinta+=cost[i][x];
    }
    return tinta;
}

int main(){
    int n;
    double x, y, puntos[100][2], cost[100][100];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        puntos[i][0]= x;
        puntos[i][1]= y;
    }
    llenarMatriz(cost, n, puntos);
    cout << fixed << setprecision(2) << prim(cost,n)<< endl;
    return 0;
}
