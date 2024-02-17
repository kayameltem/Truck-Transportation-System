#ifndef ASIGTGUNCEL_PACKAGES_H
#define ASIGTGUNCEL_PACKAGES_H
#include <string>

class Packages {
private:
    std::string id;

public:
    Packages(){}
    Packages(std::string id){
        this->id = id;
    }
    std::string getID() {
        return id;
    }
    void setID(std::string id){
        this->id = id;
    }

};


#endif //ASIGTGUNCEL_PACKAGES_H
