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



double aproxi(double var) 
{ //funcion copiada de https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
    //no me gusta que hayan tantos puntos decimales en la solucion :) 
    //a 4 cifras decimales 
    double value = (int)(var * 10000 + .5); 
    return (double)value / 10000; 
} 


int main(void){
    fstream outFile;
    unsigned int N=0;
    unsigned int Nt=0;
    double L=0,l=0;
    double T=10;
    double dx=0,dt=0;
    // Definimos los apuntadores para el vector 'U'
    double *U;
    double *d2; //vec de segundas derivdas

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
    
    dx = L/(N);
    dt = T/(Nt);

    // 4. Ya con N, cree el vector U de manera dinámica usando 'new'
    
    U = new double[N+1];

    // 5. Llene el vector U con las condiciones iniciales de U(x,0)
    
    int k = (int) round((l/dx)); //discretizamos l
    
    for(int i = 0; i<=N; i++){
        if(i==k){
            U[i] = aproxi(1/dx);
        }
        else{
            U[i] = 0.0000; 
        }
    }
       
    
    // 6. Guarde el vector U(x,0) en la primera línea del archivo
    //    difusion.txt utilizando un for loop, la notación conveniente
    //    outFile<<... Recuerden el "endl" sólo al final del arreglo.
    //    la idea es que la primera linea del archivo sea:
    //    0 0 0 ... 0 0 1/dt 0 0 ... 0 0 0 //error! es 1/dx, no 1/dt
    
    for(int i = 0; i<=N; i++){
        outFile <<U[i]<<"   ";
    }
    outFile << endl;

    // 7. Utilice un for loop (bucle) para actualizar el tiempo y así actua-
    //    lizar U(x,t) con las reglas descritas en el texto. Fíjense que ya
    //    cuentan con U(x,0) luego de la primera iteración encontrarían
    //    U(x,dt). Al finalizar la actualización en cada iteración no olvide
    //    guardar el vector U(x,t) en una fila del archivo difusion.txt.
    
    
    d2 = new double[N+1]; //vec de segundas derivadas discretas
    for(int i = 0; i<N; i++){
        d2[i] = 0; //inicilizamos en cero
    }
    
    
    for(int j=0;j<Nt;j++){
        for(int i=0;i<=N-2;i++){ //un for para crear el vector de segunda derivada en cada punto
            d2[i+1] = aproxi((U[i+2]+U[i]-2*U[i+1])/(dx*dx));
            //No tocamos ni el primero ni el último porque las paredes son impermeables
        } 
        for(int i=0;i<=N;i++){ //otro for para crear los nuevos valores de U[i]
            //son dos fors porque crear los U[i] en el anterior dañaría el calculo de d2 :)
            U[i] += aproxi(dt*0.5*d2[i]);
            outFile << U[i] <<"   ";
        }
        outFile << endl;
    }
    
    
    //Asumiendo que la última pregunta es cuál es el numero máximo de intervalos....
    //Para responder esta pregunta grafique algunos de los estados U(x) en diferentes momentos.
    //Me esta dando decente para N = 18, para N mayor se pone feo. 
    //Cambiando a T=5 alcanzo a llegar a N = 25 pero no demora en dañarse. 
    //No se realmente cual es la relación entre estas dos cantidades
    
    
    //Si la pregunta es cuál es le numero mínimo, entonces es N = 2. 
    //Así obtengo por lo menos el punto donde hay mayor concentración.
    
    
    
    
    

    // 8. Por último destruya el vector U y cierre el archivo difusion.txt
    delete [] U; U = nullptr;
    delete [] d2; d2 = nullptr;
    outFile.close();
    return 0;
}
