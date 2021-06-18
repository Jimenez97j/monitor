#include "teclado.h"
#include "ui_teclado.h"
#include <QTimer>

#include <qdebug.h>
bool mayus = false;
bool shift = false;
int tiempo=0;
Teclado::Teclado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teclado)
{
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(1);
}

Teclado::~Teclado()
{
    delete ui;
}

void Teclado::funcionActivacionTimer(){
    tiempo=tiempo+1;//Timer animacion de puntos en "Realizando Analisis

    //Animación de puntos en label "Realizando Analisis..."
    if(tiempo==200){
        //ui->BORRAR->setStyleSheet("background-image: url(:/imagenes/borrar.png);background-repeat:none;border: none");
        ui->BORRAR->setIcon(QIcon(":/imagenes/borrar.png"));
        tiempo=0;

    }
}


void Teclado::on_BORRAR_pressed()
{
    //ui->BORRAR->setStyleSheet("background-image: url(:/imagenes/borrar2.png);background-repeat:none;border: none");
    ui->BORRAR->setIcon(QIcon(":/imagenes/borrar2.png"));
    emit erase_names();
    tiempo=0;


}

void Teclado::on_Q_pressed()
{
    if(shift){
        emit letter_press("¬");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("Q");
        }else{
            emit letter_press("q");
        }
    }

}

void Teclado::on_W_pressed()
{
    if(shift){
        emit letter_press("^");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("W");
        }else{
            emit letter_press("w");
        }
    }
}

void Teclado::on_E_pressed()
{
    if(shift){
        emit letter_press("~");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));


    }else{
        if(mayus){
            emit letter_press("E");
        }else{
            emit letter_press("e");
        }
    }
}

void Teclado::on_MAYUS_pressed()
{
    if(mayus){
        mayus = false;
        ui->MAYUS->setStyleSheet("color:#CDCDCD;background-color: rgb(30, 30, 30); font: 11pt 'Ubuntu Condensed';");
    }else{
        mayus = true;
        ui->MAYUS->setStyleSheet("color:green;background-color: rgb(30, 30, 30); font: 11pt 'Ubuntu Condensed';");
    }
}

void Teclado::on_R_pressed()
{
    if(shift){
        emit letter_press("|");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("R");
        }else{
            emit letter_press("r");
        }
    }
}

void Teclado::on_T_pressed()
{
    if(shift){
        emit letter_press("[");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("T");
        }else{
            emit letter_press("t");
        }
    }
}

void Teclado::on_Y_pressed()
{
    if(shift){
        emit letter_press("]");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("Y");
        }else{
            emit letter_press("y");
        }
    }
}

void Teclado::on_U_pressed()
{
    if(shift){
        emit letter_press("<");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("U");
        }else{
            emit letter_press("u");
        }
    }
}

void Teclado::on_I_pressed()
{
    if(shift){
        emit letter_press(">");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("I");
        }else{
            emit letter_press("i");
        }
    }
}

void Teclado::on_O_pressed()
{
    if(shift){
        emit letter_press("{");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("O");
        }else{
            emit letter_press("o");
        }
    }
}

void Teclado::on_P_pressed()
{
    if(shift){
        emit letter_press("}");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("P");
        }else{
            emit letter_press("p");
        }
    }
}

void Teclado::on_A_pressed()
{
    if(shift){
        emit letter_press("@");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("A");
        }else{
            emit letter_press("a");
        }
    }
}

void Teclado::on_S_pressed()
{
    if(shift){
        emit letter_press("#");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("S");
        }else{
            emit letter_press("s");
        }
    }
}

void Teclado::on_D_pressed()
{
    if(shift){
        emit letter_press("&");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("D");
        }else{
            emit letter_press("d");
        }
    }
}

void Teclado::on_F_pressed()
{
    if(shift){
        emit letter_press("*");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("F");
        }else{
            emit letter_press("f");
        }
    }
}

void Teclado::on_G_pressed()
{
    if(shift){
        emit letter_press("-");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("G");
        }else{
            emit letter_press("g");
        }
    }
}

void Teclado::on_H_pressed()
{
    if(shift){
        emit letter_press("+");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("H");
        }else{
            emit letter_press("h");
        }
    }
}

void Teclado::on_J_pressed()
{
    if(shift){
        emit letter_press("=");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("J");
        }else{
            emit letter_press("j");
        }
    }
}

void Teclado::on_K_pressed()
{
    if(shift){
        emit letter_press("(");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("K");
        }else{
            emit letter_press("k");
        }
    }
}

void Teclado::on_L_pressed()
{
    if(shift){
        emit letter_press(")");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("L");
        }else{
            emit letter_press("l");
        }
    }
}

void Teclado::on_ENE_pressed()
{
    if(shift){
        emit letter_press("%");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("Ñ");
        }else{
            emit letter_press("ñ");
        }
    }
}

void Teclado::on_Z_pressed()
{
    if(shift){
        emit letter_press("_");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("Z");
        }else{
            emit letter_press("z");
        }
    }
}

void Teclado::on_X_pressed()
{
    if(shift){
        emit letter_press("$");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("X");
        }else{
            emit letter_press("x");
        }
    }
}

void Teclado::on_C_pressed()
{
    if(shift){
        emit letter_press("''");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("C");
        }else{
            emit letter_press("c");
        }
    }
}

void Teclado::on_V_pressed()
{
    if(shift){
        emit letter_press("'");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("V");
        }else{
            emit letter_press("v");
        }
    }
}

void Teclado::on_B_pressed()
{
    if(shift){
        emit letter_press(":");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("B");
        }else{
            emit letter_press("b");
        }
    }
}

void Teclado::on_N_pressed()
{
    if(shift){
        emit letter_press(";");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("N");
        }else{
            emit letter_press("n");
        }
    }
}

void Teclado::on_M_pressed()
{
    if(shift){
        emit letter_press("/");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        if(mayus){
            emit letter_press("M");
        }else{
            emit letter_press("m");
        }
    }
}

void Teclado::on_SPACE_pressed()
{
    emit letter_press(" ");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));


}


void Teclado::on_HIDE_pressed()
{
    ui->HIDE->setStyleSheet("background-image: url(:/imagenes/ocultar2.png);background-repeat:none;border: none");
    this->close();
    ui->HIDE->setStyleSheet("background-image: url(:/imagenes/ocultar.png);background-repeat:none;border: none");

}

void Teclado::on_N7_pressed()
{
    if(shift){
        emit letter_press("°");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        emit letter_press("7");
    }
}

void Teclado::on_N8_pressed()
{
    if(shift){
        emit letter_press("!");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        emit letter_press("8");
    }
}

void Teclado::on_N9_pressed()
{
    if(shift){
        emit letter_press("¡");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        emit letter_press("9");
    }
}

void Teclado::on_N4_pressed()
{
    if(shift){
        emit letter_press("?");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        emit letter_press("4");
    }
}

void Teclado::on_N5_pressed()
{
    if(shift){
        emit letter_press("¿");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        emit letter_press("5");
    }
}

void Teclado::on_N6_pressed()
{
    if(shift){
        emit letter_press("¨");
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        emit letter_press("6");
    }
}

void Teclado::on_N1_pressed()
{
    emit letter_press("1");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

}

void Teclado::on_N2_pressed()
{
    emit letter_press("2");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

}

void Teclado::on_N3_pressed()
{
    emit letter_press("3");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

}

void Teclado::on_N0_pressed()
{
    emit letter_press("0");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

}

void Teclado::on_PUNTO_pressed()
{
    emit letter_press(".");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

}

void Teclado::on_COMA_pressed()
{
    emit letter_press(",");
    //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
    ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

}

void Teclado::on_N0_2_pressed()
{
    if(shift){
        shift = false;
        //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift.png);background-repeat:none;border: none");
        ui->N0_2->setIcon(QIcon(":/imagenes/shift.png"));

    }else{
        shift = true;
        ui->N0_2->setIcon(QIcon(":/imagenes/shift2.png"));
         //ui->N0_2->setStyleSheet("background-image: url(:/imagenes/shift2.png);background-repeat:none;border: none");
    }
}


void Teclado::on_Teclado_finished(int result)
{
    emit close_keyboard();
}
