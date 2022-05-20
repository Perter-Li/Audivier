QT   += core gui
QT   += multimedia
QT   += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    media.cpp \
    playerslider.cpp

HEADERS += \
    mainwindow.h \
    playerslider.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/include

LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/avcodec.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/avdevice.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/avfilter.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/avformat.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/avutil.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/postproc.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/swresample.lib
LIBS += D:/Applications/QT/FFmpeg/ffmpeg-n4.3.2-160-gfbb9368226-win64-gpl-shared-4.3/lib/swscale.lib
