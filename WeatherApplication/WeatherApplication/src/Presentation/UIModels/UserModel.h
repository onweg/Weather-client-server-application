#ifndef USERMODEL_H
#define USERMODEL_H

#include <QObject>
#include <QString>

class UserModel : public QObject
{
    Q_OBJECT
public:
    explicit UserModel(QObject *parent = nullptr);
    QString getUsername() const;
    QString getPassword() const;
    void setUsername(const QString &username);
    void setPassword(const QString &password);
private:
    QString username_ = "";
    QString password_ = "";

signals:

};

#endif // USERMODEL_H
