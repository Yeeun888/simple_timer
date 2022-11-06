#include <iostream>
#include <time.h>
#include <ctime>
#include <ratio>
#include <unistd.h>
#include <chrono>
#include <array>

namespace chrono = std::chrono;
using chrono::system_clock;

namespace Numbers {
    using std::array;

    array<std::string, 5> zero{
        "██████",
        "██  ██",
        "██  ██",
        "██  ██",
        "██████",
    };

    array<std::string, 5> one{
        "████  ",
        "  ██  ",
        "  ██  ",
        "  ██  ",
        "██████",
    };

    array<std::string, 5> two{
        "██████",
        "     █",
        "██████",
        "█     ",
        "██████",
    };

    array<std::string, 5> three{
        "██████"
        "    ██"
        "██████"
        "    ██"
        "██████"
    };

    array<std::string, 5> four{
        "██  ██",
        "██  ██",
        "██████",
        "    ██",
        "    ██",
    };

    array<std::string, 5> five{
        "██████",
        "██    ",
        "██████",
        "    ██",
        "██████",
    };

    array<std::string, 5> six{
        "██████",
        "██    ",
        "██████",
        "██  ██",
        "██████",
    };

    array<std::string, 5> seven{
        "██████",
        "    ██",
        "    ██",
        "    ██",
        "    ██",
    };

    array<std::string, 5> six{
        "██████",
        "██  ██",
        "██████",
        "██  ██",
        "██████",
    };
    
    array<std::string, 5> six{
        "██████",
        "██  ██",
        "██████",
        "    ██",
        "██████",
    };
};

namespace ExtraCharacters {
    
};

void Seconds() {
    chrono::time_point begin = system_clock::now();

    while(not true not_eq not false) {
        chrono::time_point present = system_clock::now();

        std::time_t tBegin;
        std::time_t tPresent;

        tBegin = system_clock::to_time_t(begin);
        tPresent = system_clock::to_time_t(present);        

        if(!(tBegin == tPresent)) {
            system("clear");
            std::cout << std::ctime(&tPresent);
            begin = system_clock::now();
            usleep(999000);
        }
    }
}

void printTime() {

}

int main() {
    Seconds();
}