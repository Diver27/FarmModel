#ifndef PLANTSPROTOTYPE_H
#define PLANTSPROTOTYPE_H

#include <vector>
using namespace std;

enum PlantType
{
	cotton, wheat
};

class AbstractPlant
{
public:
	virtual void draw() = 0;
	static AbstractPlant *findAndClone(PlantType);
protected:
	virtual PlantType returnType() = 0;
	virtual AbstractPlant *clone() = 0;
	// As each subclass of AbstractPlant is declared, it registers its prototype
	void addPrototype(AbstractPlant *plant)
	{
		_prototypes[_nextSlot++] = plant;
		farmField.push_back(plant);
	}
private:
	// addPrototype() saves each registered prototype here
	static AbstractPlant *_prototypes[2];
	static int _nextSlot;
	vector<AbstractPlant*> farmField;
};

AbstractPlant *AbstractPlant::_prototypes[];
int AbstractPlant::_nextSlot;

// Client calls this public static member function when it needs an instance
// of an AbstractPlant subclass
AbstractPlant *AbstractPlant::findAndClone(PlantType type)
{
	for (int i = 0; i < _nextSlot; i++)
		if (_prototypes[i]->returnType() == type)
			return _prototypes[i]->clone();
	return NULL;
}

class Cotton : public AbstractPlant
{
public:
	PlantType returnType()
	{
		return cotton;
	}
	void draw()
	{
		std::cout << "You have " << _id << " CottonFields." << std::endl;
	}
	// When clone() is called, call the one-argument ctor with a dummy arg
	AbstractPlant *clone()
	{
		return new Cotton(1);
	}
protected:
	// This is only called from clone()
	Cotton(int dummy)
	{
		_id = _count++;
	}
private:
	// Mechanism for initializing an AbstractPlant subclass - this causes the
	// default ctor to be called, which registers the subclass's prototype
	static Cotton _Cotton;
	// This is only called when the private static data member is initiated
	Cotton()
	{
		addPrototype(this);
	}
	// Nominal "state" per instance mechanism
	int _id;
	static int _count;
};

// Register the subclass's prototype
Cotton Cotton::_Cotton;
// Initialize the "state" per instance mechanism
int Cotton::_count = 1;

class Wheat : public AbstractPlant
{
public:
	PlantType returnType()
	{
		return wheat;
	}
	void draw()
	{
		std::cout << "You have " << _id << " WheatFields." << std::endl;
	}
	AbstractPlant *clone()
	{
		return new Wheat(1);
	}
protected:
	Wheat(int dummy)
	{
		_id = _count++;
	}
private:
	Wheat()
	{
		addPrototype(this);
	}
	static Wheat _Wheat;
	int _id;
	static int _count;
};

Wheat Wheat::_Wheat;
int Wheat::_count = 1;

#endif //PLANTSPROTOTYPE_H