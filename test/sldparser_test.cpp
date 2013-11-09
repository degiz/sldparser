#include "sldparser_test.h"

SLDParserTest::SLDParserTest()
{

}

SLDParserTest::~SLDParserTest()
{

}

void SLDParserTest::setUp()
{
    _p1 = new SLDParser(testfile_1);
    _p2 = new SLDParser(no_file);
    _p3 = new SLDParser(wrong_file);
}

void SLDParserTest::tearDown()
{
    delete _p1, _p2, _p3;
}

void SLDParserTest::checkNoFile()
{
    CPPUNIT_ASSERT( _p2->loaded() == false);
    CPPUNIT_ASSERT( _p3->loaded() == false);
}

void SLDParserTest::checkNamedLayer()
{
    CPPUNIT_ASSERT( _p1->NamedLayers().size() == 1 );
    
    std::vector<NamedLayer>& namedLayers = _p1->NamedLayers();
    
    CPPUNIT_ASSERT(namedLayers[0].nodeName() == "NamedLayer");
    CPPUNIT_ASSERT(namedLayers[0].name() == "poptot");

}

void SLDParserTest::checkUserStyle()
{
    std::vector<UserStyle>& userStyles = _p1->NamedLayers()[0].UserStyles();
    
    CPPUNIT_ASSERT( _p1->NamedLayers()[0].UserStyles().size() == 1 );
    
    CPPUNIT_ASSERT( userStyles[0].title() == "Population" );
    CPPUNIT_ASSERT( userStyles[0].abstract() == "A grayscale style showing the population numbers in a given geounit." );
}

void SLDParserTest::checkFeatureTypeStyle()
{
    std::vector<FeatureStyleType>& featureTypeStyles= _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes();
    
    CPPUNIT_ASSERT( featureTypeStyles.size() == 1 );
    
}

void SLDParserTest::checkRule()
{
    std::vector<Rule>& rules = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules();
    
    CPPUNIT_ASSERT(rules.size() == 8);
    CPPUNIT_ASSERT(rules[0].title() == ">= 345 AND < 880");
    CPPUNIT_ASSERT(rules[1].title() == "> 345 AND <= 880");
    CPPUNIT_ASSERT(rules[2].title() == "< 345 OR > 880");
    CPPUNIT_ASSERT(rules[3].title() == "= 345");
    CPPUNIT_ASSERT(rules[4].title() == "!= 345");
    CPPUNIT_ASSERT(rules[5].title() == "!= 345");
    CPPUNIT_ASSERT(rules[6].title() == "Complex");
    CPPUNIT_ASSERT(rules[7].title() == "Else");
    
}

void SLDParserTest::checkFilter()
{
    std::vector<Rule>& rules = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules();
    
    Feature f1("number", Variant((unsigned int)880));
    Feature f2("number", Variant((unsigned int)345));
    Feature f3("number", Variant((unsigned int)879));
    Feature f4("number", Variant((unsigned int)346));
    Feature f5("number", Variant((unsigned int)344));
    Feature f6("number", Variant((unsigned int)881));
    Feature f7("number", Variant((unsigned int)401));
    Feature f8("number", Variant((unsigned int)599));
    Feature f9("number", Variant((unsigned int)500));
    Feature f10("number", Variant((unsigned int)550));
    Feature f11("number", Variant((unsigned int)501));
    
    CPPUNIT_ASSERT(rules[0].check(f1) == false);
    CPPUNIT_ASSERT(rules[0].check(f2) == true);
    CPPUNIT_ASSERT(rules[0].check(f3) == true);
    CPPUNIT_ASSERT(rules[0].check(f4) == true);
    CPPUNIT_ASSERT(rules[0].check(f5) == false);
    
    CPPUNIT_ASSERT(rules[1].check(f1) == true);
    CPPUNIT_ASSERT(rules[1].check(f2) == false);
    CPPUNIT_ASSERT(rules[1].check(f3) == true);
    CPPUNIT_ASSERT(rules[1].check(f4) == true);
    CPPUNIT_ASSERT(rules[1].check(f5) == false);
    
    CPPUNIT_ASSERT(rules[2].check(f1) == false);
    CPPUNIT_ASSERT(rules[2].check(f2) == false);
    CPPUNIT_ASSERT(rules[2].check(f3) == false);
    CPPUNIT_ASSERT(rules[2].check(f4) == false);
    CPPUNIT_ASSERT(rules[2].check(f5) == true);
    CPPUNIT_ASSERT(rules[2].check(f6) == true);
    
    CPPUNIT_ASSERT(rules[3].check(f1) == false);
    CPPUNIT_ASSERT(rules[3].check(f2) == true);
   
    CPPUNIT_ASSERT(rules[4].check(f1) == true);
    CPPUNIT_ASSERT(rules[4].check(f2) == false);
    
    CPPUNIT_ASSERT(rules[5].check(f1) == true);
    CPPUNIT_ASSERT(rules[5].check(f2) == false);
    
    CPPUNIT_ASSERT(rules[6].check(f1) == false);
    CPPUNIT_ASSERT(rules[6].check(f2) == false);
    CPPUNIT_ASSERT(rules[6].check(f3) == false);
    CPPUNIT_ASSERT(rules[6].check(f4) == false);
    CPPUNIT_ASSERT(rules[6].check(f7) == true);
    CPPUNIT_ASSERT(rules[6].check(f8) == true);
    CPPUNIT_ASSERT(rules[6].check(f9) == true);
    CPPUNIT_ASSERT(rules[6].check(f10) == false);
    CPPUNIT_ASSERT(rules[6].check(f11) == true);
    
    CPPUNIT_ASSERT(rules[0].hasElseFilter() == false);
    CPPUNIT_ASSERT(rules[7].hasElseFilter() == true);
    
}

void SLDParserTest::checkSymbolizer()
{
    std::vector<Symbolizer>& symbolizer0 = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules()[0].Symbolizers();
    
    CPPUNIT_ASSERT(symbolizer0.size() == 1);
    CPPUNIT_ASSERT(symbolizer0[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer0[0].color() == "#636363");

    std::vector<Symbolizer>& symbolizer1 = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules()[1].Symbolizers();
    
    CPPUNIT_ASSERT(symbolizer1.size() == 1);
    CPPUNIT_ASSERT(symbolizer1[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer1[0].color() == "#969696");
    
    std::vector<Symbolizer>& symbolizer2 = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules()[2].Symbolizers();
    
    CPPUNIT_ASSERT(symbolizer2.size() == 1);
    CPPUNIT_ASSERT(symbolizer2[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer2[0].color() == "#CCCCCC");
    
    std::vector<Symbolizer>& symbolizer3 = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules()[3].Symbolizers();
    
    CPPUNIT_ASSERT(symbolizer3.size() == 1);
    CPPUNIT_ASSERT(symbolizer3[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer3[0].color() == "#F7F7F7");
    
    std::vector<Symbolizer>& symbolizer4 = _p1->NamedLayers()[0].UserStyles()[0].FeatureStyleTypes()[0].Rules()[4].Symbolizers();
    
    CPPUNIT_ASSERT(symbolizer4.size() == 1);
    CPPUNIT_ASSERT(symbolizer4[0].nodeName() == "LineSymbolizer");
    CPPUNIT_ASSERT(symbolizer4[0].color() == "#202020");
    CPPUNIT_ASSERT(symbolizer4[0].width() == 0.5);
}






