#ifndef CONNECTIONDATABASEMODEL_H
#define CONNECTIONDATABASEMODEL_H

#include <QObject>

class ConnectionDatabaseModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString dsHost READ dsHost WRITE setDsHost NOTIFY dsHostChanged FINAL)
    Q_PROPERTY(QString dsPort READ dsPort WRITE setDsPort NOTIFY dsPortChanged FINAL)
    Q_PROPERTY(QString dsDatabaseName READ dsDatabaseName WRITE setDsDatabaseName NOTIFY dsDatabaseNameChanged FINAL)
    Q_PROPERTY(QString dsUsername READ dsUsername WRITE setDsUsername NOTIFY dsUsernameChanged FINAL)
    Q_PROPERTY(QString dsPassword READ dsPassword WRITE setDsPassword NOTIFY dsPasswordChanged FINAL)
public:
    explicit ConnectionDatabaseModel(QObject *parent = nullptr);

    QString dsHost() const;
    void setDsHost(const QString &newDsHost);

    QString dsPort() const;
    void setDsPort(const QString &newDsPort);

    QString dsDatabaseName() const;
    void setDsDatabaseName(const QString &newDsDatabaseName);

    QString dsUsername() const;
    void setDsUsername(const QString &newDsUsername);

    QString dsPassword() const;
    void setDsPassword(const QString &newDsPassword);

signals:
    void dsHostChanged();
    void dsPortChanged();
    void dsDatabaseNameChanged();
    void dsUsernameChanged();
    void dsPasswordChanged();
private:
    QString _dsHost;
    QString _dsPort;
    QString _dsDatabaseName;
    QString _dsUsername;
    QString _dsPassword;
};

#endif // CONNECTIONDATABASEMODEL_H
