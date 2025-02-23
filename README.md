# GitHub Actions to Compile C Programs

This repository demonstrates how to use GitHub Actions to automatically compile and test a simple C program every time you push or create a pull request to the `main` branch. The action installs GCC, compiles the C program, and runs it, ensuring that the program is functional.

## Usage

### 1. Clone the Repository

To get started, clone this repository to your local machine:

```bash
git clone https://github.com/BaseMax/github-actions-compile-c.git
```

### 2. GitHub Action Setup

The GitHub Action is configured to automatically compile the C program every time a change is pushed to the main branch or a pull request is created.

Create a new file in the `.github/workflows` directory:

- File name: `c-compile.yml`
- Action Setup: The action is defined in the `c-compile.yml` file, which runs the following steps:
  - Checkout code using the actions/checkout@v3 action.
  - Install GCC using the apt-get package manager on Ubuntu.
  - Compile the C program using gcc -o my_program main.c.
  - Run the compiled program and ensure that it works.

### 3. Example C Program

The program compiled in this repository is a simple C program that calculates the factorial of a number.

**Example C Program (main.c):**

```c
#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    printf("Hello, GitHub Actions!\n");

    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));

    return 0;
}
```

### 4. Running the GitHub Action

Whenever you push to the main branch or create a pull request, the GitHub Action will automatically:

- Check out the code.
- Set up the GCC compiler.
- Compile the program.
- Run the program to verify that the compilation was successful.
- You can view the results of the action under the Actions tab of the GitHub repository.

### GitHub Action Workflow

The workflow for compiling the C program is defined in the .github/workflows/c-compile.yml file.

```yaml
name: Compile and Test C Program

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout code
        uses: actions/checkout@v3

      - name: Set up GCC
        run: sudo apt-get install -y gcc

      - name: Compile C program
        run: gcc -o my_program main.c

      - name: Run tests
        run: |
          if ./my_program; then
            echo "Test Passed"
          else
            echo "Test Failed"
            exit 1
          fi
```

### Workflow Explanation:

- **Checkout code:** The actions/checkout action checks out the code from the repository.
- **Set up GCC:** Installs GCC (GNU Compiler Collection) to compile the C program.
- **Compile C program:** The gcc command compiles the main.c file into an executable named my_program.
- **Run tests:** The program is run, and if the execution is successful, it outputs "Test Passed"; otherwise, it outputs "Test Failed" and exits with a failure code.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository, create a pull request with your changes, and submit it for review.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Max Base, 2025
