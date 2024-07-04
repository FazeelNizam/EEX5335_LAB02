# EEX5335_LAB02 - MultiThreaded Matrix Multiplication Using Pthreds and Java Threads

This project contains a C program and a Java Program that calculates the multiplication of two matrices using pthreads in a Linux environment and Java Threads in Java environment.

## Prerequisites

- GCC (GNU Compiler Collection)
- Linux or Windows with WSL (Windows Subsystem for Linux)
  > I used WSL - `Ubuntu 18.04.6 LTS` to do this Lab exercise so in this procedure I explained how to use this code in the WSL environment.
- Basic understanding of command-line operations
- Java 8.0 or Higher JVM

## Getting Started

### Cloning the Repository

- Clone the repository to your local machine using Git:

```sh
git clone https://github.com/FazeelNizam/EEX5355_LAB02.git
```

##Pthreads

### Compiling the Code

- Open the Ubuntu terminal (on Windows with WSL) `Ubuntu 18.04 LTS` and open the home folder:

```sh
explorer.exe .
```

- Move the `MetrixMultiplication.c` file into your Linux directory or Navigate to the directory where you cloned the repository.

- Compile the program using GCC:

```sh
gcc -pthread MetrixMultiplication.c
```

### Running the Program

- After compilation, you can run the program using beloved command:

```sh
./a.out
```

### Troubleshooting

- If the `gcc` compiler is not installed, you can install it using:

  ```sh
  sudo apt update
  sudo apt install gcc
  ```

##Java Threads

### Compiling the Code

- Open the terminal and open the navigate to the cloned folder:

- Compile the program using java c:

```sh
javac MatrixMultiplication.java
```

### Running the Program

- After compilation, you can run the program by using the command
```sh
java MatrixMultiplication
```

### Troubleshooting

- Find the Java path; it looks like this: `C:\Program Files\Java\jdkxxxx\bin\`
- Start-menu search for "environment variable" to open the options dialog.
- Examine `PATH`. Remove old Java paths.
- Add the new Java path to `PATH`.
- Close and re-open console/IDE.

### Contributing

Feel free to open issues or submit pull requests if you have any suggestions or improvements.

### Acknowledgments

- Based on examples from:
  > "Operating System Concepts" by Abraham Silberschatz, Peter B. Galvin, and Greg Gagne.
- JavaPoint and GeeksforGeeks
