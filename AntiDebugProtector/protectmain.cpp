#pragma once
#include "protectmain.h"
#include "antidump.h"
#include "anti_debugger.h"
#include <string>
#include <windows.h> 
#include <iostream>

std::uintptr_t process_find(const std::string& name)
{
	const auto snap = LI_FN(CreateToolhelp32Snapshot).safe()(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!LI_FN(Process32First).safe()(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!LI_FN(Process32Next).safe()(snap, &proc_entry));
	}

	LI_FN(CloseHandle).safe()(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}

void blue_screen()
{
	BOOLEAN bluescr;
	ULONG cevap;
	RtlAdjustPrivilege(19, TRUE, FALSE, &bluescr);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &cevap);
}

void kill_process()
{
	system(skCrypt("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
	system(skCrypt("sc stop HTTPDebuggerPro >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1"));
}

void find_exe_title()
{
    while (true) {
        if (process_find("KsDumperClient.exe")) {
            std::cout << "KsDumperClient.exe 감지" << std::endl;
        }
        else if (process_find("HTTPDebuggerUI.exe")) {
            std::cout << "HTTPDebuggerUI.exe 감지" << std::endl;
        }
        else if (process_find("HTTPDebuggerSvc.exe")) {
            std::cout << "HTTPDebuggerSvc.exe 감지" << std::endl;
        }
        else if (process_find("FolderChangesView.exe")) {
            std::cout << "FolderChangesView.exe 감지" << std::endl;
        }
        else if (process_find("ProcessHacker.exe")) {
            std::cout << "ProcessHacker.exe 감지" << std::endl;
        }
        else if (process_find("procmon.exe")) {
            std::cout << "procmon.exe 감지" << std::endl;
        }
        else if (process_find("idaq.exe")) {
            std::cout << "idaq.exe 감지" << std::endl;
        }
        else if (process_find("idaq64.exe")) {
            std::cout << "idaq64.exe 감지" << std::endl;
        }
        else if (process_find("Wireshark.exe")) {
            std::cout << "Wireshark.exe 감지" << std::endl;
        }
        else if (process_find("Fiddler.exe")) {
            std::cout << "Fiddler.exe 감지" << std::endl;
        }
        else if (process_find("Xenos64.exe")) {
            std::cout << "Xenos64.exe 감지" << std::endl;
        }
        else if (process_find("Cheat Engine.exe")) {
            std::cout << "Cheat Engine.exe 감지" << std::endl;
        }
        else if (process_find("HTTP Debugger Windows Service (32 bit).exe")) {
            std::cout << "HTTP Debugger Windows Service (32 bit).exe 감지" << std::endl;
        }
        else if (process_find("KsDumper.exe")) {
            std::cout << "KsDumper.exe 감지" << std::endl;
        }
        else if (process_find("x64dbg.exe")) {
            std::cout << "x64dbg.exe 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("ProcessHacker.exe"))) {
            std::cout << "ProcessHacker.exe 창 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("IDA: Quick start"))) {
            std::cout << "IDA: Quick start 창 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("Memory Viewer"))) {
            std::cout << "Memory Viewer 창 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("Process List"))) {
            std::cout << "Process List 창 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("KsDumper"))) {
            std::cout << "KsDumper 창 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("HTTP Debugger"))) {
            std::cout << "HTTP Debugger 창 감지" << std::endl;
        }
        else if (FindWindow(0, skCrypt("OllyDbg"))) {
            std::cout << "OllyDbg 창 감지" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void mainprotect() {
	std::thread(hidethread).detach();
	std::thread(remotepresent).detach();
	std::thread(contextthread).detach();
	std::thread(debugstring).detach();
	std::thread(kill_process).detach();
	std::thread(find_exe_title).detach();
}

int main()
{
    while (true) {  // 무한 루프
    mainprotect();  // mainprotect 함수 호출
    Sleep(3000);    // 3000 밀리초 (3초) 대기
    }
}