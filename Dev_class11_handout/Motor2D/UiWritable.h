#ifndef __UIWRITABLE_H__
#define __UIWRITABLE_H__

#include "UiText.h"

class UiWritable : public UiText
{
public:
	
	UiWritable(UItype type, UI_element* parent, bool password);
	~UiWritable();


private:
	bool password;

};

#endif // !__UIWRITABLE_H__

