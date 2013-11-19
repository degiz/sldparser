#ifndef LOGIC_OPERATION_H
#define LOGIC_OPERATION_H

#include "operation.h"
#include "feature.h"

#include <vector>

namespace automap {

class LogicOperation : public Operation {
public:

    void add(Operation);
    
protected:
    std::vector<Operation> _operations;
};

}

#endif // LOGIC_OPERATION_H