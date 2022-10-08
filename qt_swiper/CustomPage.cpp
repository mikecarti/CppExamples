#include "CustomPage.h"

#include "ui_CustomPage.h"

#include <QMouseEvent>

CustomPage::CustomPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui_CustomPage)
    , m_sensitive(100)
{
    ui->setupUi(this);
    setupUi();
}

CustomPage::~CustomPage()
{}

void CustomPage::addContent(QWidget *wgt_content)
{
    if (!wgt_content)
        return;

    wgt_content->setParent(ui->sa_content);
    ui->sa_content->layout()->addWidget(wgt_content);
}

void CustomPage::setupUi()
{
    layout()->setContentsMargins(0, 0, 0, 0);
    ui->sa_content->layout()->setContentsMargins(0, 0, 0, 0);
    ui->sa->setFixedHeight(100);

    ui->sa->installEventFilter(this);
}

bool CustomPage::eventFilter(QObject *watched, QEvent *event)
{
    if (QMouseEvent *mouse_event = dynamic_cast<QMouseEvent *>(event); mouse_event)
    {
        if (mouse_event->type() == QMouseEvent::MouseButtonPress)
        {
            m_start_pos = mouse_event->pos();
        }
        else if (mouse_event->type() == QMouseEvent::MouseMove)
        {

        }
        else if (mouse_event->type() == QMouseEvent::MouseButtonRelease)
        {
            QPoint cur_pos = mouse_event->pos();
            if (abs(m_start_pos.x() - cur_pos.x()) > m_sensitive)
            {
                if (m_start_pos.x() > cur_pos.x())
                {
                    emit sigSwipeLeft();
                }
                else
                {
                    emit sigSwipeRight();
                }
            }

            m_start_pos = QPoint();
        }
    }

    return QWidget::eventFilter(watched, event);
}
