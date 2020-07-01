#ifndef SBK_USERPARAMHOLDERWRAPPER_H
#define SBK_USERPARAMHOLDERWRAPPER_H

#include <PyNode.h>

class UserParamHolderWrapper : public Natron::Python::UserParamHolder
{
public:
    UserParamHolderWrapper();
    ~UserParamHolderWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_USERPARAMHOLDERWRAPPER_H

