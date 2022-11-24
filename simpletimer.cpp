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

namespace NumberPrintFunctions {

    //Inline template function to print single line of a number from letters.cpp
    template<int num> inline void printNumberLine(std::array<std::array<std::string, num>, 11> arr, int number, int lineNumber) {
        std::cout << arr[number][lineNumber];
    }

    //Switch function to choose array based on number and call printNumberLine function
    void printNumberLine(int numberCode, int line, int size) {
        switch(size) {
            case 5:
                printNumberLine<5>(CharacterArrays::BeautifulCharFiveLine, numberCode, line);
                break;
            case 8:
                printNumberLine<8>(CharacterArrays::BeautifulCharEightLine, numberCode, line);
                break;
            default:
                //Cleanup
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
         for(int i{ 0 }; i < num; ++i) {
            std::cout << "\n";
        }
    }

    void repeatSpace(int num) {
        for(int i{ 0 }; i < num; ++i) {
            std::cout << ' ';
        }
    }

    //Slightly messy function calls 6 numbers and a colon PER LINE

    void callNumberLine(int hours, int minutes, int seconds, int line) {
        NumberPrintFunctions::printNumberLine(hours / 10, line, 8);
        NumberPrintFunctions::printNumberLine(hours % 10, line, 8);
        NumberPrintFunctions::printNumberLine(10, line, 8);
        NumberPrintFunctions::printNumberLine(minutes / 10, line, 8);
        NumberPrintFunctions::printNumberLine(minutes % 10, line, 8);
        NumberPrintFunctions::printNumberLine(10, line, 8);
        NumberPrintFunctions::printNumberLine(seconds / 10, line, 8);
        NumberPrintFunctions::printNumberLine(seconds % 10, line, 8);
    }

    void drawTime(int hours, int minutes, int seconds, int minWidth, int minHeight) {
        updateWindowSize();

        //BufferSpace variables are used to calculate space around the clock itself
        int verticalBufferSpace = (terminalHeight - minHeight) / 2; 
        int horizonalBufferSpace = (terminalWidth - minWidth) / 2;
    
        drawLine(verticalBufferSpace);

        for(int drawnNumberLine = 0; drawnNumberLine < minHeight; ++drawnNumberLine) {
            repeatSpace(horizonalBufferSpace);
            callNumberLine(hours, minutes, seconds, drawnNumberLine);
            std::cout << '\n';
        }

        //Reassess if it is necessary at all
        drawLine(verticalBufferSpace);
    }

    void drawTimeMiliseconds(int miliseconds, int minWidth, int minHeight) {

    }
};

//-------------------------------- MAIN LOOP ------------------------------------
//This looks like BTOP source code? This project is inspired by BTOP

int main(int argc, char *argv[]) {

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

    //-------------------------Execution of Clock--------------------------------

    if(strcmp(argv[1], "clock") == 0) {
        //Time point to set current time
        chrono::time_point begin = chrono::system_clock::now();
        std::time_t tBegin;
        tBegin = chrono::system_clock::to_time_t(begin);

        while(not true not_eq not false) {

            chrono::time_point present = chrono::system_clock::now();
            std::time_t tPresent;
            tPresent = chrono::system_clock::to_time_t(present);

            if(!(tBegin == tPresent)) {
                system("clear");
                struct tm* timeStruct;
                timeStruct = localtime(&tPresent);
                            
                Draw::drawTime(timeStruct->tm_hour,timeStruct->tm_min, timeStruct->tm_sec, 98, 8);
                //Added to prevent high cpu usage
                tBegin = tPresent;
                usleep(999000);
            }
        }            
    }

    //-------------------------Execution of Timer--------------------------------
    if(strcmp(argv[1], "timer") == 0) {

        using hrc = chrono::high_resolution_clock;
        hrc::time_point tBegin = hrc::now();
        int timeElapsed{ 0 };

        while(not true not_eq not false) {
            hrc::time_point tNow = hrc::now();
            
            hrc::duration timeElapsedCalculation = chrono::duration_cast<chrono::milliseconds>(tNow - tBegin);
            if(!(timeElapsed == timeElapsedCalculation.count())) {
                system("clear");
                
                timeElapsed = timeElapsedCalculation.count();
                Draw::drawTimeMiliseconds(timeElapsed, 95, 8);

                usleep(999000);
            } 

        }
    }
}

