#include "ServerSocket.h"
#include "SocketException.h"
#include "Socket.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include "thread.h"


using namespace std;

Socket * s = new Socket ();
int main (int argc, char* argv[]) {
  if(argc !=2) {
    cout << "invalid number of arguments: call with `./server port`" << endl;
    return 1;
  }

  int port = atoi(argv[1]);

  cout << "Sever running at " << port << endl;

  Thread* tableau_de_threads[2];

  for(int i = 0; i < 2; i++)
  {

    tableau_de_threads[i] = new Thread(s, "pierre","coucou les gens");
  }
  try {
    ServerSocket server ( port );

    while ( true ) {

      ServerSocket new_sock;
      server.accept ( new_sock );

      try {
        while ( true ) {
          string data;
          new_sock >> data;
          cout << data << endl;
          new_sock << data;
        }
      } catch ( SocketException& ) {}

    }
  } catch ( SocketException& e ) {
    cout << "Exception was caught:" << e.description() << "\nExiting" << endl;
  }

  return 0;
}
