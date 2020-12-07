#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Databinding.h"
#include "SupportCanvas3D.h"
#include "Settings.h"
#include "QSettings"
#include "CS123XmlSceneParser.h"
#include <math.h>
#include <QFileDialog>
#include <QMessageBox>

#include <unistd.h>

#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Make sure the settings are loaded before the UI
    settings.loadSettingsOrDefaults();

    QGLFormat qglFormat;
    qglFormat.setVersion(4, 3);
    qglFormat.setProfile(QGLFormat::CoreProfile);
    qglFormat.setSampleBuffers(true);
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(ui->canvas3D);
    m_canvas3D = new SupportCanvas3D(qglFormat, this);
    gridLayout->addWidget(m_canvas3D, 0, 1);
    ui->tabWidget->setCurrentWidget(ui->tab3D);

    // Restore the UI settings
    QSettings qtSettings("CS123", "CS123");
    restoreGeometry(qtSettings.value("geometry").toByteArray());
    restoreState(qtSettings.value("windowState").toByteArray());

    // Resize the window because the window is huge since all docks were visible.
    resize(1000, 600);

    // Bind the UI elements to their properties in the global Settings object, using binding
    // objects to simplify the code.  Each binding object connects to its UI elements and keeps
    // the UI and its setting in sync.

    QList<QAction*> actions;

#define SETUP_ACTION(dock, key) \
    actions.push_back(ui->dock->toggleViewAction()); \
    actions.back()->setShortcut(QKeySequence(key));

    SETUP_ACTION(shapesDock,    "CTRL+3");

    ui->menuToolbars->addActions(actions);
#undef SETUP_ACTION

    dataBind();
    QList<QRadioButton*> a;
    a.clear();
    a += ui->texture2;
    a += ui->texture1;
    a += ui->texture4;
    a += ui->intersectSphere;
    a += ui->intersectHole;
    foreach (QRadioButton *rb, a)
        connect(rb, SIGNAL(clicked()), this, SLOT(activateCanvas3D()));

    QWidget *widget = ui->tabWidget->currentWidget();
    ui->tabWidget->setCurrentWidget(ui->tab3D);
    show();
    ui->tabWidget->setCurrentWidget(widget);
    show();

}

MainWindow::~MainWindow()
{
    foreach (DataBinding *b, m_bindings)
        delete b;
    foreach (QButtonGroup *bg, m_buttonGroups)
        delete bg;
    delete ui;
}

void MainWindow::dataBind() {
    // Brush dock
#define BIND(b) { \
    DataBinding *_b = (b); \
    m_bindings.push_back(_b); \
    assert(connect(_b, SIGNAL(dataChanged()), this, SLOT(settingsChanged()))); \
}

    QButtonGroup *textureButtonGroup = new QButtonGroup;

    m_buttonGroups.push_back(textureButtonGroup);
    BIND(ChoiceBinding::bindRadioButtons(
            textureButtonGroup,
            4,
            settings.textureType,
            ui->texture1,
            ui->texture2,
            ui->texture3,
            ui->texture4))

    QButtonGroup *intersectionButtonGroup = new QButtonGroup;

    m_buttonGroups.push_back(intersectionButtonGroup);
    BIND(ChoiceBinding::bindRadioButtons(
            intersectionButtonGroup,
            3,
            settings.intersectionType,
            ui->intersectNone,
            ui->intersectSphere,
            ui->intersectHole))


    BIND(IntBinding::bindSliderAndTextbox(
        ui->clothParameterSlider1, ui->clothParameterTextbox1, settings.shapeParameter1, 10.f, 100.f))
    BIND(IntBinding::bindSliderAndTextbox(
        ui->clothParameterSlider2, ui->clothParameterTextbox2, settings.shapeParameter2, 2.f, 10.f))
    BIND(BoolBinding::bindCheckbox(ui->useLightingCheckbox, settings.useLighting))
    BIND(BoolBinding::bindCheckbox(ui->drawWireframeCheckbox, settings.drawWireframe))
    BIND(BoolBinding::bindCheckbox(ui->drawNormalsCheckbox, settings.drawNormals))
    BIND(BoolBinding::bindCheckbox(ui->clipLeftCorner, settings.clipLeftCorner))
    BIND(BoolBinding::bindCheckbox(ui->clipRightCorner, settings.clipRightCorner))
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->intersectionRadiusSlider, ui->intersectionRadiusTextbox, settings.intersectionRadius, 0.f, 0.5f))
    BIND(ChoiceBinding::bindTabs(ui->tabWidget, settings.currentTab))
    BIND(BoolBinding::bindCheckbox(ui->upwardsWind, settings.upWind))
    BIND(BoolBinding::bindCheckbox(ui->leftwardsWind, settings.leftWind))
    BIND(BoolBinding::bindCheckbox(ui->rightwardsWind, settings.rightWind))

#undef BIND

    // make sure the aspect ratio updates when m_canvas3D changes size
    connect(m_canvas3D, SIGNAL(aspectRatioChanged()), this, SLOT(updateAspectRatio()));
}

void MainWindow::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e); // allow the superclass to handle this for the most part...

    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // Save the settings before we quit
    settings.saveSettings();
    QSettings qtSettings("CS123", "CS123");
    qtSettings.setValue("geometry", saveGeometry());
    qtSettings.setValue("windowState", saveState());

    QMainWindow::closeEvent(event);
}

void MainWindow::updateAspectRatio() {
    // Update the aspect ratio text so the aspect ratio will be correct even if the
    // 3D canvas isn't visible (the 3D canvas isn't resized when it isn't visible)
    QSize activeTabSize = ui->tabWidget->currentWidget()->size();
    float aspectRatio = static_cast<float>(activeTabSize.width()) / static_cast<float>(activeTabSize.height());
//    ui->cameraAspectRatio->setText(QString("Aspect ratio: %1").arg(aspectRatio));
}


void MainWindow::settingsChanged() {
    m_canvas3D->settingsChanged();
}

void MainWindow::renderCloth() {
    int timerId = startTimer(10);
    //m_canvas3D->updateCloth();
}

void MainWindow::timerEvent(QTimerEvent *event) {
    std::cout << "timer event";
    m_canvas3D->updateCloth();
}

void MainWindow::setAllEnabled(bool enabled) {
    QList<QWidget *> widgets;
    widgets += ui->shapesDock;

    QList<QAction *> actions;
    actions += ui->actionQuit;

    foreach (QWidget *widget, widgets)
        widget->setEnabled(enabled);
    foreach (QAction *action, actions)
        action->setEnabled(enabled);
}

void MainWindow::activateCanvas3D() {
    ui->tabWidget->setCurrentWidget(ui->tab3D);
}

void MainWindow::setCameraAxisX() {
    m_canvas3D->setCameraAxisX();
}

void MainWindow::setCameraAxisY() {
    m_canvas3D->setCameraAxisY();
}

void MainWindow::setCameraAxisZ() {
    m_canvas3D->setCameraAxisZ();
}

void MainWindow::updateCameraTranslation() {
    m_canvas3D->updateCameraTranslation();
}

void MainWindow::updateCameraRotationN() {
    m_canvas3D->updateCameraRotationN();
}

void MainWindow::updateCameraRotationV() {
    m_canvas3D->updateCameraRotationV();
}

void MainWindow::updateCameraRotationU() {
    m_canvas3D->updateCameraRotationU();
}

void MainWindow::resetUpVector() {
    m_canvas3D->resetUpVector();
}

void MainWindow::updateCameraClip() {
    m_canvas3D->updateCameraClip();
}

void MainWindow::updateCameraHeightAngle() {
    m_canvas3D->updateCameraHeightAngle();
}

void MainWindow::setCameraAxonometric() {
    m_canvas3D->setCameraAxonometric();
}
