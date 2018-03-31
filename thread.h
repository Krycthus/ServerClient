#ifndef Thread_class
#define Thread_class

#include "thread.h"


class Thread {
 public:
   Thread ( Socket * s, std::string n, std::string message);
   Thread();
   const Thread& operator << (const std::string& ) const;
   const Thread& operator >> (std::string& ) const;

  private:
  	Socket socket;
  	std::string name_user;
  	std::string message;
};


#endif
