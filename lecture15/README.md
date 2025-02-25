# Lecture 15: RAII & Building Projects

You can take a look at the driver code in `main.cpp`. 

To compile this you can use the following command:

```sh
g++ -std=c++20 main.cpp StudentID.cpp IntVector.cpp -o main
```

Notice that you're using multiple source files to compile the target `main`.

You can instead do the following:

```sh
mkdir build
```

```sh
cd build
```


```sh
cmake ..
```

```sh
make
```

```sh
./main
```

This might seem a bit over-cooked for a project as simple as this (and you're probably right), but this is good measure for 
situations where you may have hundreds our thousands of C++ source files. The principles remain the same.