#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

string funkcja_kwad(double a, double b, double c){
    double delta =(b*b) - (4*a*c);
    string message="";
    if(delta<0){
        message ="Brak pierwiastków";
    }
    if(delta ==0){
        double x0 = ((-1)*b)/(2*a);
        string x0s = to_string(x0);
        message = "jeden pierwiastek"<x0s;
    }
    else{
        double x1 = (((-1)*b)-sqrt(delta))/(2*a);
        double x2 = (((-1)*b)+sqrt(delta))/(2*a);;
        message = "x1 wynosi: "<<to_string(x1)<<"/n  x2 wynosi: "<<to_string(x2);
    }
	return message;

}
int main(){
    cout<<funkcja_kwad(3.0,3.0,-1.0);
	return 0;
}
