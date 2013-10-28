#include "sldparser_p.h"

namespace automap {

SLDParserPrivate::SLDParserPrivate(std::string fileName) :
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

SLDParserPrivate::~SLDParserPrivate()
{
    xmlFreeDoc(_document);
    xmlCleanupParser();
}

bool SLDParserPrivate::loaded()
{
    return _loaded;
}

bool SLDParserPrivate::_openFile()
{
    _document = xmlReadFile(_fileName.c_str(), NULL, 0);
    return _document != NULL;
}

bool SLDParserPrivate::_parseFile()
{
    _loaded = _parseNamedLayers();
    
    return _loaded;
}

bool SLDParserPrivate::_parseNamedLayers()
{
    XmlIterator iterator(_document);
    
    while (iterator.moveToNextNode()) {
        if (iterator.name() == "NamedLayer") {
            NamedLayerPrivate namedLayer(iterator);
            _namedLayers.push_back(namedLayer);
        }
    }
    
    return true;
}

std::vector<NamedLayerPrivate>& SLDParserPrivate::NamedLayers()
{
    return _namedLayers;
}

}