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

## 🤝 Contributing

This project is a demonstration of a Monty language interpreter, and is not open for contribution.

## 📜 License

This project is licensed under the MIT License.

## 🎉 Acknowledgments

- Holberton School for providing the project.
