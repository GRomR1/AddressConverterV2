#ifndef XLSPARSER_H
#define XLSPARSER_H

#include <QObject>
#include "defines.h"
#include "address.h"
#include "tablemodel.h"

class XlsParser : public QObject
{
    Q_OBJECT
public:
    explicit XlsParser(QObject *parent = 0);
    ~XlsParser();
    void setTableOfData(QMap<QString, TableModel *> *data);

signals:
    void finished();
    void sheetParsed(QString sheet);
    void rowParsed(QString sheet, int row, Address addr);
    void headParsed(QString sheet, MapAddressElementPosition head);
    void appendColumn(int nCol, QString nameCol);
    void notFoundMandatoryColumn(AddressElements ae, QString colName);

public slots:
    void process();
    void onReadHead(const QString &sheet,
                    QStringList &head);
    Address onReadRow(const QString &sheet,
                   const int &rowNumber,
                   const QStringList &row);
    void onAppendColumn(int nCol,
                        QString nameCol);

private:
    QMap<QString, MapAddressElementPosition> _mapHead;
    QMap<QString, MapAddressElementPosition> _mapPHead;
    QMap<QString, TableModel *> *_data;
    bool _error;
    bool _isOneColumn;

    bool parseObject(QString &str, QString &result, QString regPattern, int regCap);
    bool parseObject(QString &str, QStringList &result, QString regPattern);
};

#endif // XLSPARSER_H