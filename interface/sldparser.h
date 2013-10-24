#include <string>

namespace automap {

class SLDParserPrivate;

class SLDParser {
public:
    SLDParser(std::string);
    ~SLDParser();
    SLDParser(const SLDParser&);
    SLDParser& operator= (const SLDParser&);
    bool loaded();
    
private:
    SLDParserPrivate* _impl;
};

}

