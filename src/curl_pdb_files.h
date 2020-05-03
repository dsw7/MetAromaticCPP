#ifndef CURL_PDB_FILES_H
#define CURL_PDB_FILES_H

#include <string>
#include <iostream>
#include <curl/curl.h>

bool download_https_file(std::string filename, std::string *output);

#endif