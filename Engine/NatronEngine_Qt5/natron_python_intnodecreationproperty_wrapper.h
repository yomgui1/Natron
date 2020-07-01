#ifndef SBK_INTNODECREATIONPROPERTYWRAPPER_H
#define SBK_INTNODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>

class IntNodeCreationPropertyWrapper : public Natron::Python::IntNodeCreationProperty
{
public:
    IntNodeCreationPropertyWrapper(const std::vector<int > & values = std::vector< int >());
    IntNodeCreationPropertyWrapper(int value);
    ~IntNodeCreationPropertyWrapper();
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

#endif // SBK_INTNODECREATIONPROPERTYWRAPPER_H

