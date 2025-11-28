# Unit Testing using Google Test

Google Test Documentation: https://google.github.io/googletest/

This project consists of 3 files:
1. `bank_account.hpp`: Header file for BankAccount class.
2. `bank_account.cpp`: Implementation of BankAccount class.
3. `main.cpp`: Example test suite for the BankAccount class.

Because we are using the Google Test library, we have to make sure to include it properly in our build. The `CMakeLists.txt` file does this for you already.

To build and run the project, do the following (make sure you are inside the `unit_testing` directory):

```sh
mkdir build
```

```sh
cd build
```

Just to be transparent, running the following command will download a version of the Google Test project into the `build` directory. If you do not want this to be automatically done or want a newer version of the Google Test project, remove the `FetchContent` from the `CMakeLists.txt` file, download the project manually, and reconfigure the `CMakeLists.txt` to work with the manually downloaded project.
```sh
cmake ..
```

```sh
make
```

```sh
./main
```

Upon building and running, you should see something similar in your terminal:
```sh
[==========] Running 5 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from AccountTest
[ RUN      ] AccountTest.BankAccountStartsEmpty
[       OK ] AccountTest.BankAccountStartsEmpty (0 ms)
[----------] 1 test from AccountTest (0 ms total)

[----------] 2 tests from BankAccountTest
[ RUN      ] BankAccountTest.BankAccountStartsEmpty
[       OK ] BankAccountTest.BankAccountStartsEmpty (0 ms)
[ RUN      ] BankAccountTest.CanDepositMoney
[       OK ] BankAccountTest.CanDepositMoney (0 ms)
[----------] 2 tests from BankAccountTest (0 ms total)

[----------] 2 tests from DEFAULT/WithdrawAccountTest
[ RUN      ] DEFAULT/WithdrawAccountTest.FinalBalance/0
[       OK ] DEFAULT/WithdrawAccountTest.FinalBalance/0 (0 ms)
[ RUN      ] DEFAULT/WithdrawAccountTest.FinalBalance/1
[       OK ] DEFAULT/WithdrawAccountTest.FinalBalance/1 (0 ms)
[----------] 2 tests from DEFAULT/WithdrawAccountTest (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 3 test suites ran. (0 ms total)
[  PASSED  ] 5 tests.
```

See if you can make your own tests/test fixtures that reveal bugs in the BankAccount class! A few examples are overflows, underflows, and negative deposits.
