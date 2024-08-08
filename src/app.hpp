#ifndef _APP_H_
#define _APP_H_

#include "person.hpp"
#include "personDb.hpp"
class App {
    public:
        App();
        PersonDb database;
        void draw();
        Person tmpPerson;
};

#endif
