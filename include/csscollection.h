#ifndef CSSCOLLECTION_H
#define CSSCOLLECTION_H

#include "sldnode.h"
#include "csselement.h"

namespace automap {
    
class CssCollection : public SLDNode {
public:
    CssCollection();
    CssCollection(XmlIterator);
    ~CssCollection();
    
    std::vector<CssElement> cssElements();
    
private:
    void _parseNode();

    
    std::vector<CssElement> _csselements;

};
    
};

#endif // CSSCOLLECTION_H