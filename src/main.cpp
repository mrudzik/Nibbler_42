
#include <iostream>
#include <string>

#include "Core.hpp"



void    GameLoop()
{
    Core gameCore(10, 10, false);

    while (1)
    {
        std::string text;
        std::getline(std::cin, text);
		std::cout << "Input " << text << std::endl;
        if (text.compare("exit") == 0)
            break;
        if (text.compare("q") == 0)
            break;
    //////////////////////////////

        gameCore.MakeTurn();

        
    }
}




int     main(int argv, char** argc)
{
    (void)argv;
    (void)argc;
    std::cout << "Hello There" << std::endl;

    // Parser here
    GameLoop();

    system("leaks nibbler");
}