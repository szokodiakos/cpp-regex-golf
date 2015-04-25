#ifndef JSONLEVELPARSER_H
#define JSONLEVELPARSER_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "rapidjson/document.h"

/**
 * @class JSONLevelParser
 * @file JSONLevelParser.h
 * @brief Parses a level file using JSON Rapid JSON library.
 */
struct JSONLevelParser {

	/**
	 * @brief Parses a string containing JSON by extracting the shouldMatch and
	 * shouldNotMatch word arrays into the given parameters respectively.
	 * @param content The string containing the JSON structure.
	 * @param shouldMatch Reference to a string vector, which will be filled
	 * with the JSON's shouldMatch array.
	 * @param shouldNotMatch Reference to a string vector, which will be filled
	 * with the JSON's shouldNotMatch array.
	 */
	static void parse(std::string const& content,
	                  std::vector<std::string>& shouldMatch,
	                  std::vector<std::string>& shouldNotMatch);
};

#endif // JSONLEVELPARSER_H
