#pragma once

#include <QWidget>

class Ui_CustomPage;

class CustomPage final : public QWidget
{
    Q_OBJECT

public:
    CustomPage(QWidget *parent = nullptr);
    ~CustomPage();

public:
    void addContent(QWidget *wgt_content);

private:
    void setupUi();

    bool eventFilter(QObject* watcher, QEvent *event);

signals:
    void sigSwipeLeft();
    void sigSwipeRight();

private:
    std::unique_ptr<Ui_CustomPage> ui;
    QPoint m_start_pos;
    int m_sensitive;
};
