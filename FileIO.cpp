#include "FileIO.h"

FileIO::FileIO(std::string dests,std::string packages,std::string trucks,std::string missions,std::string outputFile ){
    readDestination(dests);
    readPackage(packages);
    readTruck(trucks);
    try {
        std::ofstream out(outputFile);
        readMission(missions);
        int i = 0;
        for(;i < getStations().size();i++){
            out << getStations()[i]->display();
        }
        out.close();
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
    }

}
void FileIO::readDestination(std::string dests) {
    std::ifstream dest(dests);
    while (getline(dest, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[line.length() - 1] == '\n') {
            line = line.substr(0, line.find("\n"));
        }
        destinations.push_back(new Station(line));
    }
    dest.close();
}
void FileIO::readTruck(std::string trucks) {
    std::ifstream truck(trucks);
    while (getline(truck, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[line.length() - 1] == '\n') {
            line = line.substr(0, line.find("\n"));
        }
        while(!line.empty()){
            if (line.find(" ") == -1) {
                v.push_back(line);
                break;
            }
            v.push_back(line.substr(0,line.find(" ")));
            line = line.substr(line.find(" ") + 1);
        }
        int i ;
        for (i = 0; i < destinations.size(); i++) {
            if (destinations[i]->getCity() == v[1]) {
                destinations[i]->getTrucks()->enqueue(Truck(v[0], v[2]));
                break;
            }
        }
        v.clear();
    }
    truck.close();
}
void FileIO::readMission(std::string missions) {
    std::ifstream mission(missions);
    while (getline(mission, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[line.length() - 1] == '\n') {
            line = line.substr(0, line.find("\n"));
        }
        while (line.find("-") != -1) {
            v.push_back(line.substr(0, line.find("-")));
            line = line.substr(line.find("-") + 1);
        }
        while (!line.empty()) {
            if (line.find(",") == -1) {
                v.push_back(line);
                break;
            }
            v.push_back(line.substr(0, line.find(",")));
            line = line.substr(line.find(",") + 1);
        }
        int i = 0;
        int packNum = stoi(v[3]);
        Truck truck;
        Packages package;
        transport = new DoubleLinkedList();
        for (; i < destinations.size(); i++) {
            if (destinations[i]->getCity() == v[0]) {
                if(destinations[i]->getTrucks()->isEmpty()){
                    throw "QueueException: There is no truck in starting station..\n";
                }
                destinations[i]->getTrucks()->getFront(truck);
                destinations[i]->getTrucks()->dequeue();
                transport->insert(truck);
                if (packNum > destinations[i]->getPacks()->size()) {
                    throw "StackException: Number of packages in starting station is smaller than expected..\n";
                }
                for (; packNum > 0; packNum--) {
                    destinations[i]->getPacks()->getTop(package);
                    destinations[i]->getPacks()->pop();
                    transport->insert(package);
                }
                break;
            }
        }
        if(transport->isEmpty()){
            throw "Starting station has not found..\n";
        }
        for (i = 0; i < destinations.size(); i++) {
            if (destinations[i]->getCity() == v[1]) {
                packNum = stoi(v[4]);
                if(packNum > destinations[i]->getPacks()->size()){
                    throw "StackException: Number of packages in the midway station is smaller than expected..\n";
                }
                for (; packNum > 0; packNum--) {
                    destinations[i]->getPacks()->getTop(package);
                    destinations[i]->getPacks()->pop();
                    transport->insert(package);
                }
                for (packNum = 5; packNum < v.size(); packNum++) {
                    Packages pack ;
                    transport->del(stoi(v[packNum]), pack);
                    if(pack.getID().size() == 0){
                        throw "DoublyLinkedListException: Package has not found in the truck..\n";
                    }
                    destinations[i]->getPacks()->push(pack);
                }
                break;
            }
        }
        if (i == destinations.size()){
            throw "Midway station has not found..\n";
        }
        for(i = 0; i < destinations.size();i++){
            if(destinations[i]->getCity() == v[2]){
                transport->delHead(truck);
                destinations[i]->getTrucks()->enqueue(truck);
                while(!transport->isEmpty()) {
                    transport->delHead(package);
                    destinations[i]->getPacks()->push(package);
                }
            }
        }
        if(!transport->isEmpty()) {
            throw "Target station has not found..\n";
        }
        v.clear();
    }
    mission.close();
}

void FileIO::readPackage(std::string packages) {
    std::ifstream package(packages);
    while (getline(package, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[line.length() - 1] == '\n') {
            line = line.substr(0, line.find("\n"));
        }
        while(!line.empty()){
            if (line.find(" ") == -1) {
                v.push_back(line);
                break;
            }
            v.push_back(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ") + 1);
            }
        int i;
        for (i = 0; i < destinations.size(); i++) {
            if (destinations[i]->getCity() == v[1]) {
                destinations[i]->getPacks()->push(Packages(v[0]));
                break;
            }
        }
        v.clear();
    }
    package.close();
}
