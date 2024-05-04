#pragma once
#include <string>

void task();

void readFromConsole(std::string& buffer);

void readFromFile(std::string filename,std::string& buffer);

void writeToFile(std::string filename, std::string& buffer);

void editData(std::string& buffer);