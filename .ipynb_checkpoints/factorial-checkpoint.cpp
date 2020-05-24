// Encabezado
#include <iostream> 
using namespace std;
// la funion main es muy importante

int factorial(int n);

int main(){
    int n;
    cout << "Mete un número natural porfa" << endl;
    cin >> n;
    cout << "El factorial de ese hermoso número es " << factorial(n) << endl;
    
    return 0;
}

int factorial(int n){
    if (n>1) // matemos a los negativos
        return n*factorial(n-1);
    else
        return 1;
}