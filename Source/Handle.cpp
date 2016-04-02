#include "..\Include\Handle.h"

using namespace std;

Handle::Handle(HANDLE& rawHandle) :
	_handle(rawHandle)
{	
};

void Handle::closeHandle(){
	if (_handle != nullptr){
		if (!(CloseHandle(_handle))){
			throw CloseHandleException(GetLastError());
		}
	}	
};

HandleCloser::~HandleCloser() {
	closeHandle();
};

void FindHandle::closeHandle(){
	if (_handle != nullptr){
		if (!(FindClose(_handle))){
			throw CloseHandleException(GetLastError());
		}
	}
};

FindHandleCloser::~FindHandleCloser() {
	closeHandle();
};

