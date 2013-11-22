#include "sldparser_p.h"

#include "namedlayer_p.h"

namespace SldParser {

SLDParserPrivate::SLDParserPrivate(std::string fileName) :
    _fileName(fileName),
    _document(NULL),
    _loaded(false)
{
    // TODO: initializer of libxml and shutdown in static struct
    
    if (_openFile()) {
        _loaded = _parseFile();
    } else {
        _loaded = false;
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
    return _parseNamedLayers();
}

bool SLDParserPrivate::_parseNamedLayers()
{
    XmlIterator iterator(_document);
    
    while (iterator.moveToNextNode()) {
        if (iterator.name() == "NamedLayer") {
            NamedLayerPrivate namedLayer(iterator);
            NamedLayer pub(namedLayer);
            _namedLayers.push_back(pub);
        }
    }
    
    return _namedLayers.size() > 0;
}

std::vector<NamedLayer>& SLDParserPrivate::namedLayers()
{
    return _namedLayers;
}

}