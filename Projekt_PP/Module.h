#pragma once
#include "defines.h"
#include "includes.h"
class Module
{
private:
	int number_in_queue;
public:
	static Module* queue[MAX_MODULES];
	int setActive();
	void setInactive();
	bool isActive();
//	virtual void onInit() = 0;
	virtual void onFrame(key_buffer kb) = 0;
	virtual void onActivate();
	virtual void onDeactivate();
	Module();
	virtual ~Module();
};

