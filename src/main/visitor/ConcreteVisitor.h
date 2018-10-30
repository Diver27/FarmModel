#pragma once
#ifndef CONCRETE_VISITOR_H
#define CONCRETE_VISITOR_H

#include "Visitor.h"
#include "../plants/Wheat.h"
#include "../plants/Cotton.h"
// StaffA
class StaffA : public IVisitor
{
public:
	virtual void Visit(Cotton *) {
		std::cout << "I will sell these cotton!" << std::endl;
	}

	virtual void Visit(Wheat *) {
		std::cout << "I will sell these Wheat!" << std::endl;
	}
};

// StaffB
class StaffB : public IVisitor
{
public:
	virtual void Visit(Cotton  *) {
		std::cout << "I will processing these cotton!" << std::endl;
	}

	virtual void Visit(Wheat *) {
		std::cout << "I will process these wheat!" << std::endl;
	}
};

#endif // CONCRETE_VISITOR_H
