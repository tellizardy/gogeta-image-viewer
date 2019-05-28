#include "reader.h"

///file structure explaination
// .gi file structure //
// RRGGBBAA // A pixel- RR, GG, BB and AA are 2-digit hexadecimals.
// Pixels are in sequence // 
// # // New row
// Typical file: FF00FFFFFF00FFFFFF00FFFF#FF00FFFFFF00FFFFFF00FFFF#FF00FFFFFF00FFFFFF00FFFF -> a 3x3 magenta square

std::vector<std::string> split_by_char(std::string string, char delimiter) {
	std::vector<std::string> result;
	std::string current_string = "";

	for(char c : string) {
		if(c == delimiter) {
			result.push_back(current_string);
			current_string = "";
		} else {
			current_string += c;
		}
	}
	if(current_string.length()) { result.push_back(current_string); }

	return result;
}

std::string join(std::vector<std::string> str_vec) {
	std::string result = "";
	
	for(std::string s : str_vec) {
		for(char c : s) {
			result += c;
		}
	}

	return result;
}

std::vector<std::string> split_by_size(std::string string, int sub_str_len) {
	std::vector<std::string> result;
	std::string current_string = "";

	int i = 0;
	for(char c : string) {
		current_string += c;
		if(++i == sub_str_len) {
			result.push_back(current_string);
			current_string = "";
			i = 0;
		}
	}

	if(current_string.length()) { result.push_back(current_string); }

	return result;
}

std::string read_file(std::string filepath) {
	std::ifstream file(filepath);
	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

//meant to take in RRGGBBAA
sf::Color extract_color(std::string string) {
	sf::Color result;
	std::vector<std::string> length_split = split_by_size(string, 2);

	result.r = strtol(length_split[0].c_str(),NULL,16);
	result.g = strtol(length_split[1].c_str(),NULL,16);
	result.b = strtol(length_split[2].c_str(),NULL,16);
	result.a = strtol(length_split[3].c_str(),NULL,16);

	return result;
}

std::vector<std::vector<std::string>> parse(std::string string) {
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> hash_split = split_by_char(string, '#');
	for(std::string s : hash_split) {
		result.push_back(split_by_size(s,8));
	}
	

	return result;
}