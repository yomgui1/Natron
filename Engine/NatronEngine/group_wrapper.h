#ifndef SBK_GROUPWRAPPER_H
#define SBK_GROUPWRAPPER_H

#include <shiboken.h>

#include <PyNodeGroup.h>

namespace Natron { namespace Python {
class GroupWrapper : public Group
{
public:
    GroupWrapper();
    virtual ~GroupWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_GROUPWRAPPER_H

