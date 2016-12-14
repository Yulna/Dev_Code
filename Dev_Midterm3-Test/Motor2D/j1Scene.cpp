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
	
	
	
	//Image test
	UI_element* window = App->gui->create(UI_ELEMENT, nullptr);
	window->SetRect(970, 1844, 768, 579);
	window->SetPos(0,0);


	UI_element* characterbox = App->gui->create(UI_ELEMENT, window);
	characterbox->SetRect(1209, 1935, 288, 191);
	characterbox->SetPos(239, 91);



	//Button test
	player1 = (UiSelectBox*)App->gui->create(UI_SELECTBOX, characterbox);
	player1->SetRect(1485, 110, 72, 109 );
	player1->SetPos(0, -12);


	UiSelectBox* player2 = (UiSelectBox*)App->gui->create(UI_SELECTBOX, characterbox);
	player2->SetRect(1560, 110, 72, 109);
	player2->SetPos(72, -12);
	player2->slctstate = SLCT_ACTIVE;




	




	


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
