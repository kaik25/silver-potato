#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Handle.h"
#include "DirDataTypes.h"
#include "DirectoryList.h"

using namespace std;

void _tmain(int argc, TCHAR *argv[])
{
	string targetFolder = "c:\\temp";
	cout << "Performing Dir on " << targetFolder;

	DirectoryFileList directoryFileList = DirectoryFileList(targetFolder);
}