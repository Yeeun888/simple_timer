#include <iostream>
#include <ctime> //Use ot time_t 
#include <cstring>
#include <ratio>
#include <chrono>
#include <array>
#include <string>
#include <sys/ioctl.h>

#include <time.h>
#include <unistd.h> //Use of sleep

#include "letters.cpp"

namespace chrono = std::chrono;
using chrono::system_clock;

namespace NumberPrintFunctions {

    template<int num> void printNumberLine(std::array<std::string, num> arr, int lineNumber) {
        std::cout << arr[lineNumber];
    }

    void printNumber(int num, int line) {
        switch(num) {
            case 0:
                printNumberLine<5>(SolidNumberFiveChar::zero, line); 
                break;
            case 1: 
                printNumberLine<5>(SolidNumberFiveChar::one, line); 
                break;
            case 2:
                printNumberLine<5>(SolidNumberFiveChar::two, line); 
                break;
            case 3:
                printNumberLine<5>(SolidNumberFiveChar::three, line); 
                break;
            case 4:
                printNumberLine<5>(SolidNumberFiveChar::four, line); 
                break;
            case 5:
                printNumberLine<5>(SolidNumberFiveChar::five, line); 
                break;
            case 6:
                printNumberLine<5>(SolidNumberFiveChar::six, line); 
                break;
            case 7:
                printNumberLine<5>(SolidNumberFiveChar::seven, line); 
                break;
            case 8:
                printNumberLine<5>(SolidNumberFiveChar::eight, line); 
                break;
            case 9:
                printNumberLine<5>(SolidNumberFiveChar::nine, line); 
                break;
            default:
                break;
        }
    }

    void printNumberEight(int num, int line) {
        switch(num) {
            case 0:
                printNumberLine<8>(BeautifulNumbersEightChar::zero, line); 
                break;
            case 1: 
                printNumberLine<8>(BeautifulNumbersEightChar::one, line); 
                break;
            case 2:
                printNumberLine<8>(BeautifulNumbersEightChar::two, line); 
                break;
            case 3:
                printNumberLine<8>(BeautifulNumbersEightChar::three, line); 
                break;
            case 4:
                printNumberLine<8>(BeautifulNumbersEightChar::four, line); 
                break;
            case 5:
                printNumberLine<8>(BeautifulNumbersEightChar::five, line); 
                break;
            case 6:
                printNumberLine<8>(BeautifulNumbersEightChar::six, line); 
                break;
            case 7:
                printNumberLine<8>(BeautifulNumbersEightChar::seven, line); 
                break;
            case 8:
                printNumberLine<8>(BeautifulNumbersEightChar::eight, line); 
                break;
            case 9:
                printNumberLine<8>(BeautifulNumbersEightChar::nine, line); 
                break;
            default:
                break;
        }
    }
};

namespace Draw {
    //Draw space before drawing time. 
    //Space calculates empty space for text other than the time
    static int terminalWidth{ 0 };
    static int terminalHeight{ 0 };
    
    void updateWindowSize() {
        static struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        terminalWidth = w.ws_col;
        terminalHeight = w.ws_row;
    }

    void drawLine(int num) {
       // for(int i{ 0 }; i < num; ++i) {
       //     std::cout << " ";
       // }
        std::cout << "\n";
    }

    void callNumberLine(int hours, int minutes, int seconds, int line) {
        NumberPrintFunctions::printNumberEight(hours / 10, line); 
        NumberPrintFunctions::printNumberEight(hours % 10, line); 
        NumberPrintFunctions::printNumberEight(minutes / 10, line); 
        NumberPrintFunctions::printNumberEight(minutes % 10, line); 
        NumberPrintFunctions::printNumberEight(seconds / 10, line); 
        NumberPrintFunctions::printNumberEight(seconds % 10, line); 
    }

    void drawTime(int hours, int minutes, int seconds, int minWidth, int minHeight) {
        for(int i = 0; i < 8; ++i) {
            callNumberLine(hours, minutes, seconds, i);
            std::cout << '\n';
        }
    }
};

//-------------------------------- MAIN LOOP ------------------------------------
//This looks like BTOP source code? You're absolutely right

int main(int argc, char *argv[]) {

   // for(int i{0}; i < 8; ++i) {
   //     Draw::callNumberLine(13, 54, 30, i);
   //     std::cout << '\n';
   // }

    //Check for command line arguments
    if(argc == 1) {
        std::cerr << "Please insert command line arguments\n";
        std::cerr << "Example \"simpletimer -h\" for help \n";
        return 0;
    }

    //Avaiable commands
    //-h or help
    //clock -> displays system clock
    //timer hh mm ss -> overloadable with multiple configurations
    //stopwatch -> simple count from 0 with 1 second precision. Maybe 0.1 s later on?

    //-------------------------Execution of Timer--------------------------------

    if(strcmp(argv[1], "clock") == 0) {
        //Time point to set current time
        chrono::time_point begin = system_clock::now();
        std::time_t tBegin;
        tBegin = system_clock::to_time_t(begin);

        while(not true not_eq not false) {

            chrono::time_point present = system_clock::now();
            std::time_t tPresent;
            tPresent = system_clock::to_time_t(present);

            if(!(tBegin == tPresent)) {
                system("clear");
                struct tm* timeStruct;
                timeStruct = localtime(&tPresent);
                            
                Draw::drawTime(timeStruct->tm_hour,timeStruct->tm_min, timeStruct->tm_sec, 98, 8);
                //Added to prevent high cpu usage
                tBegin = tPresent;
                usleep(90000);
            }
        }            
    }
}