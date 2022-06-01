#ifndef __INPUT_CLI__
#define __INPUT_CLI__

#include "InputAdapter.h"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

class InputCLI
{
private:

    InputAdapter* adapter;
    std::list<std::string> commandTokens
    {
        "add",
        "start",
    };

    std::map<std::string, const std::type_info&> addParams
    {
        {"shape", typeid(std::string)},
        {"x", typeid(int)},
        {"y", typeid(int)},
        {"width", typeid(int)},
        {"height", typeid(int)},
        {"weight", typeid(int)},
        {"velX", typeid(int)},
        {"velY", typeid(int)}
    };

public:
    InputCLI(InputAdapter& adapter);
    bool parse();
private:
    std::vector<std::string> parseCmd(std::string cmd);
    bool parseParams(std::vector<std::string> tokens);
    void createObject(std::map<std::string, std::string> objects);
};

#endif
