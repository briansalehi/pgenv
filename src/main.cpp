#include <pgenv/pgenv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    try
    {
        pg::argument_parser options{argc, argv};
        pg::executor executor{};
        executor.run(options);
    }
    catch (std::exception const& exp)
    {
        std::cerr << exp.what() << std::endl;
        return 1;
    }

    return 0;
}
