#ifndef DEBUGWIDGET_H
#define DEBUGWIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "defines.h"

/// Отправлять отладочные сообщения в файл
#define DEBUG_TO_FILE

const QString LogFileName = "Log1.txt";
const int LogOpenMode (
        QIODevice::WriteOnly | QIODevice::Text | /*QIODevice::Truncate | */QIODevice::Append
        );


namespace Ui {
class DebugWidget;
}

// ********************* class DebugWidget ********************
/**
 * \class DebugWidget
 * \brief Класс для сохранения и показа отладочных сообщений
 */
class DebugWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DebugWidget(QWidget *parent = 0);
    ~DebugWidget();

public slots:
    void add(QString objName, QString mes);
    void add(QString str);
    void add(int n);
    void save(QString file);
    void clear();
    void closeLog();
    void addToFile(QString objName, QString mes);

private slots:
    void on__pushButtonClear_clicked();
    void on__pushButtonSave_clicked();

private:
    Ui::DebugWidget *_ui;
    QFile _logFile;
    QTextStream _logStream;
};

#endif // DEBUGWIDGET_H
