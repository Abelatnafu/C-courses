//
//  hash.h
//  lets try hash
//
//  Created by Abel Atnafu on 9/11/20.
//  Copyright © 2020 Abel Atnafu. All rights reserved.
//

#ifndef hash_h
#define hash_h
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <list>
using namespace std;
class Hashtable{
private:
    int size;
    string * employee;
    static const int Naughty = 3230;
    static const int hunnid = 65;
    static const int jay = 444;
    int amountOfEmployees;
    int totalCollision;
public:
    Hashtable(int len);//
    int getHashVal(int badgeNum);//
    bool insertNewEmployeeBadge(int employeeLuckyNum, string employeeName);//
    int searchEmployeeByNumName(int employeeLuckyNum, string employeeName);//
    string fireEmployee(int employeeLuckyNum, string firedEmployee);//
    int getSize(){return size;}//
    int getAmountOfEmployee(){return amountOfEmployees;}//
    int getTotalCollision(){return totalCollision;}//
    void mightGoWrong(int num);//
    void showAllEmployees();//
protected:
    void expandLenght();//
};
 
#endif /* hash_h */


Hashtable :: Hashtable(int len){
    employee = new string[len];
    size = len;
    amountOfEmployees = 0;
    totalCollision = 0;
    
    for (int i = 0; i <len ; i++){
        employee[i] = "-";
    }
}

int Hashtable :: getHashVal(int badgeNum){
    int code = 0;
    code = ((Naughty * badgeNum)/ hunnid) + jay;
    code = code % size;
    return code;
}

void Hashtable:: mightGoWrong(int num){
    if( num > size)
    {
        throw string("HashCode bigger that the HashTable size.");
    }
}

bool Hashtable:: insertNewEmployeeBadge(int newEmployeeBadge, string employeeName){
    int employeeId;
    int employeeIdSlotChecked = 0;
    int i = 1;
    employeeId = getHashVal(newEmployeeBadge);
    try{
        mightGoWrong(employeeId);
    }
    catch(string * e){
        cout<<"Error: "<< e<<endl;
        return false;
    }
//    if (employee[employeeId] == "-"){
//        employee[employeeId]= employeeName;
//        return true;
//    }
//    else{
//        while((employeeIdSlotChecked < size ) & (employee[employeeId] != "-" || employee[employeeId] != "0") ){
//
//
//    }
    while( employeeIdSlotChecked < size){
        if (employee[employeeId] == "-" || employee[employeeId] == "0"){
        //        employee[employeeId]= employeeName;
        //        return true;){
            amountOfEmployees++;
            employee[employeeId]= employeeName;
            return true;
        }
        employeeId = (employeeId + (i*i)+i) % size;
        i++;
        totalCollision++;
        
        employeeIdSlotChecked++;
            
    }
    expandLenght();
    insertNewEmployeeBadge(newEmployeeBadge, employeeName);
    return false;
    
}

void Hashtable:: showAllEmployees(){
    for (int i = 0; i < size; i++){
        if (employee[i] == "-" || employee[i] == "0" ){
            cout<< "000" << i <<": "<< "empty"<<endl;
        }
        else{
             cout<< "000" << i <<": "<< employee[i]<<endl;
        }
    }
}


void Hashtable:: expandLenght(){
    string oldTable[size];
    for (int i = 0; i < size; i++){
        oldTable[i] = employee[i];
    }
//    delete employee;
    size = size * 2;
    employee = new string[size];
    for (int j = 0; j < size/2; j++){
       employee[j] = oldTable[j];
        }
    for (int k = size/2; k < size; k++){
    employee[k] = "-";
     }
}
int Hashtable:: searchEmployeeByNumName(int employeeLuckyNum, string employeeName){
    
    int employeeIdSlotChecked = 0;
    int i = 1 ;
    int employeeID = getHashVal(employeeLuckyNum);
    while( (employeeIdSlotChecked < size) & (employee[employeeID] != "-")){
           if (employee[employeeID] == employeeName){
               return employeeID;
           }
           employeeID = (employeeID + (i*i)+i) % size;
           i++;
           employeeIdSlotChecked++;
               
       }
    return -1;
}

string Hashtable:: fireEmployee(int employeeLuckyNum, string firedEmployee){
    if (searchEmployeeByNumName(employeeLuckyNum, firedEmployee) > -1){
        employee[searchEmployeeByNumName(employeeLuckyNum, firedEmployee)] = "0";
    }
    amountOfEmployees--;
    return firedEmployee;
}
