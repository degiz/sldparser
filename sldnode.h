#ifndef SLDNODE_H
#define SLDNODE_H

#include <vector>
#include <map>
#include <string>

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

namespace automap {

class SLDNode {
public:
    SLDNode(xmlNode*);
    ~SLDNode();
    
    std::string nodeName();
    
protected:
    std::string _nodeName;
    xmlNode* _node;

    virtual void _parseNode() = 0;
};

};

#endif // SLDNODE_H