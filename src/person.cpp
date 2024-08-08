#include "person.hpp"
#include <string>

Person::Person(std::string _name, int _age) {
    name = _name;
    age = _age;
}

Person::Person() {
    name = std::string(64, '\0');
    age = 0;
}
