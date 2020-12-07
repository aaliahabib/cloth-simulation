/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
//#include "Canvas2D.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;

    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QTabWidget *tabWidget;
    QGridLayout *gridLayout_11;
    QScrollArea *scrollArea;
    QWidget *tab3D;
    QGridLayout *gridLayout_12;
    QWidget *canvas3D;

    QDockWidget *shapesDock;
    QWidget *shapesDockContents;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *textureType;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *texture1;
    QRadioButton *texture2;
    QRadioButton *texture3;
    QRadioButton *texture4;

    QVBoxLayout *verticalLayout_1;
    QGroupBox *intersectionType;
    QRadioButton *intersectSphere;
    QRadioButton *intersectHole;
    QGridLayout *gridLayout_1;

    QGroupBox *clothParameters;
    QGridLayout *gridLayout_4;
    QLabel *clothParameterLabel1;
    QLabel *clothParameterLabel2;
    QLabel *intersectionRadiusLabel;
    QSlider *clothParameterSlider1;
    QSlider *clothParameterSlider2;
    QSlider *intersectionRadiusSlider;
    QLineEdit *clothParameterTextbox1;
    QLineEdit *clothParameterTextbox2;
    QLineEdit *intersectionRadiusTextbox;
    QCheckBox *useLightingCheckbox;
    QCheckBox *drawWireframeCheckbox;
    QCheckBox *drawNormalsCheckbox;
    QCheckBox *clipLeftCorner;
    QCheckBox *clipRightCorner;
    QPushButton *renderClothButton;
    QWidget *shapesDockEmptySpace;

    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuToolbars;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 3112);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::VerticalTabs);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tab3D = new QWidget();
        tab3D->setObjectName(QString::fromUtf8("tab3D"));
        gridLayout_12 = new QGridLayout(tab3D);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        canvas3D = new QWidget(tab3D);
        canvas3D->setObjectName(QString::fromUtf8("canvas3D"));

        gridLayout_12->addWidget(canvas3D, 0, 0, 1, 1);

        tabWidget->addTab(tab3D, QString());

        gridLayout_10->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);

        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);

        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);

        shapesDock = new QDockWidget(MainWindow);
        shapesDock->setObjectName(QString::fromUtf8("shapesDock"));
        shapesDockContents = new QWidget();
        shapesDockContents->setObjectName(QString::fromUtf8("shapesDockContents"));
        verticalLayout_7 = new QVBoxLayout(shapesDockContents);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        textureType = new QGroupBox(shapesDockContents);
        textureType->setObjectName(QString::fromUtf8("textureType"));

        verticalLayout_8 = new QVBoxLayout(textureType);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 5, -1, 5);

        texture1 = new QRadioButton(textureType);
        texture1->setObjectName(QString::fromUtf8("texture1"));
        texture1->setChecked(true);

        verticalLayout_8->addWidget(texture1);

        texture2 = new QRadioButton(textureType);
        texture2->setObjectName(QString::fromUtf8("shapeTypeCone"));

        verticalLayout_8->addWidget(texture2);

        texture3 = new QRadioButton(textureType);
        texture3->setObjectName(QString::fromUtf8("shapeTypeSphere"));

        verticalLayout_8->addWidget(texture3);

        texture4 = new QRadioButton(textureType);
        texture4->setObjectName(QString::fromUtf8("shapeTypeCylinder"));

        verticalLayout_8->addWidget(texture4);
        verticalLayout_7->addWidget(textureType);

        intersectionType = new QGroupBox(shapesDockContents);
        intersectionType->setObjectName(QString::fromUtf8("intersectionType"));

        gridLayout_1 = new QGridLayout(intersectionType);
        gridLayout_1->setSpacing(6);
        gridLayout_1->setContentsMargins(11, 11, 11, 11);
        gridLayout_1->setObjectName(QString::fromUtf8("gridLayout_1"));
        gridLayout_1->setVerticalSpacing(5);
        gridLayout_1->setContentsMargins(-1, 5, -1, 5);

        intersectSphere = new QRadioButton(intersectionType);
        intersectSphere->setObjectName(QString::fromUtf8("intersectSphere"));

        gridLayout_1->addWidget(intersectSphere, 0, 0, 1, 1);

        intersectHole = new QRadioButton(intersectionType);
        intersectHole->setObjectName(QString::fromUtf8("intersectHole"));

        gridLayout_1->addWidget(intersectHole, 1, 0, 1, 1);

        intersectionRadiusLabel = new QLabel(intersectionType);
        intersectionRadiusLabel->setObjectName(QString::fromUtf8("intersectionRadiusLabel"));

        intersectionRadiusSlider = new QSlider(intersectionType);
        intersectionRadiusSlider->setObjectName(QString::fromUtf8("intersectionRadiusSlider"));
        intersectionRadiusSlider->setMinimumSize(QSize(100, 0));
        intersectionRadiusSlider->setOrientation(Qt::Horizontal);

        intersectionRadiusTextbox = new QLineEdit(intersectionType);
        intersectionRadiusTextbox->setObjectName(QString::fromUtf8("intersectionRadiusTextbox"));
        intersectionRadiusTextbox->setMinimumSize(QSize(40, 0));
        intersectionRadiusTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_1->addWidget(intersectionRadiusLabel, 2, 0, 1, 1);
        gridLayout_1->addWidget(intersectionRadiusTextbox, 2, 2, 1, 1);
        gridLayout_1->addWidget(intersectionRadiusSlider, 2, 1, 1, 1);

        verticalLayout_7->addWidget(intersectionType);

        clothParameters = new QGroupBox(shapesDockContents);
        clothParameters->setObjectName(QString::fromUtf8("clothParameters"));
        gridLayout_4 = new QGridLayout(clothParameters);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(5);
        gridLayout_4->setContentsMargins(-1, 5, -1, 5);
        clothParameterLabel1 = new QLabel(clothParameters);
        clothParameterLabel1->setObjectName(QString::fromUtf8("clothParameterLabel1"));

        gridLayout_4->addWidget(clothParameterLabel1, 0, 0, 1, 1);

        clothParameterLabel2 = new QLabel(clothParameters);
        clothParameterLabel2->setObjectName(QString::fromUtf8("clothParameterLabel2"));

        gridLayout_4->addWidget(clothParameterLabel2, 2, 0, 1, 1);

        clothParameterSlider1 = new QSlider(clothParameters);
        clothParameterSlider1->setObjectName(QString::fromUtf8("clothParameterSlider1"));
        clothParameterSlider1->setMinimumSize(QSize(100, 0));
        clothParameterSlider1->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(clothParameterSlider1, 0, 1, 1, 1);

        clothParameterSlider2 = new QSlider(clothParameters);
        clothParameterSlider2->setObjectName(QString::fromUtf8("clothParameterSlider2"));
        clothParameterSlider2->setMinimumSize(QSize(100, 0));
        clothParameterSlider2->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(clothParameterSlider2, 2, 1, 1, 1);

        clothParameterTextbox1 = new QLineEdit(clothParameters);
        clothParameterTextbox1->setObjectName(QString::fromUtf8("clothParameterTextbox1"));
        clothParameterTextbox1->setMinimumSize(QSize(40, 0));
        clothParameterTextbox1->setMaximumSize(QSize(40, 16777215));

        gridLayout_4->addWidget(clothParameterTextbox1, 0, 2, 1, 1);

        clothParameterTextbox2 = new QLineEdit(clothParameters);
        clothParameterTextbox2->setObjectName(QString::fromUtf8("clothParameterTextbox2"));
        clothParameterTextbox2->setMinimumSize(QSize(40, 0));
        clothParameterTextbox2->setMaximumSize(QSize(40, 16777215));

        gridLayout_4->addWidget(clothParameterTextbox2, 2, 2, 1, 1);


        verticalLayout_7->addWidget(clothParameters);

        useLightingCheckbox = new QCheckBox(shapesDockContents);
        useLightingCheckbox->setObjectName(QString::fromUtf8("useLightingCheckbox"));

        verticalLayout_7->addWidget(useLightingCheckbox);

        drawWireframeCheckbox = new QCheckBox(shapesDockContents);
        drawWireframeCheckbox->setObjectName(QString::fromUtf8("drawWireframeCheckbox"));

        verticalLayout_7->addWidget(drawWireframeCheckbox);

        drawNormalsCheckbox = new QCheckBox(shapesDockContents);
        drawNormalsCheckbox->setObjectName(QString::fromUtf8("drawNormalsCheckbox"));

        verticalLayout_7->addWidget(drawNormalsCheckbox);


        clipLeftCorner = new QCheckBox(shapesDockContents);
        clipLeftCorner->setObjectName(QString::fromUtf8("clipLeftCorner"));

        verticalLayout_7->addWidget(clipLeftCorner);

        clipRightCorner = new QCheckBox(shapesDockContents);
        clipRightCorner->setObjectName(QString::fromUtf8("clipRightCorner"));

        verticalLayout_7->addWidget(clipRightCorner);

        renderClothButton = new QPushButton(shapesDockContents);
        renderClothButton->setObjectName(QString::fromUtf8("renderClothButton"));
        verticalLayout_7->addWidget(renderClothButton);

        shapesDockEmptySpace = new QWidget(shapesDockContents);
        shapesDockEmptySpace->setObjectName(QString::fromUtf8("shapesDockEmptySpace"));
        sizePolicy2.setHeightForWidth(shapesDockEmptySpace->sizePolicy().hasHeightForWidth());
        shapesDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(shapesDockEmptySpace);

        shapesDock->setWidget(shapesDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, shapesDock);

        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuToolbars = new QMenu(menuBar);
        menuToolbars->setObjectName(QString::fromUtf8("menuToolbars"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuToolbars->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(renderClothButton, SIGNAL(clicked()), MainWindow, SLOT(renderCloth()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Killer Cloth", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tab3D), QCoreApplication::translate("MainWindow", "3D", nullptr));

        textureType->setTitle(QCoreApplication::translate("MainWindow", "Texture Type", nullptr));

        texture1->setText(QCoreApplication::translate("MainWindow", "Texture 1", nullptr));
        texture2->setText(QCoreApplication::translate("MainWindow", "Texture 2", nullptr));
        texture3->setText(QCoreApplication::translate("MainWindow", "Texture 3", nullptr));
        texture4->setText(QCoreApplication::translate("MainWindow", "Texture 4", nullptr));

        intersectionType->setTitle(QCoreApplication::translate("MainWindow", "Intersection Type", nullptr));
        intersectSphere->setText(QCoreApplication::translate("MainWindow", "Hole", nullptr));
        intersectHole->setText(QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        intersectionRadiusLabel->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));

        clothParameters->setTitle(QCoreApplication::translate("MainWindow", "Cloth Parameters", nullptr));
        clothParameterLabel1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        clothParameterLabel2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));

        useLightingCheckbox->setText(QCoreApplication::translate("MainWindow", "Use lighting", nullptr));
        drawWireframeCheckbox->setText(QCoreApplication::translate("MainWindow", "Draw wireframe", nullptr));
        drawNormalsCheckbox->setText(QCoreApplication::translate("MainWindow", "Draw normals", nullptr));
        clipRightCorner->setText(QCoreApplication::translate("MainWindow", "Clip Right Corner", nullptr));
        clipLeftCorner->setText(QCoreApplication::translate("MainWindow", "Clip Left Corner", nullptr));
        renderClothButton->setText(QCoreApplication::translate("MainWindow", "Render Cloth!", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuToolbars->setTitle(QCoreApplication::translate("MainWindow", "&Toolbars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
