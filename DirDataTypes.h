#ifndef __DIRDATATYPES_H
#define __DIRDATATYPES_H

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include <string>

typedef FILETIME;

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
};

#endif