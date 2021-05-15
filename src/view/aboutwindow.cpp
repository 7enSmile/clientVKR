#include "view/aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("О программе");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QString aboutText = QString(
            "<p style=\"white-space: pre-wrap;\">"
            "\n\n"
            "Программа предназначена для учёта связей кафедры высшего учебного заведения с работодателями.\n\n"
            "<table>"
            "<tr><td>Репозиторий: </td><td><a href=\"https://github.com/7enSmile/clientVKR\">GitHub</a></td></tr>"
            "</table>"
            );
    ui->about->setText(aboutText);
    ui->about->setOpenExternalLinks(true);
    QString authorText=QString(

                "<p style=\"white-space: pre-wrap;\">"
                "\n\n"
                "<table>"
                "<tr><td>Автор: </td><td>Панкратов Семен Александрович</td></tr>"
                "<tr><td>Группа: </td><td>КИ17-08Б</td></tr>"
                "<tr><td>Почта: </td><td>sema2012r@mail.ru</td></tr>"
                "</table>"
                "</p>");
    ui->author->setText(authorText);

    QString licenceText=QString(
                "<p style=\"white-space: pre-wrap;\">"
                "\n\n"
                "Copyright 2021 Semen Pankratov\n\n"
                 "\n\n"
                "This program is free software: you can redistribute it and/or modify\n\n"
                "it under the terms of the GNU General Public License as published by\n\n"
                "the Free Software Foundation, either version 3 of the License, or\n\n"
                "(at your option) any later version.\n\n"
                "\n\n"
                "This program is distributed in the hope that it will be useful,\n\n"
                "but WITHOUT ANY WARRANTY; without even the implied warranty of\n\n"
                "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n\n"
                "GNU General Public License for more details.\n\n"
                "\n\n"
                "You should have received a copy of the GNU General Public License\n\n"
                "along with this program. If not, see https://www.gnu.org/licenses.\n\n"
                );
    ui->license->setText(licenceText);




}

AboutWindow::~AboutWindow()
{
    delete ui;
}
