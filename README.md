# CS106L Lecture Code

This repository contains code examples and lecture materials for Stanford CS106L, a course on Standard C++ programming. The code in this repository is meant to supplement the lectures and provide hands-on examples of the concepts discussed in class.

## Getting Started

### Prerequisites

Before getting started, make sure you have the following installed:

- **C++ Compiler**: You will need a C++ compiler like GCC or Clang. You can check if you have one installed by running `g++ --version` in your terminal.
- **CMake**: We will be using CMake to manage our build process. You can check if you have it installed by running `cmake --version`.
- **Git**: To download the lecture code, you'll need Git. You can check if you have it installed by running `git --version`.

### Cloning the Repository

To download the lecture code, open up a terminal and run the following command:

```sh
git clone https://github.com/cs106l/cs106l-lecture-code.git
```

This will download the code into a folder named `cs106l-lecture-code`.

### Opening the Code in VSCode

If you're using VSCode, navigate into the folder and open it with:

```sh
cd cs106l-lecture-code && code .
```

This will open the entire repository as a workspace in VSCode.

## Getting Started with CMake

We will be using CMake to build the lecture code examples. Here's how you can set it up and build the project.

### Step 1: Installing CMake

If you don't have CMake installed, you can follow the instructions [here](https://cmake.org/install/) to download and install it for your operating system.

### Step 2: Creating a Build Directory

It's a good practice to create a separate directory for your build files. This keeps the source code clean and separates it from the generated build files. Run the following commands:

```sh
mkdir build
cd build
```

### Step 3: Generating the Build Files

Once you're inside the `build` directory, use CMake to generate the necessary build files. Assuming your `CMakeLists.txt` file is in the root of the repository, run:

```sh
cmake ..
```

This command tells CMake to look in the parent directory (`..`) for the `CMakeLists.txt` file.

### Step 4: Building the Project

Once CMake has generated the build files, you can compile the project by running:

```sh
make
```

This will compile the project and produce the executable files for the code examples.

### Step 5: Running the Code

After building the project, you can run the compiled code. For example, if your executable is named `main`, you can run it with:

```sh
./main
```

### Updating the Project

As we update the lecture code, you can pull the latest changes by running:

```sh
git pull origin main
```

This will fetch the latest lecture code examples.

---

Feel free to reach out if you have any issues or questions about the setup!
