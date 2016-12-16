#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1PathFinding.h"
#include "j1Gui.h"
#include "j1Scene.h"

#include "UiSelectBox.h"
#include "UiButton.h"
#include "UiText.h"
#include "UiMask.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	
	
	
	//EXERCICE 1
	UI_element* background = App->gui->create(UI_ELEMENT, nullptr);
	background->SetRect(0, 1600, 1024, 576);
	background->SetPos(0,0);
	
	UI_element* window = App->gui->create(UI_ELEMENT, background);
	window->SetRect(15, 515, 466, 508);
	window->SetPos(20, 50);
	
	UiButton* button = (UiButton*)App->gui->create(UI_BUTTON, window);
	button->SetRect(1, 110, 229, 70);
	button->SetPos(110, 400);

	UiText* continue_ = (UiText*)App->gui->create(UI_LABEL, button);
	continue_->SetSentence("Continue");
	continue_->SetPos(60,18);
	UiText* title = (UiText*)App->gui->create(UI_LABEL, window);
	title->SetSentence("Select Your Character");
	title->SetPos(110, 40);


	//EXERCICE 2
	UI_element* thumbnail = App->gui->create(UI_ELEMENT, window);
	thumbnail->SetRect(0,290, 300, 169);
	thumbnail->SetPos(90, 175);

	//UiSelectBox used as a lens tool
	UiSelectBox* selector = (UiSelectBox*)App->gui->create(UI_SELECTBOX, thumbnail);
	selector->SetRect(900, 314, 68, 54);


	//EXERCICE 3
	UiMask* amplifiedviewport = (UiMask*)App->gui->create(UI_MASK, background);
	amplifiedviewport->SetRect(0, 0, 300,287);
	amplifiedviewport->SetPos(600, 150);

	UI_element* bigthumbnail = App->gui->create(UI_ELEMENT, amplifiedviewport);
	bigthumbnail->SetRect(0, 1024, 205*5, 287*2);
	selector->SetAmplification(bigthumbnail);
	


	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	
	{
		int x, y;
		App->input->GetMousePosition(x, y); 
		App->gui->InputReader(iPoint(x, y));
	}

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	// Gui ---
	
	// -------
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");



	



	

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
