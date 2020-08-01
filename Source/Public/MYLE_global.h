#ifndef MYLE_GLOBAL_H
#define MYLE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYLE_LIBRARY)
#  define MYLE_EXPORT Q_DECL_EXPORT
#else
#  define MYLE_EXPORT Q_DECL_IMPORT
#endif

#endif // MYLE_GLOBAL_H
