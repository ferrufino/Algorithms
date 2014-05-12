//
//  main.cpp
//  RockyTheBeagle
//
//  Created by Gustavo Ferrufino on 3/24/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//
#include <iostream>
#include <climits>
#include <stdio.h>
#define Max 1000000
using namespace std;
int mejor, letra;
int minDistance(int dist[], bool sptSet[], int tamano)
{
    // Initialize min value
    int mini = Max, min_index;
    
    for (int v = 0; v < tamano; v++){
        if (sptSet[v] == false && dist[v] <= mini){
            mini = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[20][20], int src, int tamano)
{    mejor = 0;
    letra= 0;
    int dist[tamano];     // The output array.  dist[i] will hold the shortest
    // distance from src to i
    
    bool sptSet[tamano]; // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < tamano; i++){
        dist[i] = Max;
        sptSet[i] = false;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // Find shortest path for all vertices
    for (int cont = 0; cont < tamano-1; cont++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet, tamano);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < tamano; v++){
            
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != Max && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    for (int i = 0; i < tamano; i++){
        if (mejor < dist[i]){
            mejor = dist[i];
            letra = i;
        }
    }
    
}

int main()
{   int c,n,k,matriz[20][20],tam, cont = 1;
    char l1,l2;
    cin >> c;
    while (c > 0){
        cin >> n >> k;
        for (int i = 0; i < n; i++){ //llenar Matriz predeterminada
            for (int j = i; j < n; j++){
                if (j == i){
                    matriz[i][j] = 0;
                }
                else{
                    matriz[i][j] = Max;
                    matriz[j][i] = Max;
                }
            }
        }
        for (int i = 0; i < k; i++){// CREAR MATRIZ DE CASO
            cin >> l1 >> l2 >> tam;
            matriz[l1-'A'][l2-'A'] = tam;
            matriz[l2-'A'][l1-'A'] = tam;
        }
        /*for(int i = 0; i < n; i++){    MOSTRAR MATRIZ RESULTANTE
         for (int j = 0; j < n; j++){
         if (matriz[i][j]== Max){
         cout << "M"<< "\t";
         }
         else
         cout << matriz[i][j] << "\t";;
         }
         cout << endl;
         }*/
        
        dijkstra(matriz, 0, n);
        char res = 'A' + letra;
        cout << "Case " << cont << ": "<<res << endl;
        c--;
        cont++;
    }
    return 0;
}
