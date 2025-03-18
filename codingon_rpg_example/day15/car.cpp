#include "car.h"

Car::Car(string b) : brand(b) {}

void Car::show() {
	cout << "차의 브랜드는: " << brand << endl;
}