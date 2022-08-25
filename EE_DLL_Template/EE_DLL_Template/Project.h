#pragma once

#include "Utils.h"
#include "Logger.h"

#include <string>

// Project INFO
static const std::string PROJECT_NAME_STR = "Project";			// Also used as log file name!
static const std::string PROJECT_AUTHOR_STR = "YourPseudo";
static const std::string PROJECT_VERSION_STR = "1.0.0";
static const unsigned int PROJECT_VERSION_MAJOR = 1;
static const unsigned int PROJECT_VERSION_MINOR = 0;
static const unsigned int PROJECT_VERSION_PATCH = 0;
// END Project INFO

// Hard Coded Project Settings
static bool KEEP_ALIVE = true;		// Use => true:		the DLL will wait until game stop to call onStop()
									//     => false:	the DLL will call onStop() (Detach) if onStart() ended and didn't
									//					created any additional thread (so, if the DLL is fully inative)

class Project
{
public:
	void printCredit();

	void onStart();
	void onStop();

};

