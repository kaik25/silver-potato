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

Win32FindData::~Win32FindData() {};

void Win32FindData::print(){
	cout << "FileName: " << _fileName.c_str() << endl;
	cout << "AlternateFileName: " << _alternateFileName.c_str() << endl;
	cout << "FileAttributes: " << to_string(_fileAttributes) << endl;
	cout << "CreateionTime: " << _creationTime.getTimeStr() << endl;
	cout << "LastAccessTime: " <<  _lastAccessTime.getTimeStr() << endl;
	cout << "LastWriteTime: " <<  _lastWriteTime.getTimeStr() << endl;
	cout << "FileSizeHigh: " << to_string(_fileSizeHigh) << endl;
	cout << "FileSizeLow: " << to_string(_fileSizeLow) << endl;

};

FirstFileFindData::FirstFileFindData(string directoryPath) :
	_directoryPath(directoryPath),
	_findHandlePtr(),
	_findWin32DataPtr()
{	
	_findFirstFile();
};

void FirstFileFindData::_findFirstFile(){
	WIN32_FIND_DATA findFileData;

	HANDLE findHandle = FindFirstFile(_directoryPath.c_str(), &findFileData);
	_findHandlePtr = FindHandleCloserPtr(new FindHandleCloser(findHandle));

	if (findHandle == INVALID_HANDLE_VALUE){
		DWORD lastError = GetLastError();
		if (lastError == ERROR_FILE_NOT_FOUND) {
			throw FileNotFoundException(_directoryPath);
		} else {
			throw OpenHandleException(lastError);
		}
	} 	
	
	_findWin32DataPtr = Win32FindDataPtr(new Win32FindData(findFileData));
	
	//_autoCloseFindHandlePtr = make_shared<FindHandleCloser>(findHandle);

	/*FindHandleCloser safeFindHandle = FindHandleCloser(findHandle);
	return safeFindHandle;*/
};

void FirstFileFindData::print() {
	_findWin32DataPtr->print();
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

void FileTime::print() {
	cout << "LowDateTime: " << to_string(_lowDateTime).c_str() << endl;
	cout << "HighDateTime: " << to_string(_highDateTime).c_str() << endl;
};

string FileTime::getTimeStr() {
	return to_string(_getTime());
};
	
time_t FileTime::_getTime(){ 
   ULARGE_INTEGER ull;
   ull.LowPart =_lowDateTime;
   ull.HighPart = _highDateTime;

   return ull.QuadPart / 10000000ULL - 11644473600ULL;
};
