// The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users
// Encapsulation ensures better control of your data, because you (or others) can change one part of the code without affecting other parts
// Increased security of data

#include <iostream>
using namespace std;

class Employee {
  private:
    // Private attribute
    int salary;

  public:
    // Setter
    void setSalary(int s) {
      salary = s;
    }
    // Getter
    int getSalary() {
      return salary;
    }
};

int main() {
  Employee myObj;
  myObj.setSalary(50000);
  cout << myObj.getSalary();
  return 0;
}