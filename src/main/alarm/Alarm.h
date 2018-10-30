#pragma once
#ifndef ALARM_H
#define ALARM_H

#include<iostream>
#include<vector>
using namespace std;

//Alarm_sysytem

class AlarmSys
{
public:
	static void alarm();
	static void alarmways(int num);
};

//Observer DP
class Observer
{
public:
	virtual void update(int value, int num) = 0;
};

//ObsControl_observerable
class Subject
{
	int m_value;
	vector<Observer*>m_views;
public:
	int attach(Observer *obs)
	{
		m_views.push_back(obs);
		return m_views.size();
	}
	void set_val(int value)
	{
		m_value = value;
		notify();
	}
	void notify()
	{
		for (int i = 0; i < m_views.size(); ++i)
			m_views[i]->update(m_value, i);
	}
};

//State DP

class Context
{
	class FireObsState *current;
public:
	Context(int num);
	void setCurrent(FireObsState *s)
	{
		current = s;
	}
	void on(int num);
	void off(int num);
};

class FireObsState
{
public:
	virtual void on(Context *m, int num)
	{
		cout << "FireObs" << num << "  " << "already ON\n";
	}
	virtual void off(Context *m, int num)
	{
		cout << "FireObs" << num << "  " << "already OFF\n";
	}
};

void Context::on(int num)
{
	current->on(this, num);
}

void Context::off(int num)
{
	current->off(this, num);
}

//on_state
class ON :public FireObsState
{
	int num;
public:
	ON(int n)
	{
		num = n;
	}
	~ON()
	{
		cout << "FireObs" << num << "  " << "State: OFF\n";
	}
	void off(Context *m, int num);
};

//off_state
class OFF :public FireObsState
{
	int num;
public:
	OFF(int n)
	{
		num = n;
	}
	~OFF()
	{
		cout << "FireObs" << num << "  " << "State: ON\n";
	}
	void on(Context *m, int num)
	{
		cout << "FireObs" << num << "  " << "going from OFF to ON\n";
		AlarmSys::alarmways(num);
		m->setCurrent(new ON(num));
		delete this;
	}
};

void ON::off(Context *m, int num)
{
	cout << "FireObs" << num << "  " << "going from ON to OFF\n";
	m->setCurrent(new OFF(num));
	delete this;
}

Context::Context(int num)
{
	current = new OFF(num);
}


//FireObserver

class FireObserver : public Observer
{
	int mynum;
	Context ctrl = Context(1);
public:
	FireObserver(Subject *model)
	{
		mynum = model->attach(this);
		ctrl = Context(mynum - 1);
	}
	/*virtual*/void update(int v, int num)
	{
		void(Context:: *ptrs[])(int num) =
		{
			&Context::off,&Context::on
		};
		(ctrl.*ptrs[v])(num);
	}
};

#endif
