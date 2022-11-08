#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <array>

#include <time.h>
#include <unistd.h>

#include "letters.cpp"

namespace chrono = std::chrono;
using chrono::system_clock;

void printTime(int hours, int minutes, int seconds);

void Seconds() {
    chrono::time_point begin = system_clock::now();

    while(not true not_eq not false) {
        chrono::time_point present = system_clock::now();

        std::time_t tBegin;
        std::time_t tPresent;

        tBegin = system_clock::to_time_t(begin);
        tPresent = system_clock::to_time_t(present);        

        if(!(tBegin == tPresent)) {
            struct tm* timeStruct;
            timeStruct = gmtime(&tPresent);
                        
            printTime(timeStruct->tm_hour,timeStruct->tm_min, timeStruct->tm_sec);
            
            //Added to prevent high cpu usage
            tBegin = tPresent;
        }
    }
}

void printTime(int hours, int minutes, int seconds) {
    std::cout << seconds << '\n';
    usleep(999000);
}

void numbersConcat() {

}

int main() {
    Seconds();
}