#include <array>
#include <string>

namespace SolidNumberFiveChar {
    using std::array;

    array<std::string, 5> zero{
        "000000",
        "00  00",
        "00  00",
        "00  00",
        "000000",
    };

    array<std::string, 5> one{
        "1111  ",
        "  11  ",
        "  11  ",
        "  11  ",
        "111111",
    };

    array<std::string, 5> two{
        "222222",
        "     2",
        "222222",
        "2     ",
        "222222",
    };

    array<std::string, 5> three{
        "333333",
        "    33",
        "333333",
        "    33",
        "333333",
    };

    array<std::string, 5> four{
        "44  44",
        "44  44",
        "444444",
        "    44",
        "    44",
    };

    array<std::string, 5> five{
        "555555",
        "55    ",
        "555555",
        "    55",
        "555555",
    };

    array<std::string, 5> six{
        "555555",
        "55    ",
        "555555",
        "    55",
        "555555",
    };

    array<std::string, 5> seven{
        "777777",
        "    77",
        "    77",
        "    77",
        "    77",
    };

    array<std::string, 5> eight{
        "888888",
        "88  88",
        "888888",
        "88  88",
        "888888",
    };
    
    array<std::string, 5> nine{
        "999999",
        "99  99",
        "999999",
        "    99",
        "999999",
    };
};

namespace SolidExtrasFiveChar {
    using std::array;
    
    array<std::string, 5> space{
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
    };

    array<std::string, 5> colon{
        "  ",
        "██",
        "  ",
        "██",
        "  ",
    };

};


namespace BeautifulNumbersEightChar {
    using std::array;

    array<std::string, 8> zero{
        " .d8888b.     ",    
        "d88P  Y88b    ",    
        "888    888    ",    
        "888    888    ",    
        "888    888    ",    
        "888    888    ",    
        "Y88b  d88P    ",    
        " \"Y8888P\"     ",   

    };

    array<std::string, 8> one{
        "   888       ",
        "od8888       ",
        "   888       ",
        "   888       ",
        "   888       ",
        "   888       ",
        "   888       ",
        "888888888    ",
    };

    array<std::string, 8> two{
        " .d8888b.     ",
        "d88P  Y88b    ",
        "       888    ",
        "     .d88P    ",
        " .od888P\"     ",
        "d88P\"         ",
        "888\"          ",
        "888888888     ",
    };

    array<std::string, 8> three{
        " .d8888b.     ",
        "d88P  Y88b    ",
        "     .d88P    ",
        "    8888\"     ",
        "     \"Y8b.    ",
        "888    888    ",
        "Y88b  d88P    ",
        " \"Y8888P\"     ",
    };

    array<std::string, 8> four{
        "    d8888     ",
        "   d8P888     ",
        "  d8P 888     ",
        " d8P  888     ",
        "d88   888     ",
        "8888888888    ",
        "      888     ",
        "      888     ",
    };

    array<std::string, 8> five{
        "888888888     ",
        "888           ",
        "888           ",
        "8888888b.     ",
        "     \"Y88b    ",
        "       888    ",
        "Y88b  d88P    ",
        " \"Y8888P\"     ",
    };

    array<std::string, 8> six{
        " .d8888b.     ",
        "d88P  Y88b    ",
        "888           ",
        "888d888b.     ",
        "888P \"Y88b    ",
        "888    888    ",
        "Y88b  d88P    ",
        " \"Y8888P\"     ",
    };

    array<std::string, 8> seven{
        "8888888888    ",
        "      d88P    ",
        "     d88P     ",
        "    d88P      ",
        " 88888888     ",
        "  d88P        ",
        " d88P         ",
        "d88P          ",
    };

    array<std::string, 8> eight{
        " .d8888b.     ",
        "d88P  Y88b    ",
        "Y88b. d88P    ",
        " \"Y88888\"     ",
        ".d8P\"\"Y8b.    ",
        "888    888    ",
        "Y88b  d88P    ",
        " \"Y8888P\"     ",
    };    

    array<std::string, 8> nine{
        " .d8888b.     ",
        "d88P  Y88b    ",
        "888    888    ",
        "Y88b. d888    ",
        " \"Y888P888    ",
        "       888    ",
        "Y88b  d88P    ",
        " \"Y8888P\"     ",
    };
};

namespace BeautifulExtraCharEight{
    using std::array;

    array<std::string, 8> colon{
        "        ",
        " d0b    ",
        " 90P    ",
        "        ",
        "        ",
        " d0b    ",
        " 90P    ",
        "        ",
    };
};

//Refactror to use array instead of namespace
namespace CharacterArrays {
    using std::array;

    array<array<std::string, 5>, 11> BeautifulCharFiveLine { { //Keep in mind double brackets here
        
        {
            "000000  ",
            "00  00  ",
            "00  00  ",
            "00  00  ",
            "000000  ",
        },

        {
            "1111    ",
            "  11    ",
            "  11    ",
            "  11    ",
            "111111  ",
        },

        {
            "222222  ",
            "     2  ",
            "222222  ",
            "2       ",
            "222222  ",
        },

        {
            "333333  ",
            "    33  ",
            "333333  ",
            "    33  ",
            "333333  ",
        },

        {
            "44  44  ",
            "44  44  ",
            "444444  ",
            "    44  ",
            "    44  ",
        },

        {
            "555555  ",
            "55      ",
            "555555  ",
            "    55  ",
            "555555  ",
        },

        {
            "555555  ",
            "55      ",
            "555555  ",
            "    55  ",
            "555555  ",
        },

        {
            "777777  ",
            "    77  ",
            "    77  ",
            "    77  ",
            "    77  ",
        },

        {
            "888888  ",
            "88  88  ",
            "888888  ",
            "88  88  ",
            "888888  ",
        },
        
        {
            "999999  ",
            "99  99  ",
            "999999  ",
            "    99  ",
            "999999  ",
        },

        {
        "    ",
        "::: ",
        "    ",
        "::: ",
        "    ",
        }
    } }; 

    array<array<std::string, 8>, 11> BeautifulCharEightLine { {
        {
            " .d8888b.     ",    
            "d88P  Y88b    ",    
            "888    888    ",    
            "888    888    ",    
            "888    888    ",    
            "888    888    ",    
            "Y88b  d88P    ",    
            " \"Y8888P\"     ",   

        },

        {
            "   888       ",
            "od8888       ",
            "   888       ",
            "   888       ",
            "   888       ",
            "   888       ",
            "   888       ",
            "888888888    ",
        },

        {
            " .d8888b.     ",
            "d88P  Y88b    ",
            "       888    ",
            "     .d88P    ",
            " .od888P\"     ",
            "d88P\"         ",
            "888\"          ",
            "888888888     ",
        },

        {
            " .d8888b.     ",
            "d88P  Y88b    ",
            "     .d88P    ",
            "    8888\"     ",
            "     \"Y8b.    ",
            "888    888    ",
            "Y88b  d88P    ",
            " \"Y8888P\"     ",
        },

        {
            "    d8888     ",
            "   d8P888     ",
            "  d8P 888     ",
            " d8P  888     ",
            "d88   888     ",
            "8888888888    ",
            "      888     ",
            "      888     ",
        },
        {
            "888888888     ",
            "888           ",
            "888           ",
            "8888888b.     ",
            "     \"Y88b    ",
            "       888    ",
            "Y88b  d88P    ",
            " \"Y8888P\"     ",
        },

        {
            " .d8888b.     ",
            "d88P  Y88b    ",
            "888           ",
            "888d888b.     ",
            "888P \"Y88b    ",
            "888    888    ",
            "Y88b  d88P    ",
            " \"Y8888P\"     ",
        },

        {
            "8888888888    ",
            "      d88P    ",
            "     d88P     ",
            "    d88P      ",
            " 88888888     ",
            "  d88P        ",
            " d88P         ",
            "d88P          ",
        },

        {
            " .d8888b.     ",
            "d88P  Y88b    ",
            "Y88b. d88P    ",
            " \"Y88888\"     ",
            ".d8P\"\"Y8b.    ",
            "888    888    ",
            "Y88b  d88P    ",
            " \"Y8888P\"     ",
        },    

        {
            " .d8888b.     ",
            "d88P  Y88b    ",
            "888    888    ",
            "Y88b. d888    ",
            " \"Y888P888    ",
            "       888    ",
            "Y88b  d88P    ",
            " \"Y8888P\"     ",
        },
        
        {
        "        ",
        " d0b    ",
        " 90P    ",
        "        ",
        "        ",
        " d0b    ",
        " 90P    ",
        "        ",
        }
    } };
};
