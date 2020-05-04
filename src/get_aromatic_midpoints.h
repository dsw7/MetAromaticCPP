#ifndef GET_AROMATIC_MIDPOINTS_H
#define GET_AROMATIC_MIDPOINTS_H

#include <set>
#include <vector>
#include <iostream>

void get_trp_midpoints(std::vector<std::map<std::string, std::string>> *trp_data) {
    std::set<std::string> res;
    for (std::vector<std::map<std::string, std::string>>::iterator it = trp_data->begin(); it != trp_data->end(); ++it) {
        res.insert(it->at("res_pos"));
    }

    for (std::set<std::string>::iterator it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

#endif