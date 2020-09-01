/**
 *  MainWindow ViewController class
 */

#ifndef MAIN_VIEW_CONTROLLER_HPP
#define MAIN_VIEW_CONTROLLER_HPP

#include "ViewController.hpp"

class MainViewController: public ViewController {
    public:
        MainViewController(const std::string &uiFile);

        void decreaseBtnClicked();
        void increaseBtnClicked();

    private:
        Gtk::Button *decreaseBtn;
        Gtk::Button *increaseBtn;
        Gtk::LevelBar *progress;

        void connectSignals();
};

#endif