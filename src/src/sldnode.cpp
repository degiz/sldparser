#include "sldnode.h"

namespace SldParser {

SLDNode::SLDNode()
{

}

SLDNode::SLDNode(XmlIterator iterator) :
    _nodeName(iterator.name()),
    _iterator(iterator)
{
    _iterator.moveToChildNode();
}

SLDNode::~SLDNode()
{
    
}

std::string SLDNode::nodeName() const
{
    return _nodeName;
}


}