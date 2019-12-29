////
//// Created by aharon on 22/12/2019.
////
//#include "General.h"
//ConnectCommand::ConnectCommand() {
//}
//
//int ConnectCommand::clientConnect(int PORT, const char *hostAddress) {
//
//  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
//  if (client_socket==-1) {
//    cerr << "could not create a socket" << endl;
//    return -1;
//  }
//  sockaddr_in address;
//  address.sin_family = AF_INET;
//  address.sin_addr.s_addr = inet_addr(hostAddress);
//  address.sin_port = htons(PORT);
//  int is_Connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
//  if (is_Connect==-1) {
//    cerr << "Could not connect to host server" << endl;
//    return -2;
//  } else {
//    cout << "Client is now connected to server" << endl;
//  }
//  char hello[] = "hiiiiiiiii";
//  int is_sent = send(client_socket, hello, strlen(hello), 0);
//  if (is_sent==-1) {
//    cout << "Error sending message" << endl;
//    return -2;
//  } else {
//    cout << "hello message sent to server" << endl;
//  }
//
//
//
////  close(client_socket);
//}
//
//int ConnectCommand::execute(vector<string> &arguments) {
//  // converting the port number(string) to int
//  stringstream geek(arguments[2]);
//  int port = 0;
//  geek >> port;
//  // converting the address(string) to const char*
//  const char *address = arguments[1].c_str();
//  // opening a thread by
//  thread threadClient(&ConnectCommand::clientConnect, this, port);
//
//  threadClient.join();
//
//  return 1;
//}
//
//
