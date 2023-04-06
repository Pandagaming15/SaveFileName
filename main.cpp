#include "library.h"

// SAUtils
#include <isautils.h>
ISAUtils* sautils = NULL;

#define sizeofA(__aVar)  ((int)(sizeof(__aVar)/sizeof(__aVar[0])))
MYMODCFG(SaveGameFileName, SaveGameFileName, 1.0, PandaGaming)

ConfigEntry* name;

extern "C" void OnModLoad()
{
	/*
	sautils = (ISAUtils*)GetInterface("SAUtils");
    if(sautils != nullptr) 
    {
    sautils->AddSettingsTabButton("Discord", Open, "menu_maindiscord", NULL);
    }*/
	name = cfg->Bind("Name", "GTASAMP", "SaveFile");
	CHook::MemCopy((char*)libs.pGame + 0x6B012C, name->GetString());
}
