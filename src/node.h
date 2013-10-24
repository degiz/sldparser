#ifndef XMLREADER_H
#define XMLREADER_H

#include "sldnode.h"

#include <libxml/parser.h>
#include <libxml/tree.h>

namespace automap {

class XmlReader {
public:
    XmlReader(xmlNode*);
    bool hasNextNode();

private:
    xmlNode* _rootNode;
    xmlNode* _currentNode;

};

}

#endif XMLREADER_H