#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QListView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Controller");
    setMinimumSize(800, 400);
    resize(800, 400);
    QLabel* all_songs= new QLabel("All songs", this);
    QListView* list1 = new QListView(this);

    QLabel* label1 = new QLabel("Title:", this);
    QLineEdit* ledit1 = new QLineEdit(this);
    QLabel* label2 = new QLabel("Artist:", this);
    QLineEdit* ledit2 = new QLineEdit(this);
    QLabel* label3 = new QLabel("Link:", this);
    QLineEdit* ledit3 = new QLineEdit(this);
    QLabel* label4 = new QLabel("Lyrics:", this);
    QLineEdit* ledit4 = new QLineEdit(this);

    QFormLayout* input = new QFormLayout();
    input->addRow(label1, ledit1);
    input->addRow(label2, ledit2);
    input->addRow(label3, ledit3);
    input->addRow(label4, ledit4);

    QPushButton* btn1 = new QPushButton("Add", this);
    QPushButton* btn2 = new QPushButton("Delete", this);
    QPushButton* btn3 = new QPushButton("View Song Lyrics", this);
    QPushButton* btn4 = new QPushButton("Sort Titles", this);
    QPushButton* btn5 = new QPushButton("Sort Artists", this);
    QPushButton* btn6 = new QPushButton("Generate Random Playlist", this);

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(btn1, 0, 0);
    grid->addWidget(btn2, 0, 1);
    grid->addWidget(btn3, 0, 2);
    grid->addWidget(btn4, 1, 0);
    grid->addWidget(btn5, 1, 1);
    grid->addWidget(btn6, 1, 2);

    QVBoxLayout* left = new QVBoxLayout();
    left->addWidget(all_songs);
    left->addWidget(list1);
    left->addLayout(input);
    left->addLayout(grid);

    QPushButton* r_playlist = new QPushButton(">", this);
    QPushButton* l_playlist = new QPushButton("<", this);

    QVBoxLayout* center = new QVBoxLayout();
    center->addWidget(r_playlist, 0, Qt::AlignBottom);
    center->addWidget(l_playlist, 0, Qt::AlignTop);

    QLabel* label_playlist = new QLabel("Playlist", this);
    QListView* list2 = new QListView(this);
    QPushButton* play = new QPushButton("Play", this);

    QVBoxLayout* right = new QVBoxLayout();
    right->addWidget(label_playlist);
    right->addWidget(list2);
    right->addWidget(play);


    QGridLayout* main_layout = new QGridLayout(this);
    main_layout->addLayout(left, 0, 0);
    main_layout->addLayout(center, 0, 1);
    main_layout->addLayout(right, 0, 2);
}

Widget::~Widget()
{
}

void Widget::on_pushButton_clicked(){
    QString str = Widget->list1->text()
}
