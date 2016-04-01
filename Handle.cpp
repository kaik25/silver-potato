#include "Handle.h"

using namespace std;

Handle::Handle(HANDLE rawHandle) :
	_handle(rawHandle)
{	
};

void Handle::closeHandle(){
	if (_handle != NULL){
		if (!(CloseHandle(_handle))){
			throw CloseHandleException(GetLastError());
		}
	}	
};

AutoCloseHandle::~AutoCloseHandle() {
	closeHandle();
};

void FindHandle::closeHandle(){
	if (_handle != NULL){
		if (!(FindClose(_handle))){
			throw CloseHandleException(GetLastError());
		}
	}
};

AutoCloseFindHandle::~AutoCloseFindHandle() {
	closeHandle();
};

