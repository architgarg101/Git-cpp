#include <headers/commands.hpp>
int handleHashObject(int argc, char *argv[])
{
    if (argc < 4)
    {
        cerr << "Usage: hash-object -w <string>\n";
        return EXIT_FAILURE;
    }

    string mode = argv[2];
    if (mode != "-w")
    {
        cerr << mode << '\n';
        return EXIT_FAILURE;
    }
    string arg = static_cast<string>(argv[3]);
    try
    {
        if (exists(path(arg)))
        {
            arg = readFileContents(arg);
        }
    }
    catch (const exception &e)
    {
        // If reading as file failed, proceed treating `arg` as literal content
    }
    string header = "blob " + to_string(arg.size()) + '\0';
    string content = header + arg;
    string sha = sha1(content);
    string dir = sha.substr(0, 2);
    string file_name = sha.substr(2);
    string zlib_compressed = compressZlib(content);
    try
    {
        create_directories(".git/objects/" + dir);
    }
    catch (const exception &e)
    {
        return error("Failed to create object directory: " + string(e.what()));
    }
    string path = ".git/objects/" + dir + "/" + file_name;
    try
    {
        writeFileContents(path, zlib_compressed);
    }
    catch (const exception &e)
    {
        return error(string("Failed to write object file: ") + e.what());
    }
    cout << sha << endl;
    return EXIT_SUCCESS;
}