#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtApp.h"

class QtApp : public QMainWindow
{
    Q_OBJECT

public:
    QtApp(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtAppClass ui;
};
