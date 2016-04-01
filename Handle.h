#ifndef __HANDLE_H
#define __HANDLE_H

#include <Windows.h>
#include <exception>
#include <string>

using namespace std;


class Handle{
protected:
	HANDLE _handle;
public:
	Handle(HANDLE rawHandle);
	void closeHandle();
};

class AutoCloseHandle : public Handle {
public:
	AutoCloseHandle(HANDLE rawHandle) : Handle(rawHandle) {};
	~AutoCloseHandle();
};

class FindHandle : public Handle {
public:
	FindHandle(HANDLE rawHandle) : Handle(rawHandle) {};
	void closeHandle();
};

class AutoCloseFindHandle : public FindHandle {
public:
	AutoCloseFindHandle() : FindHandle(nullptr){};
	AutoCloseFindHandle(HANDLE rawHandle) : FindHandle(rawHandle) {};
	~AutoCloseFindHandle();

};

class BaseHandleException : public exception {
public:
	virtual const char * what() const = 0;
};

class CloseHandleException : public BaseHandleException {
	string _dwLastError;
	string _exceptionMessage;
public:
	CloseHandleException(DWORD dwLastError) : _dwLastError(std::to_string(dwLastError)){ _exceptionMessage = "Error occurred during closing handle (LastError: " + _dwLastError + " )"; };
	virtual const char * what() const { return _exceptionMessage.c_str(); };
};

class OpenHandleException : public BaseHandleException {
	string _dwLastError;
	string _exceptionMessage;
public:
	OpenHandleException(DWORD dwLastError) : _dwLastError(std::to_string(dwLastError)){ _exceptionMessage = "Error occurred during openning handle (LastError: " + _dwLastError + " )"; };
	virtual const char * what() const { return _exceptionMessage.c_str(); };
};

#endif