//I affirm that all code given below was written solely by me, Kathleen Levi, and that any help I received adhered to the rules stated for this exam.

#ifndef __Exam2__Runner__
#define __Exam2__Runner__

#include <stdio.h>
#include <string>
using namespace std;

//class for the runner
class Runner{
private:
    string firstname;
    string lastname;
    int pace;
    
public:
    Runner(string first, string last, int pace);
    void set_firstname(string first);
    void set_lastname(string last);
    void set_pace(int Pace);
    string get_firstname();
    string get_lastname();
    int get_pace();
};


#endif /* defined(__Exam2__Runner__) */
