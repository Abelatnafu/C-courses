//
//  main.cpp
//  lets try hash
//
//  Created by Abel Atnafu on 9/11/20.
//  Copyright © 2020 Abel Atnafu. All rights reserved.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include "hash.h"


using namespace std;

int main(){
    Hashtable nobHill(13);
    nobHill.insertNewEmployeeBadge(3230, "Abel");
    nobHill.insertNewEmployeeBadge(17, "Jordan");
    nobHill.insertNewEmployeeBadge(102, "Dan");
    nobHill.insertNewEmployeeBadge(62, "Denis");
    nobHill.fireEmployee(69, "Denis");
    nobHill.insertNewEmployeeBadge(21, "Jaren");
    nobHill.insertNewEmployeeBadge(420, "Cri");
    nobHill.insertNewEmployeeBadge(123, "Lauri");
    nobHill.insertNewEmployeeBadge(92, "Logan");
    nobHill.insertNewEmployeeBadge(6, "John");
    nobHill.insertNewEmployeeBadge(22, "Dominic");
    nobHill.showAllEmployees();
    
    if (nobHill.searchEmployeeByNumName(6, "John") != -1)
    cout<<"000"<< nobHill.searchEmployeeByNumName(6, "John")<<endl;
    cout<<"Size: "<<nobHill.getSize()<<endl;
    cout<<"Amount of Employees: "<<nobHill.getAmountOfEmployee()<<endl;
    cout<<"Collisions: "<<nobHill.getTotalCollision()<<endl;
    return 0;
}

