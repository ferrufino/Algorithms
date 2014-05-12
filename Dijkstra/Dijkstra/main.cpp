//
//  main.cpp
//  Dijkstra
//
//  Created by Gustavo Ferrufino on 3/13/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;
#define Max 1000

/***
 http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
 ****/

int minDistance(int dist[], bool sptSet[], int tam)
{
    // Initialize min value
    int mini = Max, min_index;
    for (int v = 0; v < tam; v++){
        if (sptSet[v] == false && dist[v] <= mini){
            mini = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


int dijkstra(int graph[20][20], int src, int tam)
{
    int dist[tam];     // The output array.  dist[i] will hold the shortest
    // distance from src to i
    bool sptSet[tam]; // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < tam; i++){
        dist[i] = Max;
        sptSet[i] = false;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // Find shortest path for all vertices
    for (int cont = 0; cont < tam-1; cont++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet, tam);
        // Mark the picked vertex as processed
        sptSet[u] = true;
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < tam; v++){
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != Max && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    return *dist;
    
}
int main()

{   int numCasos,numCuartos,arco;
    int matriz[20][20];
    int tam;
    int longRoute=0, ansWord=0;
    int cont = 0;
    char a,b;
  
    
    cin >> numCasos;
    int dist[numCuartos];
    
    while (numCasos > 0){
        cin >> numCuartos >> arco;
        for (int i = 0; i < numCuartos; i++){ //llenar Matriz predeterminada
            for (int j = i; j < numCuartos; j++){
                if (j == i){
                    matriz[i][j] = 0;
                }
                else{
                    matriz[i][j] = Max;
                    matriz[j][i] = Max;
                }
            }
        }
        for (int i = 0; i < arco; i++){// CREAR MATRIZ DE CASO
            
            cin >> a >> b >> tam;
            
            matriz[a-'A'][b-'A'] = tam;
            matriz[b-'A'][a-'A'] = tam;
        }
       
        *dist=dijkstra(matriz, 0, numCuartos);
        
        for (int i = 0; i < numCuartos; i++){
            if ( dist[i] > longRoute){
                longRoute = dist[i];
                ansWord = i;
            }
        }
        cout << "Case " << ++cont << ": "<<(char) ('A' + ansWord )<< endl;
        numCasos--;
        
    }
    
}