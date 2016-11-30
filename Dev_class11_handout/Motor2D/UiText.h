#ifndef __UITEXT_H__
#define __UITEXT_H__

#include "UI_element.h"
#include "p2SString.h"


 
class UiText : public UI_element
{
public:

	UiText(UItype type, UI_element* parent);
	~UiText();

	void Draw();
	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate);

	void SetSentence(const char* str);



protected:
	p2SString* words;


};



#endif // !__WORDSBOX_H__

