# Video Store
:star: Star me on GitHub — it helps!

This project is a implementation of a video store in ANSI C with SQLite3
licensed under the permissive MIT license.

### Prerequisites

In order to be able to install customer you will need following software:
Make, Autoconf, Automake, GCC, and optionally Doxygen if you wish to
generate documentation. If you're using Windows system you may need to
install cygwin and use its package manager to install the aforementioned
tools.

### How to use this project

Clone the repository:
```
$ git clone ssh://git@github.com/javiermontenegro/C_VideoStore.SQLite3.git
```

Or else simply download zip file from [this link](https://codeload.github.com/javiermontenegro/C_VideoStore.SQLite3/zip/refs/heads/master).

### SQLite3 requirements
```
$ sudo apt-get update
$ sudo apt-get install sqlite3 libsqlite3-dev
```

### Installing

The installation process is fairly simple once the prerequisite tools have
been acquired. The first step is to generate a configure script and run it.
```
$ ./bootstrap.sh
$ ./configure
```

The next step is to build and install the software using make.
```
$ make
$ make install
```
## Running the program 
```
// username: admin 
// password: 12345 

$ ./video
```

## Built With

* [GNU Compiler Collection](https://gcc.gnu.org/) - ANSI C compiler.
* [GNU Make](https://www.gnu.org/software/make/) - a tool which controls the generation of executables and other non-source files of a program from the program's source files.
* [GNU Autoconf](https://www.gnu.org/software/autoconf/) - an extensible package of M4 macros that produce shell scripts to automatically configure software source code packages.
* [GNU Automake](https://www.gnu.org/software/automake/) - a tool for automatically generating Makefile.in files compliant with the GNU Coding Standards.
* [Doxygen](http://www.doxygen.nl/) - de facto standard tool for generating documentation from annotated C++ sources, but it also supports other popular programming languages such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and UNO/OpenOffice flavors), Fortran, VHDL, Tcl, and to some extent D.

## Author

* **Javier Montenegro** - [javiermontenegro](https://javiermontenegro.github.io/)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
