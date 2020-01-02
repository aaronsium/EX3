//
// Created by aharon on 22/12/2019.
//

#include "General.h"
ConnectCommand::ConnectCommand() {
}

int ConnectCommand::clientConnect(int PORT, string hostAddress) {

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket==-1) {
    cerr << "could not create a socket" << endl;
    return -1;
  }
  sockaddr_in address;
  address.sin_family = AF_INET;
  //convert
      const char *address3 = hostAddress.c_str();
   //

  address.sin_addr.s_addr = inet_addr(address3);
  address.sin_port = htons(PORT);
  int is_Connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));

  if (is_Connect==-1) {
    cerr << "Could not connect to host server" << endl;
    return -2;
  } else {
    cout << "Client is now connected to server" << endl;
  }
  while (isParsing) {
    if (!setQueue.empty()) {
      string message = "set " + setQueue.front().GetSim() + " " + to_string(setQueue.front().GetValue()) + "\r\n";
      setQueue.pop();
      ssize_t return_val;
      return_val = write(client_socket, message.c_str(), message.length());
    }

  }

 close(client_socket);
//  char hello[] = "hiiiiiiiii";
//  int is_sent = send(client_socket, hello, strlen(hello), 0);
//  if (is_sent==-1) {
//    cout << "Error sending message" << endl;
//    return -2;
//  } else {
//    cout << "hello message sent to server" << endl;
//  }




}

int ConnectCommand::execute(vector<string> &arguments) {
  // converting the port number(string) to int
  stringstream geek(arguments[2]);

  cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
  int port = 0;
  geek >> port;
  // converting the address(string) to const char*
  string adress2 = arguments[1];
  adress2.erase(std::remove(adress2.begin(), adress2.end(), '"'), adress2.end());

//  const char *address = adress2.c_str();
//  // opening a thread by
  thread threadClient(&ConnectCommand::clientConnect, this, port,adress2);
  threadClient.detach();
  return 3;
}


