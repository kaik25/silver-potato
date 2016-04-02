#ifndef __DIRDATATYPES_H
#define __DIRDATATYPES_H

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <memory>
#include <string>

#include "Handle.h"
#include "DirectoryList.h"

using namespace std;

//typedef struct _WIN32_FIND_DATA {
//	DWORD    dwFileAttributes;
//	FILETIME ftCreationTime;
//	FILETIME ftLastAccessTime;
//	FILETIME ftLastWriteTime;
//	DWORD    nFileSizeHigh;
//	DWORD    nFileSizeLow;
//	DWORD    dwReserved0;
//	DWORD    dwReserved1;
//	TCHAR    cFileName[MAX_PATH];
//	TCHAR    cAlternateFileName[14];
//} WIN32_FIND_DATA, *PWIN32_FIND_DATA, *LPWIN32_FIND_DATA;
//
//typedef struct _FILETIME {
//	DWORD dwLowDateTime;
//	DWORD dwHighDateTime;
//} FILETIME, *PFILETIME;



class FileTime{
	DWORD _lowDateTime;
	DWORD _highDateTime;
public:
	FileTime(FILETIME rawFileTimeData);
	FileTime();
	void print();
	string getTimeStr();
private:
	time_t _getTime();

};

class Win32FindData {
	DWORD    _fileAttributes;
	FileTime _creationTime;
	FileTime _lastAccessTime;
	FileTime _lastWriteTime;
	DWORD    _fileSizeHigh;
	DWORD    _fileSizeLow;
	DWORD    _reserved0;
	DWORD    _reserved1;
	string   _fileName;
	string   _alternateFileName;	
public:
	Win32FindData(WIN32_FIND_DATA rawFindFileData);
	Win32FindData();
	~Win32FindData();
	void print();
};

typedef shared_ptr<Win32FindData> Win32FindDataPtr;

class FirstFileFindData {
	string _directoryPath;
	Win32FindDataPtr _findWin32DataPtr;
	FindHandleCloserPtr _findHandlePtr;	
public:
	FirstFileFindData(string directoryPath);
	void print();
private:
	void _findFirstFile();
};

typedef shared_ptr<FirstFileFindData> FirstFileFindDataPtr;

#endif