#include <cctype>
#include "Util.h"

namespace Util {
bool isNumber(std::string const& str) {
	bool isNumber = true;
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (!isdigit(*it)) {
			isNumber = false;
		}
	}
	return isNumber;
}
}
