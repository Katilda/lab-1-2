#include <cxxtest/TestSuite.h>
#include "maintest.h"

    class MyTest : public CxxTest::TestSuite
        {
        public:

    void testEasy(void)
    {
        listalke Listalke1,Listalke2,Listalke3,Listalke4,Listalke5,Listalke6; //создание объекта класса
TS_ASSERT_EQUALS(Listalke1.start(0,0,0),"0")
TS_ASSERT_EQUALS(Listalke2.start(1,1,1),"1")
TS_ASSERT_EQUALS(Listalke3.start(5,1,8),"0")
TS_ASSERT_EQUALS(Listalke4.start(8,1,5),"0")
TS_ASSERT_EQUALS(Listalke5.start(100,3,2),"0")
TS_ASSERT_EQUALS(Listalke6.start(1,1,100),"0")
    }

    void testMultiplication(void)
    {
        listalke Listalke1,Listalke2,Listalke3,Listalke4,Listalke5,Listalke6,Listalke7,Listalke8; //создание объекта класса
TS_ASSERT_EQUALS(Listalke1.start(3,100,8),"1 << 7 [8] 9 >> 100")
TS_ASSERT_EQUALS(Listalke2.start(1,12,10),"1 << [10] >> 12")
TS_ASSERT_EQUALS(Listalke3.start(4,5000000,1000000),"1 << 999999 [1000000] 1000001 1000002 >> 5000000")
TS_ASSERT_EQUALS(Listalke4.start(2,10,3),"1 << [3] 4 >> 10")  
TS_ASSERT_EQUALS(Listalke5.start(3,4,1),"[1] 2 3 >> 4")
TS_ASSERT_EQUALS(Listalke6.start(3,5,5),"1 << 3 4 [5]") 
TS_ASSERT_EQUALS(Listalke7.start(1,10,1),"[1] >> 10")
TS_ASSERT_EQUALS(Listalke8.start(5,10,2),"1 << [2] 3 4 5 6 >> 10") 
    }
};

