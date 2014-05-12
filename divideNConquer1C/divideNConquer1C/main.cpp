//PROYECTO 1C
//Eduardo Zardain Canabal
//A00813391
//Gustavo Ferrufino de la Fuente
//A00812572

#include <iostream>
#include <limits>
using namespace std;


const int MINIMUM = numeric_limits<int>::min();
int arr[500];
int buyDay;
int sellDay;
int profit = 0;
void maxEarnings(int start, int end){
    if (start<end) {
        int m = (start+end)/2;
        maxEarnings(start, m);
        maxEarnings(m+1, end);
        int minIndex = start;
        int maxIndex = m+1;
        for (int i=start; i<=m; i++) {
            if (arr[i]<arr[minIndex]) {
                minIndex = i;
            }
        }
        for (int j=m+1; j<=end; j++) {
            if (arr[j]>arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        if (arr[maxIndex]-arr[minIndex] > profit) {
            buyDay = minIndex;
            sellDay = maxIndex;
            profit = arr[sellDay]-arr[buyDay];
        }
    }
}
int main()
{
    int cases, n;
    
    cin >> cases;
    
    for (int i=1; i<=cases; i++) {
        cin >> n;
        for (int j=1; j<=n; j++) {
            cin >> arr[j];
        }
        profit = 0;
        maxEarnings(1, n);
        cout << "Buy in " <<  buyDay << ", sell in " << sellDay << endl;
    }
    
    return 0;
}