#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QSpinBox>

class MySpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit MySpinBox(QWidget *parent = 0);
protected:
    QString textFromValue(int val) const;
};

#endif // MYSPINBOX_H
