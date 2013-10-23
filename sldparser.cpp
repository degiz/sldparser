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

bool SLDParser::_openFile()
{
    _document = xmlReadFile(_fileName.c_str(), NULL, 0);
    return _document != NULL;
}

bool SLDParser::_parseFile()
{
    xmlNode* currentNode = NULL;
    
    _rootElement = xmlDocGetRootElement(_document);
    
    _parseNamedLayers();
}

void SLDParser::_parseNamedLayers()
{
    xmlNode* currentElement = _rootElement->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"NamedLayer"))) {
            NamedLayer namedLayer(currentElement);
            _namedLayers.push_back(namedLayer);
        }
        currentElement = currentElement->next;
    }
}

std::vector<NamedLayer> SLDParser::namedLayers()
{
    return _namedLayers;
}

}