# Lecture 10: Functions and Lambdas

> [!IMPORTANT]
> Compiling the project requires a compiler that can compile C++26. For reference, GCC 14 and above should work.

To compile this code, run:

```sh
g++ -std=c++26 main.cpp soundex-ranges.cpp soundex.cpp -o main
```

Pass the `-O3` flag to compile the code with all optimizations enabled (it will run much faster if you do this).

To run the code, use:

```sh
./main [soundex] [soundexRanges]
```

Where `soundex` will run the standard STL algorithm and `soundexRanges` will run the STL ranges/views algorithm. You can specify both to run them side by side!