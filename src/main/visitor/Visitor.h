#pragma once
#ifndef VISITOR_H
#define VISITOR_H
class Cotton;
class Wheat;
// ทรฮสี฿
class IVisitor
{
public:
	virtual ~IVisitor() {}
	virtual void Visit(Cotton *) = 0;
	virtual void Visit(Wheat *) = 0;
};

#endif // VISITOR_H
