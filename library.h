#pragma once
#include <unistd.h>
#include "ARMHook/CHook.h"
#include "ARMHook/CPatch.h"
#include "ARMHook/Call.h"
#include "mod/amlmod.h"
#include "mod/config.h"
#include "mod/logger.h"

#include <string> // memset
#include <dlfcn.h> // dlopen


#include <stdlib.h>
#include <sys/stat.h>
#include <fstream>
#include <stdint.h>
#include <dlfcn.h>
#include <stdio.h>

#define GTAPLUGIN "GTA ANDROID PLUGIN"

using namespace ARMHook;

class library
{
public:
	static void* hGame;
	static uintptr_t pGame;
	static uintptr_t scGame;
	library();
	~library();
	static uintptr_t GetSym(const char* name);
};

extern library libs;
