#include <iostream>
#include <ctime>  // For clock() and clock_t

// Example function to measure
void exampleFunction() {
    for (double i = 0; i < 100000000; ++i);  // Simulate work
}

int maisn() {
    // Get the start time
    clock_t start = clock();

    // Call the function you want to measure
    exampleFunction();

    // Get the end time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    // Output the time taken
    std::cout << "Time taken: " << elapsed << " seconds" << std::endl;

    return 0;
}
