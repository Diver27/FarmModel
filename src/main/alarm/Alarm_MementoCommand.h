#pragma once
#ifndef ALARM_MEMENTOCOMMAND_H
#define ALARM_MEMENTOCOMMAND_H
#include "../alarm/Alarm.h"

#include<iostream>
#include<vector>
using namespace std;


//Memento&Command

class AlarmOperation;

class Memento
{
public:
	Memento(int val)
	{
		_state = val;
	}
private:
	friend class AlarmOperation;
	int _state;
};

//Memento&Command_operation

class AlarmOperation
{
public:
	AlarmOperation(int value)
	{
		_value = value;
	}
	void light()
	{
		_value = 1;
	}
	void sound()
	{
		_value = 0;

	}
	int getValue()
	{
		return _value;
	}
	Memento* createMemento()
	{
		return new Memento(_value);
	}
	void reinstateMemento(Memento* mem)
	{
		_value = mem->_state;
	}
private:
	int _value;
};

//Command&Memento DP

class Command
{
public:
	typedef void(AlarmOperation::*Action)();
	Command(AlarmOperation* receiver, Action action)
	{
		_receiver = receiver;
		_action = action;
	}
	virtual void execute()
	{
		_mementoList[_numCommands] = _receiver->createMemento();
		_commandList[_numCommands] = this;
		if (_numCommands > _highWater)
			_highWater = _numCommands;
		_numCommands++;
		(_receiver->*_action)();
	}
	static void undo()
	{
		if (_numCommands == 1)
		{
			cout << "*** Run off the end!! ***" << endl;
			return;
		}
		_commandList[_numCommands - 1]->_receiver->reinstateMemento(_mementoList[_numCommands - 1]);
		_numCommands--;
	}
	void static redo()
	{
		if (_numCommands > _highWater)
		{
			cout << "*** Run off the end!! ***" << endl;
			return;
		}
		(_commandList[_numCommands]->_receiver->*(_commandList[_numCommands]->_action))();
		_numCommands++;
	}
protected:
	AlarmOperation* _receiver;
	Action _action;
	static Command* _commandList[20];
	static Memento* _mementoList[20];
	static int _numCommands;
	static int _highWater;
};

Command* Command::_commandList[];
Memento* Command::_mementoList[];
int Command::_numCommands = 0;
int Command::_highWater = 0;

void AlarmSys::alarmways(int num)
{
	int i;
	AlarmOperation *object = new AlarmOperation(5);

	Command *commands[3];
	commands[1] = new Command(object, &AlarmOperation::light);
	commands[2] = new Command(object, &AlarmOperation::sound);

	cout << "Alarm" << num << ": exit[0], light[1], sound[2], undo[3], redo[4]:";
	cin >> i;

	while (i)
	{
		if (i == 3)
			Command::undo();
		else if (i == 4)
			Command::redo();
		else if (i == 1 || i == 2)
			commands[i]->execute();
		else
		{
			cout << "Error" << endl;
		}
		if (object->getValue() == 1)
			cout << "Light" << endl;
		else if (object->getValue() == 0)
			cout << "Sound" << endl;
		cout << "Alarm" << num << ": exit[0], light[1], sound[2], undo[3], redo[4]:";
		cin >> i;
	}
}

void AlarmSys::alarm()
{
	Subject subj;
	FireObserver fObs1(&subj);
	FireObserver fObs2(&subj);
	FireObserver fObs3(&subj);
	int num;


	cout << "InitialState:OFF " << endl;
	cout << "Enter 0/1   (0:OFF, 1:ON, 2:exit)\n";
	cin >> num;
	while (num!=2) {
		if (num != 0 && num != 1)
		{
			cout << "Error" << endl;
			break;
		}
		subj.set_val(num);
		cout << "\nEnter 0/1   (0:OFF, 1:ON, 2:exit)\n";
		cin >> num;
	}

}

#endif
