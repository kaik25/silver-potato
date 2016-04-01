#include "DirectoryList.h"

DirectoryFileList::DirectoryFileList(string directoryPath) : 
	_directoryPath(directoryPath),
	_autoCloseFindHandle(findFirstfile())
{
};

AutoCloseFindHandle DirectoryFileList::findFirstfile(){
	WIN32_FIND_DATA findFileData;

	HANDLE findHandle = FindFirstFile(_directoryPath.c_str(), &findFileData);
	
	Win32FindData _firstFileFindData = Win32FindData(findFileData);

	if (findHandle == INVALID_HANDLE_VALUE){
		throw OpenHandleException(GetLastError());
	} 

	return AutoCloseFindHandle(findHandle);
};

