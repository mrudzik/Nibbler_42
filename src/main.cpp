
#include <iostream>
#include <string>

#include "Core.hpp"
#include "Parser.hpp"

int    InputManager(std::string input)
{// Temporary function for testing purposes
    if (input.compare("8") == 0)
        return e_Up;
    if (input.compare("7") == 0)
        return e_UpLeft;
    if (input.compare("9") == 0)
        return e_UpRight;
    
    if (input.compare("2") == 0)
        return e_Down;
    if (input.compare("1") == 0)
        return e_DownLeft;
    if (input.compare("3") == 0)
        return e_DownRight;

    if (input.compare("4") == 0)
        return e_Left;
    if (input.compare("6") == 0)
        return e_Right;
    if (input.compare("5") == 0)
        return -2; // Signal to grow

    return -1;
}


void    GameLoop(Core &gameCore)
{
    s_CoreOutput    outputData;
    s_CoreInput     inputData;
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

        inputData.direction = InputManager(text);


        outputData = gameCore.MakeTurn(inputData);
        
        MapBuilder::ShowMap(outputData);


        if (outputData.win)
            throw std::logic_error("Win");
        if (outputData.lose)
            throw std::logic_error("Lose");
    }
}




int     main(int argv, char** argc)
{
    std::cout << "Press Enter" << std::endl;
    
    Core *gameCore = NULL;
    try
    {
        if (argv < 3)
        throw std::logic_error("Not enough arguments");

        int xSize = Parser::ParseNum(argc[1]);
        int ySize = Parser::ParseNum(argc[2]);
        gameCore = new Core(xSize, ySize, false);

        GameLoop(*gameCore);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // Clear
    if (gameCore != NULL) delete gameCore;

    std::cout << "Exiting programm" << std::endl;
    system("leaks nibbler");

}