![Visitor count](https://shields-io-visitor-counter.herokuapp.com/badge?page=EE-modders.EE-DLL-Template)
[![Stars](https://img.shields.io/github/stars/EE-modders/EE-DLL-Template)](https://github.com/EE-modders/EE-DLL-Template/stargazers)
[![Forks](https://img.shields.io/github/forks/EE-modders/EE-DLL-Template)](https://github.com/EE-modders/EE-DLL-Template/network)
[![Version](https://img.shields.io/badge/Empire%20Earth%20DLL%20Template%20Version-v1.0.0-blue)](https://github.com/EE-modders/EE-DLL-Template)
[![License](https://img.shields.io/github/license/EE-modders/Empire-Earth-Stats?color=brightgreen)](https://github.com/EE-modders/Empire-Earth-Stats/blob/master/LICENSE)
# 🔨 Empire Earth DLL Template
Empire Earth modding DLL, but without the init hell :> \
By [EnergyCube](https://github.com/EnergyCube) for the Empire Earth Community.

## 🧾 Where do I start ?
The files of the project should not be modified except Project.h/Project.cpp, except that feel free to create as much things as you want ! \
Now, that said, simply go in Project.cpp and start the fun !
 
```cpp
void Project::onStart()
{
    showMessage("onStart :D");
    printCredit();
}

void Project::onStop()
{
    showMessage("onStop :D");
}
```

## ⚠️ Known Limitation
If another DLL is writting log it will also be redirected in your debug console, same for log file.

## 📖 License
[GNU General Public License v3.0](https://github.com/EE-modders/Empire-Earth-Stats/blob/master/LICENSE)
