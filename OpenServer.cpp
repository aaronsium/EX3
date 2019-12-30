//
// Created by yaffa on 18/12/2019.
//

#include "General.h"

int OpenServer:: execute(vector<string> &v){
    port = stoi(v[1]);
    tableUpdate();
    thread serverThread(&OpenServer::Server, this);

    return 2;
}

void OpenServer:: Server(){

    socke = socket(AF_INET, SOCK_STREAM, 0);
    if(socke == -1){
        cerr << "Could not create a socket" << endl;
        return;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if(bind(socke, (struct sockaddr*) &address, sizeof(address)) == -1){
        cerr << "Could not bind the socket to an IP" << endl;
        return;
    }

    if(listen(socke, 5) == -1){
        cerr << "Error during listening command" << endl;
        return;
    }

    int client_socket = accept(socke, (struct sockaddr*) &address, (socklen_t*)&address);

    if(client_socket == -1){
        cerr << "Error accepting client" << endl;
        return;
    }

    char* buffer;
    while (read(client_socket, buffer, 1024)){
        string delimiter = ",";
        string token = string(buffer).substr(0, string(buffer).find(delimiter));
        buffer += delimiter.length();

        table[token] ->value = strtof((string(buffer)).c_str(),0);
    }

    close(client_socket);
}

void OpenServer::tableUpdate(){
    table["/instrumentation/airspeed-indicator/indicated-speed-kt"] = new node;
    table["/sim/time/warp"] = new node;
    table["/controls/switches/magnetos"] = new node;
    table["/instrumentation/heading-indicator/offset-deg"] = new node;
    table["/instrumentation/altimeter/indicated-altitude-ft"] = new node;
    table["/instrumentation/altimeter/pressure-alt-ft"] = new node;
    table["/instrumentation/altimeter/pressure-alt-ft"] = new node;
    table["/instrumentation/attitude-indicator/indicated-pitch-deg"] = new node;
    table["/instrumentation/attitude-indicator/indicated-roll-deg"] = new node;
    table["/instrumentation/attitude-indicator/internal-pitch-deg"] = new node;
    table["/instrumentation/attitude-indicator/internal-roll-deg"] = new node;
    table["/instrumentation/encoder/indicated-altitude-ft"] = new node;
    table["/instrumentation/encoder/pressure-alt-ft"] = new node;
    table["/instrumentation/gps/indicated-altitude-ft"] = new node;
    table["/instrumentation/gps/indicated-ground-speed-kt"] = new node;
    table["/instrumentation/gps/indicated-vertical-speed"] = new node;
    table["/instrumentation/heading-indicator/indicated-heading-deg"] = new node;
    table["/instrumentation/magnetic-compass/indicated-heading-deg"] = new node;
    table["/instrumentation/slip-skid-ball/indicated-slip-skid"] = new node;
    table["/instrumentation/turn-indicator/indicated-turn-rate"] = new node;
    table["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = new node;
    table["/controls/flight/aileron"] = new node;
    table["/controls/flight/elevator"] = new node;
    table["/controls/flight/rudder"] = new node;
    table["/controls/flight/flaps"] = new node;
    table["/controls/engines/engine/throttle"] = new node;
    table["/controls/engines/current-engine/throttle"] = new node;
    table["/controls/switches/master-avionics"] = new node;
    table["/controls/switches/starter"] = new node;
    table["/engines/active-engine/auto-start"] = new node;
    table["/controls/flight/speedbrake"] = new node;
    table["/sim/model/c172p/brake-parking"] = new node;
    table["/controls/engines/engine/primer"] = new node;
    table["/controls/engines/current-engine/mixture"] = new node;
    table["/controls/switches/master-bat"] = new node;
    table["/controls/switches/master-alt"] = new node;
    table["/engines/engine/rpm"] = new node;
}