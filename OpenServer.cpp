//
// Created by yaffa on 18/12/2019.
//

#include "General.h"

OpenServer::OpenServer(unordered_map<string,Var> &varProgram){
    this -> pathMap = varProgram;
}

int OpenServer:: execute(vector<string> &v){
    port = stoi(v[1]);
    tableUpdate();

    int socke = socket(AF_INET, SOCK_STREAM, 0);
    if(socke == -1){
        cerr << "Could not create a socket" << endl;
        return -1;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if(bind(socke, (struct sockaddr*) &address, sizeof(address)) == -1){
        cerr << "Could not bind the socket to an IP" << endl;
        return -2;
    }

    if(listen(socke, 5) == -1){
        cerr << "Error during listening command" << endl;
        return -3;
    }

    cout<<"waiting"<<endl;
    int client_socket = accept(socke, (struct sockaddr*) &address, (socklen_t*)&address);
    if(client_socket == -1){
        cerr << "Error accepting client" << endl;
        return -4;
    }


    thread serverThread(&OpenServer::Server, this, client_socket);
    serverThread.join();

    return 2;
}

void OpenServer:: Server(int client_socket){
  cout<<"waiting"<<endl;

    char buffer[1024] = {0};
    while (read(client_socket, buffer, 1024)){
      char delimiter = ',';
      int m = 0;
      int j = 0;
      for(int i = 0; i < 36 ; i++){
          while ((buffer[j] != delimiter) && (buffer[j] != '\0')){
          j++;
        }
          string token = "";
          while (m < j){
            token += buffer[m];
            m++;
          }
          m++;
        cout<<token<< " - ";
        pathMap[table[i]].SetValue(strtof((string(token)).c_str(),0));
        cout<<table[i] << " + " <<pathMap[table[i]].GetValue()<<endl;
        j++;
      }
    }
  cout<<"waiting2"<<endl;

    close(client_socket);
}


void OpenServer::tableUpdate(){
    table[0] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    table[1] = "/sim/time/warp";
    table[2] = "/controls/switches/magnetos";
    table[3] = "/instrumentation/heading-indicator/offset-deg";
    table[4] = "/instrumentation/altimeter/indicated-altitude-ft";
    table[5] = "/instrumentation/altimeter/pressure-alt-ft";
    table[6] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    table[7] = "/instrumentation/attitude-indicator/indicated-roll-deg";
    table[8] = "/instrumentation/attitude-indicator/internal-pitch-deg";
    table[9] = "/instrumentation/attitude-indicator/internal-roll-deg";
    table[10] = "/instrumentation/encoder/indicated-altitude-ft";
    table[11] = "/instrumentation/encoder/pressure-alt-ft";
    table[12] = "/instrumentation/gps/indicated-altitude-ft";
    table[13] = "/instrumentation/gps/indicated-ground-speed-kt";
    table[14] = "/instrumentation/gps/indicated-vertical-speed";
    table[15] = "/instrumentation/heading-indicator/indicated-heading-deg";
    table[16] = "/instrumentation/magnetic-compass/indicated-heading-deg";
    table[17] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    table[18] = "/instrumentation/turn-indicator/indicated-turn-rate";
    table[19] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    table[20] = "/controls/flight/aileron";
    table[21] = "/controls/flight/elevator";
    table[22] = "/controls/flight/rudder";
    table[23] = "/controls/flight/flaps";
    table[24] = "/controls/engines/engine/throttle";
    table[25] = "/controls/engines/current-engine/throttle";
    table[26] = "/controls/switches/master-avionics";
    table[27] = "/controls/switches/starter";
    table[28] = "/engines/active-engine/auto-start";
    table[29] = "/controls/flight/speedbrake";
    table[30] = "/sim/model/c172p/brake-parking";
    table[31] = "/controls/engines/engine/primer";
    table[32] = "/controls/engines/current-engine/mixture";
    table[33] = "/controls/switches/master-bat";
    table[34] = "/controls/switches/master-alt";
    table[35] = "/engines/engine/rpm";
}