#include <iostream>
#include <fstream>
#include <optional>

using Aim = unsigned int;
using Distance = unsigned int;
using Depth = unsigned int;

typedef struct {
    Aim aim {0};
    Distance distance {0};
    Depth depth {0};
} Position;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: day2b <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input_stream(argv[1]);

    if (!input_stream.is_open())
    {
        std::cerr << "Error opening " << argv[1] << std::endl;
        return 1;
    }

    std::string command, factor;

    Position position;
    while (input_stream >> command && input_stream >> factor)
    {
        auto int_factor = std::stoi(factor);

        if (command == "forward")
        {
            position.distance += int_factor;
            position.depth += position.aim * int_factor;
        }
        else if (command == "up")
        {
            position.aim -= int_factor;
        }
        else if (command == "down")
        {
            position.aim += int_factor;
        }
        else
        {
            std::cerr << "Unknown command: " << command << std::endl;
            return 1;
        }
    }

    std::cout << "Final position: distance = " << position.distance << ", depth = " << position.depth << ", multiplied = " << position.distance*position.depth << std::endl;

    return 0;
}