#include <iostream>
#include <ctime> //Use ot time_t 
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

namespace PrintFunctions{ void printTime(int hours, int minutes, int seconds);}

namespace PrintFunctions {

    void printNumberLine(std::array<std::string, 5> arr, int lineNumber);

    void printNumber(int num, int line) {
        switch(num) {
            case 0:
                printNumberLine(Numbers::zero, line); 
                break;
            case 1: 
                printNumberLine(Numbers::one, line); 
                break;
            case 2:
                printNumberLine(Numbers::two, line); 
                break;
            case 3:
                printNumberLine(Numbers::three, line); 
                break;
            case 4:
                printNumberLine(Numbers::four, line); 
                break;
            case 5:
                printNumberLine(Numbers::five, line); 
                break;
            case 6:
                printNumberLine(Numbers::six, line); 
                break;
            case 7:
                printNumberLine(Numbers::seven, line); 
                break;
            case 8:
                printNumberLine(Numbers::eight, line); 
                break;
            case 9:
                printNumberLine(Numbers::nine, line); 
                break;
            default:
                break;
        }

    }

    void printNumberLine(std::array<std::string, 5> arr, int lineNumber) {
        std::cout << arr[lineNumber];
    }
    
    auto& printCharacter = printNumberLine;    

    void twoNumbers(int hours, int row) {
        int firstNumber = hours / 10;
        int secondNumber = hours % 10;

        printNumber(firstNumber, row);
        printCharacter(ExtraCharacters::space, row);
        printNumber(secondNumber, row);
    }

    void printTime(int hours, int minutes, int seconds) {
        
        for(int outRow = 0; outRow < 5; ++outRow) {
            twoNumbers(hours, outRow);
            printCharacter(ExtraCharacters::space, outRow);
            printCharacter(ExtraCharacters::colon, outRow);
            printCharacter(ExtraCharacters::space, outRow);
            twoNumbers(minutes, outRow);
            printCharacter(ExtraCharacters::space, outRow);
            printCharacter(ExtraCharacters::colon, outRow);
            printCharacter(ExtraCharacters::space, outRow);
            twoNumbers(seconds, outRow);

            std::cout << '\n';
        }      
    }
};

namespace Draw {
    bool detectSize(int width, int height) {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        printf ("lines %d\n", w.ws_row);
        printf ("columns %d\n", w.ws_col);
        return 0;  // make sure your main returns int
    }

    void drawSpace() {

    }
    
};


//-------------------------------- MAIN LOOP ------------------------------------
//This looks like BTOP source code? You're absolutely right

int main() {

    //Time point to set current time
    chrono::time_point begin = system_clock::now();

    while(not true not_eq not false) {
        chrono::time_point present = system_clock::now();

        std::time_t tBegin;
        std::time_t tPresent;

        tBegin = system_clock::to_time_t(begin);
        tPresent = system_clock::to_time_t(present);        

        if(!(tBegin == tPresent)) {
            system("clear");
            struct tm* timeStruct;
            timeStruct = localtime(&tPresent);
                        
            PrintFunctions::printTime(timeStruct->tm_hour,timeStruct->tm_min, timeStruct->tm_sec);
            
            //Added to prevent high cpu usage
            tBegin = tPresent;
            usleep(998000);

            //Refactor code here
        }            
    }
}