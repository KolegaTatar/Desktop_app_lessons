#include "Object.h"

double PunktA::getX() {
	return x;
}
double PunktA::getY() {
	return y;
}
void PunktA::setX(double x) {
	this->x = x;
}
void PunktA::setY(double y) {
	this->y = y;
}
PunktA::PunktA(){ };
PunktA::PunktA(double x, double y){ 
	this->x = x;
	this->y = y;
};
