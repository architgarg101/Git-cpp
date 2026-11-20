#include <headers/commands.hpp>

int main(int argc, char *argv[])
{
    cout << unitbuf;
    cerr << unitbuf;
    if (argc < 2)
    {
        return error("No command provided.");
    }

    return handleCommands(argc, argv);
}
