#include <iostream>
#include <cstdlib>  
#include <ctime>   
#include <cmath>    

using namespace std;

const int DIM_X = 5; 
const int DIM_Y = 4; 


double** generateHeightData() {
    double** data = new double*[DIM_X];
    for (int i = 0; i < DIM_X; ++i) {
        data[i] = new double[DIM_Y];
        for (int j = 0; j < DIM_Y; ++j) {
            data[i][j] = 1200 + static_cast<double>(rand()) / (RAND_MAX / (3500 - 1200));
        }
    }
    return data;
}


void freeHeightData(double** data) {
    for (int i = 0; i < DIM_X; ++i) {
        delete[] data[i];
    }
    delete[] data;
}


double calculateSurfaceArea(double** heightData) {
    double totalArea = 0.0;
    const double kmToMeters = 1000.0;  

   
    for (int i = 0; i < DIM_X - 1; ++i) {
        for (int j = 0; j < DIM_Y - 1; ++j) {
            
            double h1 = heightData[i][j];
            double h2 = heightData[i+1][j];
            double h3 = heightData[i][j+1];
            double h4 = heightData[i+1][j+1];

            double d1 = sqrt(kmToMeters * kmToMeters + (h2 - h1) * (h2 - h1));
            double d2 = sqrt(kmToMeters * kmToMeters + (h3 - h1) * (h3 - h1)); 
            double d3 = sqrt(kmToMeters * kmToMeters + (h4 - h2) * (h4 - h2)); 
            double d4 = sqrt(kmToMeters * kmToMeters + (h4 - h3) * (h4 - h3));             
            double s1 = (d1 + d2 + kmToMeters) / 2.0;
            double area1 = sqrt(s1 * (s1 - d1) * (s1 - d2) * (s1 - kmToMeters));

            double s2 = (d3 + d4 + kmToMeters) / 2.0;
            double area2 = sqrt(s2 * (s2 - d3) * (s2 - d4) * (s2 - kmToMeters));

            totalArea += area1 + area2;
        }
    }

    return totalArea;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    double** heightData = generateHeightData();

    double surfaceArea = calculateSurfaceArea(heightData);

    cout << "Calkowita powierzchnia terenu: " << surfaceArea << "m^2" << endl;

    freeHeightData(heightData);

    return 0;
}

