#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "UiText.h"
#include "UiButton.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());


	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{

	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	p2List_item<UI_element*>* item;
	
	for (item = elements.start; item != nullptr ; item = item->next )
	{
			item->data->Draw();
	}


	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	//TODO: delete elements list

	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

UI_element * j1Gui::create(UItype type)
{
	//Elements factory
	//Need to delete this at cleanup

	switch (type)
	{
	case UI_ELEMENT:
		return elements.add(new UI_element(type))->data;
		break;
	case BUTTON:
		return elements.add(new UiButton(type))->data;
		break;
	case WORDSBOX:
		return elements.add(new UiText(type))->data;
		break;
	case WRITABLEBOX:
		break;
	default:
		break;
	}

}

void j1Gui::InputReader(iPoint mousepos, int key, j1KeyState keystate)
{
	p2List_item<UI_element*>* item;

	for (item = elements.start; item != nullptr; item = item->next)
	{
			item->data->handle_input(mousepos, key, keystate);
	}

}

// class Gui ---------------------------------------------------
