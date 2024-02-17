#ifndef ASIGTGUNCEL_FILEIO_H
#define ASIGTGUNCEL_FILEIO_H
#include <string>
#include <vector>
#include <fstream>
#include "Station.h"
#include "DoubleLinkedList.h"
class FileIO {
private:
    std::string line;
    std::vector<std::string> v;
    std::vector<Station*> destinations;
    DoubleLinkedList* transport;
public:
    FileIO(std::string dests,std::string packages,std::string trucks,std::string missions,std::string outputFile );
    void readDestination(std::string dests); //reads dests file
    void readMission(std::string missions); //reads missions file
    void readTruck(std::string trucks); //reads trucks  file
    void readPackage(std::string packages);  //reads packages file
    std::vector<Station*> getStations(){return destinations;}

};


#endif //ASIGTGUNCEL_FILEIO_H
