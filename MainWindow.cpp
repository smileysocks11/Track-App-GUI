#include <iostream>
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QtGUI>
#include <QMenuBar>
#include <QDialog>
#include <QPushButton>
#include <QInputDialog>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QApplication>
#include "MAINWINDOW.h";
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// MainWindow accepts no arguments
// runs functions to create menus and their actions

MainWindow::MainWindow()
{
	create_menus();
	
}
// create_menus accepts no arguments
// adds the menus to the bar of the gui

void MainWindow::create_menus()
{
	about_menu = menuBar()->addMenu(tr("&about"));
	add_menu = menuBar()->addMenu(tr("&add"));
	throw_menu = menuBar()->addMenu(tr("&begin throwing"));
	lb_menu = menuBar()->addMenu(tr("&view leaderboard"));
	adjust_menu = menuBar()->addMenu(tr("&manually adjust athletes"));

}



// test accepts no arguments
// creates a messagebox

void MainWindow::about()
{
	QMessageBox::information(this, "", "");

}
 
// create_actions accepts no arguments
// creates the actions for each of the menus in the bar
string MainWindow::create_actions(Athletes a[], int flights, int athletes, int rounds)
{
	string add;

	// creates action pointers and connect it to the test function
	QAction* about_action = about_menu->addAction("view a message about TrackApp");
	connect(about_action, &QAction::triggered, this, &MainWindow::about);

	QAction* add_action = add_menu->addAction("add athletes");
	
	// fix this so that it emits something once addathlete is runned
	connect(add_action, &QAction::triggered, this, [=] { MainWindow::addAthlete();
	});

	// it's breaking here, fix the connect to pass arguments
	QAction* throw_action = throw_menu->addAction("start throwing");
	connect(throw_action, &QAction::triggered, this, [=] {MainWindow::throwTurns(a, flights, athletes, rounds);
	});

	return add;
}






