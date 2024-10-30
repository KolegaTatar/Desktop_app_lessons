#include <iostream>
#include "Object.h"


using namespace std;
int main() {
	PunktA *punkt2 = new PunktA();
	punkt2->setX(34.5);
	punkt2->setY(32.5);
	cout<< punkt2->getX() << endl;
	cout<< punkt2->getY() << endl;
	return 0;
}

