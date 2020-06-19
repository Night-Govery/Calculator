#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

 QString display;
 typedef char ElemType;
 typedef float AAAAType;

MainWindow::~MainWindow()
{
    delete ui;
}

//1
void MainWindow::on_pushButton_7_clicked()
{
    display.append("1");
    this->ui->textEdit->setText(display);

}
//2
void MainWindow::on_pushButton_8_clicked()
{
    display.append("2");
    this->ui->textEdit->setText(display);
}
//3
void MainWindow::on_pushButton_9_clicked()
{
    display.append("3");
    this->ui->textEdit->setText(display);
}
//4
void MainWindow::on_pushButton_4_clicked()
{
    display.append("4");
    this->ui->textEdit->setText(display);
}
//5
void MainWindow::on_pushButton_5_clicked()
{
    display.append("5");
    this->ui->textEdit->setText(display);
}
//6
void MainWindow::on_pushButton_6_clicked()
{
    display.append("6");
    this->ui->textEdit->setText(display);
}

//7
void MainWindow::on_pushButton_clicked()
{
    display.append("7");
    this->ui->textEdit->setText(display);
}
//8
void MainWindow::on_pushButton_2_clicked()
{
    display.append("8");
    this->ui->textEdit->setText(display);
}
//9
void MainWindow::on_pushButton_3_clicked()
{
    display.append("9");
    this->ui->textEdit->setText(display);
}
//0
void MainWindow::on_pushButton_10_clicked()
{
    display.append("0");
    this->ui->textEdit->setText(display);
}
//CE
void MainWindow::on_pushButton_17_clicked()
{
    display.clear();
    this->ui->textEdit->setText(display);
}
//<-
void MainWindow::on_pushButton_21_clicked()
{
    display.chop(1);
    this->ui->textEdit->setText(display);
}
//.
void MainWindow::on_pushButton_11_clicked()
{
    display.append(".");
    this->ui->textEdit->setText(display);
}

// /
void MainWindow::on_pushButton_14_clicked()
{
    display.append("/");
    this->ui->textEdit->setText(display);
}
//*
void MainWindow::on_pushButton_13_clicked()
{
    display.append("*");
    this->ui->textEdit->setText(display);
}
//-
void MainWindow::on_pushButton_15_clicked()
{
    display.append("-");
    this->ui->textEdit->setText(display);
}
//+
void MainWindow::on_pushButton_12_clicked()
{
    display.append("+");
    this->ui->textEdit->setText(display);
}
//(
void MainWindow::on_pushButton_16_clicked()
{
    display.append("(");
    this->ui->textEdit->setText(display);
}
//)
void MainWindow::on_pushButton_19_clicked()
{
    display.append(")");
    this->ui->textEdit->setText(display);
}
//=
void MainWindow::on_pushButton_18_clicked()
{
    display.append("#");
    this->ui->textEdit->setText(EvaluateExpression());
}



int MainWindow::InitStackOPTR(SqStackOPTR& S)			//初始化栈
{
   S.base = (ElemType*)malloc(100 * sizeof(ElemType));
   if (!S.base)exit(1);
   S.top = S.base;
   S.stacksize = 100;
   return 1;
}

int MainWindow::InitStackOPND(SqStackOPND& S)			//初始化栈
{
   S.base = (AAAAType*)malloc(100 * sizeof(AAAAType));
   if (!S.base)exit(1);
   S.top = S.base;
   S.stacksize = 100;
   return 1;
}

int MainWindow::pushOPTR(SqStackOPTR &S,ElemType e)//入栈
{
   if(S.top-S.base==S.stacksize)
   return 0;//栈满
   *S.top++=e;//元素e压入栈顶，栈顶指针加1;
   return 1;
}
int MainWindow::pushOPND(SqStackOPND &S,AAAAType e)//入栈
{
   if(S.top-S.base==S.stacksize)
   return 0;//栈满
   *S.top++=e;//元素e压入栈顶，栈顶指针加1;
   return 1;
}

int MainWindow::popOPTR(SqStackOPTR &S,ElemType &e)//出栈
{
   if(S.top==S.base)//栈空
   return 0;
   e=*--S.top;//栈顶指针减一，将栈顶元素赋给e;
   return 1;
}

int MainWindow::popOPND(SqStackOPND &S,AAAAType &e)//出栈
{
   if(S.top==S.base)//栈空
   return 0;
   e=*--S.top;//栈顶指针减一，将栈顶元素赋给e;
   return 1;
}


ElemType MainWindow::getTopOPTR(SqStackOPTR S)//取栈顶元素
{
   if(S.top!=S.base)//栈非空
   return *(S.top-1);//返回栈顶元素的值，栈顶指针不变
}

AAAAType MainWindow::getTopOPND(SqStackOPND S)//取栈顶元素
{
   if(S.top!=S.base)//栈非空
   return *(S.top-1);//返回栈顶元素的值，栈顶指针不变
}




int MainWindow::In(ElemType c){
   if(c == '+'){
       return 1;
   }
   if(c == '-'){
       return 1;
   }
   if(c == '*'){
       return 1;
   }
   if(c == '/'){
       return 1;
   }
   if(c == '('){
       return 1;
   }
   if(c == ')'){
       return 1;
   }
   if(c == '='){
       return 1;
   }
   if(c == '#'){
       return 1;
   }
   if(c == '.'){
       return 1;
   }
   return 0;
}



ElemType MainWindow::Precede(ElemType top,ElemType c){
   if(c == '+' || c == '-'){
       if(top == '(' || top == '#'){
           return '<';
       }else{
           return '>';
       }
   }
   else if(c == '*' || c == '/'){
       if(top == '/' || top == '*' || top == ')'){
           return '>';
       }else{
           return '<';
       }
   }
   else if(c == '('){
       return '<';
   }
   else if(c == ')'){
       if(top == '('){
           return '=';
       }
       else{
           return '>';
       }
   }
   else if(c == '#'){
       if(top == '#'){
           return '=';
       }
       else{
           return '>';
       }
   }
}


AAAAType MainWindow::operate(AAAAType a,ElemType theta,AAAAType b){
   AAAAType num1 = a;
   AAAAType num2 = b;
   AAAAType result;

   switch(theta){
       case '+':
           result = num1+num2;
           break;
       case '-':
           result = num1-num2;
           break;
       case '*':
           result = num1*num2;
           break;
       case '/':
           result = num1/num2;
           break;
   }

   return result;

}


QString MainWindow::EvaluateExpression()
{
   SqStackOPTR OPTR;
   SqStackOPND OPND;
   char c,theta,x;
   AAAAType a,b,pre,tempnum1,tempnum2;

   //首位操作符标志
   int first_flag = 0;


   //多位数连用计数器
   int flag = 1;


   //小数点计数标志
   int dot_flag = 0;
   //小数点计数计数器
   int dot_count = 0;
   //小数点连用标志
   int dot_link_flag = 0;
   //小数点与操作符连用标志
   int dot_opnd_link_flag = 0;


   //读取到的字符串
   char*  ch;
   //字符串位数计数器
   int count_flag = 0;

   //操作符连用标志
   //+-*/对应1，(为2,)为3
   int opnd_flag = 0;
   //运算可行性
   bool isCalculate = true;

   //括号计数
   int count_brackets = 0;
   //运算情况>判断
   bool isThirdOpnd = false;

   InitStackOPTR(OPTR);
   pushOPTR(OPTR,'#');  //初始化运算符栈
   InitStackOPND(OPND); //初始化操作数栈

   QByteArray ba = display.toLatin1();
   ch = ba.data();
   c = ch[count_flag];

   while (c!='#' || getTopOPTR(OPTR)!='#')
   {
       if (!In(c)){
           //数字进入，操作符非首位
           first_flag++;
           //将操作符连用标志归零
           opnd_flag = 0;
           //将小数点和操作符连用标志归零
           dot_opnd_link_flag = 0;
           //读取数字时，如果遇到小数点标志为1，则增加小数点计数器
           if(dot_flag == 1){
               dot_count++;
           }
           //将读取到的字符转成数字
           tempnum1 = c - '0';
           if(flag != 1){
               popOPND(OPND,pre);
               for(int i =1;i<flag;i++){
                   tempnum2 = pre*10;
               }
               tempnum1 = tempnum1 + tempnum2;
           }         //读入的c不是运算符
           pushOPND(OPND,tempnum1);
           //添加多位数计数器
           flag++;
           //读取下一位
           count_flag++;
           c=ch[count_flag];
           isThirdOpnd = false;
       } //操作数进栈
       //当遇到小数点时，开启小数点计数器
       else if(c == '.'){
           if(opnd_flag != 0){
               QString str1 = "错误！原因:小数点和操作符连用";
               return str1;
           }
           if(dot_link_flag == 1){
               QString str1 = "错误！原因:小数点连用";
               return str1;
           }
           //添加小数点计算标志
           dot_flag = 1;
           //读取下一位
           count_flag++;
           c=ch[count_flag];
           //添加小数点连用标志
           dot_link_flag = 1;
           dot_opnd_link_flag = 1;

           isThirdOpnd = false;
       }
       else{
           if(!isThirdOpnd){
               //对括号计数进行计算，左括号加1，右括号减1
               if(c == '('){
                   count_brackets++;
               }else if(c == ')'){
                   count_brackets--;
               }
           }

           //对括号计数进行判断
           if(count_brackets<0){
               QString str1 = "错误！原因:右括号数量大于左括号数量";
               return str1;
           }

           //如果小数点和操作符连用
           if(dot_opnd_link_flag == 1){
               QString str1 = "错误！原因:操作符和小数点连用";
               return str1;
           }

           //如果操作符是首位输入
           if(first_flag == 0){
               if(c == '('){
               }else{
                   QString str1 = "错误！原因:运算符在首位";
                   return str1;
               }
           }

           //如果存在操作符连用现象，对类型进行判断
           if(opnd_flag != 0){
               if(c == '#'){
                   isCalculate = true;
               }else{
                   //上一位是+-*/
                   if(opnd_flag == 1){
                       if(c == '('){
                           isCalculate = true;
                       }else{
                           isCalculate = false;
                       }
                   }else if(opnd_flag == 3){//上一位是）
                       if(c == '('){
                           isCalculate = false;
                       }else{
                           isCalculate = true;
                       }
                   }else if(opnd_flag == 2){//上一位是（
                       if(c == '('){
                           isCalculate = true;
                       }else{
                           isCalculate = false;
                       }
                   }
               }
           }else{
               isCalculate = true;
           }

           //计算
           if(isCalculate){
               //首先判断前面的数字是否为小数
               if(dot_flag == 1){
                   popOPND(OPND,tempnum2);
                   //根据小数计数器进行缩小操作
                   for(int j =0;j<dot_count;j++){
                       tempnum2 = tempnum2/10;
                   }
                   pushOPND(OPND,tempnum2);
                   //清除小数点计算计数器
                   dot_count = 0;
                   //清除小数点计算标志
                   dot_flag = 0;
               }
               switch(Precede(getTopOPTR(OPTR),c))
               {
                   case '<':
                       //将当前操作符计入操作符连用标志
                       if(c == '('){
                           opnd_flag = 2;
                       }else if(c == ')'){
                           opnd_flag = 3;
                       }else{
                           opnd_flag = 1;
                       }
                       pushOPTR(OPTR,c);
                       count_flag++;
                       c=ch[count_flag];
                       isThirdOpnd = false;
                       break; //栈顶元素优先权低，运算符进栈
                   case '=':
                       //将当前操作符计入操作符连用标志
                       if(c == '('){
                           opnd_flag = 2;
                       }else if(c == ')'){
                           opnd_flag = 3;
                       }else{
                           opnd_flag = 1;
                       }
                       popOPTR(OPTR,x);
                       count_flag++;
                       c=ch[count_flag];
                       isThirdOpnd = false;
                       break; //脱括号并接收下一字符
                   case '>':
                       popOPTR(OPTR, theta);
                       popOPND(OPND,b);
                       popOPND(OPND,a);
                       pushOPND(OPND,operate(a,theta,b));
                       opnd_flag = 0;
                       isThirdOpnd = true;
                       break; //退栈并将运算结果入栈
               } //switch
               //清除多位数计数器
               flag = 1;
               //清除小数点连用标志
               dot_link_flag = 0;
           }else{
               QString str1 = "错误！原因:操作符和操作符连用";
               return str1;
           }
       }
   } //while
     if(count_brackets == 0){
         QString str = QString::number(getTopOPND(OPND));
         str.prepend("结果是:");
         return str;
     }else{
         QString str1 = "错误！原因:左括号数量大于右括号数量";
         return str1;
     }
} // EvaluateExpression
