#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h> //for linux use <unistd.h> instead of <Windows.h>
using std::cout;
using std::setfill; 
using std::setw;

int hrs = 0;
int mins = 0;
int secs = 0;

void commandHelp() {
    system("cls"); //this system call only works in windows, for linux use "clear" instead of "cls"
    cout << setfill(' ') << setw(40) << "Welcome\n";
    cout << setfill(' ') << setw(25);
    cout << setfill(' ') << setw(50) << "----------------------------\n";
    cout << setfill(' ') << setw(47) << "--start: start the clock\n";
    cout << setfill(' ') << setw(50) << "--help: show this help menu\n";
};

void showClock() {
    system("cls");
    cout << setfill(' ') << setw(40) << "ClockCLI\n";
    cout << setfill(' ') << setw(25);
    cout << setfill(' ') << setw(50) << "----------------------------\n";
    cout << setfill(' ') << setw(23) << hrs << " hrs";
    cout << setfill(' ') << setw(5) << mins << " mins";
    cout << setfill(' ') << setw(5) << secs << " secs";
}

void timer() {

    //main loop
    while(true) {

        //always updating the display
        showClock();
        Sleep(1000); //to use this in linux use "sleep()"

        secs++;

        if (secs == 60) {
            mins++;
            if (mins == 60) {
                hrs++;
                mins = 0;
            }
            secs = 0;
        }
    };
}

int main(int argc, char** argv) {
    if(argc == 2 && strcmp(argv[1], "--help")==0) commandHelp();
    if(argc == 2 && strcmp(argv[1], "--start")==0) timer();
    else commandHelp();
    

    return 0;
}
