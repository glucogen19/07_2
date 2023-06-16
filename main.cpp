#include <QtWidgets>
#include "road.h"

Road road;

class MainWindow : public QMainWindow {
	public:
		MainWindow();
		void startButtonClick();
		void stopButtonClick();
		void outButtonClick();
	private:
		QLabel      *textLabel;
		QPushButton *startButton;
		QPushButton *stopButton;
		QPushButton *outButton;
		
};

MainWindow :: MainWindow(){
	setFixedSize(600,200);
	setWindowTitle("Test QPushButton v7.2");
	QFont fontLabel("Courier", 18, QFont::Normal);
	QFont fontButton("Times", 18, QFont::Bold);
	
	textLabel = new QLabel("Test QLabel", this);
	textLabel->setGeometry(0, 0, 400, 50);
	textLabel->setFont(fontLabel);
	
	startButton = new QPushButton("Start", this);
	startButton->setGeometry(20, 50, 70, 50);
	startButton->setFont(fontButton);
	
	stopButton = new QPushButton("Stop", this);
	stopButton->setGeometry(110, 50, 70, 50);
	stopButton->setFont(fontButton);
	
	outButton = new QPushButton("Out", this);
	outButton->setGeometry(200, 50, 70, 50);
	outButton->setFont(fontButton);
	
	connect(startButton, &QPushButton::clicked, 
			this, &MainWindow::startButtonClick); 
	connect(stopButton, &QPushButton::clicked,
			this, &MainWindow::stopButtonClick);
	connect(outButton, &QPushButton::clicked,
			this, &MainWindow::outButtonClick);
			
}

void MainWindow::startButtonClick(){
	textLabel->setText("Clicked: Start");
}

void MainWindow::stopButtonClick(){
	textLabel->setText("Clicked: Stop");
}

void MainWindow::outButtonClick(){
	double a = road.Length;
	QString b = QString::number(a);
	b.append(" - Length, ");
	b.append( QString::number(road.Width));
	b.append(" - Width");
	textLabel->setText(b);
}

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
	
}