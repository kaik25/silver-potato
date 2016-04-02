#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "..\Include\Handle.h"
#include "..\Include\DirDataTypes.h"
#include "..\Include\DirectoryList.h"

using namespace std;

void unsafe_main(){
	string targetFolder = "d:\\projects";
	OutputDebugString(string("Performing Dir on " + targetFolder + "\n").c_str());

	DirectoryFileList directoryFileList = DirectoryFileList(targetFolder);
	directoryFileList.printFirstFile();
}

void _tmain(int argc, TCHAR *argv[]){
	try {
		unsafe_main();
	} catch (exception& e) {
		OutputDebugString(e.what());
	}
};

