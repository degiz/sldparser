#ifndef SLDPARSER_H
#define SLDPARSER_H

#include "namedlayer.h"

#include <memory>

namespace SldParser {

class SLDParserPrivate;

class SLDParser {
public:
    explicit SLDParser(std::string fileName);
    ~SLDParser();
    
    SLDParser(const SLDParser&);
    
    
    bool loaded();
    std::vector<NamedLayer>& namedLayers();
private:
    std::unique_ptr<SLDParserPrivate> _p;
};

}



#endif // SLDPARSER_H