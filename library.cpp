#include "library.h"
#include <dlfcn.h>

void* library::hGame = nullptr;
uintptr_t library::pGame = NULL;
uintptr_t library::scGame = NULL;

library::library() {
	hGame = CHook::GetLibHandle("libGTASA.so");
	pGame = CHook::GetLibraryAddress("libGTASA.so");
	scGame = CHook::GetLibraryAddress("libSCAnd.so");
	CPatch::SetTrampolinesHook(pGame + 0xB0000, 50000);//Set the starting address of the Trampolines to 0xB0000, compatible with 50000 Trampolines.
}

library::~library() {
	dlclose(hGame);
}

uintptr_t library::GetSym(const char* name) {
	static library library;
	return CHook::GetSymbolAddress(library.hGame, name);
}

library libs;
