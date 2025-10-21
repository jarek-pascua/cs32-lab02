#include "student.h"
#include <string>
#include <cstring>
#include <sstream>

Student::Student(const char * const name, int perm) {
  this->name = nullptr;
  this->setName(name);
  this->perm = perm; 
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
    perm = permNumber;
}

void Student::setName(const char * const name) {
    if(this -> name != NULL) {
        delete[] this -> name; 
        this -> name = NULL; 
    }
    const char* name2; 
    if (name != NULL) {
        name2 = name; 
    }
    else {
        name2 = ""; 
    }
  this->name = new char[strlen(name2)+1];
  strcpy(this->name,name2);
}


Student::Student(const Student &orig) {
  this -> name = NULL;
  this->setName(orig.name);
  this->setPerm(orig.perm);
}

Student::~Student() {
    delete[] this->name; 
    this->name = nullptr;

}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
    if(this != &right) {
        this->setName(right.name);
        this->setPerm(right.perm);
    }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
    std::ostringstream oss;
    oss << "[" 
        << this->getName() 
        << ","
        << this->getPerm()
        << "]";
    return oss.str();
}

