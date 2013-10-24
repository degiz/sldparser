#include "xmlreader.h"

namespace automap {

XmlReader::XmlReader(xmlNode* rootNode) :
    _rootNode(rootNode)
{
    
}

xmlNode* XmlReader::getNextNode()
{
    return _currentNode->next;
}

}
