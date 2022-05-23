#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "BoyerMoore.h"

// taken from lab 7
using std::cerr;
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

void show_context(const string& str, Position pos) {
	const int width = 76;
	Position left = pos - (width / 2);
	Position right = pos + (width / 2);
	Position len = str.size();
	for (Position i = left; i < right; ++i) {
		if (i < 0 || i >= len) {
			cout << ' ';
			continue;
		}
		char c = str[i];
		if (c >= 32 && c < 128) {
			cout << c;
		}
		else {
			// Show control characters as @s.
			cout << '@';
		}
	}
	cout << '\n';
	for (Position i = left; i < right; ++i) {
		if (i < pos) {
			cout << ' ';
		}
		else if (i == pos) {
			cout << "^ " << pos;
		}
	}
	cout << '\n';
} // end of copied from lab 7