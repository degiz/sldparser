#ifndef XMLITERATOR_H
#define XMLITERATOR_H

#include <sstream>

#include <libxml/parser.h>
#include <libxml/tree.h>

namespace automap {

 // TODO: Bad idea
#define HARD_CAST(xmlChar) \
reinterpret_cast<char*>(const_cast<unsigned char *>(xmlChar))

class XmlIterator {
public:
    XmlIterator();
    XmlIterator(xmlDoc*);
    XmlIterator(xmlNode*);
    
    XmlIterator& operator=(const XmlIterator& other)
    {
        XmlIterator tmp(other);
        _swap(tmp);
        return *this;
    }

    bool moveToNextNode();
    bool moveToChildNode();
    std::string name();
    std::string value();
    
    std::string attributeValue();

private:
    xmlNode* _rootNode;
    xmlNode* _currentNode;
    
    bool _hasNextNode();
    bool _hasChildren();
    
    void _swap(XmlIterator& other)
    {
        _rootNode = other._rootNode;
        _currentNode = other._currentNode->children;
    }

};

}

#endif // XMLITERATOR_H