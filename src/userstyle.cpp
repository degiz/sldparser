#include "userstyle.h"

namespace automap {

UserStyle::UserStyle(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

UserStyle::~UserStyle()
{
    
}

std::string UserStyle::name() const
{
    return _name;
}

std::string UserStyle::title() const
{
    return _title;
}

std::string UserStyle::abstract() const
{
    return _abstract;
}

bool UserStyle::isDefault() const
{
    return _isDefault;
}

const std::vector<FeatureStyleType>& UserStyle::featureStyleTypes() const
{
    return _features;
}

void UserStyle::_parseNode()
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

