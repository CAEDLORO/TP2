#pragma once
#include <iostream>
class Datapoint {
private:
	double latitude;
	double longitude;
	double temperature;
	std::string time;
public:
	Datapoint(double latitude, double longitude, double temperature, std::string time);
	double getLatitude();
	double getLongitude();
	double getTemperature();
	std::string getTime();
};