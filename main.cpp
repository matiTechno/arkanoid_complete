#include <app.hpp>
#include <stdexcept>
#include <iostream>
#include <sstream>

bool isUnsigned(const char* ptr)
{
    while(*ptr)
    {
        if(*ptr < '0' || *ptr > '9')
            return false;
        ++ptr;
    }
    return true;
}

int main(int argc, char** argv)
{
    unsigned width = 0, height = 0;
    if(argc == 1)
    {
        width = 800;
        height = 600;
    }
    else if(argc == 3)
    {
        if(isUnsigned(argv[1]) && isUnsigned(argv[2]))
        {
            std::stringstream ss_width(argv[1]);
            std::stringstream ss_height(argv[2]);
            ss_width >> width;
            ss_height >> height;
        }
        else
        {
            std::cout << "arguments must be unsigned" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << "0 arguments or 2 (width, height) expected" << std::endl;
        return 0;
    }
    try
    {
        App app(width, height);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
