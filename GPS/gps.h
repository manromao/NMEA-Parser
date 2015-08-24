#ifndef GPS_H
#define GPS_H

#include <iostream>
#include <vector>
#include <string>

#define MINUTE_LENGTH 9 // Length of minutes data in NMEA
#define KNOTS_TO_MPS 0.514444444

#define private public

using namespace std;

class GPS
{
public:
    GPS();
    GPS(const string GGASentence,const string RMCSentence);
    int     UTC;
    double  latitude;
    double  longitude;
    double  altitude;
    double  speed;
    double  heading;
    int     numberSatellites;
    int     date;

private:
    // Set values of each sentence type

    // GGA sentences
    bool isValidGGA(const string GGASentence);
    void setValuesGGA(const string GGASentence);

    // RMC sentence
    bool isValidRMC(const string RMCSentence);
    void setValuesRMC(const string RMCSentence);


    // Auxualiary functions
    vector<string> splitStringByComma(const string);
    double stringToDouble(const string);
    double getCoordinates(string);
};

double degreesToDecimal(const int Degrees,const double Minutes,const int seconds = 0);

#endif // GPS_H
