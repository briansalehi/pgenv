#include <pgenv/pgenv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    pg::arguments_parser options{argc, argv};
    pg::executor executor{};
    executor.run(options);
}
