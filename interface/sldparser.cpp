#include "sldparser.h"
#include "sldparser_p.h"

namespace automap {

SLDParser::SLDParser(std::string fileName) :
    _impl(new SLDParserPrivate(fileName))
{

}

SLDParser::~SLDParser()
{
    if (_impl) {
        delete _impl;
    }
}

bool SLDParser::loaded()
{
    return _impl->loaded();
}

}