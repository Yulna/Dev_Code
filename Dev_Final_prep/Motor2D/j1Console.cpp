#include "j1Console.h"
#include "j1Input.h"
#include "j1App.h"
#include "p2Log.h"
#include "SDL\include\SDL.h"

j1Console::j1Console()
{
	name.create("console");
}

j1Console::~j1Console()
{
}



bool j1Console::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_GRAVE) == KEY_DOWN)
	{
	
		
		LOG("Console should open");
	};


	return true;
}
