#include "mark.h"

namespace automap {

Mark::Mark()
{

}

Mark::Mark(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

Mark::~Mark()
{

}

std::string Mark::name()
{
    return  _name;
}

CssCollection Mark::fill()
{
    return _fill;
}

void Mark::_parseNode()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "WellKnownName") {
            _name = _iterator.value();
        } else if (_iterator.name() == "Fill") {
            CssCollection css(_iterator);
            _fill = css;
        }
    }
}

}