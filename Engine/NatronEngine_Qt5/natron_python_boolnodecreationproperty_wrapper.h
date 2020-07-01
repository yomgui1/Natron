#ifndef SBK_BOOLNODECREATIONPROPERTYWRAPPER_H
#define SBK_BOOLNODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>

class BoolNodeCreationPropertyWrapper : public Natron::Python::BoolNodeCreationProperty
{
public:
    BoolNodeCreationPropertyWrapper(bool value);
    BoolNodeCreationPropertyWrapper(const std::vector<bool > & values = std::vector< bool >());
    ~BoolNodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_NODECREATIONPROPERTYWRAPPER_H
#  define SBK_NODECREATIONPROPERTYWRAPPER_H

// Inherited base class:
class NodeCreationPropertyWrapper : public Natron::Python::NodeCreationProperty
{
public:
    NodeCreationPropertyWrapper();
    ~NodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_NODECREATIONPROPERTYWRAPPER_H

#endif // SBK_BOOLNODECREATIONPROPERTYWRAPPER_H

