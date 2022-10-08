#include "MyWgt.h"
#include "ui_MyWgt.h"

#include "CustomPage.h"
#include "PageIndicator.h"

#include <QStyle>
#include <QFile>
#include <QGraphicsScene>

MyWgt::MyWgt(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui_MyWgt)
{
    ui->setupUi(this);
    setupUi();
    setupView();
}

MyWgt::~MyWgt()
{}

void MyWgt::addPage(QWidget *wgt)
{
    CustomPage* page = new CustomPage(ui->st_wgt);
    page->addContent(wgt);
    ui->st_wgt->addWidget(page);

    connect(page, SIGNAL(sigSwipeLeft()),  this, SLOT(swipePageRight()));
    connect(page, SIGNAL(sigSwipeRight()), this, SLOT(swipePageLeft()));

    PageIndicator* new_indicator = new PageIndicator(ui->st_wgt->indexOf(page), ui->st_wgt->count());
    m_scene->addItem(new_indicator);
    m_indicators.push_back({new_indicator, page});

    updateAllPage();
}

void MyWgt::setupUi()
{
    ui->graph_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->graph_view->setFixedHeight(50);
}

void MyWgt::setupView()
{
    m_scene.reset(new QGraphicsScene());
    m_scene->setSceneRect(ui->graph_view->rect().adjusted(0, 0, -2, -2));
    ui->graph_view->setScene(m_scene.get());
}

void MyWgt::updateAllPage()
{
    int all_page_count = ui->st_wgt->count();
    for (auto &page: m_indicators)
    {
        page.first->setNewIndex(ui->st_wgt->indexOf(page.second));
        page.first->setNewAllIndexCound(all_page_count);
    }
}

void MyWgt::swipePageLeft()
{
    int current = ui->st_wgt->currentIndex();
    int min_count = 0;
    int prev_page_index = current - 1;
    min_count > prev_page_index ? void() : ui->st_wgt->setCurrentIndex(prev_page_index);
}

void MyWgt::swipePageRight()
{
    int current = ui->st_wgt->currentIndex();
    int max_count = ui->st_wgt->count() - 1;
    int next_page_index = current + 1;
    max_count < next_page_index ? void() : ui->st_wgt->setCurrentIndex(next_page_index);
}

