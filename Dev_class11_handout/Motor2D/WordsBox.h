#ifndef __WORDSBOX_H__
#define __WORDSBOX_H__

#include "UI_element.h"
#include "p2SString.h"

 
class WordsBox : public UI_element
{
public:

	WordsBox(UItype type);
	~WordsBox();

	virtual void PreUpdate() {};
	virtual void Update() {};
	virtual void handle_input() {};

	void SetSentence(p2SString* str);


private:
	p2SString* words;

};



#endif // !__WORDSBOX_H__

