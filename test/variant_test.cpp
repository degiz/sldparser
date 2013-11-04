#include "variant_test.h"


VariantTest::VariantTest()
{
    
}

VariantTest::~VariantTest()
{
    delete _vs1, delete _vs2, delete _vs3;
    delete _vi1, delete _vi2;
    delete _vd1;
}

void VariantTest::setUp()
{
    _vs1 = new Variant("");
    _vs2 = new Variant("1984");
    _vs3 = new Variant("36.6");
    
    _vi1 = new Variant((unsigned int) 0);
    _vi2 = new Variant((unsigned int) 1984);
    
    _vd1 = new Variant((double) 36.6);
    
}

void VariantTest::tearDown()
{
    
}

void VariantTest::checkAsString()
{
    CPPUNIT_ASSERT( _vs1->asString() == "" );
    CPPUNIT_ASSERT( _vs1->asString() != " " );
    CPPUNIT_ASSERT( _vi1->asString() == "0" );
    CPPUNIT_ASSERT( _vi2->asString() == "1984" );
    CPPUNIT_ASSERT( _vd1->asString() == "36.6" );
}

void VariantTest::checkAsUInt()
{
    CPPUNIT_ASSERT( _vs2->asUInt() == 1984);
    CPPUNIT_ASSERT( _vs3->asUInt() == 36);
    
    CPPUNIT_ASSERT( _vi1->asUInt() == 0);
    CPPUNIT_ASSERT( _vi2->asUInt() == 1984);
    CPPUNIT_ASSERT( _vd1->asUInt() == 36);
}

void VariantTest::checkIsDouble()
{
    CPPUNIT_ASSERT( _vi1->asDouble() == 0);
    CPPUNIT_ASSERT( _vi2->asDouble() == 1984);
    CPPUNIT_ASSERT( _vd1->asDouble() == 36.6);
}

void VariantTest::checkCopy()
{
    Variant temp_v1(""), temp_v2((unsigned int) 1984);
    Variant temp_v3(temp_v1), temp_v4(temp_v2);
    
    CPPUNIT_ASSERT(temp_v3.asString() == "");
    CPPUNIT_ASSERT(temp_v4.asUInt() == 1984);
}

