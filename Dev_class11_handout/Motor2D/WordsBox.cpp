#include "WordsBox.h"

WordsBox::WordsBox(UItype type) : UI_element(type)
{
}

WordsBox::~WordsBox()
{
}

void WordsBox::SetSentence(p2SString * str)
{
	words = str;
}
