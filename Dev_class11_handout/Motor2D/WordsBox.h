#ifndef __WORDSBOX_H__
#define __WORDSBOX_H__

#include "UI_element.h"


 
class WordsBox : public UI_element
{
public:

	virtual void PreUpdate() {};
	virtual void Update() {};
	virtual void handle_input() {};


private:
	p2SString* words;

};



#endif // !__WORDSBOX_H__

