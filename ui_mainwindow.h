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
#include "Canvas2D.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionRevert;
    QAction *actionCopy3Dto2D;
    QAction *actionClear;
    QAction *actionUseOrbitingCamera;
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QTabWidget *tabWidget;
    QWidget *tab2D;
    QGridLayout *gridLayout_11;
    QScrollArea *scrollArea;
    Canvas2D *canvas2D;
    QWidget *tab3D;
    QGridLayout *gridLayout_12;
    QWidget *canvas3D;
    QDockWidget *brushDock;
    QWidget *brushDockContents;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *brushType;
    QVBoxLayout *verticalLayout;
    QRadioButton *brushTypeConstant;
    QRadioButton *brushTypeLinear;
    QRadioButton *brushTypeQuadratic;
    QRadioButton *brushTypeSmudge;
    QRadioButton *brushTypeSpecial1;
    QRadioButton *brushTypeSpecial2;
    QGroupBox *brushColor;
    QGridLayout *gridLayout_3;
    QLineEdit *brushColorTextboxBlue;
    QSlider *brushColorSliderAlpha;
    QLabel *brushColorLabelGreen;
    QSlider *brushColorSliderGreen;
    QLabel *brushColorLabelBlue;
    QSlider *brushColorSliderBlue;
    QLabel *brushColorLabelRed;
    QLineEdit *brushColorTextboxRed;
    QLabel *brushColorLabelAlpha;
    QLineEdit *brushColorTextboxAlpha;
    QLineEdit *brushColorTextboxGreen;
    QSlider *brushColorSliderRed;
    QWidget *brushRadius;
    QGridLayout *gridLayout_6;
    QLineEdit *brushRadiusTextbox;
    QSlider *brushRadiusSlider;
    QLabel *brushRadiusLabel;
    QCheckBox *brushAlphaBlendingCheckbox;
    QWidget *emptySpaceBrush;
    QDockWidget *shapesDock;
    QWidget *shapesDockContents;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *showSceneviewInstead;
    QGroupBox *shapeType;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *shapeTypeCube;
    QRadioButton *shapeTypeCone;
    QRadioButton *shapeTypeSphere;
    QRadioButton *shapeTypeCylinder;
    QRadioButton *shapeTypeTorus;
    QRadioButton *shapeTypeSpecial1;
    QRadioButton *shapeTypeSpecial2;
    QGroupBox *shapeParameters;
    QGridLayout *gridLayout_4;
    QLabel *shapeParameterLabel1;
    QLabel *shapeParameterLabel2;
    QLabel *shapeParameterLabel3;
    QSlider *shapeParameterSlider1;
    QSlider *shapeParameterSlider2;
    QSlider *shapeParameterSlider3;
    QLineEdit *shapeParameterTextbox1;
    QLineEdit *shapeParameterTextbox2;
    QLineEdit *shapeParameterTextbox3;
    QCheckBox *useLightingCheckbox;
    QCheckBox *drawWireframeCheckbox;
    QCheckBox *drawNormalsCheckbox;
    QWidget *shapesDockEmptySpace;
    QDockWidget *filterDock;
    QWidget *filterDockContents;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *filterType;
    QVBoxLayout *verticalLayout_6;
    QFrame *line_5;
    QRadioButton *filterTypeEdgeDetect;
    QWidget *edgeDetectThreshold;
    QGridLayout *gridLayout_13;
    QLabel *edgeDetectSensitivityLabel;
    QSlider *edgeDetectSensitivitySlider;
    QLineEdit *edgeDetectSensitivityTextbox;
    QFrame *line;
    QRadioButton *filterTypeBlur;
    QWidget *blurRadius;
    QGridLayout *gridLayout_8;
    QLineEdit *blurRadiusTextbox;
    QSlider *blurRadiusSlider;
    QLabel *blurRadiusLabel;
    QFrame *line_2;
    QRadioButton *filterTypeScale;
    QWidget *scale;
    QGridLayout *gridLayout_9;
    QLabel *scaleLabelX;
    QSlider *scaleSliderX;
    QLineEdit *scaleTextboxX;
    QLabel *scaleLabelY;
    QSlider *scaleSliderY;
    QLineEdit *scaleTextboxY;
    QFrame *line_3;
    QRadioButton *filterTypeRotate;
    QWidget *rotateAngle;
    QGridLayout *gridLayout_17;
    QLabel *rotateAngleLabel;
    QSlider *rotateSlider;
    QLineEdit *rotateAngleEdit;
    QFrame *line_4;
    QRadioButton *filterTypeSpecial1;
    QRadioButton *filterTypeSpecial2;
    QRadioButton *filterTypeSpecial3;
    QPushButton *filterButton;
    QWidget *filterDockEmptySpace;
    QDockWidget *rayDock;
    QWidget *rayDockContents;
    QVBoxLayout *verticalLayout_4;
    QWidget *rayAllOrNone;
    QHBoxLayout *horizontalLayout;
    QPushButton *rayAllButton;
    QPushButton *rayNoneButton;
    QGroupBox *rayFeatures;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *raySuperSamping;
    QWidget *raySuperSamples;
    QGridLayout *gridLayout_7;
    QLabel *raySuperSamplesLabel;
    QLineEdit *raySuperSamplesTextbox;
    QCheckBox *rayAntiAliasing;
    QCheckBox *rayShadows;
    QCheckBox *rayTextureMapping;
    QCheckBox *rayReflection;
    QCheckBox *rayRefraction;
    QCheckBox *rayMultiThreading;
    QCheckBox *rayUseKDTree;
    QGroupBox *rayLighting;
    QVBoxLayout *verticalLayout_9;
    QCheckBox *rayPointLights;
    QCheckBox *rayDirectionalLights;
    QCheckBox *raySpotLights;
    QPushButton *rayRenderButton;
    QPushButton *rayStopRenderingButton;
    QWidget *rayDockEmptySpace;
    QDockWidget *camtransDock;
    QWidget *camtransDockContents;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *cameraOrbitCheckbox;
    QGroupBox *cameraPosition;
    QGridLayout *gridLayout;
    QLabel *cameraPositionLabelX;
    QLabel *cameraPositionLabelY;
    QLabel *cameraPositionLabelZ;
    QDial *transX;
    QDial *transY;
    QDial *transZ;
    QGroupBox *cameraRotation;
    QVBoxLayout *verticalLayout_13;
    QWidget *cameraRotation_2;
    QGridLayout *gridLayout_15;
    QDial *rotU;
    QDial *rotV;
    QDial *rotW;
    QLabel *cameraRotationLabelYaw;
    QLabel *cameraRotationLabelPitch;
    QLabel *cameraRotationLabelRoll;
    QPushButton *resetUpVector;
    QGroupBox *cameraResetAxis;
    QGridLayout *gridLayout_14;
    QPushButton *xAxisButton;
    QPushButton *yAxisButton;
    QPushButton *zAxisButton;
    QPushButton *axonometricButton;
    QWidget *cameraFrustum;
    QGridLayout *gridLayout_5;
    QLabel *cameraFovLabel;
    QLineEdit *cameraFovTextbox;
    QSlider *cameraFovSlider;
    QLabel *cameraNearLabel;
    QLineEdit *cameraNearTextbox;
    QLabel *cameraFarLabel;
    QLineEdit *cameraFarTextbox;
    QSlider *cameraNearSlider;
    QSlider *cameraFarSlider;
    QPushButton *resetSliders;
    QLabel *cameraAspectRatio;
    QLabel *label;
    QWidget *cameraDockEmptySpace;
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
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionRevert = new QAction(MainWindow);
        actionRevert->setObjectName(QString::fromUtf8("actionRevert"));
        actionRevert->setEnabled(true);
        actionCopy3Dto2D = new QAction(MainWindow);
        actionCopy3Dto2D->setObjectName(QString::fromUtf8("actionCopy3Dto2D"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionUseOrbitingCamera = new QAction(MainWindow);
        actionUseOrbitingCamera->setObjectName(QString::fromUtf8("actionUseOrbitingCamera"));
        actionUseOrbitingCamera->setCheckable(true);
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
        tab2D = new QWidget();
        tab2D->setObjectName(QString::fromUtf8("tab2D"));
        gridLayout_11 = new QGridLayout(tab2D);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab2D);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        canvas2D = new Canvas2D();
        canvas2D->setObjectName(QString::fromUtf8("canvas2D"));
        canvas2D->setGeometry(QRect(0, 0, 250, 3058));
        scrollArea->setWidget(canvas2D);

        gridLayout_11->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab2D, QString());
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
        brushDock = new QDockWidget(MainWindow);
        brushDock->setObjectName(QString::fromUtf8("brushDock"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(brushDock->sizePolicy().hasHeightForWidth());
        brushDock->setSizePolicy(sizePolicy);
        brushDock->setFloating(false);
        brushDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        brushDockContents = new QWidget();
        brushDockContents->setObjectName(QString::fromUtf8("brushDockContents"));
        sizePolicy.setHeightForWidth(brushDockContents->sizePolicy().hasHeightForWidth());
        brushDockContents->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(brushDockContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        brushType = new QGroupBox(brushDockContents);
        brushType->setObjectName(QString::fromUtf8("brushType"));
        verticalLayout = new QVBoxLayout(brushType);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, 5);
        brushTypeConstant = new QRadioButton(brushType);
        brushTypeConstant->setObjectName(QString::fromUtf8("brushTypeConstant"));
        brushTypeConstant->setChecked(true);

        verticalLayout->addWidget(brushTypeConstant);

        brushTypeLinear = new QRadioButton(brushType);
        brushTypeLinear->setObjectName(QString::fromUtf8("brushTypeLinear"));

        verticalLayout->addWidget(brushTypeLinear);

        brushTypeQuadratic = new QRadioButton(brushType);
        brushTypeQuadratic->setObjectName(QString::fromUtf8("brushTypeQuadratic"));

        verticalLayout->addWidget(brushTypeQuadratic);

        brushTypeSmudge = new QRadioButton(brushType);
        brushTypeSmudge->setObjectName(QString::fromUtf8("brushTypeSmudge"));

        verticalLayout->addWidget(brushTypeSmudge);

        brushTypeSpecial1 = new QRadioButton(brushType);
        brushTypeSpecial1->setObjectName(QString::fromUtf8("brushTypeSpecial1"));

        verticalLayout->addWidget(brushTypeSpecial1);

        brushTypeSpecial2 = new QRadioButton(brushType);
        brushTypeSpecial2->setObjectName(QString::fromUtf8("brushTypeSpecial2"));

        verticalLayout->addWidget(brushTypeSpecial2);


        verticalLayout_3->addWidget(brushType);

        brushColor = new QGroupBox(brushDockContents);
        brushColor->setObjectName(QString::fromUtf8("brushColor"));
        gridLayout_3 = new QGridLayout(brushColor);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(5);
        gridLayout_3->setContentsMargins(-1, 5, -1, 5);
        brushColorTextboxBlue = new QLineEdit(brushColor);
        brushColorTextboxBlue->setObjectName(QString::fromUtf8("brushColorTextboxBlue"));
        brushColorTextboxBlue->setMinimumSize(QSize(50, 0));
        brushColorTextboxBlue->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(brushColorTextboxBlue, 2, 3, 1, 1);

        brushColorSliderAlpha = new QSlider(brushColor);
        brushColorSliderAlpha->setObjectName(QString::fromUtf8("brushColorSliderAlpha"));
        brushColorSliderAlpha->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(brushColorSliderAlpha, 3, 2, 1, 1);

        brushColorLabelGreen = new QLabel(brushColor);
        brushColorLabelGreen->setObjectName(QString::fromUtf8("brushColorLabelGreen"));

        gridLayout_3->addWidget(brushColorLabelGreen, 1, 0, 1, 1);

        brushColorSliderGreen = new QSlider(brushColor);
        brushColorSliderGreen->setObjectName(QString::fromUtf8("brushColorSliderGreen"));
        brushColorSliderGreen->setMinimumSize(QSize(100, 0));
        brushColorSliderGreen->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(brushColorSliderGreen, 1, 2, 1, 1);

        brushColorLabelBlue = new QLabel(brushColor);
        brushColorLabelBlue->setObjectName(QString::fromUtf8("brushColorLabelBlue"));

        gridLayout_3->addWidget(brushColorLabelBlue, 2, 0, 1, 1);

        brushColorSliderBlue = new QSlider(brushColor);
        brushColorSliderBlue->setObjectName(QString::fromUtf8("brushColorSliderBlue"));
        brushColorSliderBlue->setMinimumSize(QSize(100, 0));
        brushColorSliderBlue->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(brushColorSliderBlue, 2, 2, 1, 1);

        brushColorLabelRed = new QLabel(brushColor);
        brushColorLabelRed->setObjectName(QString::fromUtf8("brushColorLabelRed"));

        gridLayout_3->addWidget(brushColorLabelRed, 0, 0, 1, 1);

        brushColorTextboxRed = new QLineEdit(brushColor);
        brushColorTextboxRed->setObjectName(QString::fromUtf8("brushColorTextboxRed"));
        brushColorTextboxRed->setMinimumSize(QSize(50, 0));
        brushColorTextboxRed->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(brushColorTextboxRed, 0, 3, 1, 1);

        brushColorLabelAlpha = new QLabel(brushColor);
        brushColorLabelAlpha->setObjectName(QString::fromUtf8("brushColorLabelAlpha"));

        gridLayout_3->addWidget(brushColorLabelAlpha, 3, 0, 1, 1);

        brushColorTextboxAlpha = new QLineEdit(brushColor);
        brushColorTextboxAlpha->setObjectName(QString::fromUtf8("brushColorTextboxAlpha"));
        brushColorTextboxAlpha->setMinimumSize(QSize(50, 0));
        brushColorTextboxAlpha->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(brushColorTextboxAlpha, 3, 3, 1, 1);

        brushColorTextboxGreen = new QLineEdit(brushColor);
        brushColorTextboxGreen->setObjectName(QString::fromUtf8("brushColorTextboxGreen"));
        brushColorTextboxGreen->setMinimumSize(QSize(50, 0));
        brushColorTextboxGreen->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(brushColorTextboxGreen, 1, 3, 1, 1);

        brushColorSliderRed = new QSlider(brushColor);
        brushColorSliderRed->setObjectName(QString::fromUtf8("brushColorSliderRed"));
        brushColorSliderRed->setMinimumSize(QSize(100, 0));
        brushColorSliderRed->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(brushColorSliderRed, 0, 2, 1, 1);


        verticalLayout_3->addWidget(brushColor);

        brushRadius = new QWidget(brushDockContents);
        brushRadius->setObjectName(QString::fromUtf8("brushRadius"));
        gridLayout_6 = new QGridLayout(brushRadius);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        brushRadiusTextbox = new QLineEdit(brushRadius);
        brushRadiusTextbox->setObjectName(QString::fromUtf8("brushRadiusTextbox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(brushRadiusTextbox->sizePolicy().hasHeightForWidth());
        brushRadiusTextbox->setSizePolicy(sizePolicy1);
        brushRadiusTextbox->setMinimumSize(QSize(40, 0));
        brushRadiusTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_6->addWidget(brushRadiusTextbox, 0, 3, 1, 1);

        brushRadiusSlider = new QSlider(brushRadius);
        brushRadiusSlider->setObjectName(QString::fromUtf8("brushRadiusSlider"));
        brushRadiusSlider->setMinimumSize(QSize(100, 0));
        brushRadiusSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(brushRadiusSlider, 0, 2, 1, 1);

        brushRadiusLabel = new QLabel(brushRadius);
        brushRadiusLabel->setObjectName(QString::fromUtf8("brushRadiusLabel"));

        gridLayout_6->addWidget(brushRadiusLabel, 0, 0, 1, 1);


        verticalLayout_3->addWidget(brushRadius);

        brushAlphaBlendingCheckbox = new QCheckBox(brushDockContents);
        brushAlphaBlendingCheckbox->setObjectName(QString::fromUtf8("brushAlphaBlendingCheckbox"));

        verticalLayout_3->addWidget(brushAlphaBlendingCheckbox);

        emptySpaceBrush = new QWidget(brushDockContents);
        emptySpaceBrush->setObjectName(QString::fromUtf8("emptySpaceBrush"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(emptySpaceBrush->sizePolicy().hasHeightForWidth());
        emptySpaceBrush->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(emptySpaceBrush);

        brushDock->setWidget(brushDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, brushDock);
        shapesDock = new QDockWidget(MainWindow);
        shapesDock->setObjectName(QString::fromUtf8("shapesDock"));
        shapesDockContents = new QWidget();
        shapesDockContents->setObjectName(QString::fromUtf8("shapesDockContents"));
        verticalLayout_7 = new QVBoxLayout(shapesDockContents);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        showSceneviewInstead = new QCheckBox(shapesDockContents);
        showSceneviewInstead->setObjectName(QString::fromUtf8("showSceneviewInstead"));

        verticalLayout_7->addWidget(showSceneviewInstead);

        shapeType = new QGroupBox(shapesDockContents);
        shapeType->setObjectName(QString::fromUtf8("shapeType"));
        verticalLayout_8 = new QVBoxLayout(shapeType);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 5, -1, 5);
        shapeTypeCube = new QRadioButton(shapeType);
        shapeTypeCube->setObjectName(QString::fromUtf8("shapeTypeCube"));
        shapeTypeCube->setChecked(true);

        verticalLayout_8->addWidget(shapeTypeCube);

        shapeTypeCone = new QRadioButton(shapeType);
        shapeTypeCone->setObjectName(QString::fromUtf8("shapeTypeCone"));

        verticalLayout_8->addWidget(shapeTypeCone);

        shapeTypeSphere = new QRadioButton(shapeType);
        shapeTypeSphere->setObjectName(QString::fromUtf8("shapeTypeSphere"));

        verticalLayout_8->addWidget(shapeTypeSphere);

        shapeTypeCylinder = new QRadioButton(shapeType);
        shapeTypeCylinder->setObjectName(QString::fromUtf8("shapeTypeCylinder"));

        verticalLayout_8->addWidget(shapeTypeCylinder);

        shapeTypeTorus = new QRadioButton(shapeType);
        shapeTypeTorus->setObjectName(QString::fromUtf8("shapeTypeTorus"));

        verticalLayout_8->addWidget(shapeTypeTorus);

        shapeTypeSpecial1 = new QRadioButton(shapeType);
        shapeTypeSpecial1->setObjectName(QString::fromUtf8("shapeTypeSpecial1"));

        verticalLayout_8->addWidget(shapeTypeSpecial1);

        shapeTypeSpecial2 = new QRadioButton(shapeType);
        shapeTypeSpecial2->setObjectName(QString::fromUtf8("shapeTypeSpecial2"));

        verticalLayout_8->addWidget(shapeTypeSpecial2);


        verticalLayout_7->addWidget(shapeType);

        shapeParameters = new QGroupBox(shapesDockContents);
        shapeParameters->setObjectName(QString::fromUtf8("shapeParameters"));
        gridLayout_4 = new QGridLayout(shapeParameters);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(5);
        gridLayout_4->setContentsMargins(-1, 5, -1, 5);
        shapeParameterLabel1 = new QLabel(shapeParameters);
        shapeParameterLabel1->setObjectName(QString::fromUtf8("shapeParameterLabel1"));

        gridLayout_4->addWidget(shapeParameterLabel1, 0, 0, 1, 1);

        shapeParameterLabel2 = new QLabel(shapeParameters);
        shapeParameterLabel2->setObjectName(QString::fromUtf8("shapeParameterLabel2"));

        gridLayout_4->addWidget(shapeParameterLabel2, 2, 0, 1, 1);

        shapeParameterLabel3 = new QLabel(shapeParameters);
        shapeParameterLabel3->setObjectName(QString::fromUtf8("shapeParameterLabel3"));

        gridLayout_4->addWidget(shapeParameterLabel3, 4, 0, 1, 1);

        shapeParameterSlider1 = new QSlider(shapeParameters);
        shapeParameterSlider1->setObjectName(QString::fromUtf8("shapeParameterSlider1"));
        shapeParameterSlider1->setMinimumSize(QSize(100, 0));
        shapeParameterSlider1->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(shapeParameterSlider1, 0, 1, 1, 1);

        shapeParameterSlider2 = new QSlider(shapeParameters);
        shapeParameterSlider2->setObjectName(QString::fromUtf8("shapeParameterSlider2"));
        shapeParameterSlider2->setMinimumSize(QSize(100, 0));
        shapeParameterSlider2->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(shapeParameterSlider2, 2, 1, 1, 1);

        shapeParameterSlider3 = new QSlider(shapeParameters);
        shapeParameterSlider3->setObjectName(QString::fromUtf8("shapeParameterSlider3"));
        shapeParameterSlider3->setMinimumSize(QSize(100, 0));
        shapeParameterSlider3->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(shapeParameterSlider3, 4, 1, 1, 1);

        shapeParameterTextbox1 = new QLineEdit(shapeParameters);
        shapeParameterTextbox1->setObjectName(QString::fromUtf8("shapeParameterTextbox1"));
        shapeParameterTextbox1->setMinimumSize(QSize(40, 0));
        shapeParameterTextbox1->setMaximumSize(QSize(40, 16777215));

        gridLayout_4->addWidget(shapeParameterTextbox1, 0, 2, 1, 1);

        shapeParameterTextbox2 = new QLineEdit(shapeParameters);
        shapeParameterTextbox2->setObjectName(QString::fromUtf8("shapeParameterTextbox2"));
        shapeParameterTextbox2->setMinimumSize(QSize(40, 0));
        shapeParameterTextbox2->setMaximumSize(QSize(40, 16777215));

        gridLayout_4->addWidget(shapeParameterTextbox2, 2, 2, 1, 1);

        shapeParameterTextbox3 = new QLineEdit(shapeParameters);
        shapeParameterTextbox3->setObjectName(QString::fromUtf8("shapeParameterTextbox3"));
        shapeParameterTextbox3->setMinimumSize(QSize(40, 0));
        shapeParameterTextbox3->setMaximumSize(QSize(40, 16777215));

        gridLayout_4->addWidget(shapeParameterTextbox3, 4, 2, 1, 1);


        verticalLayout_7->addWidget(shapeParameters);

        useLightingCheckbox = new QCheckBox(shapesDockContents);
        useLightingCheckbox->setObjectName(QString::fromUtf8("useLightingCheckbox"));

        verticalLayout_7->addWidget(useLightingCheckbox);

        drawWireframeCheckbox = new QCheckBox(shapesDockContents);
        drawWireframeCheckbox->setObjectName(QString::fromUtf8("drawWireframeCheckbox"));

        verticalLayout_7->addWidget(drawWireframeCheckbox);

        drawNormalsCheckbox = new QCheckBox(shapesDockContents);
        drawNormalsCheckbox->setObjectName(QString::fromUtf8("drawNormalsCheckbox"));

        verticalLayout_7->addWidget(drawNormalsCheckbox);

        shapesDockEmptySpace = new QWidget(shapesDockContents);
        shapesDockEmptySpace->setObjectName(QString::fromUtf8("shapesDockEmptySpace"));
        sizePolicy2.setHeightForWidth(shapesDockEmptySpace->sizePolicy().hasHeightForWidth());
        shapesDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(shapesDockEmptySpace);

        shapesDock->setWidget(shapesDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, shapesDock);
        filterDock = new QDockWidget(MainWindow);
        filterDock->setObjectName(QString::fromUtf8("filterDock"));
        filterDockContents = new QWidget();
        filterDockContents->setObjectName(QString::fromUtf8("filterDockContents"));
        verticalLayout_5 = new QVBoxLayout(filterDockContents);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        filterType = new QGroupBox(filterDockContents);
        filterType->setObjectName(QString::fromUtf8("filterType"));
        verticalLayout_6 = new QVBoxLayout(filterType);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 5, -1, 5);
        line_5 = new QFrame(filterType);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_5);

        filterTypeEdgeDetect = new QRadioButton(filterType);
        filterTypeEdgeDetect->setObjectName(QString::fromUtf8("filterTypeEdgeDetect"));

        verticalLayout_6->addWidget(filterTypeEdgeDetect);

        edgeDetectThreshold = new QWidget(filterType);
        edgeDetectThreshold->setObjectName(QString::fromUtf8("edgeDetectThreshold"));
        edgeDetectThreshold->setEnabled(false);
        gridLayout_13 = new QGridLayout(edgeDetectThreshold);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        edgeDetectSensitivityLabel = new QLabel(edgeDetectThreshold);
        edgeDetectSensitivityLabel->setObjectName(QString::fromUtf8("edgeDetectSensitivityLabel"));

        gridLayout_13->addWidget(edgeDetectSensitivityLabel, 0, 0, 1, 1);

        edgeDetectSensitivitySlider = new QSlider(edgeDetectThreshold);
        edgeDetectSensitivitySlider->setObjectName(QString::fromUtf8("edgeDetectSensitivitySlider"));
        edgeDetectSensitivitySlider->setOrientation(Qt::Horizontal);

        gridLayout_13->addWidget(edgeDetectSensitivitySlider, 0, 1, 1, 1);

        edgeDetectSensitivityTextbox = new QLineEdit(edgeDetectThreshold);
        edgeDetectSensitivityTextbox->setObjectName(QString::fromUtf8("edgeDetectSensitivityTextbox"));
        edgeDetectSensitivityTextbox->setMinimumSize(QSize(40, 0));
        edgeDetectSensitivityTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_13->addWidget(edgeDetectSensitivityTextbox, 0, 2, 1, 1);


        verticalLayout_6->addWidget(edgeDetectThreshold);

        line = new QFrame(filterType);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        filterTypeBlur = new QRadioButton(filterType);
        filterTypeBlur->setObjectName(QString::fromUtf8("filterTypeBlur"));

        verticalLayout_6->addWidget(filterTypeBlur);

        blurRadius = new QWidget(filterType);
        blurRadius->setObjectName(QString::fromUtf8("blurRadius"));
        gridLayout_8 = new QGridLayout(blurRadius);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        blurRadiusTextbox = new QLineEdit(blurRadius);
        blurRadiusTextbox->setObjectName(QString::fromUtf8("blurRadiusTextbox"));
        blurRadiusTextbox->setEnabled(false);
        blurRadiusTextbox->setMinimumSize(QSize(40, 0));
        blurRadiusTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_8->addWidget(blurRadiusTextbox, 0, 2, 1, 1);

        blurRadiusSlider = new QSlider(blurRadius);
        blurRadiusSlider->setObjectName(QString::fromUtf8("blurRadiusSlider"));
        blurRadiusSlider->setEnabled(false);
        blurRadiusSlider->setMinimumSize(QSize(100, 0));
        blurRadiusSlider->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(blurRadiusSlider, 0, 1, 1, 1);

        blurRadiusLabel = new QLabel(blurRadius);
        blurRadiusLabel->setObjectName(QString::fromUtf8("blurRadiusLabel"));
        blurRadiusLabel->setEnabled(false);

        gridLayout_8->addWidget(blurRadiusLabel, 0, 0, 1, 1);


        verticalLayout_6->addWidget(blurRadius);

        line_2 = new QFrame(filterType);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_2);

        filterTypeScale = new QRadioButton(filterType);
        filterTypeScale->setObjectName(QString::fromUtf8("filterTypeScale"));
        filterTypeScale->setEnabled(true);
        filterTypeScale->setChecked(false);

        verticalLayout_6->addWidget(filterTypeScale);

        scale = new QWidget(filterType);
        scale->setObjectName(QString::fromUtf8("scale"));
        gridLayout_9 = new QGridLayout(scale);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(5);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        scaleLabelX = new QLabel(scale);
        scaleLabelX->setObjectName(QString::fromUtf8("scaleLabelX"));
        scaleLabelX->setEnabled(false);

        gridLayout_9->addWidget(scaleLabelX, 0, 0, 1, 1);

        scaleSliderX = new QSlider(scale);
        scaleSliderX->setObjectName(QString::fromUtf8("scaleSliderX"));
        scaleSliderX->setEnabled(false);
        scaleSliderX->setMinimumSize(QSize(100, 0));
        scaleSliderX->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(scaleSliderX, 0, 1, 1, 1);

        scaleTextboxX = new QLineEdit(scale);
        scaleTextboxX->setObjectName(QString::fromUtf8("scaleTextboxX"));
        scaleTextboxX->setEnabled(false);
        scaleTextboxX->setMinimumSize(QSize(40, 0));
        scaleTextboxX->setMaximumSize(QSize(40, 16777215));

        gridLayout_9->addWidget(scaleTextboxX, 0, 2, 1, 1);

        scaleLabelY = new QLabel(scale);
        scaleLabelY->setObjectName(QString::fromUtf8("scaleLabelY"));
        scaleLabelY->setEnabled(false);

        gridLayout_9->addWidget(scaleLabelY, 1, 0, 1, 1);

        scaleSliderY = new QSlider(scale);
        scaleSliderY->setObjectName(QString::fromUtf8("scaleSliderY"));
        scaleSliderY->setEnabled(false);
        scaleSliderY->setMinimumSize(QSize(100, 0));
        scaleSliderY->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(scaleSliderY, 1, 1, 1, 1);

        scaleTextboxY = new QLineEdit(scale);
        scaleTextboxY->setObjectName(QString::fromUtf8("scaleTextboxY"));
        scaleTextboxY->setEnabled(false);
        scaleTextboxY->setMinimumSize(QSize(40, 0));
        scaleTextboxY->setMaximumSize(QSize(40, 16777215));

        gridLayout_9->addWidget(scaleTextboxY, 1, 2, 1, 1);


        verticalLayout_6->addWidget(scale);

        line_3 = new QFrame(filterType);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_3);

        filterTypeRotate = new QRadioButton(filterType);
        filterTypeRotate->setObjectName(QString::fromUtf8("filterTypeRotate"));

        verticalLayout_6->addWidget(filterTypeRotate);

        rotateAngle = new QWidget(filterType);
        rotateAngle->setObjectName(QString::fromUtf8("rotateAngle"));
        gridLayout_17 = new QGridLayout(rotateAngle);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        rotateAngleLabel = new QLabel(rotateAngle);
        rotateAngleLabel->setObjectName(QString::fromUtf8("rotateAngleLabel"));
        rotateAngleLabel->setEnabled(false);

        gridLayout_17->addWidget(rotateAngleLabel, 0, 0, 1, 1);

        rotateSlider = new QSlider(rotateAngle);
        rotateSlider->setObjectName(QString::fromUtf8("rotateSlider"));
        rotateSlider->setEnabled(false);
        rotateSlider->setMinimum(-360);
        rotateSlider->setMaximum(360);
        rotateSlider->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(rotateSlider, 0, 1, 1, 1);

        rotateAngleEdit = new QLineEdit(rotateAngle);
        rotateAngleEdit->setObjectName(QString::fromUtf8("rotateAngleEdit"));
        rotateAngleEdit->setEnabled(false);
        rotateAngleEdit->setMaximumSize(QSize(40, 16777215));

        gridLayout_17->addWidget(rotateAngleEdit, 0, 2, 1, 1);


        verticalLayout_6->addWidget(rotateAngle);

        line_4 = new QFrame(filterType);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_4);

        filterTypeSpecial1 = new QRadioButton(filterType);
        filterTypeSpecial1->setObjectName(QString::fromUtf8("filterTypeSpecial1"));

        verticalLayout_6->addWidget(filterTypeSpecial1);

        filterTypeSpecial2 = new QRadioButton(filterType);
        filterTypeSpecial2->setObjectName(QString::fromUtf8("filterTypeSpecial2"));

        verticalLayout_6->addWidget(filterTypeSpecial2);

        filterTypeSpecial3 = new QRadioButton(filterType);
        filterTypeSpecial3->setObjectName(QString::fromUtf8("filterTypeSpecial3"));

        verticalLayout_6->addWidget(filterTypeSpecial3);


        verticalLayout_5->addWidget(filterType);

        filterButton = new QPushButton(filterDockContents);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        verticalLayout_5->addWidget(filterButton);

        filterDockEmptySpace = new QWidget(filterDockContents);
        filterDockEmptySpace->setObjectName(QString::fromUtf8("filterDockEmptySpace"));
        sizePolicy2.setHeightForWidth(filterDockEmptySpace->sizePolicy().hasHeightForWidth());
        filterDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(filterDockEmptySpace);

        filterDock->setWidget(filterDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, filterDock);
        rayDock = new QDockWidget(MainWindow);
        rayDock->setObjectName(QString::fromUtf8("rayDock"));
        rayDockContents = new QWidget();
        rayDockContents->setObjectName(QString::fromUtf8("rayDockContents"));
        verticalLayout_4 = new QVBoxLayout(rayDockContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        rayAllOrNone = new QWidget(rayDockContents);
        rayAllOrNone->setObjectName(QString::fromUtf8("rayAllOrNone"));
        horizontalLayout = new QHBoxLayout(rayAllOrNone);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rayAllButton = new QPushButton(rayAllOrNone);
        rayAllButton->setObjectName(QString::fromUtf8("rayAllButton"));

        horizontalLayout->addWidget(rayAllButton);

        rayNoneButton = new QPushButton(rayAllOrNone);
        rayNoneButton->setObjectName(QString::fromUtf8("rayNoneButton"));

        horizontalLayout->addWidget(rayNoneButton);


        verticalLayout_4->addWidget(rayAllOrNone);

        rayFeatures = new QGroupBox(rayDockContents);
        rayFeatures->setObjectName(QString::fromUtf8("rayFeatures"));
        verticalLayout_11 = new QVBoxLayout(rayFeatures);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 5, -1, 5);
        raySuperSamping = new QCheckBox(rayFeatures);
        raySuperSamping->setObjectName(QString::fromUtf8("raySuperSamping"));

        verticalLayout_11->addWidget(raySuperSamping);

        raySuperSamples = new QWidget(rayFeatures);
        raySuperSamples->setObjectName(QString::fromUtf8("raySuperSamples"));
        sizePolicy.setHeightForWidth(raySuperSamples->sizePolicy().hasHeightForWidth());
        raySuperSamples->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(raySuperSamples);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(6);
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        raySuperSamplesLabel = new QLabel(raySuperSamples);
        raySuperSamplesLabel->setObjectName(QString::fromUtf8("raySuperSamplesLabel"));
        sizePolicy.setHeightForWidth(raySuperSamplesLabel->sizePolicy().hasHeightForWidth());
        raySuperSamplesLabel->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(raySuperSamplesLabel, 1, 1, 1, 1);

        raySuperSamplesTextbox = new QLineEdit(raySuperSamples);
        raySuperSamplesTextbox->setObjectName(QString::fromUtf8("raySuperSamplesTextbox"));
        raySuperSamplesTextbox->setEnabled(false);
        sizePolicy1.setHeightForWidth(raySuperSamplesTextbox->sizePolicy().hasHeightForWidth());
        raySuperSamplesTextbox->setSizePolicy(sizePolicy1);
        raySuperSamplesTextbox->setMinimumSize(QSize(40, 0));
        raySuperSamplesTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_7->addWidget(raySuperSamplesTextbox, 1, 0, 1, 1);


        verticalLayout_11->addWidget(raySuperSamples);

        rayAntiAliasing = new QCheckBox(rayFeatures);
        rayAntiAliasing->setObjectName(QString::fromUtf8("rayAntiAliasing"));

        verticalLayout_11->addWidget(rayAntiAliasing);

        rayShadows = new QCheckBox(rayFeatures);
        rayShadows->setObjectName(QString::fromUtf8("rayShadows"));

        verticalLayout_11->addWidget(rayShadows);

        rayTextureMapping = new QCheckBox(rayFeatures);
        rayTextureMapping->setObjectName(QString::fromUtf8("rayTextureMapping"));

        verticalLayout_11->addWidget(rayTextureMapping);

        rayReflection = new QCheckBox(rayFeatures);
        rayReflection->setObjectName(QString::fromUtf8("rayReflection"));

        verticalLayout_11->addWidget(rayReflection);

        rayRefraction = new QCheckBox(rayFeatures);
        rayRefraction->setObjectName(QString::fromUtf8("rayRefraction"));

        verticalLayout_11->addWidget(rayRefraction);

        rayMultiThreading = new QCheckBox(rayFeatures);
        rayMultiThreading->setObjectName(QString::fromUtf8("rayMultiThreading"));

        verticalLayout_11->addWidget(rayMultiThreading);

        rayUseKDTree = new QCheckBox(rayFeatures);
        rayUseKDTree->setObjectName(QString::fromUtf8("rayUseKDTree"));

        verticalLayout_11->addWidget(rayUseKDTree);


        verticalLayout_4->addWidget(rayFeatures);

        rayLighting = new QGroupBox(rayDockContents);
        rayLighting->setObjectName(QString::fromUtf8("rayLighting"));
        verticalLayout_9 = new QVBoxLayout(rayLighting);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, 5, -1, 5);
        rayPointLights = new QCheckBox(rayLighting);
        rayPointLights->setObjectName(QString::fromUtf8("rayPointLights"));

        verticalLayout_9->addWidget(rayPointLights);

        rayDirectionalLights = new QCheckBox(rayLighting);
        rayDirectionalLights->setObjectName(QString::fromUtf8("rayDirectionalLights"));

        verticalLayout_9->addWidget(rayDirectionalLights);

        raySpotLights = new QCheckBox(rayLighting);
        raySpotLights->setObjectName(QString::fromUtf8("raySpotLights"));

        verticalLayout_9->addWidget(raySpotLights);


        verticalLayout_4->addWidget(rayLighting);

        rayRenderButton = new QPushButton(rayDockContents);
        rayRenderButton->setObjectName(QString::fromUtf8("rayRenderButton"));

        verticalLayout_4->addWidget(rayRenderButton);

        rayStopRenderingButton = new QPushButton(rayDockContents);
        rayStopRenderingButton->setObjectName(QString::fromUtf8("rayStopRenderingButton"));

        verticalLayout_4->addWidget(rayStopRenderingButton);

        rayDockEmptySpace = new QWidget(rayDockContents);
        rayDockEmptySpace->setObjectName(QString::fromUtf8("rayDockEmptySpace"));
        sizePolicy2.setHeightForWidth(rayDockEmptySpace->sizePolicy().hasHeightForWidth());
        rayDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(rayDockEmptySpace);

        rayDock->setWidget(rayDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, rayDock);
        camtransDock = new QDockWidget(MainWindow);
        camtransDock->setObjectName(QString::fromUtf8("camtransDock"));
        camtransDockContents = new QWidget();
        camtransDockContents->setObjectName(QString::fromUtf8("camtransDockContents"));
        verticalLayout_10 = new QVBoxLayout(camtransDockContents);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        cameraOrbitCheckbox = new QCheckBox(camtransDockContents);
        cameraOrbitCheckbox->setObjectName(QString::fromUtf8("cameraOrbitCheckbox"));

        verticalLayout_10->addWidget(cameraOrbitCheckbox);

        cameraPosition = new QGroupBox(camtransDockContents);
        cameraPosition->setObjectName(QString::fromUtf8("cameraPosition"));
        gridLayout = new QGridLayout(cameraPosition);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        cameraPositionLabelX = new QLabel(cameraPosition);
        cameraPositionLabelX->setObjectName(QString::fromUtf8("cameraPositionLabelX"));
        cameraPositionLabelX->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cameraPositionLabelX, 1, 0, 1, 1);

        cameraPositionLabelY = new QLabel(cameraPosition);
        cameraPositionLabelY->setObjectName(QString::fromUtf8("cameraPositionLabelY"));
        cameraPositionLabelY->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cameraPositionLabelY, 1, 1, 1, 1);

        cameraPositionLabelZ = new QLabel(cameraPosition);
        cameraPositionLabelZ->setObjectName(QString::fromUtf8("cameraPositionLabelZ"));
        cameraPositionLabelZ->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cameraPositionLabelZ, 1, 2, 1, 1);

        transX = new QDial(cameraPosition);
        transX->setObjectName(QString::fromUtf8("transX"));
        transX->setMinimumSize(QSize(60, 60));
        transX->setMaximumSize(QSize(60, 60));
        transX->setMinimum(-360);
        transX->setMaximum(360);
        transX->setSingleStep(10);
        transX->setPageStep(30);
        transX->setOrientation(Qt::Horizontal);
        transX->setInvertedControls(true);
        transX->setWrapping(true);

        gridLayout->addWidget(transX, 0, 0, 1, 1);

        transY = new QDial(cameraPosition);
        transY->setObjectName(QString::fromUtf8("transY"));
        transY->setMinimumSize(QSize(60, 60));
        transY->setMaximumSize(QSize(60, 60));
        transY->setMinimum(-360);
        transY->setMaximum(360);
        transY->setSingleStep(10);
        transY->setPageStep(30);
        transY->setOrientation(Qt::Horizontal);
        transY->setInvertedControls(true);
        transY->setWrapping(true);

        gridLayout->addWidget(transY, 0, 1, 1, 1);

        transZ = new QDial(cameraPosition);
        transZ->setObjectName(QString::fromUtf8("transZ"));
        transZ->setMinimumSize(QSize(60, 60));
        transZ->setMaximumSize(QSize(60, 60));
        transZ->setMinimum(-360);
        transZ->setMaximum(360);
        transZ->setSingleStep(10);
        transZ->setPageStep(30);
        transZ->setOrientation(Qt::Horizontal);
        transZ->setInvertedControls(true);
        transZ->setWrapping(true);

        gridLayout->addWidget(transZ, 0, 2, 1, 1);


        verticalLayout_10->addWidget(cameraPosition);

        cameraRotation = new QGroupBox(camtransDockContents);
        cameraRotation->setObjectName(QString::fromUtf8("cameraRotation"));
        cameraRotation->setEnabled(true);
        verticalLayout_13 = new QVBoxLayout(cameraRotation);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(-1, 5, -1, 5);
        cameraRotation_2 = new QWidget(cameraRotation);
        cameraRotation_2->setObjectName(QString::fromUtf8("cameraRotation_2"));
        gridLayout_15 = new QGridLayout(cameraRotation_2);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setVerticalSpacing(18);
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        rotU = new QDial(cameraRotation_2);
        rotU->setObjectName(QString::fromUtf8("rotU"));
        rotU->setMinimumSize(QSize(60, 60));
        rotU->setMaximumSize(QSize(60, 60));
        rotU->setMinimum(-360);
        rotU->setMaximum(360);
        rotU->setSingleStep(10);
        rotU->setPageStep(30);
        rotU->setOrientation(Qt::Horizontal);
        rotU->setInvertedControls(true);
        rotU->setWrapping(true);

        gridLayout_15->addWidget(rotU, 0, 0, 1, 1);

        rotV = new QDial(cameraRotation_2);
        rotV->setObjectName(QString::fromUtf8("rotV"));
        rotV->setMinimumSize(QSize(60, 60));
        rotV->setMaximumSize(QSize(60, 60));
        rotV->setMinimum(-360);
        rotV->setMaximum(360);
        rotV->setSingleStep(10);
        rotV->setPageStep(30);
        rotV->setOrientation(Qt::Horizontal);
        rotV->setInvertedControls(true);
        rotV->setWrapping(true);

        gridLayout_15->addWidget(rotV, 0, 1, 1, 1);

        rotW = new QDial(cameraRotation_2);
        rotW->setObjectName(QString::fromUtf8("rotW"));
        rotW->setMinimumSize(QSize(60, 60));
        rotW->setMaximumSize(QSize(60, 60));
        rotW->setMinimum(-360);
        rotW->setMaximum(360);
        rotW->setSingleStep(10);
        rotW->setPageStep(30);
        rotW->setOrientation(Qt::Horizontal);
        rotW->setInvertedControls(true);
        rotW->setWrapping(true);

        gridLayout_15->addWidget(rotW, 0, 2, 1, 1);

        cameraRotationLabelYaw = new QLabel(cameraRotation_2);
        cameraRotationLabelYaw->setObjectName(QString::fromUtf8("cameraRotationLabelYaw"));
        cameraRotationLabelYaw->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(cameraRotationLabelYaw, 1, 0, 1, 1);

        cameraRotationLabelPitch = new QLabel(cameraRotation_2);
        cameraRotationLabelPitch->setObjectName(QString::fromUtf8("cameraRotationLabelPitch"));
        cameraRotationLabelPitch->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(cameraRotationLabelPitch, 1, 1, 1, 1);

        cameraRotationLabelRoll = new QLabel(cameraRotation_2);
        cameraRotationLabelRoll->setObjectName(QString::fromUtf8("cameraRotationLabelRoll"));
        cameraRotationLabelRoll->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(cameraRotationLabelRoll, 1, 2, 1, 1);


        verticalLayout_13->addWidget(cameraRotation_2);

        resetUpVector = new QPushButton(cameraRotation);
        resetUpVector->setObjectName(QString::fromUtf8("resetUpVector"));

        verticalLayout_13->addWidget(resetUpVector);


        verticalLayout_10->addWidget(cameraRotation);

        cameraResetAxis = new QGroupBox(camtransDockContents);
        cameraResetAxis->setObjectName(QString::fromUtf8("cameraResetAxis"));
        cameraResetAxis->setMinimumSize(QSize(0, 0));
        gridLayout_14 = new QGridLayout(cameraResetAxis);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        xAxisButton = new QPushButton(cameraResetAxis);
        xAxisButton->setObjectName(QString::fromUtf8("xAxisButton"));

        gridLayout_14->addWidget(xAxisButton, 0, 0, 1, 1);

        yAxisButton = new QPushButton(cameraResetAxis);
        yAxisButton->setObjectName(QString::fromUtf8("yAxisButton"));

        gridLayout_14->addWidget(yAxisButton, 1, 0, 1, 1);

        zAxisButton = new QPushButton(cameraResetAxis);
        zAxisButton->setObjectName(QString::fromUtf8("zAxisButton"));

        gridLayout_14->addWidget(zAxisButton, 0, 1, 1, 1);

        axonometricButton = new QPushButton(cameraResetAxis);
        axonometricButton->setObjectName(QString::fromUtf8("axonometricButton"));

        gridLayout_14->addWidget(axonometricButton, 1, 1, 1, 1);


        verticalLayout_10->addWidget(cameraResetAxis);

        cameraFrustum = new QWidget(camtransDockContents);
        cameraFrustum->setObjectName(QString::fromUtf8("cameraFrustum"));
        gridLayout_5 = new QGridLayout(cameraFrustum);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(5);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        cameraFovLabel = new QLabel(cameraFrustum);
        cameraFovLabel->setObjectName(QString::fromUtf8("cameraFovLabel"));

        gridLayout_5->addWidget(cameraFovLabel, 0, 0, 1, 1);

        cameraFovTextbox = new QLineEdit(cameraFrustum);
        cameraFovTextbox->setObjectName(QString::fromUtf8("cameraFovTextbox"));
        cameraFovTextbox->setMinimumSize(QSize(60, 0));
        cameraFovTextbox->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(cameraFovTextbox, 0, 3, 1, 1);

        cameraFovSlider = new QSlider(cameraFrustum);
        cameraFovSlider->setObjectName(QString::fromUtf8("cameraFovSlider"));
        cameraFovSlider->setMinimumSize(QSize(100, 0));
        cameraFovSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(cameraFovSlider, 0, 1, 1, 1);

        cameraNearLabel = new QLabel(cameraFrustum);
        cameraNearLabel->setObjectName(QString::fromUtf8("cameraNearLabel"));

        gridLayout_5->addWidget(cameraNearLabel, 1, 0, 1, 1);

        cameraNearTextbox = new QLineEdit(cameraFrustum);
        cameraNearTextbox->setObjectName(QString::fromUtf8("cameraNearTextbox"));
        cameraNearTextbox->setMinimumSize(QSize(60, 0));
        cameraNearTextbox->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(cameraNearTextbox, 1, 3, 1, 1);

        cameraFarLabel = new QLabel(cameraFrustum);
        cameraFarLabel->setObjectName(QString::fromUtf8("cameraFarLabel"));

        gridLayout_5->addWidget(cameraFarLabel, 2, 0, 1, 1);

        cameraFarTextbox = new QLineEdit(cameraFrustum);
        cameraFarTextbox->setObjectName(QString::fromUtf8("cameraFarTextbox"));
        cameraFarTextbox->setMinimumSize(QSize(60, 0));
        cameraFarTextbox->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(cameraFarTextbox, 2, 3, 1, 1);

        cameraNearSlider = new QSlider(cameraFrustum);
        cameraNearSlider->setObjectName(QString::fromUtf8("cameraNearSlider"));
        cameraNearSlider->setMinimumSize(QSize(100, 0));
        cameraNearSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(cameraNearSlider, 1, 1, 1, 1);

        cameraFarSlider = new QSlider(cameraFrustum);
        cameraFarSlider->setObjectName(QString::fromUtf8("cameraFarSlider"));
        cameraFarSlider->setMinimumSize(QSize(100, 0));
        cameraFarSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(cameraFarSlider, 2, 1, 1, 1);


        verticalLayout_10->addWidget(cameraFrustum);

        resetSliders = new QPushButton(camtransDockContents);
        resetSliders->setObjectName(QString::fromUtf8("resetSliders"));

        verticalLayout_10->addWidget(resetSliders);

        cameraAspectRatio = new QLabel(camtransDockContents);
        cameraAspectRatio->setObjectName(QString::fromUtf8("cameraAspectRatio"));

        verticalLayout_10->addWidget(cameraAspectRatio);

        label = new QLabel(camtransDockContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setWordWrap(true);

        verticalLayout_10->addWidget(label);

        cameraDockEmptySpace = new QWidget(camtransDockContents);
        cameraDockEmptySpace->setObjectName(QString::fromUtf8("cameraDockEmptySpace"));
        sizePolicy2.setHeightForWidth(cameraDockEmptySpace->sizePolicy().hasHeightForWidth());
        cameraDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_10->addWidget(cameraDockEmptySpace);

        camtransDock->setWidget(camtransDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, camtransDock);
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
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionRevert);
        menuFile->addAction(actionClear);
        menuFile->addAction(actionCopy3Dto2D);
        menuFile->addAction(actionUseOrbitingCamera);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(filterTypeEdgeDetect, SIGNAL(toggled(bool)), edgeDetectThreshold, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeBlur, SIGNAL(toggled(bool)), blurRadiusSlider, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeBlur, SIGNAL(toggled(bool)), blurRadiusTextbox, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeScale, SIGNAL(toggled(bool)), scaleTextboxX, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeScale, SIGNAL(toggled(bool)), scaleTextboxY, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeScale, SIGNAL(toggled(bool)), scaleSliderX, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeScale, SIGNAL(toggled(bool)), scaleSliderY, SLOT(setEnabled(bool)));
        QObject::connect(raySuperSamping, SIGNAL(toggled(bool)), raySuperSamplesTextbox, SLOT(setEnabled(bool)));
        QObject::connect(rayAllButton, SIGNAL(clicked()), MainWindow, SLOT(checkAllRayFeatures()));
        QObject::connect(rayNoneButton, SIGNAL(clicked()), MainWindow, SLOT(uncheckAllRayFeatures()));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), cameraRotation, SLOT(setDisabled(bool)));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), cameraPosition, SLOT(setDisabled(bool)));
        QObject::connect(xAxisButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxisX()));
        QObject::connect(yAxisButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxisY()));
        QObject::connect(axonometricButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxonometric()));
        QObject::connect(transX, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraTranslation()));
        QObject::connect(transY, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraTranslation()));
        QObject::connect(transZ, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraTranslation()));
        QObject::connect(rotU, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraRotationU()));
        QObject::connect(rotW, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraRotationN()));
        QObject::connect(rotV, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraRotationV()));
        QObject::connect(cameraNearSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraNearTextbox, SIGNAL(textChanged(QString)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraFarSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraFarTextbox, SIGNAL(textChanged(QString)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraFovSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraHeightAngle()));
        QObject::connect(cameraFovTextbox, SIGNAL(textChanged(QString)), MainWindow, SLOT(updateCameraHeightAngle()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(fileSave()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(fileOpen()));
        QObject::connect(rayRenderButton, SIGNAL(clicked()), MainWindow, SLOT(renderImage()));
        QObject::connect(actionNew, SIGNAL(triggered()), MainWindow, SLOT(fileNew()));
        QObject::connect(filterTypeBlur, SIGNAL(toggled(bool)), blurRadiusLabel, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeRotate, SIGNAL(toggled(bool)), rotateAngleLabel, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeRotate, SIGNAL(toggled(bool)), rotateSlider, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeRotate, SIGNAL(toggled(bool)), rotateAngleEdit, SLOT(setEnabled(bool)));
        QObject::connect(resetUpVector, SIGNAL(clicked()), MainWindow, SLOT(resetUpVector()));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), cameraResetAxis, SLOT(setDisabled(bool)));
        QObject::connect(showSceneviewInstead, SIGNAL(toggled(bool)), shapeType, SLOT(setDisabled(bool)));
        QObject::connect(rayStopRenderingButton, SIGNAL(clicked()), canvas2D, SLOT(cancelRender()));
        QObject::connect(filterButton, SIGNAL(clicked()), MainWindow, SLOT(filterImage()));
        QObject::connect(actionCopy3Dto2D, SIGNAL(triggered()), MainWindow, SLOT(fileCopy3Dto2D()));
        QObject::connect(zAxisButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxisZ()));
        QObject::connect(actionClear, SIGNAL(triggered()), MainWindow, SLOT(clearImage()));
        QObject::connect(filterTypeScale, SIGNAL(toggled(bool)), scaleLabelX, SLOT(setEnabled(bool)));
        QObject::connect(filterTypeScale, SIGNAL(toggled(bool)), scaleLabelY, SLOT(setEnabled(bool)));
        QObject::connect(actionRevert, SIGNAL(triggered()), MainWindow, SLOT(revertImage()));
        QObject::connect(resetSliders, SIGNAL(clicked()), MainWindow, SLOT(resetSliders()));
        QObject::connect(actionUseOrbitingCamera, SIGNAL(toggled(bool)), cameraOrbitCheckbox, SLOT(setChecked(bool)));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), actionUseOrbitingCamera, SLOT(setChecked(bool)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CS 123: Introduction to Computer Graphics", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRevert->setText(QCoreApplication::translate("MainWindow", "&Revert Image", nullptr));
#if QT_CONFIG(shortcut)
        actionRevert->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy3Dto2D->setText(QCoreApplication::translate("MainWindow", "Copy &3D tab to 2D tab", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "&Clear Image", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "Clear Image", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUseOrbitingCamera->setText(QCoreApplication::translate("MainWindow", "&Use Orbiting Camera", nullptr));
#if QT_CONFIG(shortcut)
        actionUseOrbitingCamera->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tab2D), QCoreApplication::translate("MainWindow", "2D", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3D), QCoreApplication::translate("MainWindow", "3D", nullptr));
        brushDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Br&ush", nullptr));
        brushType->setTitle(QCoreApplication::translate("MainWindow", "Brush Type", nullptr));
        brushTypeConstant->setText(QCoreApplication::translate("MainWindow", "Constant", nullptr));
        brushTypeLinear->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        brushTypeQuadratic->setText(QCoreApplication::translate("MainWindow", "&Quadratic", nullptr));
        brushTypeSmudge->setText(QCoreApplication::translate("MainWindow", "S&mudge", nullptr));
        brushTypeSpecial1->setText(QCoreApplication::translate("MainWindow", "Special &1", nullptr));
        brushTypeSpecial2->setText(QCoreApplication::translate("MainWindow", "Special 2", nullptr));
        brushColor->setTitle(QCoreApplication::translate("MainWindow", "Brush Color", nullptr));
        brushColorLabelGreen->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        brushColorLabelBlue->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        brushColorLabelRed->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        brushColorLabelAlpha->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        brushRadiusTextbox->setText(QString());
        brushRadiusLabel->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        brushAlphaBlendingCheckbox->setText(QCoreApplication::translate("MainWindow", "No alpha blending", nullptr));
        shapesDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Shapes/Scene&view", nullptr));
        showSceneviewInstead->setText(QCoreApplication::translate("MainWindow", "Show sceneview instead", nullptr));
        shapeType->setTitle(QCoreApplication::translate("MainWindow", "Shape Type", nullptr));
        shapeTypeCube->setText(QCoreApplication::translate("MainWindow", "Cube", nullptr));
        shapeTypeCone->setText(QCoreApplication::translate("MainWindow", "Cone", nullptr));
        shapeTypeSphere->setText(QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        shapeTypeCylinder->setText(QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        shapeTypeTorus->setText(QCoreApplication::translate("MainWindow", "Torus", nullptr));
        shapeTypeSpecial1->setText(QCoreApplication::translate("MainWindow", "Special 1", nullptr));
        shapeTypeSpecial2->setText(QCoreApplication::translate("MainWindow", "Special 2", nullptr));
        shapeParameters->setTitle(QCoreApplication::translate("MainWindow", "Shape Parameters", nullptr));
        shapeParameterLabel1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        shapeParameterLabel2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        shapeParameterLabel3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        useLightingCheckbox->setText(QCoreApplication::translate("MainWindow", "Use lighting", nullptr));
        drawWireframeCheckbox->setText(QCoreApplication::translate("MainWindow", "Draw wireframe", nullptr));
        drawNormalsCheckbox->setText(QCoreApplication::translate("MainWindow", "Draw normals", nullptr));
        filterDock->setWindowTitle(QCoreApplication::translate("MainWindow", "F&ilter", nullptr));
        filterType->setTitle(QCoreApplication::translate("MainWindow", "Filter Type", nullptr));
        filterTypeEdgeDetect->setText(QCoreApplication::translate("MainWindow", "Edge Detect", nullptr));
        edgeDetectSensitivityLabel->setText(QCoreApplication::translate("MainWindow", "Sensitivity", nullptr));
        filterTypeBlur->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        blurRadiusLabel->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        filterTypeScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        scaleLabelX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        scaleLabelY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        filterTypeRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        rotateAngleLabel->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        filterTypeSpecial1->setText(QCoreApplication::translate("MainWindow", "Special 1", nullptr));
        filterTypeSpecial2->setText(QCoreApplication::translate("MainWindow", "Special 2", nullptr));
        filterTypeSpecial3->setText(QCoreApplication::translate("MainWindow", "Special 3", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Filter!", nullptr));
        rayDock->setWindowTitle(QCoreApplication::translate("MainWindow", "&Ray", nullptr));
        rayAllButton->setText(QCoreApplication::translate("MainWindow", "All", nullptr));
        rayNoneButton->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        rayFeatures->setTitle(QCoreApplication::translate("MainWindow", "Features", nullptr));
        raySuperSamping->setText(QCoreApplication::translate("MainWindow", "Super sampling", nullptr));
        raySuperSamplesLabel->setText(QCoreApplication::translate("MainWindow", "sqrt(samples)", nullptr));
        raySuperSamplesTextbox->setText(QString());
        rayAntiAliasing->setText(QCoreApplication::translate("MainWindow", "Anti-aliasing", nullptr));
        rayShadows->setText(QCoreApplication::translate("MainWindow", "Shadows", nullptr));
        rayTextureMapping->setText(QCoreApplication::translate("MainWindow", "Texture Mapping", nullptr));
        rayReflection->setText(QCoreApplication::translate("MainWindow", "Reflection", nullptr));
        rayRefraction->setText(QCoreApplication::translate("MainWindow", "Refraction", nullptr));
        rayMultiThreading->setText(QCoreApplication::translate("MainWindow", "Multithreading", nullptr));
        rayUseKDTree->setText(QCoreApplication::translate("MainWindow", "Use KD tree", nullptr));
        rayLighting->setTitle(QCoreApplication::translate("MainWindow", "Lighting", nullptr));
        rayPointLights->setText(QCoreApplication::translate("MainWindow", "Point lights", nullptr));
        rayDirectionalLights->setText(QCoreApplication::translate("MainWindow", "Directional lights", nullptr));
        raySpotLights->setText(QCoreApplication::translate("MainWindow", "Spot lights", nullptr));
        rayRenderButton->setText(QCoreApplication::translate("MainWindow", "Render!", nullptr));
        rayStopRenderingButton->setText(QCoreApplication::translate("MainWindow", "Stop rendering", nullptr));
        camtransDock->setWindowTitle(QCoreApplication::translate("MainWindow", "&Camtrans", nullptr));
        cameraOrbitCheckbox->setText(QCoreApplication::translate("MainWindow", "Use orbit camera instead", nullptr));
        cameraPosition->setTitle(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        cameraPositionLabelX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        cameraPositionLabelY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        cameraPositionLabelZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        cameraRotation->setTitle(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        cameraRotationLabelYaw->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        cameraRotationLabelPitch->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        cameraRotationLabelRoll->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        resetUpVector->setText(QCoreApplication::translate("MainWindow", "Reset up vector", nullptr));
        cameraResetAxis->setTitle(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        xAxisButton->setText(QCoreApplication::translate("MainWindow", "X axis", nullptr));
        yAxisButton->setText(QCoreApplication::translate("MainWindow", "Y axis", nullptr));
        zAxisButton->setText(QCoreApplication::translate("MainWindow", "Z axis", nullptr));
        axonometricButton->setText(QCoreApplication::translate("MainWindow", "Axonometric", nullptr));
        cameraFovLabel->setText(QCoreApplication::translate("MainWindow", "FOV", nullptr));
        cameraNearLabel->setText(QCoreApplication::translate("MainWindow", "Near", nullptr));
        cameraFarLabel->setText(QCoreApplication::translate("MainWindow", "Far", nullptr));
        resetSliders->setText(QCoreApplication::translate("MainWindow", "Reset FOV / Near / Far", nullptr));
        cameraAspectRatio->setText(QCoreApplication::translate("MainWindow", "Aspect ratio:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Resize the window to change the aspect ratio.", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuToolbars->setTitle(QCoreApplication::translate("MainWindow", "&Toolbars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
