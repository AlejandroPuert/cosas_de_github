#include <iostream>
using namespace std;

float rungekutta(dt,t,X,Xprima);

    
//def rungekutta4(dt,t,X,Xprima):
  //  assert callable(Xprima)
   // k1 = Xprima(X,t)*dt
   // k2 = Xprima(X+k1/2,t+dt/2)*dt
    // k3 = Xprima(X+k2/2,t+dt/2)*dt
    //k4 = Xprima(X+k3,t+dt)*dt
    //return t+dt,X+(k1+2*k2+2*k3+k4)/6