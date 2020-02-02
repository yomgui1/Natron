#ifndef SBK_GROUPPARAMWRAPPER_H
#define SBK_GROUPPARAMWRAPPER_H

#include <shiboken.h>

#include <PyParameter.h>

namespace Natron { namespace Python {
class GroupParamWrapper : public GroupParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Param * param, int thisDimension) { GroupParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    virtual ~GroupParamWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_GROUPPARAMWRAPPER_H

