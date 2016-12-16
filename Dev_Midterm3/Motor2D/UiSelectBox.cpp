#include "UiSelectBox.h"
#include "j1Input.h"
#include "j1App.h"
#include "SDL/include/SDL.h"

UiSelectBox::UiSelectBox(UItype type, UI_element * parent) : UI_element(type, parent)
{
	slctstate = SLCT_STANDBY;
}

UiSelectBox::~UiSelectBox()
{
}

void UiSelectBox::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	//EXERCICE 2 & 3
	switch (slctstate)
	{
	case SLCT_STANDBY:
		
		if (key == SDL_BUTTON_LEFT && keystate == KEY_DOWN && mouseIn(mousepos.x, mousepos.y))
		{
			slctstate = SLCT_ACTIVE;
		}


		break;
	case SLCT_ACTIVE:

		if (key == SDL_BUTTON_LEFT)
		{
			int x, y;
			App->input->GetMouseMotion(x, y);
			if (parent != nullptr) 
			{
				if ((parent->GetGlobalPos().y < GetGlobalPos().y + y) && (parent->GetGlobalPos().y + parent->rect->h) > (GetGlobalPos().y+rect->h+y))
				{
					Move(0, y);
					
					linkedobj->Move(0, -y*hrelation);
				}
				if ((parent->GetGlobalPos().x < GetGlobalPos().x + x) && (parent->GetGlobalPos().x + parent->rect->w) >(GetGlobalPos().x + rect->w + x))
				{
					Move(x, 0);
				
					linkedobj->Move(-x*wrelation, 0);
				}
			}
			else
			{
				Move(x, y);
			}



			if (keystate == KEY_UP)
			{
				slctstate = SLCT_STANDBY;


				//Exercice 4
				float champw = parent->rect->w / 5;
				float champh = parent->rect->h / 2;

				int champtileX = (pos.x + rect->w / 2) / champw;
				int champtileY = (pos.y + rect->h / 2) / champh;
				SetPos(champtileX*champw, champtileY*champh);
				linkedobj->SetPos(-pos.x*wrelation, -pos.y*hrelation);

				
			}
		}

		


		break;
	default:
		break;
	}


}

void UiSelectBox::SetAmplification(UI_element * amplified)
{
	linkedobj = amplified;
	wrelation = float(linkedobj->rect->w) / float(parent->rect->w);
	hrelation = float(linkedobj->rect->h) / float(parent->rect->h);
}
