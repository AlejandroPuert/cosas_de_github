/*
    Vamos a resolver un problema de difusión unidimensional

    Instrucciones de compilación:

    g++ -std=c++11 difusion.cpp

    Instrucciones de ejecución:
    ./a.out
*/

#include <iostream>
#include <fstream>
#include <ctgmath>

using namespace std;

int main(void){
    fstream outFile;
    unsigned int N=0;
    unsigned int Nt=0;
    double L=0,l=0;
    double T=10;
    double dx=0,dt=0;
    // Es conveniente tener las variables 'x' y 't'
    double x=0,t=0;
    // Definimos los apuntadores para el vector 'U'
    double *U;

    // 1. Cree el archivo difusion.txt
    outFile.open ("difusion.txt", ios::out | ios::trunc);

    // 2. Utilice 'cin' para que el usuario tenga que digitar N, Nt, L y l
    
    cout<<"El número de intervalos espaciales N es: "; cin>> N;
    cout<<"El número de intervalos temporales N_t es: "; cin>> Nt;
    cout<<"La longitud del medio L es: "; cin>> L;
    cout<<"La posición inicial del material l es: "; cin>> l;
    if(l>=L/2){
        cout<<"l tiene que ser menor a L/2"<<endl;
    }

    // 3. Ya con N y Nt defina dx y dt a saber que el tiempo máximo es T=10
    //    como está definido en la línea 17. Nota: Usted puede cambiar el
    //    tiempo si bien lo desea.
    
    dx = L/(N+1);
    dt = T/(Nt+1);

    // 4. Ya con N, cree el vector U de manera dinámica usando 'new'
    
    U = new double(N+1);

    // 5. Llene el vector U con las condiciones iniciales de U(x,0)
    
    
    for(int i = 0; i<=N; i++){
        U[i] = 0; //Primero supogamos todos cero
    }
    
    
    int k = (int) round((l/dx));//discretizamos l
    
    U[k-1] = 1/dx;  //Ahora si asignamos (de manera discreta) U(l,0) = U[k-1]
    //el menos 1 es porque el índice empieza en cero :) 
    
    
    
    // 6. Guarde el vector U(x,0) en la primera línea del archivo
    //    difusion.txt utilizando un for loop, la notación conveniente
    //    outFile<<... Recuerden el "endl" sólo al final del arreglo.
    //    la idea es que la primera linea del archivo sea:
    //    0 0 0 ... 0 0 1/dt 0 0 ... 0 0 0
    
    for(int i = 0; i<=N; i++){
        outFile <<U[i]<<"   ";
    }
    outFile << endl;

    // 7. Utilice un for loop (bucle) para actualizar el tiempo y así actua-
    //    lizar U(x,t) con las reglas descritas en el texto. Fíjense que ya
    //    cuentan con U(x,0) luego de la primera iteración encontrarían
    //    U(x,dt). Al finalizar la actualización en cada iteración no olvide
    //    guardar el vector U(x,t) en una fila del archivo difusion.txt.
    
    
    double *d2;
    d2 = new double(N+1); //vec de segundas derivadas discretas
    
    for(int j=0;j<Nt;j++){
        for(int i=0;i<=N;i++){ //un for para crear el vector de segunda derivada en cada punto
            d2[i] = (U[i+1]+U[i-1]-2*U[i])/(pow(dx,2));
            cout << d2[i] <<endl;
            cout << pow(dx,2) <<endl;
        } 
        for(int i=0;i<=N;i++){ //otro for para crear los nuevos valores de U[i]
            //son dos fors porque crear los U[i] en el anterior dañaría el calculo de d2[i+1] :)
            U[i] += dt*0.5*d2[i];
            outFile << U[i] <<"   ";
        }
        outFile << endl;
    }

    // 8. Por último destruya el vector U y cierre el archivo difusion.txt
    delete [] U; U = nullptr;
    outFile.close();
    return 0;
}
