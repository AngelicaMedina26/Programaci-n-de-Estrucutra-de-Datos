#include <iostream>
using namespace std;

int main() {
    int num[] = { 50,20,40,80,30 };
    int aux;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (num[j] > num[j + 1]) {  // numActual > numSiguiente
                aux = num[j];           // Proceso de intercambio
                num[j] = num[j + 1];
                num[j + 1] = aux;
            }
        }
    }
    cout << "Numeros de manera ascendente : ";
    for (int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    
    return 0;
}
