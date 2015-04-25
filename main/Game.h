#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include <map>
#include "Level.h"

/**
 * @class Game
 * @file Game.h
 * @brief Class representing the game. Handles input from the user, evaluates it
 * against the current level, then calculates a score.
 */
class Game {

	/**
	 * @brief Pointer to the currently loaded level.
	 */
	std::shared_ptr<Level> currentLevel;

	/**
	 * @brief Contains each level's filename.
	 */
	std::vector<std::string> levelNames;

	/**
	 * @brief Maps the user's input pattern's result to each word in the current level.
	 */
	std::map<std::string, std::string> results;

	/**
	 * @brief Current score of the player.
	 */
	int score;

	/**
	 * @brief Holds the value if the user gave a valid regex pattern guess.
	 */
	bool validGuess;
public:

	/**
	 * @brief No-arg constructor.
	 */
	Game();

	/**
	 * @brief Destructor.
	 */
	~Game();

	/**
	 * @brief Prints the game's user interface including the level selection
	 * menu or the currently loaded level with the current score.
	 */
	void print();

	/**
	 * @brief Handles the input from the user, forwards it to the game. This
	 * function handles both the level selection and in-game input handling.
	 * @param input Input string given by user.
	 */
	void input(std::string const& input);

	/**
	 * @brief Determines whether a level is loaded by checking that currentlevel
	 * pointer is nullptr.
	 * @return True if level is loaded, else false.
	 */
	bool isLevelLoaded();

	/**
	 * @brief Evaluates a regex pattern against the current level's words and
	 * determines a score for the pattern: each character in the pattern awards
	 * -1 point per character, if a pattern matches a 'shouldMatch' word, it
	 * awards 10 points per word, if a pattern matches a 'shouldNotMatch' word
	 * it awards -10 point per word.
	 * @param guess The string containing the regex pattern.
	 * @return The score gained with the input pattern.
	 */
	int evaluateGuess(std::string const& guess);
};

#endif // GAME_H
