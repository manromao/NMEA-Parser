#include <QCoreApplication>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Running tests" << endl;
    ::testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();



    return a.exec();
}
