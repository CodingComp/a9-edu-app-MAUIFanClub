#include "circuitelementsmenu.h"
#include "ui_circuitelementsmenu.h"

circuitElementsMenu::circuitElementsMenu(CircuitManager *circuitManager, QWidget *parent)
    : circuitManager(circuitManager)
    , ui(new Ui::circuitElementsMenu)
{
    ui->setupUi(this);
    x.push_back(ui->inputsGrid);
    x.push_back(ui->logicGatesGrid);

    this->move(QPoint(20, 200));

    for (QWidget *currentWidget : x) {
        currentWidget->setHidden(true);
    }
}

circuitElementsMenu::~circuitElementsMenu()
{
    delete ui;
}

void circuitElementsMenu::on_CircuitElementsButton_clicked()
{
    if (!ui->elementsList->isHidden()) {
        ui->elementsList->setHidden(true);
    } else {
        ui->elementsList->setHidden(false);
    }
}

void circuitElementsMenu::on_logicGatesButton_clicked()
{
    if (!ui->logicGatesGrid->isHidden()) {
        ui->logicGatesGrid->setHidden(true);
    } else {
        for (QWidget *currentWidget : x) {
            currentWidget->setHidden(true);
        }
        ui->logicGatesGrid->setHidden(false);
    }
}

void circuitElementsMenu::on_inputsButton_clicked()
{
    if (!ui->inputsGrid->isHidden()) {
        ui->inputsGrid->setHidden(true);
    } else {
        for (QWidget *currentWidget : x) {
            currentWidget->setHidden(true);
        }
        ui->inputsGrid->setHidden(false);
    }
}

void circuitElementsMenu::on_andGateBtn_clicked()
{
    circuitManager->createAndGate();
}

void circuitElementsMenu::on_orGateBtn_clicked()
{
    circuitManager->createOrGate();
}

void circuitElementsMenu::on_nandGateBtn_clicked()
{
    circuitManager->createNAndGate();
}

void circuitElementsMenu::on_norGateBtn_clicked()
{
    circuitManager->createNOrGate();
}

void circuitElementsMenu::on_newInputBtn_clicked()
{
    circuitManager->createInputNode();
}

void circuitElementsMenu::on_newOutputBtn_clicked()
{
    circuitManager->createOutputNode();
}

void circuitElementsMenu::on_runBtn_clicked()
{
    circuitManager->run();
}
