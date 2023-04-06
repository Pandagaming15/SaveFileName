#pragma once
#include "Assembly/UsefulMacros.h"
#include "Assembly/InstructionType.h"
#include <stdint.h>
#include <vector>

namespace ARMHook
{
	class CPatch
	{
	public:
		static void WriteDataToMemory(uintptr_t addr, void* data, int size);
		static void SetUint8(uintptr_t addr, uint8_t value);
		static void SetUint16(uintptr_t addr, uint16_t value);
		static void SetUint32(uintptr_t addr, uint32_t value);
		static void SetPointer(uintptr_t addr, void* value);
		static void SetFloat(uintptr_t addr, float value);
		static void SetInt(uintptr_t addr, int value);
		static void SetUintptr(uintptr_t addr, uintptr_t value);
		static uint8_t GetUint8(uintptr_t addr);
		static uint16_t GetUint16(uintptr_t addr);
		static uint32_t GetUint32(uintptr_t addr);
		static void* GetPointer(uintptr_t addr);
		static float GetFloat(uintptr_t addr);
		static int GetInt(uintptr_t addr);
		static uintptr_t GetUintptr(uintptr_t addr);
		static void NOP(eInstructionSet sourceInstructionSet, uintptr_t dwAddress, int iSize);
		static void RedirectCode(eInstructionSet sourceInstructionSet, uintptr_t dwAddress, uintptr_t to);
		static void RedirectCodeEx(eInstructionSet sourceInstructionSet, uintptr_t dwAddress, const void* to);
		static void RedirectFunction(uintptr_t functionJumpAddress, void* to);

		static void SetTrampolinesHook(uintptr_t addr, int32_t num_trampolines);
		static void TrampolinesRedirectCall(eInstructionSet sourceInstructionSet, uintptr_t addr, void* func, void** orig_func, InstructionType CallType);
		static void TrampolinesRedirectJump(eInstructionSet sourceInstructionSet, uintptr_t addr, void* func, void** orig_func);

	private:
		static uintptr_t Trampolines_addr_start;
		static uintptr_t Trampolines_addr_end;
		static void CheckTrampolinesLimit();
	};
}
