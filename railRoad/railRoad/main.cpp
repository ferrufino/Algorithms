//Eduardo Zardain Canabal
//A00813391
//Gustavo Ferrufino de la Fuente
//A00812572
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    
    int n1, n2;
    int trainA[1005], trainB[1005], trainE[2010];
    int mat[1005][1005];
    
    cin >> n1 >> n2;
    
    while (n1!=0 || n2!=0) {
        
        for (int i=0; i<n1; i++) {
            cin >> trainA[i];
        }
        
        for (int i=0; i<n2; i++) {
            cin >> trainB[i];
        }
        
        for (int i=0; i<n1+n2; i++) {
            cin >> trainE[i];
        }
        
        mat[0][0] = 1;
        for (int i=0; i<=n2; i++) {
            for (int j=0; j<=n1; j++) {
                if (i!=0 || j!=0) {
                    if (i==0) {
                        mat[i][j] = (trainA[j-1]==trainE[j-1] && mat[i][j-1]==1)? 1 : 0;
                    } else if (j==0) {
                        mat[i][j] = (trainB[i-1]==trainE[i-1] && mat[i-1][j]==1)? 1 : 0;
                    } else {
                        mat[i][j] = ((trainB[i-1]==trainE[i+j-1] && mat[i-1][j]) || (trainA[j-1]==trainE[i+j-1] && mat[i][j-1]))? 1 : 0;
                    }
                }
            }
        }
        
        if (mat[n2][n1]==1) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
        
        memset(mat,0,sizeof(mat));
        memset(trainA,0,sizeof(trainA));
        memset(trainB,0,sizeof(trainB));
        
        cin >> n1 >> n2;
    }
    
    
    return 0;
}
