#include "CFantasyMovies.h"
#include <QRandomGenerator>

CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent) {}

void CFantasyMovies::selectMovie(int number)
{
    QStack<QString> *selectedStack;
    if (number % 2 == 0) {
        selectedStack = &stackEven;
    } else {
        selectedStack = &stackOdd;
    }

    if (selectedStack->isEmpty()) {
        emit displayMovie("No other available films");
        return;
    }

    QString selectedMovie = selectedStack->top();

    emit displayMovie(selectedMovie);
}
