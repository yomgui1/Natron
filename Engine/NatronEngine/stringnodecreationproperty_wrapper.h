#ifndef SBK_STRINGNODECREATIONPROPERTYWRAPPER_H
#define SBK_STRINGNODECREATIONPROPERTYWRAPPER_H

#include <shiboken.h>

#include <PyAppInstance.h>

namespace Natron { namespace Python {
class StringNodeCreationPropertyWrapper : public StringNodeCreationProperty
{
public:
    StringNodeCreationPropertyWrapper(const std::string & value);
    StringNodeCreationPropertyWrapper(const std::vector<std::string > & values = std::vector< std::string >());
    virtual ~StringNodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_STRINGNODECREATIONPROPERTYWRAPPER_H

