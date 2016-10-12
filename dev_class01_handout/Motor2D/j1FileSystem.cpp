#include "p2Defs.h"
#include "j1App.h"
#include "p2Log.h"
#include "j1FileSystem.h"
#include "SDL/include/SDL_rwops.h"
#include "SDL/include/SDL_filesystem.h"
#include "PhysFS/include/physfs.h"

#pragma comment( lib, "PhysFS/libx86/physfs.lib" )

j1FileSystem::j1FileSystem(const char* game_path) : j1Module()
{
	name.create("file_system");

	// TODO 1: Init PhysFS lib
	if (PHYSFS_init(game_path))
		LOG("PhysicsFS initialized");
	else
		LOG("Error at initializing PhysicsFS");

	// TODO 2: Mount directory ".", then mount "data.zip"
	// files in the folder should take precendence over the zip file!

	if(PHYSFS_mount("./", NULL, 0))
		LOG("PHYS MOUNT WORKED");

	if (PHYSFS_mount("./data.zip", NULL, 0))
		LOG("data.zip LOADED");

}

// Destructor
j1FileSystem::~j1FileSystem()
{
	// TODO 1: stop PhysFS lib
	if (PHYSFS_deinit())
		LOG("PhysucsFS deinitialized");
	else
		LOG("Error at deinitializing Physics");

}

// Called before render is available
bool j1FileSystem::Awake()
{
	LOG("Loading File System");
	bool ret = true;

	// This is a good place to setup the write dir (homework)

	return ret;
}

// Read a whole file and put it in a new buffer
unsigned int j1FileSystem::Load(const char* file, char** buffer) const
{
	unsigned int ret = 0;
	unsigned int len;

	PHYSFS_File* handle = PHYSFS_openRead(file);

	// TODO 3: Read a file and allocate needed bytes to buffer and write all data into it
	// return the size of the data
	if (handle != NULL) {
		
		LOG("test.png OPENED");
	
		len = PHYSFS_fileLength(handle);

		*buffer = new char[len];

		ret = PHYSFS_read(handle, *buffer, 1, len);

	}

	else
		LOG(PHYSFS_getLastError());


	return ret;
}

// Read a whole file and put it in a new buffer
SDL_RWops* j1FileSystem::Load(const char* file) const
{
	// TODO 4: Using our previous Load method
	// create a sdl rwops using SDL_RW_From_ConstMem()
	// and return it if everything goes well
	char* buffer = nullptr;
	
	int size = Load(file, &buffer);

	
	if (size > 0) 
	{
		SDL_RWops* rw = SDL_RWFromConstMem(buffer, size);
		if (rw != NULL)
			rw->close = close_sdl_rwops;

		return rw;
	}



	return NULL;
}

// TODO 4: you will need to use this small helper function
// to make sure all data is freed automatically
int close_sdl_rwops(SDL_RWops *rw)
{
	RELEASE(rw->hidden.mem.base);
	SDL_FreeRW(rw);
	return 0;
}
