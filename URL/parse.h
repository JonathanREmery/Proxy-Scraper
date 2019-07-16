#pragma once

#include <string>
#include <vector>

std::string replace(std::string s, const char* x, std::string r) {
	std::string s1 = s;
	while (s1.find(x) <= s1.length() - 1) {
		int pos = s1.find(x);
		int size = strlen(x);
		s1.replace(pos, size, r);
	}
	return s1;
}

int count(std::string s, const char* d) {
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		bool isSubStr = true;
		for (int x = 0; x < strlen(d); x++) {
			if (s[i + x] != d[x]) {
				isSubStr = false;
			}
		}
		if (isSubStr) {
			c++;
		}
	}
	return c;
}

std::vector<std::string> split(std::string s, const char* d) {

	std::vector<std::string> arr;

	std::string s1 = s;

	s1 = replace(s1, d, ",,,");

	while (s1.find(d) <= s1.length() - 1) {
		int pos = s1.find(d);
		int size = strlen(d);

		std::string rep = ",,,";

		s1.replace(pos, size, rep);
	}

	std::vector<int> positions;

	for (int i = 0; i < s1.length()-2; i++) {
		if (s1[i] == ',' && s1[i+1] == ',' && s1[i+2] == ',') {
			positions.push_back(i);
		}
	}

	for (int i = 0; i < positions.size(); i++) {
		std::string s2 = s1;
		if (i == 0) {
			arr.push_back(s2.erase(positions[i], s2.length()));
		} else {
			arr.push_back(s2.erase(0, positions[i - 1]+3).erase(positions[i] - (positions[i - 1]+3), s2.length()));
		}
		if (i == positions.size() - 1) {
			std::string s4 = s1;
			arr.push_back(s4.erase(0, positions[positions.size() - 1] + 3));
		}
	}

	return arr;
}