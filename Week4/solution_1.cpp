#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

#define CSV_SEPARATOR ','

class Record {
private:
    int year;
    double min;
    double max;
    vector<double> measurements;
public:
    Record(int year): year(year), min(INT_MAX), max(INT_MIN){}

    int getYear() const {
        return year;
    }
    
    double getMin() const {
        return min;
    }
    
    double getMax() const {
        return max;
    }

    void addMeasurement(double temperature) {
        measurements.push_back(temperature);
        min = min < temperature ? min : temperature;
        max = max > temperature ? max : temperature;
    }
    
    int getNumberOfMeasurements() const {
        return measurements.size();
    }
    
    double getAverage() const {
        double result = 0.0;
        
        for(int idx = 0; idx < measurements.size(); ++idx) {
            result = result + measurements[idx];
        }
        
        return measurements.size() == 0 ? 0.0 : result / measurements.size();
    }
};

vector<Record> readRecords(const char *file) {
    ifstream input(file);
    if(!input.is_open()){
        throw runtime_error("failed to open file for reading");
    }

    char buffer[17];
    vector<Record> records;

    do {
        input.getline(buffer, 16); // A line looks like so: dd/mm/yyyy,dd.d

        buffer[2] = buffer[5] = buffer[10] = '\0'; // Turn the separators into \0

        int year = atoi(buffer + 6); // Parse the year
        double temperature = atof(buffer + 11); // Parse the temperature
        
        if(records.size() == 0 || records.back().getYear() != year) {
            records.push_back(Record(year));
        }
        
        records.back().addMeasurement(temperature);
    } while(input.gcount() > 0); // Only stop when we have read 0 symbols from the file

    return records;
}

void writeRecords(const vector<Record>& records, const char* file) {
    ofstream output(file);
    if(!output.is_open()){
        throw runtime_error("failed to open file for writing");
    }
    
    for(int idx = 0; idx < records.size(); ++idx) {
        output << setw(4) << setfill('0') << records[idx].getYear() << CSV_SEPARATOR; // The year
        output << setw(3) << setfill('0') << setprecision(3) << records[idx].getMin() << CSV_SEPARATOR; // The min temperature
        output << setw(3) << setfill('0') << setprecision(3) << records[idx].getMax() << CSV_SEPARATOR; // The max temperature
        output << setw(3) << setfill('0') << setprecision(3) << records[idx].getAverage() << CSV_SEPARATOR; // The average temperature
        output << setw(3) << setfill('0') << records[idx].getNumberOfMeasurements() << endl; // The number of days for which we have data
    }
}

int main()
{
    writeRecords(readRecords("temperature.csv"), "result.csv");

    return 0;
}
