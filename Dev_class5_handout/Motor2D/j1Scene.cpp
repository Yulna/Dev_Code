#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");

	player_x = player_y = 10;
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& node)
{
	LOG("Loading Scene");
	bool ret = true;

	xspeed = node.child("cameraspeed").attribute("x").as_int(0);
	yspeed = node.child("cameraspeed").attribute("y").as_int(0);

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	App->map->Load("iso.tmx");

	debug_tex = App->tex->Load("textures/path.png");


	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y -= yspeed;

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y += yspeed;

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x -= xspeed;

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x += xspeed;


	// Move the player
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	{
		player_y--;
		player_x--;
	}


	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		player_y++;
		player_x++;
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{
		player_y++;
		player_x--;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
	{
		player_y--;
		player_x++;
	}

	App->map->Draw();

	// Debug pathfinding
	iPoint p = App->map->MapToWorld(player_x, player_y, MAPTYPE_ISOMETRIC);
	App->render->Blit(debug_tex, p.x, p.y);


	int x = 0;
	int y = 0;

	App->input->GetMousePosition(x, y);

	iPoint mouse_cordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);

	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%i, %i",
					App->map->data.width, App->map->data.height,
					App->map->data.tile_width, App->map->data.tile_height,
					App->map->data.tilesets.count(),
					mouse_cordinates.x , mouse_cordinates.y );

	App->win->SetTitle(title.GetString());

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
