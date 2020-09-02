/**
 *  Top level ViewController class
 */

#ifndef VIEW_CONTROLLER_HPP
#define VIEW_CONTROLLER_HPP

#include "gtkmm.h"
#include <string>

class ViewController {
    public:
        ViewController(const std::string &uiFile, const std::string &rootWidget) {
            this->builder = builder = Gtk::Builder::create_from_file(uiFile);
            this->builder->get_widget(rootWidget, this->root);
        }

        virtual ~ViewController() {
            if (this->root) {
                delete this->root;
            }
        }

        Gtk::Window *getRoot() {
            return this->root;
        }

    private:
        Gtk::Window *root;

    protected:
        Glib::RefPtr<Gtk::Builder> builder;

        virtual void connectSignals() = 0;
        virtual void fetchWidgets() = 0;
};

#endif