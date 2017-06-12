# MemSteve

> Course Project for Infomation Theory. To commemorate the commencement which Steve Jobs delivered in 2005 Stanford University.

## Introduction

* **Compute the Frequency of each letter/punctuation/space**

* **Compute the Entropy of the passage**

* **Compression Methods Implementation**

	* Huffmen Coding
	* Shannon Coding
	* Shannon-Fano-Elias Coding

## Files

* **include** directory for header files

	* **Counter.h**: Compute the frequency of elementes and calculate entropy
	* **Encoding.h**: Algotithms, Encoder Class
	* **Common.h**: timer

* **src** directory for source files (implementation)

	* Counter.cpp
	* Encoding.cpp
	* Common.cpp

* **test**

	* **Steve.txt** origin txt
	* **xxxxxcode.csv** code word for each letter (The first line is a `\n` character)
	* **xxxx.dat** encoded txt
	* **xxxxdecode.txt** content by decoded the compressed string.

## Usage

You need to install CMake or use Makefile directly.


````
cd MemSteve
cmake .
make
./MemSteve
````

**ATTENTION**

if you run this source code, you need to specify the path of the whole project!!

Notice the warning in the `main.cpp`

````
#warning please change the path when you run in your own computer
std::string path = "/Users/vic/Dev/Alg/InfomationTheory/MemSteve/test/";
int m = wordCounter.readFile(path+"Steve.txt",s);
````

you need to change the `path`!

## Output

> output files are in the **test** directory

* encoded strings(dat file)
* code (csv file)
* decoded strings(txt file)

## Test

This Program has been tested on my MacBook(macOS Sierra 10.12.14)

````
cmake version: 3.8.0
Clang version:Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.5.0
Thread model: posix
````

## Licence

**This Project is under the MIT Licence**