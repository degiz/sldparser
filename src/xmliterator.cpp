#include "xmliterator.h"

namespace automap {

XmlIterator::XmlIterator()
{
    
}

XmlIterator::XmlIterator(xmlDoc* document) :
    _rootNode(xmlDocGetRootElement(document)->children)
{
    
}

XmlIterator::XmlIterator(xmlNode* rootNode) :
    _rootNode(rootNode)
{
    
}

bool XmlIterator::moveToNextNode()
{
    bool hasMoved = false;
    
    if (_hasNextNode()) {
        _currentNode = _currentNode->next;
        hasMoved = true;
    }
    
    return hasMoved;
}

bool XmlIterator::moveToChildNode()
{
    bool hasMoved = false;
    
    if (_hasChildren()) {
        _currentNode = _currentNode->children;
        hasMoved = true;
    }
    
    return hasMoved;
}

std::string XmlIterator::name()
{
    std::string name = HARD_CAST (_currentNode->children->name);
    return name;
}

std::string XmlIterator::value()
{
    std::string value("");
    
    if (_currentNode->children->content) {
        value = HARD_CAST (_currentNode->children->content);
    }
    return value;
}

std::string XmlIterator::attributeValue()
{
    xmlAttr* attribute = _currentNode->children->properties;
    xmlChar* value = xmlNodeListGetString(_currentNode->doc, attribute->children, 1);
    std::string attributeString = HARD_CAST (value);
    xmlFree(value);
    
    return attributeString;
}

bool XmlIterator::_hasNextNode()
{
    return _currentNode->next == NULL;
}

bool XmlIterator::_hasChildren()
{
    return _currentNode->children == NULL;
}

}
