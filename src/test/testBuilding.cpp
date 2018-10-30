#include "building.h"
int main() {
	BuildingBuilder *farm=new BuildFarm();
	farm->configureDoor();
	farm->configureFence();
	farm->configureFloor();
	farm->configureRoof();
	farm->configureWall();

	BuildingBuilder *house=new BuildHouse;
	house->configureDoor();
	house->configureFence();
	house->configureFloor();
	house->configureRoof();
	house->configureWall();

	cout << farm->getResult()->ReturnName() << " " << endl;
	cout << farm->getResult()->ReturnDoor() << " " << endl;
	cout << farm->getResult()->ReturnFence() << " " << endl;
	cout << farm->getResult()->ReturnWall() << " " << endl;
	cout << farm->getResult()->ReturnRoof() << " " << endl;
	cout << farm->getResult()->ReturnFloor() << " " << endl;
	
	cout<<house->getResult()->ReturnName() << " " << endl;
	cout << house->getResult()->ReturnDoor() << " " << endl;
	cout << house->getResult()->ReturnFence() << " " << endl;
	cout << house->getResult()->ReturnWall() << " " << endl;
	cout << house->getResult()->ReturnRoof() << " " << endl;
	cout << house->getResult()->ReturnFloor() << " " << endl;
	cin.get();



}
