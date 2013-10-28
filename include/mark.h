#ifndef MARK_H
#define MARK_H

#include "sldnode.h"
#include "csscollection.h"

namespace automap {

class Mark : public SLDNode {
public:
    Mark();
    Mark(XmlIterator);
    ~Mark();
    
    std::string name();
    CssCollection fill();
    
private:
    std::string _name;
    CssCollection _fill;
    unsigned int _size;
    unsigned int _rotation;
    
    void _parseNode();

};

}

#endif