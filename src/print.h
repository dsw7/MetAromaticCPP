#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>

void print_stdout(std::string msg) {
	std::cout << msg << std::endl;
}

void print_stderr(std::string msg) {
	std::cerr << msg << std::endl;
}

#endif