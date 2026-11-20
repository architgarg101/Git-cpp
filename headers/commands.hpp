#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <filesystem>
#include <fstream>
#include <zlib.h>
#include <bits/stdc++.h>
#include <headers/helpers.hpp>
#include <openssl/sha.h>
#include <iomanip>

using namespace std;
using namespace filesystem;

int handleCommands(int argc, char *argv[]);
int handleInit(int argc, char *argv[]);
int handleCatFile(int argc, char *argv[]);
int handleHashObject(int argc, char *argv[]);
int handleLsTree(int argc, char *argv[]);
int handleWriteTree(int argc, char *argv[]);

// constants (defined in src/constants.cpp)
extern const int REGULAR_FILE;
extern const int EXECUTABLE_FILE;
extern const int DIRR;

#endif