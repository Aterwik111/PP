#pragma once
class Level
{
public:
	virtual void onEnter(int param);
	virtual void onFrame(key_buffer kb);
	virtual void onExit();
	Level();
	virtual ~Level();
};

