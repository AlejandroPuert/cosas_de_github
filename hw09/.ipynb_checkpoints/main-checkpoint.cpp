#include <iostream>
#include <vector>
#include <fstream>
#include "funciones.h"
using namespace std;


int main(){
    double t=0, dt = 0.01;
    
    double X [] = {0,20}; //inicial [posición, velocidad]
    std::vector<double> xList;
    std::vector<double> VList;
    std::vector<double> TList;
    
    xList.push_back(X[0]);
    VList.push_back(X[1]);
    TList.push_back(0);
    
    ofstream myfile;
    myfile.open ("data.txt");
    
    for(int i = 0; X[0]>= 0; i++){
        t+=dt;
        double xnew = rungekuttaX(dt,t,X)[0];
        double vnew = rungekuttaX(dt,t,X)[1];
        X[0] = xnew; X[1] = vnew;        
        xList.push_back(xnew);
        VList.push_back(vnew);
        TList.push_back(t);
        
        myfile << TList[i];
        myfile << "      ";
        myfile << xList[i];
        myfile << "\n";
    } 
    myfile.close();
    
    
    return 0;
}