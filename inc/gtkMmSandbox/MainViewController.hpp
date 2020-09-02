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
        void zeroPercentClicked();
        void fiftyPercentClicked();
        void oneHundredPercentClicked();
        void newOptSelected();

    protected:
        void connectSignals() override;
        void fetchWidgets() override;

    private:
        Gtk::Button *decreaseBtn = nullptr;
        Gtk::Button *increaseBtn = nullptr;
        Gtk::LevelBar *progress = nullptr;
        Gtk::Popover *menuPopover = nullptr;
        Gtk::Button *zeroProgress = nullptr;
        Gtk::Button *halfProgress = nullptr;
        Gtk::Button *fullProgress = nullptr;
        Gtk::ComboBoxText *optSelector = nullptr;
};

#endif