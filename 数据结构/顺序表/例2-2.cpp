#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct StudentType{
    int age;
    string student_number;
    string name;
    string gender;
};

typedef StudentType DataType;

typedef struct{
    DataType List[MAXSIZE];
    int Size; 
}SeqList;
int main(){

}