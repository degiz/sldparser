#ifndef SLDPARSER_TEST
#define SLDPARSER_TEST

#include <cppunit/extensions/HelperMacros.h>

#include "sldparser.h"

using namespace automap;
using namespace std;

const std::string no_file = " ";
const std::string wrong_file = "test.sld";
const std::string testfile_1 = "../style_1.sld";

class SLDParserTest : public CPPUNIT_NS::TestCase {

    CPPUNIT_TEST_SUITE( SLDParserTest );
    CPPUNIT_TEST( checkNamedLayer );
    CPPUNIT_TEST( checkNoFile );
    CPPUNIT_TEST( checkUserStyle );
    CPPUNIT_TEST( checkFeatureTypeStyle );
    CPPUNIT_TEST( checkRule );
    CPPUNIT_TEST( checkFilter );
    CPPUNIT_TEST( checkSymbolizer );
    CPPUNIT_TEST_SUITE_END();

public:
    SLDParserTest();
    ~SLDParserTest();
    
    void setUp();
    void tearDown();
    
    void checkNoFile();
    void checkNamedLayer();
    void checkUserStyle();
    void checkFeatureTypeStyle();
    void checkRule();
    void checkFilter();
    void checkSymbolizer();

private:
    SLDParser* _p1, *_p2, *_p3;
};

CPPUNIT_TEST_SUITE_REGISTRATION( SLDParserTest );

#endif // SLDPARSER_TEST