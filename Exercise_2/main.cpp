#include <iostream>
#include <vector>
#include "Utils.hpp"

using namespace std;

int main() {
    // Variables to store data
    double S;
    int n;
    double* w = nullptr;
    double* r = nullptr;


    // Read data from the CSV file
    if (!Utils::readCSV("data.csv", S, n, w, r)) {
        cout << "Error reading CSV file." << endl;
        return 1;
    }

    // Calculate the rate of return and the final value of the portfolio
    double total_return = Utils::calculateTotalReturn(w, r, n);
    double V = Utils::calculatePortfolioValue(S, total_return);

    // Print results to the screen and create file output
    Utils::printResults("result.txt",S, n, w, r, total_return, V);


    return 0;
}
