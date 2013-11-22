#include "variant_p.h"

VariantPrivate::VariantPrivate(unsigned int value)
{
    _type = UINT;
    _createValue<unsigned int>(value);
}

VariantPrivate::VariantPrivate(double value)
{
    _type = DOUBLE;
    _createValue<double>(value);
}

VariantPrivate::VariantPrivate(std::string value)
{
    _type = STRING;
    _createValue<std::string>(value);
}

VariantPrivate VariantPrivate::fromUInt(unsigned int value)
{
    return VariantPrivate((unsigned int)value);
}

VariantPrivate VariantPrivate::fromString(std::string value)
{
    return VariantPrivate((std::string)value);
}

VariantPrivate VariantPrivate::fromDouble(double value)
{
    return VariantPrivate((double)value);
}

VariantPrivate::~VariantPrivate()
{
    _clear();
}

void VariantPrivate::_clear()
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

template<class T> void VariantPrivate::_deleteValue()
{
    _castTypeByPointer<T>()->~T();
}

template<class T> T* VariantPrivate::_castTypeByPointer(void* value)
{
    return static_cast<T *>(value);
}

template<class T> T* VariantPrivate::_castTypeByPointer()
{
    return static_cast<T *>(_value);
}

template<class T> T VariantPrivate::_castTypeByValue()
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
void VariantPrivate::_createValue(T v)
{
    _value = new T(v);
}

unsigned int VariantPrivate::asUInt()
{
    if (_type == NONE) {
        return 0;
    } else {
        return _convertToIntegralType<unsigned int>(UINT);
    }
}

double VariantPrivate::asDouble()
{
    if (_type == NONE) {
        return 0;
    } else {
        return _convertToIntegralType<double>(DOUBLE);
    }
}

std::string VariantPrivate::asString()
{
    if (_type == NONE) {
        return "";
    } else {
        return _convertToString();
    }
}

template<class T>
T VariantPrivate::_convertToIntegralType(VariantType type)
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

std::string VariantPrivate::_convertToString()
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

VariantType VariantPrivate::type()
{
   return _type;
}

VariantPrivate::VariantPrivate(const VariantPrivate& other)
{
    _type = NONE;
    _swap(other);
}

VariantPrivate& VariantPrivate::operator=(const VariantPrivate& other)
{
    _swap(other);
}

bool VariantPrivate::operator==(const VariantPrivate& other)
{

    if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() == const_cast<VariantPrivate*>(&other)->asDouble();
    } else {
        return asString() == const_cast<VariantPrivate*>(&other)->asString();
    }
    
    return false;
}

bool VariantPrivate::operator!=(const VariantPrivate& other)
{
     return asDouble() != const_cast<VariantPrivate*>(&other)->asDouble();
}

bool VariantPrivate::operator<(const VariantPrivate& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() < const_cast<VariantPrivate*>(&other)->asDouble();
    //}
    //return false;
}

bool VariantPrivate::operator<=(const VariantPrivate& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() <= const_cast<VariantPrivate*>(&other)->asDouble();
    //}
    //return false;
}

bool VariantPrivate::operator>(const VariantPrivate& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() > const_cast<VariantPrivate*>(&other)->asDouble();
    //}
    //return false;
}

bool VariantPrivate::operator>=(const VariantPrivate& other)
{
    //if ((_type == UINT || _type == DOUBLE) && (other._type == UINT || other._type == DOUBLE)) {
        return asDouble() >= const_cast<VariantPrivate*>(&other)->asDouble();
    //}
    //return false;
}

void VariantPrivate::_swap(const VariantPrivate& other)
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