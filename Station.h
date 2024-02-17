#ifndef ASIGTGUNCEL_STATION_H
#define ASIGTGUNCEL_STATION_H
#include "Truck.h"
#include "Stack.h"
#include "Queue.h"
#include <sstream>

class Station {
    private:
        std::string city;
        Stack<Packages>* packages;
        Queue<Truck>* trucks;
    public:
        Station(std::string city) {
            this->city = city;
            packages = new Stack<Packages>();
            trucks = new Queue<Truck>();
        }
        //Displays trucks and packages in the station.
        std::string display() {
            std::stringstream str;
            str << city <<"\nPackages:\n";
            Packages pack;
            Truck truck;
            while (!packages->isEmpty()){
                packages->getTop(pack);
                packages->pop();
                str<< pack.getID()<< "\n";
            }
            str <<"Trucks:\n";
            while(!trucks->isEmpty()){
                trucks->getFront(truck);
                trucks->dequeue();
                str<< truck.getID()<<"\n";
            }
            str <<"-------------\n";
            return str.str();
        }
        std::string getCity(){
            return city;
        }
        Stack<Packages>* getPacks(){
            return packages;
        }
        Queue<Truck>* getTrucks(){
            return trucks;
        }
};


#endif //ASIGTGUNCEL_STATION_H
