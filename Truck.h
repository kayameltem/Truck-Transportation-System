#ifndef ASIGTGUNCEL_TRUCK_H
#define ASIGTGUNCEL_TRUCK_H
#include "Packages.h"

class Truck : public Packages {
    private:
        std::string power;
    public:
        Truck(){}
        Truck(std::string id,std::string power){
            setID(id);
            this->power = power;
    }

};


#endif //ASIGTGUNCEL_TRUCK_H
