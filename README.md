<h1 align="center">🚀 Monty Language Interpreter 🚀</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-C-1f425f.svg">
  <img src="https://img.shields.io/badge/license-MIT-blue.svg">
</p>

This project is a simple interpreter for Monty ByteCodes files. Monty is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## 🎯 Features

- The interpreter can handle a variety of commands, including:
  - `push`: pushes an element to the stack.
  - `pall`: prints all the values on the stack, starting from the top.
  - `pint`: prints the value at the top of the stack.
  - `pop`: removes the top element of the stack.
  - `swap`: swaps the top two elements of the stack.
  - `add`: adds the top two elements of the stack.
  - `nop`: does nothing.
  - `sub`: subtracts the top element of the stack from the second top element.
  - `div`: divides the second top element of the stack by the top element.
  - `mul`: multiplies the top two elements of the stack.
  - `mod`: computes the rest of the division of the second top element by the top element.
  - `pchar`: prints the char at the top of the stack.
  - `pstr`: prints the string starting at the top of the stack.
  - `rotl`: rotates the stack to the top.
  - `rotr`: rotates the stack to the bottom.
  - `stack`: sets the format of the data to a stack (LIFO).
  - `queue`: sets the format of the data to a queue (FIFO).

## 🚀 Usage

To use the Monty language interpreter, you need to:
1. Clone this repository.
2. Compile the source code: `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
3. Run the interpreter on a Monty byte code file: `./monty file.m`

## ⚠️ Error Handling

The interpreter is capable of handling errors. It prints error messages to `stderr` and exits with a status of `EXIT_FAILURE` in the following situations:
- If the user does not give any file or more than one argument to the program.
- If the file provided cannot be opened or read.
- If the program cannot malloc more memory.
- If the command does not exist or is not implemented.
- If the command `push` is not followed by an integer.
- If the command `pint` or `pop` is called when the stack is empty.


## 🧪 Tests

This project includes a set of test files located in the `bytecodes` directory. To run these tests, follow these steps:

1. Navigate to the project directory: `cd path-to-your-project`
2. Run the interpreter on a test file: `./monty bytecodes/name-of-test-file.m`

Replace `name-of-test-file.m` with the name of the test file you want to run. For example, to run the `00.m` test, you would use the command `./monty bytecodes/00.m`.


## 🤝 Contributing

This project is a demonstration of a Monty language interpreter, and is not open for contribution.

## 📜 License

This project is licensed under the MIT License.

## 🎉 Acknowledgments

- Thanks ALX - Holberton School for providing the project.
