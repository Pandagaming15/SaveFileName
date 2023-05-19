#include "library.h"

#define sizeofA(__aVar)  ((int)(sizeof(__aVar)/sizeof(__aVar[0])))
MYMODCFG(SaveGameFileName, SaveGameFileName, 1.0, PandaGaming)

ConfigEntry* name;

extern "C" void OnModLoad()
{
	CHook::MemCopy((char*)libs.pGame + 0x6B012C, 'KYLE');
}
