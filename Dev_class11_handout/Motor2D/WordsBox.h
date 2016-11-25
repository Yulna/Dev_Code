#ifndef __WORDSBOX_H__
#define __WORDSBOX_H__

#include "UI_element.h"
#include "p2SString.h"
#include "p2Log.h"

 
class WordsBox : public UI_element
{
public:

	WordsBox(UItype type);
	~WordsBox();

	void Draw();
	virtual void PreUpdate() {};
	virtual void Update() { };
	virtual void handle_input() {};



	void SetSentence(const char* str);



protected:
	p2SString* words;


};



#endif // !__WORDSBOX_H__

