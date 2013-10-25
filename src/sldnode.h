#ifndef SLDNODE_H
#define SLDNODE_H

#include "xmliterator.h"

#include <string>

namespace automap {

class SLDNode {
public:
    SLDNode(XmlIterator);
    ~SLDNode();
    
    std::string nodeName();
    
protected:
    std::string _nodeName;
    XmlIterator _iterator;

    virtual void _parseNode() = 0;
};

}

#endif // SLDNODE_H