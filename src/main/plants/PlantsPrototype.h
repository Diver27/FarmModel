#ifndef PLANTSPROTOTYPE_H
#define PLANTSPROTOTYPE_H

enum PlantType
{
	Cotton, Wheat
};

class Plant
{
public:
	virtual void draw() = 0;
	static Plant *findAndClone(PlantType);
protected:
	virtual PlantType returnType() = 0;
	virtual Plant *clone() = 0;
	// As each subclass of Plant is declared, it registers its prototype
	static void addPrototype(Plant *plant)
	{
		_prototypes[_nextSlot++] = plant;
	}
private:
	// addPrototype() saves each registered prototype here
	static Plant *_prototypes[2];
	static int _nextSlot;
};

Plant *Plant::_prototypes[];
int Plant::_nextSlot;

// Client calls this public static member function when it needs an instance
// of an Plant subclass
Plant *Plant::findAndClone(PlantType type)
{
	for (int i = 0; i < _nextSlot; i++)
		if (_prototypes[i]->returnType() == type)
			return _prototypes[i]->clone();
	return NULL;
}

class CottonField : public Plant
{
public:
	PlantType returnType()
	{
		return Cotton;
	}
	void draw()
	{
		std::cout << "You have " << _id << " CottonFields." << std::endl;
	}
	// When clone() is called, call the one-argument ctor with a dummy arg
	Plant *clone()
	{
		return new CottonField(1);
	}
protected:
	// This is only called from clone()
	CottonField(int dummy)
	{
		_id = _count++;
	}
private:
	// Mechanism for initializing an Plant subclass - this causes the
	// default ctor to be called, which registers the subclass's prototype
	static CottonField _CottonField;
	// This is only called when the private static data member is initiated
	CottonField()
	{
		addPrototype(this);
	}
	// Nominal "state" per instance mechanism
	int _id;
	static int _count;
};

// Register the subclass's prototype
CottonField CottonField::_CottonField;
// Initialize the "state" per instance mechanism
int CottonField::_count = 1;

class WheatField : public Plant
{
public:
	PlantType returnType()
	{
		return Wheat;
	}
	void draw()
	{
		std::cout << "You have " << _id << " WheatFields." << std::endl;
	}
	Plant *clone()
	{
		return new WheatField(1);
	}
protected:
	WheatField(int dummy)
	{
		_id = _count++;
	}
private:
	WheatField()
	{
		addPrototype(this);
	}
	static WheatField _WheatField;
	int _id;
	static int _count;
};

WheatField WheatField::_WheatField;
int WheatField::_count = 1;

#endif //PLANTSPROTOTYPE_H
