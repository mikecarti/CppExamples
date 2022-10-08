#include "MyWgt.h"

#include <QFrame>
#include <QApplication>
#include <qgridlayout.h>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWgt w;
    auto lmbd = [&](int num)
    {
        QFrame *frame = new QFrame();
        QGridLayout *lt = new QGridLayout(frame);

        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));
        lt->addWidget(new QPushButton("test "+QString::number(num), frame));

        w.addPage(frame);
    };

    lmbd(1);
    lmbd(2);
    lmbd(3);
    lmbd(4);
    lmbd(5);
    lmbd(6);
    w.show();
    return a.exec();
}
