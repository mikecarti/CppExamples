#include "PageIndicator.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

PageIndicator::PageIndicator(int index, int all_index_count, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_width(30)
    , m_height(30)
    , m_index(index)
    , m_all_index_count(all_index_count)
{}

PageIndicator::~PageIndicator()
{}

void PageIndicator::setNewIndex(int new_index)
{
    m_index = new_index;
}

void PageIndicator::setNewAllIndexCound(int new_all_index_count)
{
    m_all_index_count = new_all_index_count;
}

QRectF PageIndicator::boundingRect() const
{
    return scene() ? calcRectF() : QRectF(0.0, 0.0, 30.0, 30.0);
}

void PageIndicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, [[maybe_unused]]QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(option->rect);
}

QRectF PageIndicator::calcRectF() const
{
    QRectF scene_rect = scene()->sceneRect();

    double all_padding = scene_rect.width() - (double)(m_all_index_count * m_width);
    double padding = all_padding / 2;

    double x = padding + m_width * m_index;
    return QRectF(x, 10, m_width, m_height);
}
