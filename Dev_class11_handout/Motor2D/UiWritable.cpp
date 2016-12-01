#include "UiWritable.h"

UiWritable::UiWritable(UItype type, UI_element * parent, bool password = false) : UiText(type, parent), password(password)
{
}
