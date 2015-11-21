#include "Module.h"

int Module::setActive() {
	onActivate();
	for (int i = 0; i < MAX_MODULES; i++) {
		if (Module::queue[i] == NULL) {
			Module::queue[i] = this;
			number_in_queue = i;
			return i;
		}
	}
	number_in_queue = NOT_IN_QUEUE;
	return ERR_QUEUE_FULL;
}
void Module::setInactive() {
	onDesactivate();
	if (number_in_queue != NOT_IN_QUEUE) {
		Module::queue[number_in_queue] = NULL;
	}
	number_in_queue = NOT_IN_QUEUE;
}
bool Module::isActive()
{
	if (number_in_queue == NOT_IN_QUEUE) {
		return false;
	}
	return true;
}
void Module::onActivate()
{

}
void Module::onDesactivate()
{
}
Module::Module()
{
	number_in_queue = NOT_IN_QUEUE;
//	setActive();
}

Module::~Module()
{
	setInactive();
}
Module* Module::queue[MAX_MODULES];