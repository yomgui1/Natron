#ifndef SBK_STRINGNODECREATIONPROPERTYWRAPPER_H
#define SBK_STRINGNODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>

class StringNodeCreationPropertyWrapper : public Natron::Python::StringNodeCreationProperty
{
public:
    StringNodeCreationPropertyWrapper(const std::string & value);
    StringNodeCreationPropertyWrapper(const std::vector<std::string > & values = std::vector< std::string >());
    ~StringNodeCreationPropertyWrapper();
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

#endif // SBK_STRINGNODECREATIONPROPERTYWRAPPER_H

