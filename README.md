# Sorting Algorithms Performance Comparison Tool

---

This C project is an interactive console application designed to help you compare the performance (execution time) of various sorting algorithms. It generates an array of random numbers of a size you define, then measures and displays how long the chosen sorting algorithm takes to sort this array. This tool offers a practical way to observe algorithm complexities and their behavior with different data sizes.

## Features

* **Dynamic Array Size:** Create arrays of random numbers with a user-defined input size.
* **Diverse Sorting Algorithms:** Test popular sorting algorithms including:
    * Insertion Sort
    * Selection Sort
    * Bubble Sort
    * Merge Sort
    * Quick Sort
    * Heap Sort
* **Performance Measurement:** Accurately reports the execution time for each algorithm in seconds.
* **Array Visualization:** Option to display either the initial random (unsorted) array or the sorted array.
* **User-Friendly Console Interface:** Simple and interactive command-based menu system.

## Setup and Running

Setting up and running the project on your local machine is straightforward.

### Prerequisites

* A C Compiler (e.g., **GCC**)

### Steps

1.  **Clone (or Download) the Repository:**
    ```bash
    git clone [https://github.com/ercumentbilgic/sorting-algorithms-tester.git](https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git)
    cd YOUR_REPO_NAME
    ```

2.  **Compile the Code:**
    Once inside the repository directory, compile the code using GCC:
    ```bash
    gcc main.c -o sorting_tool
    ```

3.  **Run the Program:**
    After successful compilation, you can start the program with the following command:
    * **Linux / macOS:**
        ```bash
        ./sorting_tool
        ```
    * **Windows:**
        ```bash
        sorting_tool.exe
        ```
        or simply
        ```bash
        sorting_tool
        ```

## Usage

When you start the program, you'll be prompted to enter an `input size`. Afterwards, you can use the following commands to interact with the program and run algorithms:

* `cmd`: Lists all available commands.
* `1`, `2`, `3`, `4`, `5`, `6`: Runs the corresponding sorting algorithm.
* `print`: Displays the randomly generated (unsorted) array.
* `input`: Resets the program to change the input size.
* `clear`: Clears the terminal screen.
* `<`: Exits the program.

---

## Contributing

Contributions are welcome! Feel free to submit pull requests for bug fixes, new features, or improvements.

1.  Fork the repository.
2.  Create your feature branch (`git checkout -b feature/AmazingFeature`).
3.  Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4.  Push to the branch (`git push origin feature/AmazingFeature`).
5.  Open a Pull Request.

---

## License

This project is distributed under the MIT License. See the `LICENSE` file for more information.

---