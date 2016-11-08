#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "j1Module.h"

class j1Player : public j1Module
{
public:
	j1Player();

	//
	~j1Player();


	//Update ticks
	bool UpdateTicks();

};



#endif // !__j1PLAYER_H__

