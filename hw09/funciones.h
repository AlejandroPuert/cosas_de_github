#include <math.h> 
using namespace std;


double * Xprima(double X[2], double t){
    
    //X = [posicion, velocidad]
    
    double * X_prima = new double[2]; //X_prima = [velocidad, aceleración]
    double g = -9.8;
    X_prima[0] = X[1]; X_prima[1] = g; 
    return X_prima;
}    



double * rungekuttaX(double dt, double t, double X [2]){
    double * k1 = new double[2];
    double * k2 = new double[2];
    double * k3 = new double[2];
    double * k4 = new double[2];
    
    
    double * X1 = new double[2]; //X+k1/2
    double * X2 = new double[2]; //X+k2/2
    double * X3 = new double[2]; //X+k3
    
    //como los arrays acá se hacen los difíciles,
    //toca sacar cada componente de cada array por separado.
    
    k1[0] = Xprima(X,t)[0]*dt;
    k1[1] = Xprima(X,t)[1]*dt;
    
    X1[0] = X[0]+k1[0]/2;
    X1[1] = X[1]+k1[1]/2;
    
    k2[0] = Xprima(X1,t+dt/2)[0]*dt;
    k2[1] = Xprima(X1,t+dt/2)[1]*dt;
    
    X2[0] = X[0]+k2[0]/2;
    X2[1] = X[1]+k2[1]/2;
    
    k3[0] = Xprima(X2,t+dt/2)[0]*dt;
    k3[1] = Xprima(X2,t+dt/2)[1]*dt;
    
    X3[0] = X[0]+k3[0];
    X3[1] = X[1]+k3[1];
    
    k4[0] = Xprima(X3,t+dt)[0]*dt;
    k4[1] = Xprima(X3,t+dt)[1]*dt;
    
    
    X[0] = X[0] + (k1[0]+2*k2[0]+2*k3[0]+k4[0])/6;
    X[1] = X[1] + (k1[1]+2*k2[1]+2*k3[1]+k4[1])/6;
    
    
    return X;
}


