## File descriptions

- `p4ltllexer.ll` `p4ltlScanner.hpp` are for Scanner.

- `p4ltlparser.ypp` is for Parser.

- `p4ltlast.hpp` contains the ast for P4LTL, and the `.cpp` version is the implementation.

- `exampleMain.cpp` shows an example to parse P4LTL strings and extract allof the atom in them.

- `Makefile` contains shows the way to build the example.

## Enviroment

Ubuntu 18.04, and currently the version of bison and flex used are `flex 2.6.4` and `bison 3.5.1`.

## How to build/use the parser

Run the following command

```
    $ make
    $ make run
```
then can the example be run.