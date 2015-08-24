#include <gtest/gtest.h>
#include "gps.h"



TEST(GPSClassTest, Constructor){
    string GGA = "$GPGGA,123519,4807.038000,N,01131.000000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    string RMC = "$GPRMC,123519,A,4807.038000,N,01131.000000,E,022.4,084.4,230394,003.1,W*6A";

    GPS myGps(GGA,RMC);

    EXPECT_EQ(myGps.UTC                 , 123519);
    EXPECT_FLOAT_EQ(myGps.latitude     , 48.1173);
    EXPECT_FLOAT_EQ(myGps.longitude    , 11.5166667);
    EXPECT_FLOAT_EQ(myGps.altitude     , 545.4);
    EXPECT_EQ(myGps.numberSatellites    , 8);

    EXPECT_EQ(myGps.UTC                 , 123519);
    EXPECT_DOUBLE_EQ(myGps.latitude     , 48.1173);
    EXPECT_NEAR(myGps.longitude, 11.516666,0.000001);
    EXPECT_NEAR(myGps.speed ,11.52,0.1);
    EXPECT_DOUBLE_EQ(myGps.heading    , 84.4);
    EXPECT_EQ(myGps.date    , 230394);


}


TEST(GPSClassTest, isGGAValid)
{
    GPS myGps;
    string GGA = "$GPGGA,123519,4807.038000,N,01131.000000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    EXPECT_TRUE(myGps.isValidGGA(GGA));

    GGA = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    EXPECT_FALSE(myGps.isValidGGA(GGA));

    GGA = "$GPGGA,,,,,,,,,,,,,,*46";
    EXPECT_FALSE(myGps.isValidGGA(GGA));

    GGA = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    EXPECT_FALSE(myGps.isValidGGA(GGA));
}


TEST(GPSClassTest, SetValuesGGA)
{
    GPS myGps;
    string GGA = "$GPGGA,123519,4807.038000,N,01131.000000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    myGps.setValuesGGA(GGA);

    EXPECT_EQ(myGps.UTC                 , 123519);
    EXPECT_FLOAT_EQ(myGps.latitude     , 48.1173);
    EXPECT_FLOAT_EQ(myGps.longitude    , 11.5166667);
    EXPECT_FLOAT_EQ(myGps.altitude     , 545.4);
    EXPECT_EQ(myGps.numberSatellites    , 8);

    GGA = "$GPGGA,,,,,,,,,,,,,,*46";
    myGps.setValuesGGA(GGA);

    EXPECT_EQ(myGps.UTC                 , 0);
    EXPECT_DOUBLE_EQ(myGps.latitude     , 0);
    EXPECT_DOUBLE_EQ(myGps.longitude    , 0);
    EXPECT_DOUBLE_EQ(myGps.altitude     , 0);
    EXPECT_EQ(myGps.numberSatellites    , 0);

    GGA = "$GPGGA,123519,4807.038000,S,01131.000000,W,1,08,0.9,545.4,M,46.9,M,,*47";
    myGps.setValuesGGA(GGA);

    EXPECT_EQ(myGps.UTC                 , 123519);
    EXPECT_FLOAT_EQ(myGps.latitude     , -48.1173);
    EXPECT_FLOAT_EQ(myGps.longitude    , -11.5166667);
    EXPECT_FLOAT_EQ(myGps.altitude     , 545.4);
    EXPECT_EQ(myGps.numberSatellites    , 8);

}

TEST(GPSClassTest, isRMCValid){
    GPS myGps;
    string RMC = "$GPRMC,175423,A,4026.500000,N,00340.200133,W,,070815,,,D*67";
    EXPECT_TRUE(myGps.isValidRMC(RMC));

    RMC = "$GPRMC,175423,V,4026.500000,N,00340.200133,W,,,070815,,,D*67";
    EXPECT_FALSE(myGps.isValidRMC(RMC));

    RMC = "$GPRMC,175423,,,,,,,,,,D*67";
    EXPECT_FALSE(myGps.isValidRMC(RMC));



}

TEST(GPSClassTest, setValuesRMC){
    GPS myGps;
    string RMC = "$GPRMC,123519,A,4807.038000,N,01131.000000,E,022.4,084.4,230394,003.1,W*6A";
    myGps.setValuesRMC(RMC);
    EXPECT_EQ(myGps.UTC                 , 123519);
    EXPECT_DOUBLE_EQ(myGps.latitude     , 48.1173);
    EXPECT_NEAR(myGps.longitude, 11.516666,0.000001);
    EXPECT_NEAR(myGps.speed ,11.52,0.1);
    EXPECT_DOUBLE_EQ(myGps.heading    , 84.4);
    EXPECT_EQ(myGps.date    , 230394);



}


TEST(GPSClassTest, StringToDouble)
{

    GPS myGps;
    double returnDouble1 = myGps.stringToDouble("03.00000000000000001");
    EXPECT_DOUBLE_EQ(3.00000000000000001, returnDouble1);

}

TEST(GPSClassTest, SplitStringByComma)
{
    GPS myGps;
    string testString = "1,2,3,4,5,";
    vector<string> returnVector = myGps.splitStringByComma(testString);

    EXPECT_EQ("1", returnVector[0]);
    EXPECT_EQ("5", returnVector.back());
    EXPECT_EQ(5,returnVector.size());

}

TEST(GPSClassTest, DegreesToDecimal)
{
    GPS myGps;
    int degrees1 = 40;
    double minutes1 = 30.00;

    double  return1 = degreesToDecimal(degrees1,minutes1);
    EXPECT_DOUBLE_EQ(return1, 40.50);

    int degrees2 = 40;
    double minutes2 = 30;
    int seconds2 = 30;

    double  return2 = degreesToDecimal(degrees2,minutes2,seconds2);
    EXPECT_FLOAT_EQ(return2, 40.50833);


}
