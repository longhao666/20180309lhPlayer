#ifndef VIDEOWIDGET_GLOBAL_H
#define VIDEOWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VIDEOWIDGET_LIBRARY)
#  define VIDEOWIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VIDEOWIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VIDEOWIDGET_GLOBAL_H
