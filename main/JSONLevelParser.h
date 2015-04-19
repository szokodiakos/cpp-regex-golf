#ifndef JSONLEVELPARSER_H
#define JSONLEVELPARSER_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "rapidjson/document.h"

struct JSONLevelParser {
    static void parse(std::string content,
                      std::shared_ptr<std::vector<std::string>>& shouldMatch,
                      std::shared_ptr<std::vector<std::string>>& shouldNotMatch) {
        std::vector<std::string> matchVector;
        std::vector<std::string> notMatchVector;
        rapidjson::Document doc;
        doc.Parse(content.c_str());
        if (doc.Parse(content.c_str()).HasParseError()) {
            throw std::string("Failed parsing JSON. Is it well formed?");
        }

        if (!doc["level"].IsObject()) {
            throw std::string("Invalid JSON format ('level' is not an object).");
        }

        // parse 'shouldMatch' json array
        const rapidjson::Value& matchArray = doc["level"]["shouldMatch"];
        if (!matchArray.IsArray()) {
            throw std::string("Invalid JSON format ('shouldMatch' is not an array).");
        }
        for (rapidjson::SizeType i = 0; i < matchArray.Size(); ++i) {
            const rapidjson::Value& item = matchArray[i];
            if (!item.IsString()) {
                throw std::string("Invalid JSON format ('shouldMatch' array's member is not a string).");
            }
            std::string stringItem = item.GetString();
            matchVector.push_back(stringItem);
        }

        // parse 'shouldNotMatch' json array
        const rapidjson::Value& notMatchArray = doc["level"]["shouldNotMatch"];
        if (!notMatchArray.IsArray()) {
            throw std::string("Invalid JSON format ('shouldNotMatch' is not an array).");
        }
        for (rapidjson::SizeType i = 0; i < notMatchArray.Size(); ++i) {
            const rapidjson::Value& item = notMatchArray[i];
            if (!item.IsString()) {
                throw std::string("Invalid JSON format ('shouldNotMatch' array's member is not a string).");
            }
            std::string stringItem = item.GetString();
            notMatchVector.push_back(stringItem);
        }

        // if everything went right, pass vectors to level's fields
        shouldMatch = std::make_shared<std::vector<std::string>>(matchVector);
        shouldNotMatch = std::make_shared<std::vector<std::string>>(notMatchVector);
    }
};

#endif // JSONLEVELPARSER_H