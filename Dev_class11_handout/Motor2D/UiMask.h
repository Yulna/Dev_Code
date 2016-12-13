#ifndef __UIMASK_H__
#define __UIMASK_H__

#include "UI_element.h"

class UiMask : public UI_element
{
public:
	UiMask(UItype type, UI_element* parent);
	~UiMask();

	void Draw();

};


#endif