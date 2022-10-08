#pragma once
#include <QGraphicsItem>

class PageIndicator final : public QGraphicsItem
{
public:
    PageIndicator(int index, int all_index_count, QGraphicsItem *parent = nullptr);
    ~PageIndicator();

public:
    void setNewIndex(int new_index);
    void setNewAllIndexCound(int new_all_index_count);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QRectF calcRectF() const;

private:
    int m_width;
    int m_height;
    int m_index;
    int m_all_index_count;
};
