#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include "stdlib.h"
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>

std::vector<std::string> split_by_char(std::string string,char delimiter);
std::vector<std::string> split_by_size(std::string string,int sub_str_len);
std::string read_file(std::string filepath);
std::vector<std::vector<std::string>> parse(std::string string);
std::string join(std::vector<std::string> str_vec);
sf::Color extract_color(std::string str);