#ifndef SLDPARSER_PRIVATE_H
#define SLDPARSER_PRIVATE_H

#include "sldnode.h"
#include "namedlayer.h"

#include <string>
#include <iostream>
#include <vector>

#include <libxml/parser.h>
#include <libxml/tree.h>

namespace automap {
    
class SLDParserPrivate {
public:
    SLDParserPrivate(std::string);
    ~SLDParserPrivate();
    
    bool loaded();
    std::vector<NamedLayer> NamedLayers();
private:
    std::string _fileName;
    bool _loaded;
    xmlDoc* _document;
    xmlNode* _rootElement;
    std::vector<NamedLayer> _namedLayers;
    
    bool _openFile();
    bool _parseFile();
    bool _parseNamedLayers();
};

}

#endif // SLDPARSER_PRIVATE_H