#include "sldnode.h"

namespace automap {

SLDNode::SLDNode()
{

}

SLDNode::SLDNode(XmlIterator iterator) :
    _nodeName(iterator.name()),
    _iterator(iterator)
{
    _iterator.moveToChildNode();
    // _iterator.moveToNextNode(); // skip "text"
}

SLDNode::~SLDNode()
{
    
}

std::string SLDNode::nodeName() const
{
    return _nodeName;
}


}