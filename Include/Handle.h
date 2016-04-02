#ifndef __HANDLE_H
#define __HANDLE_H

#include <Windows.h>
#include <exception>
#include <string>
#include <memory>

using namespace std;


class Handle{
protected:
	HANDLE _handle;
public:
	Handle(HANDLE& rawHandle);
	Handle() : _handle(nullptr){}; 
	void closeHandle();
};

typedef shared_ptr<Handle> HandlePtr;

class HandleCloser : public Handle {
public:
	HandleCloser(HANDLE& rawHandle) : Handle(rawHandle) {};
	HandleCloser() : Handle(){};
	~HandleCloser();
};

typedef shared_ptr<HandleCloser> HandleCloserPtr;

class FindHandle : public Handle {
public:
	FindHandle(HANDLE& rawHandle) : Handle(rawHandle) {};
	FindHandle() : Handle(){};
	void closeHandle();
};

typedef shared_ptr<FindHandle> FindHandlePtr;

class FindHandleCloser : public FindHandle {
public:
	//FindHandleCloser() : FindHandle(nullptr){};
	FindHandleCloser(HANDLE& rawHandle) : FindHandle(rawHandle) {};
	FindHandleCloser() : FindHandle(){};
	~FindHandleCloser();

};

typedef shared_ptr<FindHandleCloser> FindHandleCloserPtr;

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