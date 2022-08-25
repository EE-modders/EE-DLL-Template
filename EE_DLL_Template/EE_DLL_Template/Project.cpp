#include "pch.h"
#include "Project.h"

/*
    #################################
    #        EE DLL Template        #
    #################################

    Note: General Reminder
      Always use x86
      Use Debug when dev don't share the dll in that form
      Use Release when creating a version that you will share publicly

*/

void Project::printCredit()
{
    Logger::showMessage("------------------------------------------------------");
#ifdef _DEBUG
    Logger::showMessage("  " + PROJECT_NAME_STR + " v" + PROJECT_VERSION_STR + " (DEBUG)");
#else
    Logger::showMessage("  " + PROJECT_NAME_STR + " v" + PROJECT_VERSION_STR);
#endif // _DEBUG
    Logger::showMessage("  By " + PROJECT_AUTHOR_STR);
    Logger::showMessage("------------------------------------------------------");
    Logger::showMessage("  Credits:");
    Logger::showMessage("    EnergyCube (EE DLL Template)"); // Don't remove me or I will find your house :>
    Logger::showMessage("------------------------------------------------------");
}

void Project::onStart()
{
    printCredit();

    Logger::showMessage("onStart :D");

    /*
    
    Exemple
    
    while (1)
    {
        Sleep(1000);
        Logger::showMessage("Cool message every second :>");
    }

    */
}

void Project::onStop()
{
    Logger::showMessage("onStop :D");
}