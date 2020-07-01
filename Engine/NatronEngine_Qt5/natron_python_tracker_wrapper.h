#ifndef SBK_TRACKERWRAPPER_H
#define SBK_TRACKERWRAPPER_H

#include <PyTracker.h>

class TrackerWrapper : public Natron::Python::Tracker
{
public:
    ~TrackerWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_ITEMSTABLEWRAPPER_H
#  define SBK_ITEMSTABLEWRAPPER_H

// Inherited base class:
class ItemsTableWrapper : public Natron::Python::ItemsTable
{
public:
    ~ItemsTableWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_ITEMSTABLEWRAPPER_H

#endif // SBK_TRACKERWRAPPER_H

