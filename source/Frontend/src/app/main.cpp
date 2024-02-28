#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello QT cmake project" << std::endl;
  QApplication a(argc, argv);
  return a.exec();
}
