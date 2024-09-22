# Number Corridor


A console program for memory training written in `C`/`C++`. The goal of this project is to provide a free 
alternative to the well-known website. Currently, it only allows you to remember numbers.


## License


This program is distributed under the Apache 2.0 License, [see details](LICENSE.md).


## Build


***Warning:***
For practical reasons, the executable file will be generated in the source code directory.
To build this program you will need `git` and `cmake`.

First, open the terminal and clone this repository:


`git clone https://github.com/comradecobweb/NumberCorridor`


### Linux:


Make sure you have installed `cmake`, `gcc`, `g++`, `ld` and `make`.
Then run `build.sh` file:

```shell
cd ./NumberCorridor
chmod +x ./build.sh
./build.sh
```

Now, you can run the app using `./NumberCorridor`.


### Windows:


Make sure you have installed `Microsoft Visual Studio 2022`. Then run `build.bat` file:

```shell
cd .\NumberCorridor
build.bat
```

Now, you can run the app using `NumberCorridor.exe`.


### Other OS:


Systems other than those mentioned above are not supported. You can try compiling on your own.


## To do


- Add the ability to check random numbers instead of all numbers one by one.
- Add support for macOS.
- Add support for program arguments, which would enable, among others, bypassing the menu.