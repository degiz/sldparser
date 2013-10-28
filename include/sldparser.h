#ifndef SLDPARSER_PRIVATE_H
#define SLDPARSER_PRIVATE_H

#include "sldnode.h"
#include "namedlayer.h"
#include "xmliterator.h"

#include <string>

namespace automap {
    
class SLDParser {
public:
    SLDParser(std::string);
    ~SLDParser();
    
    bool loaded();
    std::vector<NamedLayer>& NamedLayers();
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