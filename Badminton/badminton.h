#ifndef BADMINTON_H
#define BADMINTON_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class badminton; }  // 注意：这里是大写的 Badminton，因为类名通常大写
QT_END_NAMESPACE

class badminton : public QMainWindow
{
    Q_OBJECT

public:
    explicit badminton(QWidget *parent = nullptr);
    ~badminton();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private slots:
    void calculateFee();  // 声明槽函数
    void resetFields();


private:
    Ui::badminton *ui;
    bool isMousePressed;       // 标识鼠标是否被按下
    QPoint mousePressPosition; // 记录鼠标按下的位置
};

#endif // BADMINTON_H
