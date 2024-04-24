#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

class Utils {
public:
    static bool readCSV(const std::string& filename, double& S, int& n, double*& w, double*& r);
    static double calculateTotalReturn(double*& w, double*& r, int& n);
    static double calculatePortfolioValue(double S, double total_return);
    static bool printResults(const std::string& outputFilePath ,double S, int n, double*& w, double*& r, double total_return, double V);
};

#endif // UTILS_HPP
