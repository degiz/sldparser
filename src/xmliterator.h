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
    XmlIterator(const XmlIterator&);
    XmlIterator(xmlDoc*);
    XmlIterator(xmlNode*);
    
    XmlIterator& operator=(const XmlIterator&);

    bool moveToNextNode();
    void moveToPreviousNode();
    void moveToParentNode();
    bool moveToChildNode();
    std::string name();
    std::string value();
    
    std::string attributeName();
    std::string attributeValue();

private:
    xmlNode* _rootNode;
    xmlNode* _currentNode;
    
    bool _hasNextNode();
    bool _hasChildren();
    
    void _swap(const XmlIterator& other);
};

}

#endif // XMLITERATOR_H