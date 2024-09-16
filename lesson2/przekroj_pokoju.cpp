#include <iostream>
#include <cstdlib> // Dla funkcji rand() i srand()
#include <ctime>   // Dla funkcji time()
#include <cmath>   // Dla funkcji std::abs

using namespace std;

const int DIM_X = 5;
const int DIM_Y = 4;
const int DIM_Z = 2;
const int NUM_CELLS_X = DIM_X;
const int NUM_CELLS_Y = DIM_Y;
const int NUM_CELLS_Z = DIM_Z;

// Funkcja generuj¹ca tablicê 3D z losowymi temperaturami
double*** generateTemperatureData() {
    double*** data = new double**[NUM_CELLS_X];
    for (int i = 0; i < NUM_CELLS_X; ++i) {
        data[i] = new double*[NUM_CELLS_Y];
        for (int j = 0; j < NUM_CELLS_Y; ++j) {
            data[i][j] = new double[NUM_CELLS_Z];
            for (int k = 0; k < NUM_CELLS_Z; ++k) {
                data[i][j][k] = 18 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (25 - 18)));
            }
        }
    }
    return data;
}

// Funkcja zwalniaj¹ca pamiêæ tablicy 3D
void freeTemperatureData(double*** data) {
    for (int i = 0; i < NUM_CELLS_X; ++i) {
        for (int j = 0; j < NUM_CELLS_Y; ++j) {
            delete[] data[i][j];
        }
        delete[] data[i];
    }
    delete[] data;
}

// Funkcja obliczaj¹ca œredni¹ temperaturê dla przekroju pionowego
double calculateVerticalSliceAverage(double*** data, int fixed_index, bool isXAxis) {
    double sum = 0;
    int count = 0;

    if (isXAxis) {
        // Przekrój pionowy wzd³u¿ osi X
        for (int y = 0; y < NUM_CELLS_Y; ++y) {
            for (int z = 0; z < NUM_CELLS_Z; ++z) {
                sum += data[fixed_index][y][z];
                ++count;
            }
        }
    } 
	else {
        // Przekrój pionowy wzd³u¿ osi Y
        for (int x = 0; x < NUM_CELLS_X; ++x) {
            for (int z = 0; z < NUM_CELLS_Z; ++z) {
                sum += data[x][fixed_index][z];
                ++count;
            }
        }
    }
    
    return sum / count;
}

int main() {
    // Inicjalizacja generatora liczb losowych
    srand(static_cast<unsigned>(time(0)));

    // Generowanie danych temperatury
    double*** temperatureData = generateTemperatureData();

    // Znalezienie przekroju pionowego z najwiêksz¹ œredni¹ temperatur¹
    double maxAverage = -1;
    int bestIndex = 0;
    bool isXSlice = true;

    // Sprawdzanie przekrojów pionowych wzd³u¿ osi X
    for (int x = 0; x < NUM_CELLS_X; ++x) {
        double average = calculateVerticalSliceAverage(temperatureData, x, true);
        if (average > maxAverage) {
            maxAverage = average;
            bestIndex = x;
            isXSlice = true;
        }
    }

    // Sprawdzanie przekrojów pionowych wzd³u¿ osi Y
    for (int y = 0; y < NUM_CELLS_Y; ++y) {
        double average = calculateVerticalSliceAverage(temperatureData, y, false);
        if (average > maxAverage) {
            maxAverage = average;
            bestIndex = y;
            isXSlice = false;
        }
    }

    // Wyœwietlenie wyników
    if (isXSlice) {
        cout << "Najwieksza srednia temperatura znajduje sie w przekroju pionowym wzdluz osi X na indeksie: " << bestIndex << endl;
    } 
	else {
        cout << "Najwieksza srednia temperatura znajduje sie w przekroju pionowym wzdluz osi Y na indeksie: " << bestIndex << endl;
    }
    cout << "Srednia temperatura: " << maxAverage << endl;

    // Zwolnienie pamiêci
    freeTemperatureData(temperatureData);

    return 0;
}

