#include <iostream>
using namespace std;


int main() {
    
    
    int arr[53]; //arreglo de pos de cortes
    int M[300][300];
    int posCortes;//pos de cortes
    int longitud;
    
    cin >> longitud;
    
    while ( longitud != 0) {
        
        cin >> posCortes;
        
        for (int i = 0; i < posCortes; i++) {
            
            cin >> arr[i+1];
        }
        
        arr[0]=0;
        arr[posCortes+1]=longitud;
        
        
        for (int i = 0; i <= posCortes+1; i++) {
            
            for (int j = 0; j <=posCortes+1; j++) {
                
                M[i][j]=1000000;
            }
        }
        
        
        for (int i = 0; i <= posCortes+1; i++) {
            
            M[i][i+1] = 0; //llena diagonal
            M[i][i+2]=arr[i+2]-arr[i]; // llena siguiente diagonal
        }
        cout<<endl;
        
        for (int j = 3; j <= posCortes+1; j++) {
            
            for (int i = 0; i <= posCortes+1; i++) {
                
                for (int k=i+1; k<=i+j-1; k++) {
                    
                    if( M[i][i+j] > (M[i][k] + M[k][i+j] + arr[i+j] - arr[i])) {
                        
                        M[i][i+j] = M[i][k] + M[k][i+j] + arr[i+j] - arr[i];
                    }
                }
            }
        }
           cout << "The minimum cutting is " << M[0][posCortes+1] << "." << endl;
        
        cin >> longitud;
    }
    
}