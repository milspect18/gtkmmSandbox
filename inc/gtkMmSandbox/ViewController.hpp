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
            this->builder = Gtk::Builder::create_from_file(uiFile);
            this->builder->get_widget(rootWidget, this->root);

            this->root->signal_key_release_event().connect(
                sigc::mem_fun(*this, &ViewController::fullscreenBtnReleased)
            );
        }

        virtual ~ViewController() {
            if (this->root) {
                delete this->root;
            }
        }

        Gtk::Window *getRoot() {
            return this->root;
        }

        bool fullscreenBtnReleased(GdkEventKey *e) {
            if (e->type == GDK_KEY_RELEASE && e->keyval == GDK_KEY_F11) {
                if (this->isFullScreen) {
                    this->root->unfullscreen();
                    this->isFullScreen = false;
                } else {
                    this->root->fullscreen();
                    this->isFullScreen = true;
                }

                return true;
            }

            return false;
        }

    private:
        bool isFullScreen = false;
        Gtk::Window *root;

    protected:
        Glib::RefPtr<Gtk::Builder> builder;

        virtual void connectSignals() = 0;
        virtual void fetchWidgets() = 0;
};

#endif