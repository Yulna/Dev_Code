#include "UiButton.h"


UiButton::UiButton(UItype type) : UI_element(type)
{
	linkedText = nullptr;
}

UiButton::~UiButton()
{
	if (linkedText != nullptr)
		delete linkedText;
}
