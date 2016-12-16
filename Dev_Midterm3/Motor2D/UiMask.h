#ifndef __UIMASK_H__
#define __UIMASK_H__

#include "UI_element.h"

//EXERCICE 3
class UiMask : public UI_element
{
public:
	UiMask(UItype type, UI_element* parent);
	~UiMask();

	//Class just to emplty the default draw of Ui_element
	void Draw();

};


#endif