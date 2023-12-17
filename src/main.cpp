#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QMessageBox>
#include <QDir>

#include <cstdlib>
#include <unistd.h>
#include <pwd.h>


int main(int argc, char *argv[]) {
	// We create the main application
	QApplication app(argc, argv);

	// Create the main window and maximize it
	QMainWindow main_window;
	main_window.setWindowTitle("Commander-SFZ");
	main_window.showMaximized();

	// Get the home directory and store into a QString
	QString home_directory = QString(getenv("HOME"));
	if (home_directory.isEmpty()) {
		struct passwd *pw = getpwuid(getuid());
		if (pw) {
			home_directory = QString(pw->pw_dir);
		} else {
			QMessageBox::critical(nullptr, "Error", "Failed to determine home directory.");
			return EXIT_FAILURE; // Exit with an error code
		}
	}

	QString config_directory = QDir(home_directory + "/.config/commander-sfz").absolutePath();
	QDir().mkpath(config_directory); // Create the directory if it doesn't exist

	// Start the application event loop
	int result = app.exec();

	return result;
}
