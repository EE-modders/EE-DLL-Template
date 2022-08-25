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
    showMessage("------------------------------------------------------");
    showMessage("  " + PROJECT_NAME_STR + " v" + PROJECT_VERSION_STR);
    showMessage("  By " + PROJECT_AUTHOR_STR);
    showMessage("------------------------------------------------------");
    showMessage("  Credits:");
    showMessage("    EnergyCube (EE DLL Template)"); // Don't remove me or I will find your house :>
    showMessage("------------------------------------------------------");
}

void Project::onStart()
{
    showMessage("onStart :D");
    printCredit();

    /*
    
    Exemple
    
    while (1)
    {
        Sleep(1000);
        showMessage("Cool message every second :>");
    }

    */
}

void Project::onStop()
{
    showMessage("onStop :D");
}