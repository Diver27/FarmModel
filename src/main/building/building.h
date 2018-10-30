#include<iostream>
using namespace std;
class Building
{
public:
	Building(char* fn) {
		strncpy(name, fn, sizeof(name));
	}
	void SetDoor(bool fn) { 
		IsNeedDoor = fn; 
	}

	void SetWall(bool fn) { 
		IsNeedWall = fn; 
	}

	void SetFloor(bool fn) { 
		IsNeedFloor = fn; 
	}

	void SetRoof(bool fn) { 
		IsNeedRoof = fn; 
	}

	void SetFence(bool fn) { 
		IsNeedFence = fn;
	}

	char* ReturnName() { 
		return name; 
	}

	bool ReturnDoor(){ 
		return IsNeedDoor;
	}

	bool ReturnWall() { 
		return IsNeedWall;
	}

	bool ReturnFloor() { 
		return IsNeedFloor;
	}

	bool ReturnRoof() { 
		return IsNeedRoof;
	}

	bool ReturnFence() { 
		return IsNeedFence;
	}
private:
	char name[20];
	bool IsNeedDoor;
	bool IsNeedWall;
	bool IsNeedFloor;
	bool IsNeedRoof;
	bool IsNeedFence;
};
class BuildingBuilder
{
public:
	virtual void configureDoor() = 0;
	virtual void configureRoof() = 0;
	virtual void configureWall() = 0;
	virtual void configureFloor() = 0;
	virtual void configureFence() = 0;
	Building* getResult() {
		return result;
	}
protected:
	Building* result;
};
class BuildFarm :public BuildingBuilder
{
public:
	BuildFarm() {
		char name[20] = "Farm";
		result = new Building(name);
	}
	void configureDoor() {
		result->SetDoor(true);
	}
	void configureRoof() {
		result->SetRoof(false);
	}
	void configureWall() {
		result->SetWall(false);
	}
	void configureFloor() {
		result->SetFloor(false);
	}
	void configureFence() {
		result->SetFence(true);
	}
};
class BuildHouse :public BuildingBuilder
{
public:
	BuildHouse() {
		char name[20] = "House";
		result = new Building(name);
	}
	void configureDoor() {
		result->SetDoor(true);
	}
	void configureRoof() {
		result->SetRoof(true);
	}
	void configureWall() {
		result->SetWall(true);
	}
	void configureFloor() {
		result->SetFloor(true);
	}
	void configureFence() {
		result->SetFence(false);
	}
};
