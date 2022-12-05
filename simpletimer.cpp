#include <iostream>
#include <ctime> //Use ot time_t 
#include <cstring>
#include <ratio>
#include <chrono>
#include <array>
#include <string>
#include <sys/ioctl.h>
#include <sstream>

#include <time.h>
#include <unistd.h> //Use of sleep

#include "letters.cpp"

namespace chrono = std::chrono;

namespace NumberPrintFunctions {

    //Inline template function to print single line of a number from letters.cpp
    template<int num> inline void printNumberLineIndiv(std::array<std::array<std::string, num>, 11> arr, int number, int lineNumber) {
        std::cout << arr[number][lineNumber];
    }

    //Switch function to choose array based on number and call printNumberLine function
    void printNumberLine(int numberCode, int line, int size) {
        switch(size) {
            case 5:
                printNumberLineIndiv<5>(CharacterArrays::BeautifulCharFiveLine, numberCode, line);
                break;
            case 8:
                printNumberLineIndiv<8>(CharacterArrays::BeautifulCharEightLine, numberCode, line);
                break;
            default:
                throw std::invalid_argument("There is no available number");
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

    inline void drawLine(int num) {
         for(int i{ 0 }; i < num; ++i) {
            std::cout << "\n";
        }
    }

    inline void repeatSpace(int num) {
        for(int i{ 0 }; i < num; ++i) {
            std::cout << ' ';
        }
    }

    //Slightly messy function calls 6 numbers and a colon PER LINE
    void callNumberLine(int hours, int minutes, int seconds, int line, int size) {
        NumberPrintFunctions::printNumberLine(hours / 10, line, size);
        NumberPrintFunctions::printNumberLine(hours % 10, line, size);
        NumberPrintFunctions::printNumberLine(10, line, 8);
        NumberPrintFunctions::printNumberLine(minutes / 10, line, size);
        NumberPrintFunctions::printNumberLine(minutes % 10, line, size);
        NumberPrintFunctions::printNumberLine(10, line, 8);
        NumberPrintFunctions::printNumberLine(seconds / 10, line, size);
        NumberPrintFunctions::printNumberLine(seconds % 10, line, size);
    }

    void drawTime(int hours, int minutes, int seconds, int minWidth, int minHeight) {
        updateWindowSize();

        //BufferSpace variables are used to calculate space around the clock itself
        int verticalBufferSpace = (terminalHeight - minHeight) / 2; 
        int horizonalBufferSpace = (terminalWidth - minWidth) / 2;
    
        drawLine(verticalBufferSpace);

        for(int drawnNumberLine = 0; drawnNumberLine < minHeight; ++drawnNumberLine) {
            repeatSpace(horizonalBufferSpace);
            callNumberLine(hours, minutes, seconds, drawnNumberLine, minHeight);
            std::cout << '\n';
        }

        drawLine(verticalBufferSpace);

    }

    void callNumberLineMiliseconds(int minutes, int seconds, int milliseconds, int line) {
        NumberPrintFunctions::printNumberLine(minutes / 10, line, 8);
        NumberPrintFunctions::printNumberLine(minutes % 10, line, 8);
        NumberPrintFunctions::printNumberLine(10, line, 8);
        NumberPrintFunctions::printNumberLine(seconds / 10, line, 8);
        NumberPrintFunctions::printNumberLine(seconds % 10, line, 8);

        if(line >= 3) {
            NumberPrintFunctions::printNumberLine(milliseconds / 100, line - 3, 5);
            NumberPrintFunctions::printNumberLine((milliseconds / 10) % 10, line - 3, 5);
            //NumberPrintFunctions::printNumberLine((milliseconds % 10) % 10, line - 3, 5);
        }
    }

    void drawTimeMilliseconds(int milliseconds, int minWidth, int minHeight) {
        updateWindowSize();

        //BufferSpace variables are used to calculate space around the clock itself
        int verticalBufferSpace = (terminalHeight - minHeight) / 2; 
        int horizonalBufferSpace = (terminalWidth - minWidth) / 2;
    
        drawLine(verticalBufferSpace);
 
        for(int drawnNumberLine = 0; drawnNumberLine < minHeight; ++drawnNumberLine) {
            callNumberLineMiliseconds(milliseconds / 36000 ,milliseconds / 1000,milliseconds % 1000, drawnNumberLine);
            //callNumberLineMiliseconds(milliseconds / 3600000 , milliseconds / 1000, milliseconds % 1000, drawnNumberLine);
            std::cout << '\n';
        }

        drawLine(verticalBufferSpace);
    }
};

namespace Timer {
    int stringToInteger(std::string &&testString) {
        //This workss??? HAHAHAHAHAHAH cpp please fucking pointers
        std::stringstream temporaryObject{ testString };
        int returnInteger;

        temporaryObject >> returnInteger;

        return returnInteger;
    }

    void timerLoop(int seconds = 0, int minutes = 0, int hours = 0) {

        //Initialize time left in seconds
        int timeRemaining{ hours * 3600 + minutes * 60 + seconds };

        chrono::high_resolution_clock::time_point startTime = chrono::high_resolution_clock::now();

        while(true) {
            chrono::high_resolution_clock::time_point nowTime = chrono::high_resolution_clock::now();
            chrono::duration clockElapsed = chrono::duration_cast<chrono::seconds>(nowTime - startTime);
            
            if (timeRemaining == -1) {
                break;
            }

            if(clockElapsed.count() == 1) { //If there is a one second difference
                system("clear");
                printf("\e[3J");

                Draw::drawTime(timeRemaining / 3600, (timeRemaining % 3600) / 60, timeRemaining % 60, 94, 8);
                startTime = chrono::high_resolution_clock::now();
                timeRemaining -= 1;
            }
        }
    }
};

//-------------------------------- MAIN LOOP ------------------------------------
//This looks like BTOP source code? This project is inspired by BTOP

int main(int argc, char *argv[]) {

    #ifdef DEBUG_TESTCODE

    //Use this space to call functions instantly
    Timer::timerLoop(0,0,50);

    #endif

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
                printf("\e[3J");

                struct tm* timeStruct;
                timeStruct = localtime(&tPresent);
                            
                Draw::drawTime(timeStruct->tm_hour,timeStruct->tm_min, timeStruct->tm_sec, 94, 5);
                //Added to prevent high cpu usage
                tBegin = tPresent;
                usleep(999000);
            }
        }            
    }

    //-------------------------Execution of Stopwatch--------------------------------
    if(strcmp(argv[1], "stopwatch") == 0) {

        int time{ 0 };

        chrono::high_resolution_clock::time_point startTime = chrono::high_resolution_clock::now();

        while(true) {
            chrono::high_resolution_clock::time_point nowTime = chrono::high_resolution_clock::now();
            chrono::duration clockElapsed = chrono::duration_cast<chrono::seconds>(nowTime - startTime);

            if(clockElapsed.count() == 1) { //If there is a one second difference
                system("clear");
                printf("\e[3J");

                Draw::drawTime(time / 3600, (time % 3600) / 60, time % 60, 94, 8);
                startTime = chrono::high_resolution_clock::now();
                time += 1;
            }
        }
    }

    //-------------------------Execution of Timer--------------------------------
    if(strcmp(argv[1], "timer") == 0) {
        switch(argc) {
            case(3): {
                Timer::timerLoop(
                    Timer::stringToInteger(argv[2])
                );
                break;
            }

            case(4): {
                Timer::timerLoop(
                    Timer::stringToInteger(argv[2]),
                    Timer::stringToInteger(argv[3])
                );
                break; 
            }
            
            case(5): {
                Timer::timerLoop(
                    Timer::stringToInteger(argv[2]),
                    Timer::stringToInteger(argv[3]),
                    Timer::stringToInteger(argv[4])
                );
                break; 
            }

            default:
                std::cout << "Enter the appropriate amount of variables\n";
        }
    }
}

