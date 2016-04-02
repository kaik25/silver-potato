#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Handle.h"
#include "DirDataTypes.h"
#include "DirectoryList.h"

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

