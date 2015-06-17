//I affirm that all code given below was written solely by me, Kathleen Levi, and that any help I received adhered to the rules stated for this exam.

#include "Runner.h"
#include <string>
using namespace std;

Runner::Runner(string first, string last, int pace){
    firstname = first;
    lastname = last;
    this->pace = pace;
}

void Runner::set_firstname(string first){
    firstname = first;
}
void Runner::set_lastname(string last){
    lastname = last;
}
void Runner::set_pace(int Pace){
    pace = Pace;
}
string Runner::get_firstname(){
    return firstname;
}
string Runner::get_lastname(){
    return lastname;
}
int Runner::get_pace(){
    return pace;
}
