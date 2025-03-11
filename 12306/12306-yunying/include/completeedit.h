#ifndef COMPLETEEDIT_H
#define COMPLETEEDIT_H

#include <QLineEdit>
#include <QStringList>
#include <QStringListModel>
#include <QString>
#include <QCompleter>
#include <QStack>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>

#define MAX_ALPHA_NUM 26

class InputCompleter : public QCompleter
{
    Q_OBJECT

public:
    InputCompleter(QObject *parent = nullptr);
    InputCompleter &operator=(const InputCompleter &other);
    void addStationName(const QByteArray &staName, const QByteArray &staFullPinYin);
    void addStationFullPinYin(const QByteArray &staName,
                                              const QByteArray &staFullPinYin);
    void addStationSimplePinYin(const QByteArray &staName,
                                                const QByteArray &staSimplePinYin,
                                                const QByteArray &staFullPinYin);

    void update(const QByteArray &word);
    void setStationData(const QByteArray &nameText);

    inline QString word()
    {
        return m_word;
    }

private:
    // 一级索引，长度256
    QVector<int> stationNameIndexLevel1;
    // 二级索引，长度256
    QVector<int> stationNameIndexLevel2;
    // 数据
    QVector<QVector<QPair<QByteArray, QString>>> stationNameData;
    QVector<int> stationFullPinYinIndexLevel1;
    QVector<int> stationFullPinYinIndexLevel2;
    QVector<QVector<QPair<QByteArray, QString>>> stationFullPinYinData;
    QVector<int> stationSimplePinYinIndexLevel1;
    QVector<int> stationSimplePinYinIndexLevel2;
    QVector<QVector<QPair<QByteArray, QString>>> stationSimplePinYinData;
    QStack<QVector<QPair<QByteArray, QString>>> keyWordStack;
    QStringListModel m_model;
    QByteArray m_word;
    bool isAppend;
};

class CompleteEdit : public QLineEdit
{
    Q_OBJECT

public:
    CompleteEdit(QWidget *parent = nullptr);
    ~CompleteEdit();

    void setCompleter(InputCompleter *c);
    InputCompleter *completer() const;

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void insertCompletion(const QString &completion);

private:
    InputCompleter *c;
};

struct mapArea {
    bool active;
    bool selected;
    QPoint pos;
    QPixmap pixmap;
};

class VarCodeLabel : public QLabel
{
    Q_OBJECT
public:
    explicit VarCodeLabel(QWidget *parent = nullptr);
    ~VarCodeLabel() override;
    int getArea(int x, int y);
    QVector<mapArea> &getPoints();
    void clearSelected();

protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    virtual void paintEvent(QPaintEvent* event) override;

private:
    QVector<mapArea> area;
    QLabel picLabel[9];
};

class ClickLabel : public QLabel
{
    Q_OBJECT
public:
    ClickLabel(QWidget *parent = nullptr);
    ~ClickLabel();

protected:
    void mousePressEvent(QMouseEvent *ev) override;
Q_SIGNALS:
    void clicked(int x, int y);
};

class CheckedLabel : public ClickLabel
{
    Q_OBJECT
public:
    explicit CheckedLabel(QWidget *parent = nullptr);
    ~CheckedLabel() override;
    void setChecked(bool checked);
    void reSetCheckedPos();

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    //virtual void paintEvent(QPaintEvent* event) override;

private:
    QLabel checkedIndicator;
};

class MultiAreaLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MultiAreaLabel(QWidget *parent = nullptr, int areaCount = 8, int areaWidth = 64, int areaHeight = 64);
    ~MultiAreaLabel();
    void setAreaCount(int c);
    int areaCount() const;
    void setAreaWidth(int w);
    int areaWidth() const;
    void setAreaHeight(int h);
    int areaHeight() const;
    void setAreaPixmap(int area, const QString &file);
    void setAreasPixmap(const QStringList &files);
    void show();
    void hide();
    void areaClicked();
    QGridLayout *layout();
    void setAreaSelected(int area);
    int areaSelected() const;

Q_SIGNALS:
    void clicked(int area);

private:
    int count;
    int width;
    int height;
    int areaSel;
    QGridLayout gridlayout;
    QList<CheckedLabel *> areaList;
};

#endif // COMPLETEEDIT_H
