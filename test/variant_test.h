#ifndef VARIANT_TEST
#define VARIANT_TEST

#include <cppunit/extensions/HelperMacros.h>

#include "variant.h"

class VariantTest : public CPPUNIT_NS::TestCase {

    CPPUNIT_TEST_SUITE( VariantTest );
    CPPUNIT_TEST( checkAsString );
    CPPUNIT_TEST( checkAsUInt );
    CPPUNIT_TEST( checkIsDouble );
    CPPUNIT_TEST( checkCopy );
    CPPUNIT_TEST_SUITE_END();
    
public:

    VariantTest();
    ~VariantTest();
    
    void setUp();
    void tearDown();

    void checkAsString();
    void checkAsUInt();
    void checkIsDouble();
    
    void checkCopy();
    
private:
    Variant* _vs1, *_vs2, *_vs3;
    Variant* _vi1, *_vi2, *_vi3;
    Variant* _vd1, *_vd2, *_vd3;
    
};

CPPUNIT_TEST_SUITE_REGISTRATION( VariantTest );

#endif