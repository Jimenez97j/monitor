#include "wificontrol.h"

/**
 * @brief WifiControl::WifiControl
 * @param parent
 * Create the object instance
 */
WifiControl::WifiControl(QObject *parent) : QObject(parent)
{
}

/**
 * @brief WifiControl::interface_state
 * @param interface
 * @return state interface
 */
bool WifiControl::interface_state(WifiControl::Interfaces interface){
    QString interface_s;
    if(interface == WifiControl::Interfaces::ETH){
        interface_s = "eth0";
    }
    else if(interface == WifiControl::Interfaces::WIFI){
        interface_s = "wlan0";
    }
    QString result;
    if(interface_s == "eth0"){
        result = execute_process("cat", "/sys/class/net/eth0/operstate",false);
        qDebug() << result;
    }
    else if(interface_s == "wlan0"){
        result = execute_process("cat", "/sys/class/net/wlan0/operstate",false);
        //result = execute_process("sudo", "rfkill list",true);
        qDebug() << result;
    }
    else{
        qDebug() << " [WIFI] interfaz inexistente";
    }

    if(result == "up\n" or result == "dormant\n"){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief WifiControl::public_ip
 * @return get public ip
 */
QString WifiControl::public_ip(){
    QString result = execute_process("wget", "-qO- ifconfig.me/ip",false);
    return result;
    qDebug() << result;
}

/**
 * @brief WifiControl::get_wifi_level
 * @param level
 * @return QString with quality level
 */
QString WifiControl::get_wifi_level(int level){
    if(level > -76){
        return "excelente";
    }
    else if(level > -89 && level <= -77){
        return "buena";
    }
    else if(level > -97 && level <= -90){
        return "mala";
    }
    else{
        return "baja";
    }
}

/**
 * @brief WifiControl::get_available_wifi_list
 * @return A QStringList with available wifi
 */
QStringList WifiControl::get_available_wifi_list(){
    QStringList listWifiTemp;
    QStringList listWifi = {};
    QString out = execute_process("iwlist", "wlan0 scan",false);
    //qDebug() << out;
    listWifiTemp = out.split("Cell");
    for(int i=0; i < listWifiTemp.size(); i++){
        QString ttempName;
        int signalValue;
        bool ssid_ready = false;
        bool signal_ready = false;
        //obtener el nombre
        QStringList tempName = search_param(listWifiTemp.at(i), "ESSID:").split(":");
        if(tempName.size() >= 2){
            int tempSize = tempName.at(1).size() - 2 ;
            ttempName = tempName.at(1).mid(1,tempSize);
            ssid_ready = true;
        }
        //obtener level
        QStringList tempSignal = search_param(listWifiTemp.at(i), "Signal level").split(" ");
        if(tempSignal.size() > 25){
            signalValue = tempSignal.at(23).split("=").at(1).toInt();
            signal_ready = true;
        }
        //
        if(ssid_ready && signal_ready){
            listWifi.append(ttempName + ";" + get_wifi_level(signalValue));
        }
    }
    return listWifi;
}

/**
 * @brief WifiControl::search_param
 * @param frame
 * @param param
 * @return QString with a line containing the param searching
 */
QString WifiControl::search_param(QString frame, QString param){
    QStringList temp = frame.split("\n");
    QString res = "";
    for(int i=0; i < temp.size(); i++){
        if(temp.at(i).contains(param)){
            res = temp.at(i);
            break;
        }
    }
    return res;
}

/**
 * @brief WifiControl::execute_process
 * @param command
 * @param params
 * @return QString with command output or info error
 */
QString WifiControl::execute_process(QString command,QString params,bool debug)
{
    QProcess process;
    qDebug()<<"Comando:" <<command<< params;

    QStringList params_p = params.split(" ");
    process.start(command, params_p, QIODevice::ReadWrite);

    /*if(sudo)
    {
        QString tmp = params_p.join(", ");
        tmp = " -c ,"+ command + " , "+tmp;
        qDebug()<<"Comando:"<<tmp;
        params_p = tmp.split(",");
        process.startDetached("/bin/sh ",params_p);
        //process.start("sudo ",params_p, QIODevice::ReadWrite);
    }
    else
    {
        comando= command +" "+ params;
        qDebug()<<"Comando:"<<comando;

    }*/
    process.waitForFinished();
    QString out = process.readAllStandardOutput();
    QString err = process.readAllStandardError();

    if(debug)
    {
        qDebug()<<"out"<<out;
        qDebug()<<"err"<<err;
    }

    if(err.size() == 0){
        return out;
    }
    else{
        return "ERROR:" + err;
    }
}

/**
 * @brief WifiControl::get_saved_wifi_list
 * @return QStringList with saved wifi-network
 */
QStringList WifiControl::get_saved_wifi_list(){
    QStringList temp = {};
    QFile file(WifiControl::PATH_WIFI);
    if(!file.exists()){
        qDebug() << "El archivo no existe";
    }
    QString line;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line.contains("ssid")){
                QString ssid = line.split("=").at(1).mid(1, line.split("=").at(1).size() - 2 );
                temp.append(ssid);
            }
        }
    }
    file.close();
    return temp;
}

/**
 * @brief WifiControl::get_current_ssid
 * @return QString with the current ssid-wifi
 */
QString WifiControl::get_current_ssid(){
    QString prog = "/bin/bash";
    QStringList arguments;
    arguments <<"-c" << "iw dev wlan0 link | grep SSID | awk '{print $2}'";
    QProcess proc;
    proc.start(prog , arguments);
    proc.waitForFinished();
    QString out = proc.readAllStandardOutput();
    QString err = proc.readAllStandardError();
    if(err.size() == 0){
        return out.mid(0, out.size()-1);
    }
    else{
        return "";
    }
}

/**
 * @brief WifiControl::check_saved_ssid
 * @param ssid
 * @return Verify if the ssid is saved
 */
bool WifiControl::check_saved_ssid(QString ssid){
    bool found = false;
    QFile file(WifiControl::PATH_WIFI);
    if(!file.exists()){
        qDebug() << "El archivo no existe";
        return false;
    }
    QString line;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line.contains(ssid)){
                found = true;
                break;
            }
        }
    }
    file.close();
    return found;
}

/**
 * @brief WifiControl::set_interface
 * @param interface
 * @param state
 * @return state interface
 */
bool WifiControl::set_interface(Interfaces interface, bool state){
    QString interface_s;
    if(interface == WifiControl::Interfaces::ETH){
        interface_s = "eth0";
    }
    else if(interface == WifiControl::Interfaces::WIFI){
        interface_s = "wlan0";
    }

    if(state){
        //QProcess::execute("sudo ip link set "+ interface_s + " up");
        //QString resultado = execute_process("sudo","ip link set "+ interface_s + " up",true);
        QString resultado = execute_process("sudo","rfkill unblock wifi",true);
        qDebug()<<"rfkill unblock wifi"<<resultado;
       // QThread::msleep(5000);
    }
    else{
        //QString resultado = execute_process("sudo","ip link set "+ interface_s + " down",true);
        QString resultado = execute_process("sudo","rfkill block wifi",true);
        qDebug()<<"rfkill block wifi"<<resultado;
        //QProcess::execute("sudo ip link set "+ interface_s + " down");
    }
    QThread::msleep(500);
    if(interface_state(interface)){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief WifiControl::delete_wifi
 * @param ssid
 * @return If ssid was erased
 */
bool WifiControl::delete_wifi(QString ssid){
    //QProcess::execute("sudo killall wpa_supplicant");
    QString resultado = execute_process("sudo","killall wpa_supplicant",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","/bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;

    QFile file(WifiControl::PATH_WIFI);
    if(!file.exists()){
        qDebug() << "El archivo no existe";
        return false;
    }

    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QString all = file.readAll();
    QStringList lines = all.split("\n");
    QStringList newLines = {};
    file.close();
    int counter = 0;
    bool found = false;
    for(int i=0; i < lines.size(); i++){
        counter++;
        if(lines.at(i).contains(ssid)){
            found = true;
            break;
        }
    }
    QFile newfile(WifiControl::PATH_WIFI);
    if(!newfile.exists()){
        qDebug() << "El archivo no existe";
    }


    if(found){
        newfile.open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
        QTextStream out(&newfile);
        for(int i=0; i < lines.size(); i++){
            if(i < counter - 2 || i >= counter + 4){
                newLines.append(lines.at(i));
                out << lines.at(i) << endl;
            }
        }
        newfile.close();
        qDebug()<<counter<<lines[counter+2];
        if(lines[counter+2].contains("disabled=0"))
        {
            qDebug()<<"Borra la activa";
            habilita_wifi();
        }
        else
        {
            qDebug()<<"No era la activa";
            QThread::msleep(500);
            resultado = execute_process("sudo","wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf",true);
            qDebug()<<resultado;
        }
    }
    //habilita_wifi();

    /*resultado = execute_process("sudo","systemctl restart wpa_supplicant.service",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","systemctl restart dhcpcd.service",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","/bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;*/

    /*QProcess::execute(QString("sudo systemctl restart wpa_supplicant.service"));
    QProcess::execute(QString("sudo systemctl restart dhcpcd.service"));
    QProcess::execute(QString("sudo /bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf"));*/

    QThread::msleep(8000);
    if(check_saved_ssid(ssid)){
        return false;
    }
    return true;
}

/**
 * @brief WifiControl::add_wifi
 * @param ssid
 * @param pass
 */
void WifiControl::add_wifi(QString ssid, QString pass){
    //QProcess::execute("sudo killall wpa_supplicant");
    QString resultado = execute_process("sudo","killall wpa_supplicant",true);
    qDebug()<<resultado;

    QFile file(WifiControl::PATH_WIFI);
    if(!file.exists()){
        qDebug() << "El archivo no existe";
    }
    file.open(QIODevice::Text | QIODevice::ReadOnly);

    QString all = file.readAll();
    QStringList lines = all.split("\n");
    for (int i=0 ; i< lines.length();i++)
    {
        if(lines[i].contains("disabled=0")){

            lines[i].replace(QString("disabled=0"), QString("disabled=1"));
            break;
        }
    }
    QFile newfile(WifiControl::PATH_WIFI);
    if(!newfile.exists()){
        qDebug() << "El archivo no existe";
        return;
    }
    newfile.open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream out(&newfile);
    for(int i=0; i < lines.size(); i++){
        out << lines.at(i) << endl;
    }
    newfile.close();
    /*0
    QString all = file.readAll();
    all.replace(QString("disabled=0"), QString("disabled=1"));
    QFile newfile(WifiControl::PATH_WIFI);
    if(!newfile.exists()){
        qDebug() << "El archivo no existe";
        return;
    }
    QStringList lines = all.split("\n");
    newfile.open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream out(&newfile);
    for(int i=0; i < lines.size(); i++){
        out << lines.at(i) << endl;
    }
    newfile.close(); */

    QFile fileadd(WifiControl::PATH_WIFI);
    if(!fileadd.exists()){
        qDebug() << "El archivo no existe";
    }
    fileadd.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream addNetwork(&fileadd);
    QStringList addLines = {"", "network={", "        ssid=\""+ssid+"\"", "        psk=\""+pass+"\"", "        key_mgmt=WPA-PSK", "        disabled=0", "}"}; //, "    priority=1"
    for(int i=0; i < addLines.size(); i++){
        addNetwork << addLines.at(i) << endl;
    }
    fileadd.close();

    /*QProcess::execute(QString("sudo systemctl restart wpa_supplicant.service"));
    QProcess::execute(QString("sudo systemctl restart dhcpcd.service"));
    QProcess::execute(QString("sudo /bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf"));*/
    QThread::msleep(500);

    resultado = execute_process("sudo","wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;

    /*resultado = execute_process("sudo","systemctl restart wpa_supplicant.service",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","systemctl restart dhcpcd.service",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","/bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;*/


    QThread::msleep(8000);

}

void WifiControl::habilita_wifi()
{
    //QProcess::execute("sudo killall wpa_supplicant");
    QString resultado = execute_process("sudo","killall wpa_supplicant",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","/bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;
    QFile file(WifiControl::PATH_WIFI);
    if(!file.exists()){
        qDebug() << "El archivo no existe";
    }
    file.open(QIODevice::Text | QIODevice::ReadOnly
              );
    QString all = file.readAll();
    QStringList lines = all.split("\n");
    for (int i=0 ; i< lines.length();i++)
    {
        if(lines[i].contains("disabled=1")){

            lines[i].replace(QString("disabled=1"), QString("disabled=0"));
            break;
        }
    }
    QFile newfile(WifiControl::PATH_WIFI);
    if(!newfile.exists()){
        qDebug() << "El archivo no existe";
        return;
    }
    newfile.open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream out(&newfile);
    for(int i=0; i < lines.size(); i++){
        out << lines.at(i) << endl;
    }
    newfile.close();
    QThread::msleep(500);

    resultado = execute_process("sudo","wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;

}

/**
 * @brief WifiControl::change_wifi_pass
 * @param ssid
 * @param pass
 * @return If pass was modified
 */
bool WifiControl::change_wifi_pass(QString ssid, QString pass){
    QProcess::execute("sudo killall wpa_supplicant");
    QFile file(WifiControl::PATH_WIFI);
    if(!file.exists()){
        qDebug() << "El archivo no existe";
        return false;
    }
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QString all = file.readAll();
    QStringList lines = all.split("\n");
    file.close();
    int counter = 0;
    bool found = false;
    for(int i=0; i < lines.size(); i++){
        counter++;
        if(lines.at(i).contains(ssid)){
            found = true;
            break;
        }
    }

    if(found){
        QFile newfile(WifiControl::PATH_WIFI);
        if(!newfile.exists()){
            qDebug() << "El archivo no existe";
            return false;
        }

        lines[counter] = "        psk=\"" + pass + "\"";


        newfile.open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
        QTextStream out(&newfile);
        for(int i=0; i < lines.size(); i++){
            out << lines.at(i) << endl;
        }
        newfile.close();
    }
    /*QProcess::execute(QString("sudo systemctl restart wpa_supplicant.service"));
    QProcess::execute(QString("sudo systemctl restart dhcpcd.service"));
    QProcess::execute(QString("sudo /bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf"));*/
    /*QString resultado = execute_process("sudo","systemctl restart wpa_supplicant.service",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","systemctl restart dhcpcd.service",true);
    qDebug()<<resultado;
    resultado = execute_process("sudo","/bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;*/

    QThread::msleep(500);
    QString resultado = execute_process("sudo","wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf",true);
    qDebug()<<resultado;

    //QThread::msleep(8000);
    return found;
}
