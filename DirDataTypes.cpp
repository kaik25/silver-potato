#include "DirDataTypes.h"

Win32FindData::Win32FindData(WIN32_FIND_DATA rawFindFileData) :
	_fileAttributes(rawFindFileData.dwFileAttributes),
	_creationTime(rawFindFileData.ftCreationTime),
	_lastAccessTime(rawFindFileData.ftCreationTime),
	_lastWriteTime(rawFindFileData.ftLastWriteTime),
	_fileSizeHigh(rawFindFileData.nFileSizeHigh),
	_fileSizeLow(rawFindFileData.nFileSizeLow),
	_reserved0(rawFindFileData.dwReserved0),
	_reserved1(rawFindFileData.dwReserved1),
	_fileName(rawFindFileData.cFileName),
	_alternateFileName(rawFindFileData.cAlternateFileName)
{
};

Win32FindData::Win32FindData() :
_fileAttributes(0),
_creationTime(FileTime()),
_lastAccessTime(FileTime()),
_lastWriteTime(FileTime()),
_fileSizeHigh(0),
_fileSizeLow(0),
_reserved0(0),
_reserved1(0),
_fileName(string()),
_alternateFileName(string())
{
};



FileTime::FileTime(FILETIME rawFileTimeData) : 
	_lowDateTime(rawFileTimeData.dwLowDateTime),
	_highDateTime(rawFileTimeData.dwHighDateTime)
{
};

FileTime::FileTime() :
	_lowDateTime(0),
	_highDateTime(0)
{
};