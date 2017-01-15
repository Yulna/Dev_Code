#ifndef __UiLabel_H__
#define __UiLabel_H__

#include "UI_element.h"
#include "p2SString.h"


 
class UiLabel : public UI_element
{
public:

	UiLabel(UItype type, UI_element* parent);
	~UiLabel();

	virtual void Draw();
	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate);

	void SetSentence(const char* str);



protected:
	p2SString* words = nullptr;
	

};



#endif // !__WORDSBOX_H__

