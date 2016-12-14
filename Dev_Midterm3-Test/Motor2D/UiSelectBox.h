#ifndef __UI_SELECTBOX_H__
#define __UI_SELECTBOX_H__

#include "UI_element.h"

enum SelectState
{
	SLCT_STANDBY,
	SLCT_ACTIVE
};

class UiSelectBox : public UI_element
{
public:
	UiSelectBox(UItype type, UI_element* parent);
	~UiSelectBox();

	void handle_input(iPoint mousepos, int key, j1KeyState keystate);

public:
	SelectState slctstate;

};


#endif // !__UI_SELECTBOX_H__

