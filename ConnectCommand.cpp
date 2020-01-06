//
// Created by aharon on 22/12/2019.
//

#include "General.h"
ConnectCommand::ConnectCommand() {
}


int ConnectCommand::clientConnect(int client_socket) {
  while(!isServerOpen){};
  while (isParsing) {
    if (!setQueue.empty()) {
      string message = "set " + setQueue.front().GetSim() + " " + to_string(setQueue.front().GetValue()) + "\r\n";
      setQueue.pop();
      ssize_t return_val;
      return_val = write(client_socket, message.c_str(), message.length());
    }

  }
  close(client_socket);
  cout << "closing client thread" << endl;
  unique_lock<std::mutex> lock(mutex1);
  isThreadEnd2.notify_all();
}

int ConnectCommand::execute(vector<string> &arguments) {
  // converting the port number(string) to int
  stringstream geek(arguments[2]);
  int port = 0;
  geek >> port;
  // converting the address(string) to const char*
  string adress2 = arguments[1];
  adress2.erase(std::remove(adress2.begin(), adress2.end(), '"'), adress2.end());

// opening a thread by
  thread threadClient(&ConnectCommand::clientConnect, this, ConnectCommand:: newSocket(adress2, port));
  threadClient.detach();
  return 3;
}

int ConnectCommand:: newSocket(string adress2, int port){
    while(!serverReady){}
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket==-1) {
        cerr << "could not create a socket" << endl;
        return -1;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    //convert
    const char *address3 = adress2.c_str();

    address.sin_addr.s_addr = inet_addr(address3);
    address.sin_port = htons(port);
    int is_Connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));

    if (is_Connect==-1) {
        cerr << "Could not connect to host server" << endl;
        return -2;
    } else {
        cout << "Client is now connected to server" << endl;
    }

    return client_socket;
}
ConnectCommand::~ConnectCommand() {

}


