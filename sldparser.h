#ifndef SLDPARSER_H
#define SLDPARSER_H

#include "sldnode.h"
#include "namedlayer.h"

#include <string>
#include <iostream>
#include <vector>

#include <libxml/parser.h>
#include <libxml/tree.h>

namespace automap {
    
class SLDParser {
public:
    SLDParser(std::string);
    ~SLDParser();
    
    std::vector<NamedLayer> namedLayers();
private:
    std::string _fileName;
    bool _loaded;
    xmlDoc* _document;
    xmlNode* _rootElement;
    std::vector<NamedLayer> _namedLayers;
    
    bool _openFile();
    bool _parseFile();
    void _parseNamedLayers();

};

}

#endif