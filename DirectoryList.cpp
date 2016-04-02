#include "DirectoryList.h"

DirectoryFileList::DirectoryFileList(string directoryPath) : 
	_directoryPath(directoryPath),
	_firstFileFindDataPtr(new FirstFileFindData(_directoryPath))
{
};

void DirectoryFileList::printFirstFile(){
	if (_firstFileFindDataPtr == nullptr){
		throw UninitializedFirstFileException();
	} 
	cout << "Printing " << _directoryPath.c_str() << " first file data:" << endl;
	_firstFileFindDataPtr->print();
};



//FindHandleCloserPtr DirectoryFileList::findFirstfile(){
//	WIN32_FIND_DATA findFileData;
//
//	HANDLE findHandle = FindFirstFile(_directoryPath.c_str(), &findFileData);
//
//	if (findHandle == INVALID_HANDLE_VALUE){
//		DWORD lastError = GetLastError();
//		if (lastError == ERROR_FILE_NOT_FOUND) {
//			throw FileNotFoundException(_directoryPath);
//		} else {
//			throw OpenHandleException(lastError);
//		}
//	} 	
//	
//	_firstFileFindDataPtr = make_shared<Win32FindData>(findFileData);
//	
//	//_autoCloseFindHandlePtr = make_shared<FindHandleCloser>(findHandle);
//
//	/*FindHandleCloser safeFindHandle = FindHandleCloser(findHandle);
//	return safeFindHandle;*/
//};

