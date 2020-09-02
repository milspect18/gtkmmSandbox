/**
 *  MainWindow ViewController class
 */

#include "MainViewController.hpp"
#include <algorithm>


MainViewController::MainViewController(const std::string &uiFile)
    : ViewController(uiFile, "MainWindow")
{
    this->fetchWidgets();
    this->connectSignals();
}


void MainViewController::decreaseBtnClicked() {
    this->progress->set_value(std::max(0.0, this->progress->get_value() - 1.0));
}


void MainViewController::increaseBtnClicked() {
    this->progress->set_value(std::min(100.0, this->progress->get_value() + 1.0));
}


void MainViewController::zeroPercentClicked() {
    this->progress->set_value(0.0);
    this->menuPopover->hide();
}


void MainViewController::fiftyPercentClicked() {
    this->progress->set_value(this->progress->get_max_value() / 2.0);
    this->menuPopover->hide();
}


void MainViewController::oneHundredPercentClicked() {
    this->progress->set_value(this->progress->get_max_value());
    this->menuPopover->hide();
}


void MainViewController::connectSignals() {
    this->decreaseBtn->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::decreaseBtnClicked)
    );

    this->increaseBtn->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::increaseBtnClicked)
    );

    this->zeroProgress->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::zeroPercentClicked)
    );

    this->halfProgress->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::fiftyPercentClicked)
    );

    this->fullProgress->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::oneHundredPercentClicked)
    );
}


void MainViewController::fetchWidgets() {
    this->builder->get_widget("decreaseBtn", this->decreaseBtn);
    this->builder->get_widget("increaseBtn", this->increaseBtn);
    this->builder->get_widget("progress", this->progress);
    this->builder->get_widget("menuPopover", this->menuPopover);
    this->builder->get_widget("zeroProgress", this->zeroProgress);
    this->builder->get_widget("halfProgress", this->halfProgress);
    this->builder->get_widget("fullProgress", this->fullProgress);
}