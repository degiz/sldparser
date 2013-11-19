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
    CPPUNIT_ASSERT( _p1->namedLayers().size() == 1 );
    
    std::vector<NamedLayer>& namedLayers = _p1->namedLayers();
    
    CPPUNIT_ASSERT(namedLayers[0].nodeName() == "NamedLayer");
    CPPUNIT_ASSERT(namedLayers[0].name() == "poptot");

}

void SLDParserTest::checkUserStyle()
{
    const std::vector<UserStyle>& userStyles = _p1->namedLayers()[0].userStyles();
    
    CPPUNIT_ASSERT( _p1->namedLayers()[0].userStyles().size() == 1 );
    
    CPPUNIT_ASSERT( userStyles[0].title() == "Population" );
    CPPUNIT_ASSERT( userStyles[0].abstract() == "A grayscale style showing the population numbers in a given geounit." );
}

void SLDParserTest::checkFeatureTypeStyle()
{
    const std::vector<FeatureStyleType>& featureTypeStyles= _p1->namedLayers()[0].userStyles()[0].featureStyleTypes();
    
    CPPUNIT_ASSERT( featureTypeStyles.size() == 1 );
    
}

void SLDParserTest::checkRule()
{
    const std::vector<Rule>& rules = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules();
    
    CPPUNIT_ASSERT(rules.size() == 9);
    CPPUNIT_ASSERT(rules[0].title() == ">= 345 AND < 880");
    CPPUNIT_ASSERT(rules[1].title() == "> 345 AND <= 880");
    CPPUNIT_ASSERT(rules[2].title() == "< 345 OR > 880");
    CPPUNIT_ASSERT(rules[3].title() == "= 345");
    CPPUNIT_ASSERT(rules[4].title() == "!= 345");
    CPPUNIT_ASSERT(rules[5].title() == "!= 345");
    CPPUNIT_ASSERT(rules[6].title() == "Complex");
    CPPUNIT_ASSERT(rules[7].title() == "Иначе");
    CPPUNIT_ASSERT(rules[8].title() == "Else");
    
}

/*
void SLDParserTest::checkFilter()
{
    std::vector<Rule>& rules = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules();
    
    FeatureProperty f1("number", Variant((unsigned int)880));
    FeatureProperty f2("number", Variant((unsigned int)345));
    FeatureProperty f3("number", Variant((unsigned int)879));
    FeatureProperty f4("number", Variant((unsigned int)346));
    FeatureProperty f5("number", Variant((unsigned int)344));
    FeatureProperty f6("number", Variant((unsigned int)881));
    FeatureProperty f7("number", Variant((unsigned int)401));
    FeatureProperty f8("number", Variant((unsigned int)599));
    FeatureProperty f9("number", Variant((unsigned int)500));
    FeatureProperty f10("number", Variant((unsigned int)550));
    FeatureProperty f11("number", Variant((unsigned int)501));
    
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
*/

void SLDParserTest::checkFilter()
{
    const std::vector<Rule>& rules = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules();
    
    FeatureTest f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
    
    f1.add("number", "880");
    f2.add("number", "345");
    f3.add("number", "879");
    f4.add("number", "346");
    f5.add("number", "344");
    f6.add("number", "881");
    f7.add("number", "401");
    f8.add("number", "599");
    f9.add("number", "500");
    f10.add("number", "550");
    f11.add("номер", "501");
    f12.add("number", "501");
    
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
    CPPUNIT_ASSERT(rules[6].check(f12) == true);
    
    CPPUNIT_ASSERT(rules[7].check(f11) == true);
    CPPUNIT_ASSERT(rules[7].check(f2) == false);
    
    CPPUNIT_ASSERT(rules[0].hasElseFilter() == false);
    CPPUNIT_ASSERT(rules[8].hasElseFilter() == true);

}

void SLDParserTest::checkSymbolizer()
{
    const std::vector<Symbolizer>& symbolizer0 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[0].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer0.size() == 1);
    CPPUNIT_ASSERT(symbolizer0[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer0[0].color() == "#636363");
    CPPUNIT_ASSERT(symbolizer0[0].opacity() == 0.2);

    const std::vector<Symbolizer>& symbolizer1 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[1].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer1.size() == 1);
    CPPUNIT_ASSERT(symbolizer1[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer1[0].color() == "#969696");
    CPPUNIT_ASSERT(symbolizer1[0].opacity() == 0.5);
    
    const std::vector<Symbolizer>& symbolizer2 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[2].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer2.size() == 1);
    CPPUNIT_ASSERT(symbolizer2[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer2[0].color() == "#CCCCCC");
    CPPUNIT_ASSERT(symbolizer2[0].opacity() == 0);
    
    const std::vector<Symbolizer>& symbolizer3 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[3].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer3.size() == 1);
    CPPUNIT_ASSERT(symbolizer3[0].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer3[0].color() == "#F7F7F7");
    CPPUNIT_ASSERT(symbolizer3[0].opacity() == 1);
    
    const std::vector<Symbolizer>& symbolizer4 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[4].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer4.size() == 1);
    CPPUNIT_ASSERT(symbolizer4[0].nodeName() == "LineSymbolizer");
    CPPUNIT_ASSERT(symbolizer4[0].color() == "#202020");
    CPPUNIT_ASSERT(symbolizer4[0].width() == 0.5);
    CPPUNIT_ASSERT(symbolizer4[0].linecap() == "round");
    CPPUNIT_ASSERT(symbolizer4[0].linejoin() == "miter");
    CPPUNIT_ASSERT(symbolizer4[0].dashoffset() == 1);
    CPPUNIT_ASSERT(symbolizer4[0].opacity() == 0.5);
    
    const std::vector<Symbolizer>& symbolizer5 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[5].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer5.size() == 1);
    CPPUNIT_ASSERT(symbolizer5[0].nodeName() == "PointSymbolizer");
    CPPUNIT_ASSERT(symbolizer5[0].color() == "#FF0000");
    CPPUNIT_ASSERT(symbolizer5[0].wellKnownName() == "circle");
    CPPUNIT_ASSERT(symbolizer5[0].size() == 6);
    CPPUNIT_ASSERT(symbolizer5[0].rotation() == 10);
    
    const std::vector<Symbolizer>& symbolizer6 = _p1->namedLayers()[0].userStyles()[0].featureStyleTypes()[0].rules()[6].symbolizers();
    
    CPPUNIT_ASSERT(symbolizer6.size() == 2);
    CPPUNIT_ASSERT(symbolizer6[0].nodeName() == "LineSymbolizer");
    CPPUNIT_ASSERT(symbolizer6[0].color() == "#202020");
    CPPUNIT_ASSERT(symbolizer6[0].width() == 0.5);
    CPPUNIT_ASSERT(symbolizer6[1].nodeName() == "PolygonSymbolizer");
    CPPUNIT_ASSERT(symbolizer6[1].color() == "#F7F7F7");
    CPPUNIT_ASSERT(symbolizer6[1].opacity() == 1);
    
}






