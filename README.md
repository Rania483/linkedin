# LinkedIn Connection Suggestion Program

This project simulates a LinkedIn-like connection suggestion system using C++. It reads user profiles, builds a connection graph, and provides suggestions for potential connections based on various criteria such as shared attributes and connection distances.

## Features

- Parse and configure user profiles with attributes like ID, name, year of birth, university, major, job place, and connections.
- Build and update a connection graph based on user connections.
- Use different criteria to suggest connections:
  - Shared major
  - Same job place
  - Same university
  - Matching birth year
  - Connection distance

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Rania483/linkedin-suggestion.git
    cd linkedin-suggestion
    ```

2. Ensure you have a C++ compiler installed (e.g., `g++`).

3. Compile the project:
    ```bash
    g++ -o linkdin linkdin.cpp person.cpp
    ```

## Usage

1. Prepare your input data in a file (e.g., `input.txt`) with user profiles in the following format:

    ```
    ID: 1
    Name: John Doe
    Year of Birth: 1985
    University: Example University
    Major: Computer Science
    Job Place: Tech Inc
    Connections: 2, 3, 4

    ID: 2
    Name: Jane Smith
    Year of Birth: 1990
    University: Example University
    Major: Computer Science
    Job Place: Tech Inc
    Connections: 1, 3

    ID: 3
    Name: Alice Johnson
    Year of Birth: 1988
    University: Another University
    Major: Computer Science
    Job Place: Tech Inc
    Connections: 1, 2
    ```

2. Run the compiled executable and provide the input file through standard input:
    ```bash
    ./linkdin < input.txt
    ```

3. Follow the output to see connection suggestions for each user based on the defined criteria.

## Example

Here’s an example of how to use the LinkedIn Connection Suggestion Program:

1. Prepare a file with user profiles as shown in the "Usage" section.
2. Run the program with the prepared file.
3. Review the output for suggestions and connection information.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request or open an issue for any suggestions or improvements.

## Author

[Rania](https://github.com/Rania483)

## Acknowledgments

- Thanks to the C++ community for resources and guidance.
