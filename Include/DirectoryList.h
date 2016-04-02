#ifndef __DIRECTORYLIST_H
#define __DIRECTORYLIST_H

#include <Windows.h>
#include <string>
#include <memory>
#include <iostream>

#include "Handle.h"
#include "DirDataTypes.h"

using namespace std; 

class FirstFileFindData;
//shared_ptr<FirstFileFindData> FirstFileFindDataPtr;


class DirectoryFileList {
	string _directoryPath;
	shared_ptr<FirstFileFindData> _firstFileFindDataPtr;
	//FindHandleCloserPtr _autoCloseFindHandlePtr;
	//Win32FindDataPtr _firstFileFindDataPtr;
public:
	DirectoryFileList(string directoryPath);
	//FindHandleCloserPtr findFirstfile();
	void printFirstFile();

};

class BaseDirectoryListingException : public exception {
public:
	virtual const char * what() const = 0;
};


class FileNotFoundException : public BaseDirectoryListingException {
	string _targetDirectory;
	string _exceptionMessage;
public:
	FileNotFoundException(string targetDirectory) : _targetDirectory(targetDirectory){ _exceptionMessage = "File was not found"; };
	virtual const char * what() const { return _exceptionMessage.c_str(); };
};

class UninitializedFirstFileException : public BaseDirectoryListingException {
public:
	virtual const char * what() const { return "UninitializedFirstFileException"; };
};
#endif