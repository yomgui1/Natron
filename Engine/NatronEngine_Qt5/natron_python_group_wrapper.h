#ifndef SBK_GROUPWRAPPER_H
#define SBK_GROUPWRAPPER_H

#include <PyNodeGroup.h>

class GroupWrapper : public Natron::Python::Group
{
public:
    GroupWrapper();
    ~GroupWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_GROUPWRAPPER_H

