#ifndef LOGIC_OPERATION_H
#define LOGIC_OPERATION_H

#include "filteroperation.h"
#include "feature.h"

#include <vector>

namespace automap {

class LogicOperation : public FilterOperation {
public:

    void add(FilterOperation*);
    
protected:
    std::vector<FilterOperation*> _operations;
};

}

#endif // LOGIC_OPERATION_H