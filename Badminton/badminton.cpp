#include "badminton.h"
#include "./ui_badminton.h"

badminton::badminton(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::badminton)
    , isMousePressed(false) // 初始化鼠标按下状态为 false
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    // 添加一个默认提示项
    ui->comboBox->insertItem(0, "请选择");
    ui->comboBox_2->insertItem(0, "请选择");
    ui->comboBox_3->insertItem(0, "请选择");
    ui->comboBox_4->insertItem(0, "请选择");
    ui->comboBox_5->insertItem(0, "请选择");
    ui->comboBox_6->insertItem(0, "请选择");

    //添加初始值
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);
    ui->comboBox_5->setCurrentIndex(0);
    ui->comboBox_6->setCurrentIndex(0);

    // 连接按钮点击信号到槽函数
    connect(ui->CalculateButton, &QPushButton::clicked, this, &badminton::calculateFee);
    connect(ui->resetButton, &QPushButton::clicked, this, &badminton::resetFields);
    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->comboBox, &QComboBox::currentTextChanged, ui->ratePerCourtLineEdit, &QLineEdit::setText);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, ui->usageTimeLineEdit, &QLineEdit::setText);
    connect(ui->comboBox_3, &QComboBox::currentTextChanged, ui->menCountLineEdit, &QLineEdit::setText);
    connect(ui->comboBox_4, &QComboBox::currentTextChanged, ui->womenCountLineEdit, &QLineEdit::setText);
    connect(ui->comboBox_5, &QComboBox::currentTextChanged, ui->shuttlecockCountLineEdit, &QLineEdit::setText);
    connect(ui->comboBox_6, &QComboBox::currentTextChanged, ui->shuttlecockCostLineEdit, &QLineEdit::setText);

}

badminton::~badminton()
{
    delete ui;
}


void badminton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isMousePressed = true;
        mousePressPosition = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void badminton::mouseMoveEvent(QMouseEvent *event)
{
    if (isMousePressed) {
        this->move(event->globalPosition().toPoint() - mousePressPosition);
        event->accept();
    }
}

void badminton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isMousePressed = false;
    }
}

void badminton::calculateFee()
{
    // 获取用户输入
    double ratePerCourt = ui->ratePerCourtLineEdit->text().toDouble();
    double usageTime = ui->usageTimeLineEdit->text().toDouble();
    int menCount = ui->menCountLineEdit->text().toInt();
    int womenCount = ui->womenCountLineEdit->text().toInt();
    int shuttlecockCount = ui->shuttlecockCountLineEdit->text().toInt();
    double shuttlecockCost = ui->shuttlecockCostLineEdit->text().toDouble();




    // 计算场地总费用
    double courtFee = ratePerCourt * usageTime;

    //计算球总费用
    double totalShuttlecockFee = shuttlecockCount * shuttlecockCost;

    // 计算总费用
    double totalFeeTotal = courtFee + totalShuttlecockFee;

    // 计算人均费用
    double PerPerson = (totalFeeTotal + 5 * womenCount) / (menCount + womenCount);


    // 计算每个男士和女士的费用
    double feePerMan = qCeil(PerPerson);
    double feePerWoman = qCeil(PerPerson-5);

    // 计算总费用
    double totalFee = totalFeeTotal;
    if(womenCount == 0){
        feePerWoman = 0;
    }
    if(menCount == 0){
        feePerMan = 0;
    }
    // 在对应的框中显示结果
    ui->menFeeLineEdit->setText(QString::number(feePerMan, 'f', 2) + " 元");
    ui->womenFeeLineEdit->setText(QString::number(feePerWoman, 'f', 2) + " 元");
    ui->totalFeeLineEdit->setText(QString::number(totalFee, 'f', 2) + " 元");
}
void badminton::resetFields()
{
    ui->ratePerCourtLineEdit->clear();
    ui->usageTimeLineEdit->clear();
    ui->menCountLineEdit->clear();
    ui->womenCountLineEdit->clear();
    ui->shuttlecockCountLineEdit->clear();
    ui->shuttlecockCostLineEdit->clear();
    ui->menFeeLineEdit->clear();
    ui->womenFeeLineEdit->clear();
    ui->totalFeeLineEdit->clear();
}





