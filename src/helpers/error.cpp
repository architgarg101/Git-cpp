#include <headers/helpers.hpp>

int error(const string &msg)
{
    cerr << "Error: " << msg << endl;
    return EXIT_FAILURE;
}