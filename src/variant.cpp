#include "variant.h"

Variant::Variant(unsigned int value)
{
    _type = UINT;
    _createValue<unsigned int>(value);
}

Variant::Variant(double value)
{
    _type = DOUBLE;
    _createValue<double>(value);
}

Variant::Variant(std::string value)
{
    _type = STRING;
    _createValue<std::string>(value);
}

Variant::~Variant()
{
    if (_type == UINT) {
        _deleteValue<unsigned int>();
    } else if (_type == DOUBLE) {
        _deleteValue<double>();
    } else if (_type == STRING) {
        _deleteValue<std::string>();
    }
}

template<class T> void Variant::_deleteValue()
{
    _castTypeByPointer<T>()->~T();
}

template<class T> T* Variant::_castTypeByPointer()
{
    return static_cast<T *>(_value);
}

template<class T> T Variant::_castTypeByValue()
{
    T t;
    
    if (_type == UINT) {
        t = static_cast<T>(*_castTypeByPointer<unsigned int>());
    } else if (_type == DOUBLE) {
        t = static_cast<T>(*_castTypeByPointer<double>());
    }
    
    return t;
}

template<class T>
void Variant::_createValue(T v)
{
    _value = new T(v);
}

unsigned int Variant::asUInt()
{
    return _convertToIntegralType<unsigned int>(UINT);
}

double Variant::asDouble()
{
    return _convertToIntegralType<double>(DOUBLE);
}

std::string Variant::asString()
{
    return _convertToString();
}

template<class T>
T Variant::_convertToIntegralType(VariantType type)
{
    T t;
    if (type == _type) {
        t = *_castTypeByPointer<T>();
    } else {
        if (_type == STRING) {
            std::istringstream str(*_castTypeByPointer<std::string>());
            str >> t;
        } else {
            t = _castTypeByValue<T>();
        }
    }
    return t;
}

std::string Variant::_convertToString()
{
    std::string returnValue;
    if (_type == STRING) {
        returnValue = *_castTypeByPointer<std::string>();
    } else {
        std::ostringstream str;
        if (_type == UINT) {
            str << *_castTypeByPointer<unsigned int>();
        } else if (_type == DOUBLE) {
            str << *_castTypeByPointer<double>();
        }
        returnValue = str.str();
    }
    return returnValue;
}

VariantType Variant::type()
{
   return _type;
}