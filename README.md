# Number Corridor


A console program for memory training written in `C++`. The goal of this project is to provide a free 
alternative to the well-known website. Currently, it only allows you to remember numbers.


## License


This program is distributed under the Apache 2.0 License, [see details](LICENSE.md).


## How to use it?

To play a game, simply launch it. Also, if you want to skip the menu, you can use command line arguments.


### Screen options

```
NumberCorridor <command>
```

* `help`, `-help`, `--help`
Displays the help screen.

* `version`, `-version`, `--version`
Displays version.

* `menu`, `-menu`, `--menu`
Displays the menu screen.

* `debug`, `-debug`, `--debug`
Displays the debug screen.

### Game options

```
NumberCorridor <command> <subcommand> [value] ...
```


`play`, `-play`, `-p` Runs the game.


### Subcommands

Subcommands are used to specify the `number of digits to remember`, the `max value` and the `group size`. If you don't 
define them, you will be asked about them automatically.

*  `max`, `-max`, `--max`, `-m`, `--m` `[value greater than 2]` specifies max value (The highest value to remember will
be **max - 1**).

    * `dex`, `-dec`, `--dec` sets max to **10**.
    * `bin`, `-bin`, `--bin` sets max to **2**.


*  `length`, `-length`, `--length`, `-l`, `--l` `[value greater than 0]` specifies the number of numbers to remember.


*  `size`, `-size`, `--size`, `-s`, `--s` `[value greater than 0]` specifies group size.
    * `single`, `-single`, `--single` sets group size to **1**.
    * `PA`, `-PA`, `--PA`, `pa`, `-pa`, `--pa` sets group size to **2**.
    * `PAO`, `-PAO`, `--PAO`, `pao`, `-pao`, `--pao` sets group size to **3**.


## Build


***Warning:***
For practical reasons, the executable file will be generated in the ***out*** directory.
To clone and build this program you will need `git` and `Cmake`.

First, open the terminal and clone this repository:


`git clone https://github.com/comradecobweb/NumberCorridor`


### Linux:


Make sure you have installed `gcc`, `g++`, `ld` and `make`.
Then run `build.sh` file:

```shell
cd ./NumberCorridor
chmod +x ./build.sh
./build.sh
```

Now, you can run the app using `./out/NumberCorridor`.


### Debian Package


To build the Debian package, make sure you meet the requirements of the step above. Then type in the terminal:

```sh
cd ./NumberCorridor
chmod +x ./build_deb.sh
./build_deb.sh
```

With this you have generated the `NumberCorridor.deb` file (in the ***out*** folder) for `amd64`. You can install it like
a regular `*.deb` file.


### Windows:


Make sure you have installed `Microsoft Visual Studio 2022`. Then run `build.bat` file:

```shell
cd .\NumberCorridor
build.bat
```

Now, you can run the app using `.\out\NumberCorridor.exe`.


### Other OS:


Systems other than those mentioned above are not supported.


## To do


- Add the ability to check random numbers instead of all numbers one by one.
- Add support for macOS.