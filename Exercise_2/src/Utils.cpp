#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
bool Utils::readCSV(const string& filename, double& S, int& n, double*& w, double*& r) {
    // Open the CSV file
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    // Read data from the CSV file
    string line;
    getline(file,line);
    istringstream converter_S(line);
    char tmp;
    converter_S >> tmp >> tmp >> S;
    getline(file,line);
    istringstream converter_n(line);
    converter_n >> tmp>> tmp >> n;
    getline(file,line);
    w = new double[n];
    r = new double[n];
    unsigned int pos = 0;
    while (getline(file, line)) {
        istringstream ss(line);

        double w_value, r_value;
        char comma; // To read the comma separator
        // Read values from the two columns
        ss >> w_value >> comma >> r_value;
        w[pos] = w_value;
        r[pos] = r_value;
        pos++;
    }



    // Close the file
    file.close();

    // Extract S and n from the first row



    return true;
}

double Utils::calculateTotalReturn(double*& w, double*& r,int& n) {
    double total_return = 0.0;
    for (size_t i = 0; i < n; i++) {
        total_return += w[i] * r[i];
    }
    return total_return;
}

double Utils::calculatePortfolioValue(double S, double total_return) {
    return S * (1 + total_return);
}

bool Utils::printResults(const string& outputFilePath, double S, int n,double*& w,double*& r, double total_return, double V) {
    // Print and create file result.txt
    ofstream file;
    file.open(outputFilePath);
    if (file.fail()){
        cerr<< "file open failed"<< endl;
        return false;
    }
    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    file << "w = [ ";
    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << "w = [ ";
    for (size_t i = 0; i < n; i++) {
        cout << w[i] << " ";
        file << w[i] << " ";
    }
    cout << "]" << endl;
    cout << "r = [ ";
    file << "]" << endl;
    file << "r = [ ";
    for (size_t i = 0; i < n; i++) {
        cout << r[i] << " ";
        file << r[i] << " ";
    }
    cout << "]" << endl;
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << total_return << endl;
    cout << "V: " << fixed << setprecision(2) << V << endl;
    file << "]" << endl;
    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << total_return << endl;
    file << "V: " << fixed << setprecision(2) << V << endl;

}


