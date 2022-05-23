#include <cassert>
#include <iostream>
#include <list>
#include <string>

#include "BoyerMoore.h"

using std::cout;
using std::endl;
using std::list;
using std::string;

void boyerMoore(const string& pattern, const string& text) // source: adapted from lecture 7b
{
	Position pat_len = pattern.size();
	Position text_len = text.size();

	int skip[256];
	for (int i = 0; i < 256; ++i)
	{
		skip[i] = pat_len; //  changes every character to 0
	}
	for (int i = 0; i < pat_len; ++i)
	{
		skip[int(pattern[i])] = (pat_len - 1) - i; // changes each character in pattern to number it is from start
	}

	for (Position i = 0; i < text_len - pat_len; ++i) { // same as brute force
		Position s = skip[int(text[i + pat_len - 1])];
		if (s != 0) {
			i += s - 1; // skip forwards
			continue;
		}

		Position j;
		for (j = 0; j < pat_len; j++) {
			//show_context(text, j);
			if (text[i + j] != pattern[j]) { // if there's not match break loop and start again from next i
				break; // Doesn't match here.
			}
		}
		// break takes you to here
		if (j == pat_len) { // if second for loop has been completed the same amount of times as there is letters in the pattern, that must be where the pattern is
			cout << "Found '" << pattern << "' at position " << i << ":\n";
			show_context(text, i); //return i; // Matched here. 
			// i doesn't change in the second for loop so it is equal to the index of where the pattern starts
		}
	}
}

int main(int argc, char* argv[])
{
	// setting text / pattern
	string text = "University of Abertay Dundee, Bell Street, Dundee, Scotland";
	string pattern = "Dundee";
	
	// calling Boyer Moore search method
	boyerMoore(pattern, text);

	return 0;
}