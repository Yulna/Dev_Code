#ifndef __UISLDIERBUTTON_H__
#define __UISLIDERBUTTON_H__

#include "UiButton.h"

class UiSliderButton : public UiButton
{
public:
	UiSliderButton(UItype type, UI_element* parent);
	~UiSliderButton();


	void handle_input(iPoint mousepos, int key, j1KeyState keystate);

public:
	UI_element* linkedobj;

private:
	int movlimit = 50;

};



#endif // !__UISLDIERBUTTON_H__
