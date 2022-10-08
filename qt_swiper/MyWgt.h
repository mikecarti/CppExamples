#pragma once

#include <QWidget>

class Ui_MyWgt;
class QGraphicsScene;

class PageIndicator;
class CustomPage;

class MyWgt : public QWidget
{
    Q_OBJECT

    typedef std::pair<PageIndicator*, CustomPage*> page_t;

public:
    MyWgt(QWidget *parent = nullptr);
    ~MyWgt();

public:
    void addPage(QWidget *wgt);

private:
    void setupUi();
    void setupView();

    void updateAllPage();

private slots:
    void swipePageLeft();
    void swipePageRight();

private:
    std::unique_ptr<Ui_MyWgt> ui;
    std::unique_ptr<QGraphicsScene> m_scene;
    std::list<page_t> m_indicators;
};
