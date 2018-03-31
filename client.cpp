#include "ClientSocket.h"
#include "SocketException.h"
#include "thread.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>

using namespace std;


void cal_from_thread(ClientSocket cs, string name, string message);
{
  cout << "lancement du thread numéro" << tid << endl;
}


int main (int argc, char* argv[]) {
  if(argc != 3) {
    cout << "invalid number of arguments: call with `./client IP port`" << endl;
    return 1;
  }

  string host = argv[1];
  int port = atoi(argv[2]);



  try {
    ClientSocket client_socket ( host, port );
    string reply;

    while (true) {
      try {
        client_socket << "Test message.";
        client_socket >> reply;
      } catch ( SocketException& ) {}

      cout << "We received this response from the server:\n\"" << reply << "\"\n";;

      }
    }
    catch ( SocketException& e ) {
      cout << "Exception was caught:" << e.description() << endl;
    }

  return 0;
}
