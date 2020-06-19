#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define INITSIZE 100 /*Initial capacity of stack space*/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    typedef char ElemType;
    typedef float AAAAType;


    typedef struct         //定义栈
    {
       ElemType* base;
       ElemType* top;
       int stacksize;
    }SqStackOPTR;

    typedef struct         //定义栈
    {
       AAAAType* base;
       AAAAType* top;
       int stacksize;
    }SqStackOPND;

private slots:

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    QString EvaluateExpression();

    int InitStackOPTR(SqStackOPTR& );
    int InitStackOPND(SqStackOPND& );
    int pushOPTR(SqStackOPTR &,ElemType);
    int pushOPND(SqStackOPND &,AAAAType);
    int popOPTR(SqStackOPTR &,ElemType &);
    int popOPND(SqStackOPND &,AAAAType &);
    ElemType getTopOPTR(SqStackOPTR);
    AAAAType getTopOPND(SqStackOPND);
    int In(ElemType c);
    ElemType Precede(ElemType,ElemType);
    AAAAType operate(AAAAType,ElemType,AAAAType);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
