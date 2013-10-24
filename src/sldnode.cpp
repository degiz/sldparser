#include "sldnode.h"

namespace automap {

SLDNode::SLDNode(xmlNode* node) :
    _nodeName((char*)node->name),
    _node(node)
{

}

SLDNode::~SLDNode()
{
    
}

std::string SLDNode::nodeName()
{
    return _nodeName;
}


}