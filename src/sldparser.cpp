#include "sldparser.h"

namespace automap {

SLDParser::SLDParser(std::string fileName) :
    _fileName(fileName),
    _document(NULL),
    _loaded(false)
{
    // TODO: initializer of libxml and shutdown in static struct
    
    if (_openFile()) {
        _parseFile();
    } else {
        std::cerr << "Failed to read sld file: " << fileName << std::endl;
    }
}

SLDParser::~SLDParser()
{
    xmlFreeDoc(_document);
    xmlCleanupParser();
}

bool SLDParser::loaded()
{
    return _loaded;
}

bool SLDParser::_openFile()
{
    _document = xmlReadFile(_fileName.c_str(), NULL, 0);
    return _document != NULL;
}

bool SLDParser::_parseFile()
{
    _loaded = _parseNamedLayers();
    
    return _loaded;
}

bool SLDParser::_parseNamedLayers()
{
    XmlIterator iterator(_document);
    
    while (iterator.moveToNextNode()) {
        if (iterator.name() == "NamedLayer") {
            NamedLayer namedLayer(iterator);
            _namedLayers.push_back(namedLayer);
        }
    }
    
    return true;
}

std::vector<NamedLayer>& SLDParser::NamedLayers()
{
    return _namedLayers;
}

}