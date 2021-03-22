#include "Datapoint.h"

Datapoint::Datapoint(double latitude, double longitude, double temperature, std::string time){
	this->latitude = latitude;
	this->longitude = longitude;
	this->temperature = temperature;
	this->time = time;
}

double Datapoint::getLatitude() {
	return this->latitude;
}

double Datapoint::getLongitude() {
	return this->longitude;
}

double Datapoint::getTemperature() {
	return this->temperature;
}

std::string Datapoint::getTime()
{
	return this->time;
}

