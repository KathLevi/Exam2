//I affirm that all code given below was written solely by me, Kathleen Levi, and that any help I received adhered to the rules stated for this exam.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Runner.h"
using namespace std;

int main(){
    //open the file of runners
    string filename = "registrants.txt";
    ifstream runners(filename, ios::beg | ios:: in);
    if (runners.fail()){
        cout << "Could not open file." << endl;
        return 0;
    }
    
    //read the file into a vector
    string first, last;
    int pace;
    vector<Runner> runnerVector;
    while (!runners.eof()){
        runners >> first >> last >> pace;
        Runner r(first, last, pace);
        runnerVector.push_back(r);
    }
    
    runners.close();
    //sort the vector in ascending order (fastest pace is the first runner in the vector)
    for (int i = 0; i < runnerVector.size()-1; i++)
    {
        int currentMax = runnerVector[i].get_pace();
        int currentMaxIndex = i;
        
        for (int j = i + 1; j < runnerVector.size()-1; j++)
        {
            if (currentMax < runnerVector[j].get_pace())
            {
                currentMax = runnerVector[j].get_pace();
                currentMaxIndex = j;
            }
        }
        
        if (currentMaxIndex != i){
            runnerVector[currentMaxIndex].set_pace(runnerVector[i].get_pace());
            runnerVector[i].set_pace(currentMax);
        }
    }
    
    //create files for each color
    fstream white("white.txt");
    if (!white){
        white.open("white.txt", ios::out);
    }
    if (white.fail()){
        cout << "Cannot open the white file for writing" << endl;
        return 0;
    }
    white.close();
    fstream yellow("yellow.txt");
    if (!yellow){
        yellow.open("yellow.txt", ios::out);
    }
    if (yellow.fail()){
        cout << "Cannot open the yellow file for writing" << endl;
        return 0;
    }
    yellow.close();
    fstream green("green.txt");
    if (!green){
        green.open("green.txt", ios::out);
    }
    if (green.fail()){
        cout << "Cannot open the green file for writing" << endl;
        return 0;
    }
    green.close();
    fstream orange("orange.txt");
    if (!orange){
        orange.open("orange.txt", ios::out);
    }
    if (orange.fail()){
        cout << "Cannot open the orange file for writing" << endl;
        return 0;
    }
   orange.close();
    fstream blue("blue.txt");
    if (!blue){
        blue.open("blue.txt", ios::out);
    }
    if (blue.fail()){
        cout << "Cannot open the blue file for writing" << endl;
        return 0;
    }
    blue.close();
    fstream lilac("lilac.txt");
    if (!lilac){
        lilac.open("lilac.txt", ios::out);
    }
    if (lilac.fail()){
        cout << "Cannot open the lilac file for writing" << endl;
        return 0;
    }
    lilac.close();
    fstream red("red.txt");
    if (!red){
        red.open("red.txt", ios::out);
    }
    if (red.fail()){
        cout << "Cannot open the red file for writing" << endl;
        return 0;
    }
   red.close();
    
    int w = 0;
    int y = 0;
    int g = 0;
    int o = 0;
    int b = 0;
    int l = 0;
    int r = 0;
    //put the runners into specific color files based on pace
    for (int i = 0; i < runnerVector.size()-1; i++){
        if (runnerVector[i].get_pace() >= 0 && runnerVector[i].get_pace() <= 360){
            white.open("white.txt", ios::out | ios::app);
            white << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            w++;
            white.close();
        }
        if (runnerVector[i].get_pace() >= 361 && runnerVector[i].get_pace() <= 420){
            yellow.open("yellow.txt", ios::out | ios::app);
            yellow << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            y++;
            yellow.close();
        }
        if (runnerVector[i].get_pace() >= 421 && runnerVector[i].get_pace() <= 480){
            green.open("green.txt", ios::out | ios::app);
            green << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            g++;
            green.close();
        }
        if (runnerVector[i].get_pace() >= 481 && runnerVector[i].get_pace() <= 540){
            orange.open("orange.txt", ios::out | ios::app);
            orange << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            o++;
            orange.close();
        }
        if (runnerVector[i].get_pace() >= 541 && runnerVector[i].get_pace() <= 600){
            blue.open("blue.txt", ios::out | ios::app);
           blue << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            b++;
            blue.close();
        }
        if (runnerVector[i].get_pace() >= 601 && runnerVector[i].get_pace() <= 720){
            lilac.open("lilac.txt", ios::out | ios::app);
            lilac << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            l++;
            lilac.close();
        }
        if (runnerVector[i].get_pace() >= 721 && runnerVector[i].get_pace() <= 1200){
            red.open("red.txt", ios::out | ios::app);
            red << runnerVector[i].get_firstname() << " " << runnerVector[i].get_lastname() << " " << runnerVector[i].get_pace() << endl;
            r++;
            red.close();
        }
    }
    
    //test program to ensure that the files were created correctly
    //output each colored file
    string fname, lname;
    int p;
    cout << "White: " << endl;
    white.open("white.txt", ios::in);
    for (int i = 0; i < w; i++){
        white >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }
    cout << "\n\nYellow: " << endl;
    yellow.open("yellow.txt", ios::in);
    for (int i = 0; i < y; i++){
        yellow >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }
    cout << "\n\nGreen: " << endl;
    green.open("green.txt", ios::in);
    for (int i = 0; i < g; i++){
        green >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }
    cout << "\n\nOrange: " << endl;
    orange.open("orange.txt", ios::in);
    for (int i = 0; i < o; i++){
        orange >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }
    cout << "\n\nBlue: " << endl;
    blue.open("blue.txt", ios::in);
    for (int i = 0; i < b; i++){
        blue >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }
    cout << "\n\nLilac: " << endl;
    lilac.open("lilac.txt", ios::in);
    for (int i = 0; i < l; i++){
        lilac >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }
    cout << "\n\nRed: " << endl;
    red.open("red.txt", ios::in);
    for (int i = 0; i < r; i++){
        red >> fname >> lname >> p;
        cout << fname << " " << lname << " " << p << endl;
    }

}