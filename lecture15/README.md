# Lecture 13

Move Semantics

This project showcases the difference in performance between code that uses move semantics and code which does not. By default, move semantics operations for the `Photo` class are disabled. To enable them and see the difference in performance, run `cmake` like so:

```sh
cmake .. -DENABLE_MOVE_SEMANTICS=1
```



