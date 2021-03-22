//Carlos Lozano TP2
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <queue>
#include "Datapoint.h"
// "Compare" je l’utilise pour pouvoir comparer et trier les objets Datapoint dans le prioryty_queue.
class Compare {
public:
	bool operator()(Datapoint &d1, Datapoint &d2) {
		if (d1.getLatitude() == d2.getLatitude()) {
			return d1.getLongitude() > d2.getLongitude();
		}
		return d1.getLatitude() < d2.getLatitude();
	}
};

int main()
{
	std::priority_queue<Datapoint, std::vector <Datapoint> , Compare> Q;

	std::ifstream inputfile("rawdata.txt");//Instancier l’objet pour lire le fichier rawdata.
	double latitudeUsa;
	double longitudeUsa;
	int temperatureUsa;
	std::string stationUsa;
	std::string timeUsa;
	double latitudeCan;
	double longitudeCan;
	double temperatureCan;
	std::string stationCan;
	std::string timeCan;
	//Je vais parcourir le fichier et prendre les données du fichier USA.
	while (inputfile >> latitudeUsa >> longitudeUsa >> stationUsa >> temperatureUsa >> timeUsa) {
		latitudeCan = latitudeUsa;
		//Je fais la transformation demandée de latitude. (Enlever des décimales qui sont = 0)
		if ((double)(int)latitudeUsa - latitudeUsa == 0) {
			latitudeCan = (int)latitudeUsa;
		}
		longitudeCan = longitudeUsa;
		//Je fais la transformation demandée de latitude. (Enlever des décimales qui sont = 0)
		if ((double)(int)longitudeUsa - longitudeUsa == 0) {
			longitudeCan = (int)longitudeUsa;
		}
		//conversion de Farenheit en Celcius.
		temperatureCan = (temperatureUsa - 32.0) / 1.8;
		timeCan = timeUsa;
		
		Datapoint datapoint(latitudeCan, longitudeCan, temperatureCan, timeCan);
		Q.push(datapoint);//Il met le nouvel objet datapoint dans la priority_queue
	}

	std::ofstream fileOut;
	fileOut.open("candata.txt");//Il ouvre le fichier Canada
	//Parcourir les objets et en extraire ceux qui ont la plus grande latitude
	while (!Q.empty()) {
		Datapoint data = Q.top();
		Q.pop();
		//J’écris la ligne dans le nouveau dossier de Candata.
		fileOut << data.getTime() << " " << data.getLatitude() << " " << data.getLongitude() << " " << data.getTemperature() << '\n';
	}

}