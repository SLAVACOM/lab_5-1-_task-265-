#include <regex>
#include <iostream>
#include <string>

#include <fstream>
#include <cstring>

#include "constants.h"
#include "utils.h"

using namespace std;

void task() {
	regex valid_input("^[01]$");

	string input, in_option, out_option;

	do {
		do {
			cout << "������� '0' ��� ����� � �������, '1' ��� ����� �� �����: ";
			getline(cin, input);
		} while (!regex_match(input, valid_input));
		in_option = input;

		do {
			cout << "������� '0' ��� ������ �� �������, '1' ��� ������ � ����: ";
			getline(cin, input);
		} while (!regex_match(input, valid_input));
		out_option = input;

		string dataBuffer;

		if (in_option == "0") readFromConsole(dataBuffer);
		else if (in_option == "1") {
			bool valid_file = false;

			do {
				cout << "������� ���� ��� ����� �������� ������ (��� ����������) (enter ��� ����� �� ���������): ";
				getline(cin, input);
				valid_file = readFromFile(input, dataBuffer);
			} while (!valid_file);
			
		}

		editData(dataBuffer);

		if (out_option == "0") cout << dataBuffer << endl;
		else if (out_option == "1") {
			bool valid_file = false;
			do {
				cout << "������� ���� ��� ������ �������� ������ (��� ����������) (enter ��� ����� �� ���������): ";
				getline(cin, input);
				valid_file = writeToFile(input, dataBuffer);
			} while (!valid_file);
			
		}

		if (in_option == "0") {
			do {
				cout << "������� '0' ��� ������� ���������, '1' ��� ���������� ���������: ";
				getline(cin, input);
			} while (!regex_match(input, valid_input));
			in_option = input;
		}

	} while (in_option != "1");
}


void readFromConsole(std::string& buffer) {
	cout << "������� ������: ";
	string input;
	getline(cin, buffer);
}

void editData(std::string& buffer) {
	int startIndex{ 0 };
	while (buffer[startIndex] != constants::START_SYMBOL && startIndex <buffer.length()) startIndex++;
	for (int i{ startIndex + 1 };  i < buffer.length(); i++) {
		if(buffer[i] != '\n') buffer[i] = constants::REPLACE_SYMBOL;
	}
}

bool readFromFile(std::string filename, std::string& buffer) {
	ifstream file(filename == "" ? constants::input : filename + ".txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) buffer+=line+'\n';
		file.close();
		return true;
	}
	else cout << "������ ��� �������� �����" << endl;
	return false;
}

bool writeToFile(string filename, string& buffer) {
	ofstream outputFile(filename == "" ? constants::output : filename + ".txt");
	if (!outputFile.is_open()) cout << "������ ��� �������� ����� ��� ������" << endl;
	else {
		outputFile << buffer << endl; 
		outputFile.close();
		return true;
	}
	return false;
}