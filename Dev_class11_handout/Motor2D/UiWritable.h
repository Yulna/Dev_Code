#ifndef __UIWRITABLE_H__
#define __UIWRITABLE_H__

#include "UiText.h"

enum WriteState
{
	STAN2DBY,
	WRITING
};


class UiWritable : public UiText
{
public:
	
	UiWritable(UItype type, UI_element* parent);
	UiWritable(UItype type, UI_element* parent, bool password);
	~UiWritable();

	void handle_input(iPoint mousepos, int key, j1KeyState keystate);



private:
	bool password;
//	WriteState wstate = STANDBY;
};

#endif // !__UIWRITABLE_H__

