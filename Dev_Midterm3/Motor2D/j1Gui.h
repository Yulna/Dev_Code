#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "UI_element.h"

#define CURSOR_WIDTH 2


// ---------------------------------------------------
class j1Gui : public j1Module
{
public:



	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


	// Gui creation functions

	SDL_Texture* GetAtlas() const;
	UI_element* create(UItype type, UI_element* parent);

	void InputReader(iPoint mousepos);

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;

	p2List<UI_element*> elements;


};

#endif // __j1GUI_H__