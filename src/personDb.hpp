#ifndef _PERSON_DB_H_
#define _PERSON_DB_H_

#include "person.hpp"
#include <vector>

class PersonDb {
    public:
        PersonDb();
        void draw();
        void add(Person&);
    private:
        std::vector<Person> list;
};

#endif
