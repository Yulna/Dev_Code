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
#include "UiWritable.h"
#include "UiMask.h"
#include "UiSliderButton.h"
#include "UiSelectBox.h"

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


	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

UI_element * j1Gui::create(UItype type, UI_element* parent)
{
	//Elements factory
	//Need to delete this at cleanup

	switch (type)
	{
	case UI_ELEMENT:
		return elements.add(new UI_element(type, parent))->data;
		break;
	case UI_MASK:
		return elements.add(new UiMask(type, parent))->data;
		break;
	case UI_SELECTBOX:
		return elements.add(new UiSelectBox(type, parent))->data;
		break;
	case UI_BUTTON:
		return elements.add(new UiButton(type, parent))->data;
		break;
	case UI_SLIDERBUTTON:
		return elements.add(new UiSliderButton(type, parent))->data;
		break;
	case UI_LABEL:
		return elements.add(new UiText(type, parent))->data;
		break;
	case UI_WRITABLE:
		return elements.add(new UiWritable(type, parent))->data;
		break;
	default:
		break;
	}

}

void j1Gui::InputReader(iPoint mousepos)
{

	p2List_item<UI_element*>* item;

	//Store the keys pressed and then call the handle_input with them
	
	int inputKey = 0;
	j1KeyState inputState = KEY_IDLE;


	//Keyboard
	for (int i = 0; i < MAX_KEYS; i++) 
	{
		
		if (App->input->keyboard[i] != KEY_IDLE)
		{
			inputKey = i;
			inputState = App->input->keyboard[i];
		}
	}

	for (item = elements.start; item != nullptr; item = item->next)
	{
		item->data->handle_input(mousepos, inputKey, inputState);
	}
	inputKey = 0;
	inputState = KEY_IDLE;

	//Mouse buttons
	for (int i = 0; i < NUM_MOUSE_BUTTONS; i++) 
	{

		if (App->input->mouse_buttons[i] != KEY_IDLE)
		{
		
				//Is i+1  since SDL mouse id list starts with 1 and our mouse_button array starts with 0
				inputKey = i + 1;
				inputState = App->input->mouse_buttons[i];
		}
	}
	
	//Mouse input call
	for (item = elements.start; item != nullptr; item = item->next)
	{
		item->data->handle_input(mousepos, inputKey, inputState);
	}

	
}

// class Gui ---------------------------------------------------
