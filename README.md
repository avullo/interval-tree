# libitree

[![Build Status](https://travis-ci.org/avullo/interval-tree.svg?branch=master)](https://travis-ci.org/avullo/interval-tree)

- [About libitree](#about-libitree)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Compilers](#supported-compilers)
- [License and Copyright](#license-and-copyright)
- [Acknowledgements](#acknowledgements)
- [Projects using libitree](#projects-using-libitree)

## About libitree

Libitree is a simple C library for handling [interval trees](https://en.wikipedia.org/wiki/Interval_tree).

## Installation

```sh
$ ./configure
$ make
$ make check
$ sudo make install
```

See INSTALL for more detailed building and installation instructions.

## Usage

Proper documentation will be added soon. At the moment, look at the test suite under the _tests_ directory, the _interval_tree.c_ test suite in particular, for examples on how to use the library.

## Supported Compilers

The following compilers are known to work:

- GCC 4.8.4, 5.4.0

The following compilers are currently used in continuous integration at [Travis](https://travis-ci.org/avullo/interval-tree):

| Compiler        | Operating System             | Version String |
|-----------------|------------------------------|----------------|
| GCC 4.8.4       | Ubuntu 14.04.3 LTS           | g++-4.9 (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4 |


## License and Copyright

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The library is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2018 [Alessandro Vullo](https://avullo.github.io)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Acknowledgements

I am very grateful to Julienne Walker for generously providing the source code of his production quality C library for handling AVL balanced trees.
Libitree has been designed as an expanded adaptation of this library.

Julienne's library can be found at:

http://www.eternallyconfuzzled.com/Libraries.aspx

## Projects using libitree

