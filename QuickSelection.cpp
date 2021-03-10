#include <iostream>
using namespace std;

int quickSelection(int *arr, int inicio, int fim, int k){
    int d = inicio - 1;
    int pivo = arr[fim];

    for(int j = inicio; j < fim; j++){
        if (arr[j] <= pivo){
            int aux;
            d = d + 1;
            aux = arr[j];
            arr[j] = arr[d];
            arr[d] = aux;
        }
    }
    d = d + 1;
    int aux;
    aux = arr[fim];
    arr[fim] = arr[d];
    arr[d] = aux;

    if (d == k - 1) return pivo;
    else if (k < d)return quickSelection(arr, inicio, d-1, k);
    else return quickSelection(arr, d+1, fim, k);
}

int main(){
    int  num;
    cout<<"Insira o número de elementos:";
    cin>>num;
    int vetor[num];
    cout<<"Insira "<<num<<" elementos:";
    for (int i = 0; i < num; i++) { cin >> vetor[i];
    }
    int k;
    cout<<"Insira o K:";
    cin>>k;
    cout << quickSelection(vetor, 0, num-1, 5);
}