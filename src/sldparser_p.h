#ifndef SLDPARSER_PRIVATE_H
#define SLDPARSER_PRIVATE_H

#include "sldnode.h"
#include "namedlayer_p.h"
#include "xmliterator.h"

#include <string>

namespace automap {
    
class SLDParserPrivate {
public:
    SLDParserPrivate(std::string);
    ~SLDParserPrivate();
    
    bool loaded();
    std::vector<NamedLayerPrivate>& NamedLayers();
private:
    std::string _fileName;
    bool _loaded;
    xmlDoc* _document;
    xmlNode* _rootElement;
    std::vector<NamedLayerPrivate> _namedLayers;
    
    bool _openFile();
    bool _parseFile();
    bool _parseNamedLayers();
};

}

#endif // SLDPARSER_PRIVATE_H