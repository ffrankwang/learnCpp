/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IShop/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[21];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 15), // "on_play_clicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "on_stop_clicked"
QT_MOC_LITERAL(4, 40, 19), // "on_backward_clicked"
QT_MOC_LITERAL(5, 60, 18), // "on_forward_clicked"
QT_MOC_LITERAL(6, 79, 15), // "on_next_clicked"
QT_MOC_LITERAL(7, 95, 19), // "on_preivous_clicked"
QT_MOC_LITERAL(8, 115, 13), // "proc_finished"
QT_MOC_LITERAL(9, 129, 22), // "on_volume_valueChanged"
QT_MOC_LITERAL(10, 152, 5), // "value"
QT_MOC_LITERAL(11, 158, 24), // "on_volume_sliderReleased"
QT_MOC_LITERAL(12, 183, 18), // "on_monitor_clicked"
QT_MOC_LITERAL(13, 202, 15), // "recv_image_slot"
QT_MOC_LITERAL(14, 218, 10), // "timer_slot"
QT_MOC_LITERAL(15, 229, 15), // "play_timer_slot"
QT_MOC_LITERAL(16, 245, 19), // "proc_read_proc_slot"
QT_MOC_LITERAL(17, 265, 23), // "on_progress_sliderMoved"
QT_MOC_LITERAL(18, 289, 8), // "position"
QT_MOC_LITERAL(19, 298, 22), // "on_full_screen_clicked"
QT_MOC_LITERAL(20, 321, 16) // "on_sound_clicked"

    },
    "Widget\0on_play_clicked\0\0on_stop_clicked\0"
    "on_backward_clicked\0on_forward_clicked\0"
    "on_next_clicked\0on_preivous_clicked\0"
    "proc_finished\0on_volume_valueChanged\0"
    "value\0on_volume_sliderReleased\0"
    "on_monitor_clicked\0recv_image_slot\0"
    "timer_slot\0play_timer_slot\0"
    "proc_read_proc_slot\0on_progress_sliderMoved\0"
    "position\0on_full_screen_clicked\0"
    "on_sound_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    1,  105,    2, 0x08 /* Private */,
       9,    1,  108,    2, 0x08 /* Private */,
      11,    0,  111,    2, 0x08 /* Private */,
      12,    0,  112,    2, 0x08 /* Private */,
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    1,  117,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_play_clicked(); break;
        case 1: _t->on_stop_clicked(); break;
        case 2: _t->on_backward_clicked(); break;
        case 3: _t->on_forward_clicked(); break;
        case 4: _t->on_next_clicked(); break;
        case 5: _t->on_preivous_clicked(); break;
        case 6: _t->proc_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_volume_sliderReleased(); break;
        case 9: _t->on_monitor_clicked(); break;
        case 10: _t->recv_image_slot(); break;
        case 11: _t->timer_slot(); break;
        case 12: _t->play_timer_slot(); break;
        case 13: _t->proc_read_proc_slot(); break;
        case 14: _t->on_progress_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_full_screen_clicked(); break;
        case 16: _t->on_sound_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
