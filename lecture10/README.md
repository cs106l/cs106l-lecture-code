# Lecture 10

Functions and Lambdas

> [!IMPORTANT]
> Compiling the project requires a compiler that can compile C++26. For example, GCC 14 and above should work. **To configure CMake, you must use the following command from a `build` directory:**
>
> ```
> cmake -DCMAKE_CXX_COMPILER=<YOUR COMPILER> ..
> ```
> replacing `<YOUR COMPILER>` with the full path to your compiler. For example,
> if using `g++-14` on MacOS, you can run `which g++-14` to get the full path.
> If you do not do this step when configuring `cmake`, you might end up using
> a compiler which does not support C++26.
