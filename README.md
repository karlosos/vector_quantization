
<h1 align="center">Quantization - team project</h1>

<div align="center">

[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/karlosos/vector_quantization/graphs/commit-activity)
[![GitHub contributors](https://img.shields.io/github/contributors/karlosos/vector_quantization.svg)](https://GitHub.com/karlosos/vector_quantization/graphs/contributors/)
[![Build status](https://ci.appveyor.com/api/projects/status/jtaxsu0cl80gu5a7?svg=true)](https://ci.appveyor.com/project/karlosos/vector-quantization)
[![Coverage Status](https://coveralls.io/repos/github/karlosos/vector_quantization/badge.svg?branch=main)](https://coveralls.io/github/karlosos/vector_quantization?branch=main)
[![Lines of Code](https://tokei.rs/b1/github/karlosos/vector_quantization)](https://github.com/Aaronepower/tokei)
</div>

## Structure
``` text
.
├── CMakeLists.txt
├── app
│   └── main.cpp
├── include
│   ├── example.h
│   └── exampleConfig.h.in
├── src
│   └── example.cpp
└── tests
    ├── dummy.cpp
    └── main.cpp
```

Sources go in [src/](src/), header files in [include/](include/), main programs in [app/](app), and
tests go in [tests/](tests/) (compiled to `unit_tests` by default). 

If you add a new executable, say `app/hello.cpp`, you only need to add the following two lines to [CMakeLists.txt](CMakeLists.txt): 

``` cmake
add_executable(main app/main.cpp)   # Name of exec. and location of file.
target_link_libraries(main PRIVATE ${LIBRARY_NAME})  # Link the executable to lib built from src/*.cpp (if it uses it).
```

You can find the example source code that builds the `main` executable in [app/main.cpp](app/main.cpp) under the `Build` section in [CMakeLists.txt](CMakeLists.txt). 
If the executable you made does not use the library in [src/](src), then only the first line is needed.


## Development

Clone this repo with:

```
> git clone --recurse-submodules https://github.com/karlosos/vector_quantization
```

or fetch submodules manually.

### Building on Linux

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```

### Building on Windows

#### WSL solution with VSCode

I suggest using WSL [https://docs.microsoft.com/en-us/windows/wsl/install-win10](https://docs.microsoft.com/en-us/windows/wsl/install-win10). 

1. Open project folder in `cmd.exe` or terminal of your choice.
2. Launch wsl with `bash`.
3. Update repositories `sudo apt-get update`.
3. Install CMake with `sudo apt-get install cmake`.
4. Install development tools with `sudo apt-get install build-essential`

Then within the same terminal (on wsl) build project:

``` bash
> mkdir build && cd build
> cmake ..
> make
> ./main
```

It's working. Great success! You can now work with code however you want. Below its described way of configuring VSCode.

Now open VSCode and install following extensions:

* [Remote Development](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)
* [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
* CMake Tools

Close VSCode and launch it from wsl terminal in root folder of our project

``` bash
cd .. # you should be in vector_quantization folder
code .
```

You will be asked by CMake Tools extension to configure project. Select compiler and you're good to go.

Debug application with `F5` or run without debugging with `CTRL+F5`.

If you have error *could not find a.out* then go to `Run->Open Configuration` and check executable path to `"program": "${workspaceFolder}/build/main"`.

#### Building on real Windows

Feel free to experiment and please share steps how to deal with it.

### Building on MacOS

1. Install CMake
2. Build project

```
> mkdir build && cd build
> cmake ..
> make
> ./main
```

3. Install C++ and CMake Tools extension in VSCode and close it.
4. Open VSCode from root folder `vector_quantization`. CMake Tools should ask you to chose compiler.
5. Debug application with `F5` or run with `CTRL+F5`.

## Naming and other style guidelines

Refer to [google cppguide](https://google.github.io/styleguide/cppguide.html#Naming).

## Pair programming

Install [Live Share extension for VSCode.](https://marketplace.visualstudio.com/items?itemName=MS-vsliveshare.vsliveshare).