#include <iostream>
#include <fstream>
#include <optional>

using Depth = unsigned int;

class Sonar
{
  public:
    void push_depth(Depth depth);
    unsigned int increases_count() { return increases_count_; }
  private:
    std::optional<Depth> last_depth_;
    unsigned int increases_count_ = 0;
};

void Sonar::push_depth(Depth depth)
{
    if (last_depth_ && *last_depth_ < depth)
        increases_count_++;

    last_depth_ = depth;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: day1a <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input_stream(argv[1]);

    if (!input_stream.is_open())
    {
        std::cerr << "Error opening " << argv[1] << std::endl;
        return 1;
    }

    std::string input;
    Sonar sonar;
    while (input_stream >> input)
    {
        Depth current_depth = std::stoi(input);
        sonar.push_depth(current_depth);
    }

    std::cout << "Depth increases: " << sonar.increases_count() << std::endl;

    return 0;
}