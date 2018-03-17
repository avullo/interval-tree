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

This will install the static library libitree.a in the autotools default location (/usr/local/lib). Support for building a shared library will be added soon.

See INSTALL for more detailed building and installation instructions.

## Usage

Proper documentation will be added soon. At the moment, look at the test suite under the _tests_ directory, the _interval_tree.c_ test suite in particular, for examples on how to use the library.

## Supported Compilers

The following compilers are known to work:

- GCC 4.8 - 7.2
- Clang 3.5 - 5.0

In particular, the following compilers are currently used in continuous integration at [Travis](https://travis-ci.org/avullo/interval-tree):

| Compiler        | Operating System             | Version String |
|-----------------|------------------------------|----------------|
| GCC 4.9.4       | Ubuntu 14.04.5 LTS           | gcc-4.9 (Ubuntu 4.9.4-2ubuntu1~14.04.1) 4.9.4 |
| GCC 5.4.1       | Ubuntu 14.04.5 LTS           | gcc-5 (Ubuntu 5.4.1-2ubuntu1~14.04) 5.4.1 |
| GCC 6.3.0       | Ubuntu 14.04.5 LTS           | gcc-6 (Ubuntu/Linaro 6.3.0-18ubuntu2~14.04) 6.3.0 |
| GCC 7.2.0       | Ubuntu 14.04.5 LTS           | gcc-7 (Ubuntu 7.2.0-1ubuntu1~14.04) 7.2.0 |
| Clang 3.5.0     | Ubuntu 14.04.5 LTS           | clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) |
| Clang 3.6.2     | Ubuntu 14.04.5 LTS           | clang version 3.6.2-svn240577-1~exp1 (branches/release_36) |
| Clang 3.7.1     | Ubuntu 14.04.5 LTS           | clang version 3.7.1-svn253571-1~exp1 (branches/release_37) |
| Clang 3.8.0     | Ubuntu 14.04.5 LTS           | clang version 3.8.0-2ubuntu3~trusty5 (tags/RELEASE_380/final) |
| Clang 3.9.1     | Ubuntu 14.04.5 LTS           | clang version 3.9.1-4ubuntu3~14.04.2 (tags/RELEASE_391/rc2) |
| Clang 4.0.1     | Ubuntu 14.04.5 LTS           | clang version 4.0.1-svn305264-1~exp1 (branches/release_40) |
| Clang 5.0.0     | Ubuntu 14.04.5 LTS           | clang version 5.0.0-svn310902-1~exp1 (branches/release_500_final) |



## License and Copyright

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The library is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2018 [Alessandro Vullo](https://avullo.github.io)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Acknowledgements

I am very grateful to Julienne Walker for generously providing the source code of his production quality C [AVL balanced tree library](http://www.eternallyconfuzzled.com/Libraries.aspx). Libitree has been designed as an expanded adaptation of this library. 

Thanks to [Niels Lohmann](http://nlohmann.me) from which I borrowed the skeleton of the travis configuration file from his JSON C++ library.

## Projects using libitree

[ensembl-xs](https://github.com/Ensembl/ensembl-xs)

