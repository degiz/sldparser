#include "sldparser.h"

#include "sldparser_p.h"

namespace SldParser {

SLDParser::SLDParser(std::string fileName) :
    _p(new SLDParserPrivate(fileName))
{
    
}

SLDParser::~SLDParser()
{

}

SLDParser::SLDParser(const SLDParser& other) :
    _p(new SLDParserPrivate(*other._p))
{

}

bool SLDParser::loaded()
{
    return _p->loaded();
}

std::vector<NamedLayer>& SLDParser::namedLayers()
{
    return _p->namedLayers();
}

}