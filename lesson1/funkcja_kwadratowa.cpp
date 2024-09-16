#include <iostream>
#include <cmath>

using namespace std;

int solveQuadratic(double a, double b, double c, double* x1, double* x2) {
    if (a == 0) {
        return -1;
    }
    
    double delta = b * b - 4 * a * c;
    
    if (delta > 0) {
        
        double sqrtDelta = sqrt(delta);
        *x1 = (-b + sqrtDelta) / (2 * a);
        *x2 = (-b - sqrtDelta) / (2 * a);
        return 0;
    } 
	else if (delta == 0) {
        *x1 = -b / (2 * a);
        *x2 = *x1; 
        return 0;
    } 
	else {
        return -2;
    }
}

int main() {
    double a, b, c;

    cout << "Podaj wspolczynniki a, b i c (oddzielone spacjami): ";
    cin >> a >> b >> c;

    double x1, x2;
    int result = solveQuadratic(a, b, c, &x1, &x2);
    
    switch (result) {
        case 0:
            if (x1 == x2) {
                cout << "Jedyny pierwiastek: x = " << x1 << endl;
            } 
			else {
                cout << "Pierwiastki: x1 = " << x1 << " oraz x2 = " << x2 << endl;
            }
            break;
        case -1:
            cout << "Blad: Wspolczynnik 'a' nie moze byc zerem w rownaniu kwadratowym." << endl;
            break;
        case -2:
            cout << "Rownanie nie ma pierwiastkow rzeczywistych." <<endl;
            break;
    }
    
    return 0;
}

