#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include "FileHandler.h"
#include "JSONLevelParser.h"

/**
 * @class Level
 * @file Level.h
 * @brief Class representing a level in the game. Contains two string vectors,
 * one containing the words that a regex pattern should match, and anotherone
 * that a regex pattern should not match.
 */
class Level {

	/**
	 * @brief Vector containing words which the user's regex should match.
	 */
	std::vector<std::string> shouldMatch;

	/**
	 * @brief Vector containing words which the user's regex should NOT match.
	 */
	std::vector<std::string> shouldNotMatch;
public:

	/**
	 * @brief Constant which stores the path to the level files.
	 */
	constexpr static auto LEVELS_DIR = "../levels";

	/**
	 * @brief No-arg constructor.
	 */
	Level();

	/**
	 * @brief Constructor which creates a level using a file's content.
	 * This constructor can be parametrized with a parser strategy. Its
	 * default parser is the JSONLevelParser.
	 * @param content The string holding a level file's content.
	 */
	template <typename LevelParser = JSONLevelParser>
	Level(std::string const& content);

	/**
	 * @brief Destructor.
	 */
	~Level();

	/**
	 * @brief Prints the levels words with regex pattern match results.
	 * @param results A map with level word keys, and result values (results can
	 * be either [ OK ] if a shouldMatch word is satisfied by the pattern or a
	 * shouldNotMatch word is not satisfied by the pattern, [FAIL] if a
	 * shouldMatch pattern is not satisfied by the pattern or a shouldNotMatch
	 * word is satisfied by the pattern.
	 */
	void print(std::map<std::string, std::string> const& results);

	/**
	 * @brief Retrieves the level names in a string vector format.
	 * @return The string vector containing the level names (level file names).
	 */
	static std::vector<std::string> getLevelNames();

	/**
	 * @brief Retrieves the number of levels.
	 * @return The number of levels (number of level files).
	 */
	static int getLevelCount();

	/**
	 * @brief Creates a new level using a file name.
	 * @param fileName Name of the file containing the level.
	 * @return A new Level object filled with data from the file.
	 */
	static Level load(std::string const& fileName);

	/**
	 * @brief Getter for the shouldMatch field.
	 * @return shouldMatch field.
	 */
	const std::vector<std::string>& getShouldMatch() const;

	/**
	 * @brief Getter for the shouldNotMatch field.
	 * @return shouldNotMatch field.
	 */
	const std::vector<std::string>& getShouldNotMatch() const;
};

#endif // LEVEL_H
