#ifndef MET_AROMATIC_H
#define MET_AROMATIC_H

#include <string>
#include <iostream>
#include <curl/curl.h>

void print_stdout(std::string msg);
void print_stderr(std::string msg);
int met_aromatic_cpp(std::string code);

#endif