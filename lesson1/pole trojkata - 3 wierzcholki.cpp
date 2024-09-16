#include <iostream>
#include <cmath> 

using namespace std;

int calculateTriangleArea(double x1, double y1, double x2, double y2, double x3, double y3, double* area) {
    if (area == NULL) {
        
        return -1;
    }  
    *area = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return 0;
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    
    
    cout << "Podaj wspolrzedne wierzcholkow trojkata (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    double area;
    int result = calculateTriangleArea(x1, y1, x2, y2, x3, y3, &area);
    
    if (result == 0) {
        cout << "Pole trojkata wynosi: " << area << endl;
    } 
	else {
        cout << "Blad: Null" <<endl;
    }
    
    return 0;
}

