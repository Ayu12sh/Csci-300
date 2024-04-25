// Ayush,Samyog,Prabin 04/24/2024

#ifndef CREADFILE_H
#define CREADFILE_H

#include <QObject>
#include <QStack>

class CReadFile : public QObject
{
    Q_OBJECT
public:
    explicit CReadFile(QObject *parent = nullptr);
// Function to read and organize movies
    // This function reads movies and organizes them into odd and even stacks based on their order.
    // The odd-indexed movies are pushed onto the stackOdd, while the even-indexed movies are pushed onto the stackEven.
    Q_INVOKABLE void readAndOrganizeMovies();

signals:
// Signal emitted when movies are loaded and organized
    // Emits two stacks: one for odd-indexed movies and one for even-indexed movies.
    void moviesLoaded(QStack<QString> stackOdd, QStack<QString> stackEven);
};

#endif 
