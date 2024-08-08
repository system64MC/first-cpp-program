#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

class Person {
    public:
        std::string name;
        int age;
        Person(std::string _name, int _age);
        Person();
};

#endif
