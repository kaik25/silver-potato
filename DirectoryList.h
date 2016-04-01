#ifndef __DIRECTORYLIST_H
#define __DIRECTORYLIST_H

#include <Windows.h>
#include <string>

#include "Handle.h"
#include "DirDataTypes.h"

using namespace std; 

class DirectoryFileList {
	string _directoryPath;
	AutoCloseFindHandle _autoCloseFindHandle;
	Win32FindData _firstFileFindData;
public:
	DirectoryFileList(string directoryPath);
	AutoCloseFindHandle findFirstfile();
};

#endif