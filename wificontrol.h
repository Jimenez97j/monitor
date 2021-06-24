#ifndef WIFICONTROL_H
#define WIFICONTROL_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QThread>

class WifiControl : public QObject
{
    Q_OBJECT
public:
    enum Interfaces{
        WIFI,
        ETH
    };
    Q_ENUM(Interfaces);
    QString PATH_WIFI = "/etc/wpa_supplicant/wpa_supplicant.conf";
    //QString WIFI = "wlan0";
    //QString ETH = "eth0";
    explicit WifiControl(QObject *parent = nullptr);
    bool interface_state(Interfaces interface);
    QString public_ip();
    QString get_wifi_level(int level);
    QStringList get_available_wifi_list();
    QString search_param(QString frame, QString param);
    QStringList get_saved_wifi_list();
    bool change_wifi_pass(QString ssid, QString pass);
    bool check_saved_ssid(QString ssid);
    QString execute_process(QString command,QString params, bool sudo);
    QString get_current_ssid();
    void add_wifi(QString ssid, QString pass);
    bool delete_wifi(QString ssid);
    bool set_interface(Interfaces interface, bool state);
    void habilita_wifi();

signals:

};

#endif // WIFICONTROL_H
