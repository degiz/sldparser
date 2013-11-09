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
    _clear();
}

void Variant::_clear()
{
    if (_type == NONE) {
        return;
    } else if (_type == UINT) {
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

template<class T> T* Variant::_castTypeByPointer(void* value)
{
    return static_cast<T *>(value);
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
    if (_type == NONE) {
        return 0;
    } else {
        return _convertToIntegralType<unsigned int>(UINT);
    }
}

double Variant::asDouble()
{
    if (_type == NONE) {
        return 0;
    } else {
        return _convertToIntegralType<double>(DOUBLE);
    }
}

std::string Variant::asString()
{
    if (_type == NONE) {
        return "";
    } else {
        return _convertToString();
    }
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

Variant::Variant(const Variant& other)
{
    _type = NONE;
    _swap(other);
}

Variant& Variant::operator=(const Variant& other)
{
    _swap(other);
}

bool Variant::operator==(const Variant& other)
{

    if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() == const_cast<Variant*>(&other)->asDouble();
    } else {
        return asString() == const_cast<Variant*>(&other)->asString();
    }
    
    return false;
}

bool Variant::operator!=(const Variant& other)
{
    return !(*this == other);
}

bool Variant::operator<(const Variant& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() < const_cast<Variant*>(&other)->asDouble();
    //}
    //return false;
}

bool Variant::operator<=(const Variant& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() <= const_cast<Variant*>(&other)->asDouble();
    //}
    //return false;
}

bool Variant::operator>(const Variant& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() > const_cast<Variant*>(&other)->asDouble();
    //}
    //return false;
}

bool Variant::operator>=(const Variant& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() >= const_cast<Variant*>(&other)->asDouble();
    //}
    //return false;
}

void Variant::_swap(const Variant& other)
{
    _clear();
    
    _type = other._type;
    
    if (_type == STRING) {
    
        std::string* str = _castTypeByPointer<std::string>(other._value);
        _createValue<std::string>(*str);
        
    } else if (_type == UINT) {
    
        unsigned int* value = _castTypeByPointer<unsigned int>(other._value);
        _createValue<unsigned int>(*value);
        
    } else if (_type == DOUBLE) {
    
        double* value = _castTypeByPointer<double>(other._value);
        _createValue<double>(*value);
        
    }
}