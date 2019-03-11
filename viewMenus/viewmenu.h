#ifndef VIEWMENU_H
#define VIEWMENU_H

#include <QDialog>

namespace Ui {
class viewmenu;
}

class viewmenu : public QDialog
{
    Q_OBJECT

public:
    explicit viewmenu(QWidget *parent = nullptr);
    ~viewmenu();

private:
    Ui::viewmenu *ui;
};

#endif // VIEWMENU_H
