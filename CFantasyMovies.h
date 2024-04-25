// Ayush,Samyog,Prabin 04/24/2024

#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include <QStack>

class CFantasyMovies : public QObject
{
    Q_OBJECT
public:
// Constructor
    explicit CFantasyMovies(QObject *parent = nullptr);
// Function to select a movie
    Q_INVOKABLE void selectMovie(int number);

signals:
    void displayMovie(QString movieTitle);

private:
    QStack<QString> stackOdd;
    QStack<QString> stackEven;
};

#endif
