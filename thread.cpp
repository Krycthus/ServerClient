#include "thread.h"

Thread::Thread() {

}

Thread::Thread (Socket* s, std::string n, std::string m) {

	this.socket = s;
	this.name_user = n;
	this.message = m;
}
