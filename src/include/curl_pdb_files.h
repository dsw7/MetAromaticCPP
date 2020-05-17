#ifndef CURL_PDB_FILES_H
#define CURL_PDB_FILES_H

#include <string>
#include <iostream>
#include <curl/curl.h>

static size_t write_from_curl_to_string(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool download_https_file(std::string filename, std::string *output) {
    bool rv = true;
    CURL *curl;
    CURLcode res; 

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, filename.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_from_curl_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output);

        // return CURLE_HTTP_RETURNED_ERROR if we get 404 error due to bad PDB code
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        res = curl_easy_perform(curl);

#if DEBUG_CURL == 1
        std::cout << "CURLcode: " << res << std::endl;
#endif

        if (res != CURLE_OK) {
            rv = false;
        }
        curl_easy_cleanup(curl);
    }
    else {
        rv = false;
    }
 
    curl_global_cleanup();
    return rv;
}

#endif