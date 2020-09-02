/**
 *  MainWindow ViewController class
 */

#include "MainViewController.hpp"
#include <algorithm>


MainViewController::MainViewController(const std::string &uiFile)
    : ViewController(uiFile, "MainWindow")
{
    this->builder->get_widget("decreaseBtn", this->decreaseBtn);
    this->builder->get_widget("increaseBtn", this->increaseBtn);
    this->builder->get_widget("progress", this->progress);
    this->builder->get_widget("headerBar", this->hdrBar);

    this->connectSignals();
}


void MainViewController::decreaseBtnClicked() {
    this->progress->set_value(std::max(0.0, this->progress->get_value() - 1.0));
}


void MainViewController::increaseBtnClicked() {
    this->progress->set_value(std::min(100.0, this->progress->get_value() + 1.0));
}


void MainViewController::connectSignals() {
    this->decreaseBtn->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::decreaseBtnClicked)
    );

    this->increaseBtn->signal_clicked().connect(
        sigc::mem_fun(*this, &MainViewController::increaseBtnClicked)
    );
}
