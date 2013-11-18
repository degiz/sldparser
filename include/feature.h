#ifndef FEATURE_H
#define FEATURE_H

#include <string>

template<class T>
class Feature {
    Feature(std::map<std::string, T> features) {
        _features = features;
    }
    virtual T getFieldValue<T>(Feature<T> object, std::string fieldName) = 0;
private:
    std::map<std::string, T> _features;
};

template<class T>
class String_Feature : public Feature<std::string> {
    virtual T getFieldValue<T>(Feature<T> object, std::string fieldName);
};


#endif // FEATURE_H