#include <iostream>
#include <QApplication>

#include "editorwindow.h"
#include "microedittextedit.h"
#include "ui_editorwindow.h"
#include <algorithm>
#include <QFileDialog>

EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    connect(ui->documentTabs, &QTabWidget::currentChanged, [&](int) {
        ui->statusBar->clearPosition();
    });

    connect(ui->actionNew, &QAction::triggered, [&](){
        auto editor = new MicroEditTextEdit(ui->documentTabs);
        connect(editor, SIGNAL(editorPositionUpdated(long,long)), ui->statusBar, SLOT(updateEditorPosition(long,long)));
        ui->documentTabs->addTab(editor, newFileName());
        ui->documentTabs->setCurrentIndex(ui->documentTabs->children().size()-1);
        files.push_back(new FileRecord());
    });

    connect(ui->documentTabs, &QTabWidget::tabCloseRequested, [&](int index) {
        ui->documentTabs->removeTab(index);
    });

    connect(ui->actionSave, &QAction::triggered, [&](){
        FileRecord *file = files.at(ui->documentTabs->currentIndex());
        QString fileContents = dynamic_cast<MicroEditTextEdit*>(ui->documentTabs->currentWidget())->getText();
        if (file->isSaved())
        {
            file->save(fileContents);
        }
        else
        {
            QString fileName = QFileDialog::getSaveFileName(this, "Save As");
            file->saveAs(fileName, fileContents);
            ui->documentTabs->setTabText(ui->documentTabs->currentIndex(), fileName.mid(fileName.lastIndexOf('/')+1));
        }
    });

    connect(ui->actionOpen, &QAction::triggered, [&](){
        QString fileName = QFileDialog::getOpenFileName(this, "Open File") ;
        if (fileName != QString::null)
        {
            auto editText = new MicroEditTextEdit(this);
            ui->documentTabs->addTab(editText, fileName.mid(fileName.lastIndexOf('/')+1));
            QFile *file = new QFile(fileName);
            file->open(QIODevice::ReadOnly);
            editText->setText(QString(file->readAll()));
            file->close();
            files.push_back(new FileRecord(file));
        }

    });

    connect(ui->actionQuit, &QAction::triggered, [&](){
       qDebug("ABOUT TO QUIT");
        QApplication::quit();
    });
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::textEntered()
{

}

QString EditorWindow::newFileName()
{
    int count = 0;
    for (int i = 0; i < ui->documentTabs->tabBar()->count(); i++)
    {
        if (ui->documentTabs->tabBar()->tabText(i).startsWith("Untitled "))
        {
            count++;
        }
    }
    return QString("Untitled ") + QString::number(count + 1);
}

void EditorWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::KeyboardModifier::ControlModifier)
    {
        if (event->key() >= Qt::Key_1 && event->key()<=Qt::Key_9)
        {
            qDebug("WOOP");
            ui->documentTabs->setCurrentIndex(event->key() - Qt::Key_1);
        }
        else if (event->key() == Qt::Key_BracketLeft)
        {
            ui->documentTabs->setCurrentIndex(ui->documentTabs->currentIndex() - 1);
        }
        else if (event->key() == Qt::Key_BracketRight)
        {
            ui->documentTabs->setCurrentIndex(ui->documentTabs->currentIndex() + 1);
        }
    }
}
