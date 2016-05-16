#include <iostream>
#include "microedittextedit.h"
#include <QScrollBar>
#include <algorithm>

MicroEditTextEdit::MicroEditTextEdit(QWidget *parent) : QWidget(parent), hbox{new QHBoxLayout(parent)}, gutter{new LineCountWidget(parent)}, plainText{new QPlainTextEdit(parent)}
{
    hbox->setMargin(0);
    hbox->setSpacing(0);
    gutter->setMinimumWidth(32);
    gutter->setStyleSheet("background-color:rgb(60, 60, 60)");
    plainText->setStyleSheet("background-color:rgb(80, 80, 80); color:rgb(255,255,255); font-family:'Courier New';font-weight:800;");

    hbox->addWidget(gutter);
    hbox->addWidget(plainText);

    setLayout(hbox);

    auto updateFunc = [&](){
        auto text = plainText->toPlainText();
        long count = std::count_if(text.begin(), text.end(), [](QChar ch) {
           return ch.cell() == '\n';
        }) + 1;
        gutter->totalLines(count);
        emit editorPositionUpdated(plainText->textCursor().columnNumber(), count);
    };

    emit editorPositionUpdated(0, 1);

    connect(plainText, &QPlainTextEdit::textChanged, updateFunc);
    connect(plainText, &QPlainTextEdit::cursorPositionChanged, updateFunc);

    connect(plainText->verticalScrollBar(), &QScrollBar::valueChanged, [&](int){
       gutter->offsetLines(plainText->verticalScrollBar()->sliderPosition());
    });

    connect(plainText->verticalScrollBar(), &QScrollBar::sliderMoved, [&](int){
       gutter->offsetLines(plainText->verticalScrollBar()->sliderPosition());
    });

    connect(plainText->verticalScrollBar(), &QScrollBar::rangeChanged, [&](int, int){
       gutter->offsetLines(plainText->verticalScrollBar()->sliderPosition()+1);
    });
}

QString MicroEditTextEdit::getText() const
{
    return plainText->toPlainText();
}

void MicroEditTextEdit::setText(QString text)
{
    plainText->setPlainText(text);
}
