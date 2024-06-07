#pragma once
#include <string>

namespace Application
{
    struct ApplicationSpecifications
    {
        int Width = 640;
        int Height = 320;
        std::string Title = "Hello world";
    };
    class Application
    {
    public:
        Application();
        ~Application();
    };
}
