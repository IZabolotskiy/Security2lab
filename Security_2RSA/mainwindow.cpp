#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <exception>
#include "RSA.h"
#include "Decryptor.h"
#include "Encryptor.h"

using std::string;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    try
    {
      Crypto::RSA rsa(11, 17, 3);

      // String message to encrypt
      string in_str;
      in_str = ui->lineEdit->text().toStdString();
      Crypto::CryptoString out_str = rsa.encrypt(in_str);  // Encrypt message
      string out_str2;
      int256_t tmp;
      int it;
      for (it = 0; it < out_str.size(); it++)
      {
        tmp = out_str[it];
      out_str2.push_back(tmp.convert_to<char>());
      }


      string res_str = rsa.decrypt(out_str);               // Decrypt message

      ui->textEdit->setText(QString::fromStdString(out_str2));
      ui->textEdit_2->setText(QString::fromStdString(res_str));


    }
    catch (std::exception &e)
    {
      std::cout << "[ERR] RSA-exception thrown!\n";
      std::cout << e.what();
    }
}
