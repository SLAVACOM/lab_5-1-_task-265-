#pragma once
#include <string>

void task();

void readFromConsole(std::string& buffer);

bool readFromFile(std::string filename,std::string& buffer);

bool writeToFile(std::string filename, std::string& buffer);

void editData(std::string& buffer);