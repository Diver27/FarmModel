#ifndef ITERATOR_H
#define ITERATOR_H
#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
// interface for iterator
class Iterator {
public:
	virtual ~Iterator() {}

	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool isEnd() = 0;
	virtual T * CurItem() = 0;
};
//iterface for container
template <typename T>
class Container {
public:
	Container() = default;
	virtual ~Container() {}
	virtual int getSize() = 0;
	virtual void pushItem(const T & item) = 0;
	virtual T &operator[](int index) = 0;
	virtual Iterator<T> * getIterator() = 0;
};
//创建实现了 Container 接口的实体类 
template <typename T>
class ConcreteContainer : public  Container<T> {
public:
	virtual ~ConcreteContainer() {
		if (_iterator)
			delete(_iterator);
	}

	int getSize() override {
		return _data.size();
	}

	void pushItem(const T &item) override {
		_data.push_back(item);
	}

	T &operator[](int index) override {
		return _data[index];
	}

	Iterator<T> *getIterator() override {
		if (_iterator)
			return _iterator;
		else
			return _iterator = new ConcreteIterator<T>(this);
	}

private:
	std::vector<T> _data;
	Iterator<T> * _iterator{ nullptr };
};
//创建迭代器实现类
template <typename T>
class ConcreteIterator : public Iterator<T> {
public:
	ConcreteIterator(Container<T> * container) :_container(container), _curIndex(0) {
	}

	void First() override {
		_curIndex = 0;
	}

	void Next() override {
		if (_curIndex < _container->getSize())
			_curIndex++;
	}

	bool isEnd() override {
		return _curIndex >= _container->getSize();
	}

	T * CurItem() override {
		if (_curIndex < _container->getSize()) {
			return &(*_container)[_curIndex];
		}
		else {
			return nullptr;
		}
	}

private:
	Container<T> * _container;
	int _curIndex;
};
#endif
/*
int main(void)
{
	Container<int> * container = new ConcreteContainer<int>();
	container->pushItem(1);
	container->pushItem(2);
	container->pushItem(3);
	container->pushItem(4);
	Iterator<int> * iterator = container->getIterator();
	for (iterator->First(); !iterator->isEnd(); iterator->Next()) {
		std::cout << *iterator->CurItem() << std::endl;
	}
	system("pause");
	return 0;
}
*/
