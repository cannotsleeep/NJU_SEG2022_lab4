#ifndef RANDOM
#define RANDOM
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <sys/types.h>
#include <dirent.h>  
#include <cstring>
#include <fstream>

const int samples = 50;
const std::string dataprefix = "/stdin_format_data";

int randx(int l,int r);
void generate(char* formatname);
void GetFileName(std::string path, std::vector<std::string> &files);
int Ran_in();

#endif