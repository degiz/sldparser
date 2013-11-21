#include "userstyle_p.h"

namespace SldParser {

UserStylePrivate::UserStylePrivate(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

UserStylePrivate::~UserStylePrivate()
{
    
}

std::string UserStylePrivate::name() const
{
    return _name;
}

std::string UserStylePrivate::title() const
{
    return _title;
}

std::string UserStylePrivate::abstract() const
{
    return _abstract;
}

bool UserStylePrivate::isDefault() const
{
    return _isDefault;
}

const std::vector<FeatureStyleType>& UserStylePrivate::featureStyleTypes() const
{
    return _features;
}

void UserStylePrivate::_parseNode()
{
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Name") {
        
            _name = _iterator.value();
            
        } else if (_iterator.name() == "Title") {
        
            _title = _iterator.value();
            
        } else if (_iterator.name() == "Abstract") {
        
            _abstract = _iterator.value();
            
        } else if (_iterator.name() == "IsDefault") {
        
            if (_iterator.value() == "1") {
                _isDefault = true;
            } else {
                _isDefault = false;
            }
            
        } else if (_iterator.name() == "FeatureTypeStyle") {
        
            FeatureStyleType feature(_iterator);
            _features.push_back(feature);
            
        }
    }
}

}

