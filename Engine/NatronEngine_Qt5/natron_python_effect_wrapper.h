#ifndef SBK_EFFECTWRAPPER_H
#define SBK_EFFECTWRAPPER_H

#include <PyNode.h>

class EffectWrapper : public Natron::Python::Effect
{
public:
    ~EffectWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_USERPARAMHOLDERWRAPPER_H
#  define SBK_USERPARAMHOLDERWRAPPER_H

// Inherited base class:
class UserParamHolderWrapper : public Natron::Python::UserParamHolder
{
public:
    UserParamHolderWrapper();
    ~UserParamHolderWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_USERPARAMHOLDERWRAPPER_H

#endif // SBK_EFFECTWRAPPER_H

