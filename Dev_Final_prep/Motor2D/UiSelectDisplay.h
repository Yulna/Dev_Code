#ifndef __UISELECTDISPLAY_H__
#define __UISELECTDISPLAY_H__

#include "UiSelectBox.h"


class UiSelectDisplay : public UI_element
{
	UiSelectDisplay(UItype type, UI_element* parent);
	~UiSelectDisplay();
};

#endif // !__UISELECTDISPLAY_H__

