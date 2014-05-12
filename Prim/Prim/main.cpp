//
//  main.cpp
//  Prim
//
//  Created by Gustavo Ferrufino on 3/13/14.
//  Copyright (c) 2014 Gustavo Ferrufino. All rights reserved.
//

/*
 http://www.sanfoundry.com/c-program-to-find-mstminimum-spanning-tree-using-prims-algorithm/
 */

#include <iostream>
using namespace std;

int tam=0;

struct node
{
    int fr,to,cost;
}p[6];
int c = 0,temp1 = 0,temp = 0;
void prims(int *a,int b[][7],int i,int j)
{
    a[i] = 1;
    while (c < 6)
    {
        int min = 999;
        for (int i = 0; i < tam; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < tam; )
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;
        b[temp][temp1] = b[temp1][temp]=1000;
    }
    for (int k = 0; k < tam-1; k++)
    {
        cout<<"source node:"<<p[k].fr<<endl;
        cout<<"destination node:"<<p[k].to<<endl;
        cout<<"weight of node: "<<p[k].cost<<endl;
        cout<<endl;
    }
}
int main()
{
     tam=5;
    int a[7];
    for (int i = 0; i < tam; i++)
    {
        a[i] = 0;
    }
   
    /*
    for (int i = 0; i < 5; i++)
    {
        cout<<"enter values for "<<(i+1)<<" row"<<endl;
        for (int j = 0; j < 5; j++)
        {
            cin>>b[i][j];
        }
    }*/
   
      /*int b[7][7] = {{0, 2, 12, 10, 0},
        {2, 0, 9, 0, 5},
        {12, 9, 0, 6, 3},
        {10, 0, 6, 0, 7},
        {0, 5, 3, 7, 0},
      };*/

    int b[7][7] = {{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };
    prims(a,b,0,0);
  
}

