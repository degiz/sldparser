#include "sldnode.h"

namespace automap {

SLDNode::SLDNode(XmlIterator iterator) :
    _nodeName(iterator.name()),
    _iterator(iterator)
{
    _iterator.moveToChildNode();
}

SLDNode::~SLDNode()
{
    
}

std::string SLDNode::nodeName()
{
    return _nodeName;
}


}