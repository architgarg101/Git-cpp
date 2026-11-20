#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <bits/stdc++.h>
using namespace std;
using namespace filesystem;
string decompressZlib(const string &compressed);
string sha1(const string &input);
string sha1_byte(const string &input);
string compressZlib(const string &input);
int error(const string &msg);
// File helpers
string readFileContents(const string &path);
void writeFileContents(const string &path, const string &data);
string makeTreeBlobFromFile(const string &filePath, const string &entryName);
string to_tree_blob(const string &name, int mode, const string &content);
string write_tree_blob(const string &content);
pair<string, string> map_directory(path p, error_code ec);
path findRepoRoot(path start);
#endif
