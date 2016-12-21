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

#include "UiText.h"
#include "UiButton.h"
#include "UiWritable.h"
#include "UiSliderButton.h"
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
	if(App->map->Load("iso_walk.tmx") == true)
	{
		int w, h;
		uchar* data = NULL;
		if(App->map->CreateWalkabilityMap(w, h, &data))
			App->pathfinding->SetMap(w, h, data);

		RELEASE_ARRAY(data);
	}

	debug_tex = App->tex->Load("maps/path2.png");

	
	
	//Image test
	UI_element* window = App->gui->create(UI_ELEMENT, nullptr);
	window->SetRect( 15,515,466,508 );
	window->SetPos(100, 100);
	window->viewport = true;

	//Button test
	UiButton* button = (UiButton*)App->gui->create(UI_BUTTON, window);
	button->SetRect(1, 110, 229, 70 );
	button->SetPos(75, 200);

	//Text test
	helloworld = (UiText*)App->gui->create(UI_LABEL, button);
	helloworld->SetSentence("Hello World \n Woabnk hjbf aha \n fjkdgjikag jdagkhjdfg vhjdfg dfa gjdfagh dfkajgh fa gjadfgkahj");
	helloworld->SetPos(50, 25);



	//Writable text testing
	UI_element* text_back = App->gui->create(UI_ELEMENT, window);
	text_back->SetRect(486,	564,350 ,69);
	text_back->SetPos(50, 100);

	UiWritable* writable = (UiWritable*)App->gui->create(UI_WRITABLE, text_back);
	writable->SetPos(0, 0);

/*
	//Slider
	UiMask* slidermask = (UiMask*)App->gui->create(UI_MASK, nullptr);
	slidermask->SetPos(0, 0);
	slidermask->SetRect(0, 0, 50, 50);

	UiMask* sliderrect = (UiMask*)App->gui->create(UI_MASK, nullptr);
	sliderrect->SetPos(100, 200);
	sliderrect->SetRect(972, 785, 15, 200);
	sliderrect->viewport = false;
	UiSliderButton* sliderbutton = (UiSliderButton*)App->gui->create(UI_SLIDERBUTTON, sliderrect);
	sliderbutton->SetPos(0, 5);
	sliderbutton->SetRect(843, 320, 15, 29);
	sliderbutton->linkedobj = slidermask;

	UiText* helloworld2 = (UiText*)App->gui->create(UI_LABEL, slidermask);
	helloworld2->SetSentence("2Hello World 2\n Woabnk hjbf aha \n fjkdgjikag jdagkhjdfg vhjdfg dfa gjdfagh dfkajgh fa gjadfgkahj");
	helloworld2->SetPos(0, 0);
	*/

/*
	UI_element* window2 = App->gui->create(UI_ELEMENT, nullptr);
	window2->SetRect(485, 829, 328, 103);
	window2->SetPos(100, 100);
	*/
	


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

	

	// debug pathfing ------------------
	static iPoint origin;
	static bool origin_selected = false;

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);


	if(App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		if(origin_selected == true)
		{
			App->pathfinding->CreatePath(origin, p);
			origin_selected = false;
		}
		else
		{
			origin = p;
			origin_selected = true;
		}
	}

	
		//App->gui->InputReader(iPoint(x, y), SDL_BUTTON_LEFT, App->input->GetMouseButtonDown(SDL_BUTTON_LEFT));

	
	

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

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= floor(200.0f * dt);

	App->map->Draw();

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);
	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%d,%d",
					App->map->data.width, App->map->data.height,
					App->map->data.tile_width, App->map->data.tile_height,
					App->map->data.tilesets.count(),
					map_coordinates.x, map_coordinates.y);

	//App->win->SetTitle(title.GetString());

	// Debug pathfinding ------------------------------
	//int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);
	p = App->map->MapToWorld(p.x, p.y);

	App->render->Blit(debug_tex, p.x, p.y);

	const p2DynArray<iPoint>* path = App->pathfinding->GetLastPath();

	for(uint i = 0; i < path->Count(); ++i)
	{
		iPoint pos = App->map->MapToWorld(path->At(i)->x, path->At(i)->y);
		App->render->Blit(debug_tex, pos.x, pos.y);
	}

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
