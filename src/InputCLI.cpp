#include "InputCLI.h"

InputCLI::InputCLI(InputAdapter& adapter)
{
    this->adapter = &adapter;
}

bool InputCLI::parse()
{
    std::string in;
    std::getline(std::cin, in);
    std::vector<std::string> tokens = parseCmd(in);
    if (!tokens.empty())
        return parseParams(tokens);
    return false;
}

std::vector<std::string> InputCLI::parseCmd(std::string cmd)
{
    std::string delimiter = " ";
    size_t pos = 0;
    std::vector<std::string> tokens;
    while ((pos = cmd.find(delimiter)) != std::string::npos)
    {
        tokens.push_back(cmd.substr(0, pos));
        cmd.erase(0, pos + delimiter.length());
    }
    tokens.push_back(cmd);
    auto cmdToken = std::find(commandTokens.begin(), commandTokens.end(), tokens[0]);
    if (cmdToken == commandTokens.end())
    {
        std::cout << "Unknown command: " << tokens[0] << std::endl;
        tokens.clear();
    }
    return tokens;
}

bool InputCLI::parseParams(std::vector<std::string> tokens)
{
    std::string delimiter = "=";
    size_t pos = 0;
    std::map<std::string, std::string> params;
    std::string cmd = tokens[0];
    tokens.erase(tokens.begin());
    for (auto token : tokens)
    {
        if ((pos = token.find(delimiter)) != std::string::npos)
        {
            auto param = token.substr(0, pos);
            auto value = token.substr(pos + 1, pos + token.length());
            params.insert(std::pair<std::string, std::string>(param, value));
        }
    }
    if (cmd == "add")
    {
        for (auto [param, type] : addParams)
        {
            if (params.find(param) == params.end())
            {
                std::cout << "Can't find parameter: " << param << std::endl;
                std::cout << "Usage: add shape=[circle|rect] x=[int] y=[int] width=[int] heigth=[int] weight=[int] velX=[int] velY=[int]" << std::endl;
                return false;
            }
        }
        createObject(params);
    }
    else if (cmd == "start")
    {
        return true;
    }
    return false;
}

void InputCLI::createObject(std::map<std::string, std::string> objects)
{
    std::string shape;
    int x;
    int y; 
    int width;
    int height;
    int velX;
    int velY;
    int weight;

    for(auto [param, value] : objects)
    {
        int intValue;
        if (addParams.at(param) == typeid(int))
        {
            intValue = std::stoi(value);
        }
        if (param == "shape")
            shape = value;
        else if (param == "x")
            x = intValue;
        else if (param == "y")
            y = intValue;
        else if (param == "width")
            width = intValue;
        else if (param == "height")
            height = intValue;
        else if (param == "weight")
            weight = intValue;
        else if (param == "velX")
            velX = intValue;
        else if (param == "velY")
            velY = intValue;
    }
    adapter->createObject(shape, width, height, weight, x, y, velX, velY);
}