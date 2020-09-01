#include "gtkmm.h"
#include "MainViewController.hpp"
#include <filesystem>
#include <iostream>


std::string getExecPath() {
    char execPath[PATH_MAX];
    ssize_t len = ::readlink("/proc/self/exe", execPath, sizeof(execPath));

    if (len == -1) {
        std::cout << "Unable to locate program executable" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string pathWithExeName(std::move(execPath));
    auto lastSlashLoc = pathWithExeName.find_last_of('/');

    if (lastSlashLoc == std::string::npos) {
        std::cout << "Unable to parse dir from exe pathname" << std::endl;
        exit(EXIT_FAILURE);
    }

    return std::move(pathWithExeName.substr(0, pathWithExeName.find_last_of('/')));
}


int main(int argc, char *argv[]) {
    std::string uiFileName = "main.glade";
    std::string uiFilePath = getExecPath();

    MainViewController vc(uiFilePath + "/" + uiFileName);

    auto app = Gtk::Application::create("com.pricetecdesigns.gtkmmsandbox");

    return app->run(*vc.getRoot());
}