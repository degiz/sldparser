#include "xmliterator.h"

namespace SldParser {

XmlIterator::XmlIterator()
{

}

XmlIterator::XmlIterator(const XmlIterator& other)
{
    _swap(other);
}

XmlIterator::XmlIterator(xmlDoc* document) :
    _rootNode(xmlDocGetRootElement(document)->children),
    _currentNode(_rootNode)
{
    
}

XmlIterator::XmlIterator(xmlNode* rootNode) :
    _rootNode(rootNode)
{
    
}


XmlIterator& XmlIterator::operator=(const XmlIterator& other)
{
    XmlIterator tmp(other);
    _swap(tmp);
    return *this;
}

bool XmlIterator::moveToNextNode()
{
    bool hasMoved = false;
    
    if (_hasNextNode()) {
        _currentNode = _currentNode->next;
        if (name() == "text") {
            hasMoved = moveToNextNode();
        } else {
            hasMoved = true;
        }
    }
    
    return hasMoved;
}

void XmlIterator::moveToPreviousNode()
{
    _currentNode = _currentNode->prev;
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

void XmlIterator::moveToParentNode()
{
    _currentNode = _currentNode->parent;
}

std::string XmlIterator::name()
{
    std::string name = HARD_CAST (_currentNode->name);
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

std::string XmlIterator::attributeName()
{
    /*xmlAttr* attribute = _currentNode->properties;
    xmlChar* name = const_cast<xmlChar*>(attribute->name);
    std::string attributeName = HARD_CAST (name);*/
    
    xmlAttr* attribute = _currentNode->properties;
    xmlChar* value = xmlNodeListGetString(_currentNode->doc, attribute->children, 1);
    std::string attributeName = HARD_CAST (value);
    xmlFree(value);
    
    return attributeName;
}

std::string XmlIterator::attributeValue()
{
    /*xmlAttr* attribute = _currentNode->properties;
    xmlChar* value = xmlNodeListGetString(_currentNode->doc, attribute->children, 1);
    std::string attributeString = HARD_CAST (value);
    xmlFree(value);*/
    
    std::string attributeString;
    return attributeString;
}

bool XmlIterator::_hasNextNode()
{
    return _currentNode->next != NULL;
}

bool XmlIterator::_hasChildren()
{
    return _currentNode->children != NULL;
}

void XmlIterator::_swap(const XmlIterator& other)
{
    _rootNode = other._rootNode;
    _currentNode = other._currentNode;
}


}
