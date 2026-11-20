#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//zona de definicion de funciones (juegos)


int main(){

    //acá vamos a definir variables
    int opMen1; //validador ingreso del menu
    bool in_jug = 1; //ciclo while para validar cantidad de jugadores
    bool nom_jug = 1; //ciclo while para confirmar los nombres
    int cant_jug; //cantidad de jugadores en juego

    cout << "Bienvenido a la casa de Apuestas mas bacana del pais"
         << endl << "Encontraras juegos como blackjack, ruleta o carrera de caballos"
         << endl << endl;

    cout <<
    "1. Nueva partida" << endl <<
    "2. Continuar partida guardada" << endl <<
    "3. Consultar historial" << endl <<
    "Cualquier otro valor. Salir" << endl;

    cout << "Selecciona una opcion: ";
    cin >> opMen1;


    switch(opMen1){

        case 1: {

            // Nueva partida

            cout << "Por favor ingresa la cantidad de jugadores que habra durante el juego"
                 << endl;

            cout << "Ingresa si son 1, 2, 3 o 4 jugadores: ";
            cin >> cant_jug;


            // Validar cantidad de jugadores

            while(in_jug){

                if(cant_jug > 0 && cant_jug <= 4){

                    cout << "Entendido, jugaran: " << cant_jug << " personas"
                         << endl << "Que empiece la diversion!" << endl;

                    in_jug = 0;

                }else{

                    cout << "El valor dado no corresponde a ninguna cantidad de jugadores disponible."
                         << endl << "Vuelve a ingresar la cantidad de jugadores: ";

                    cin >> cant_jug;

                }
            }


            // Vectores y saldo inicial

            vector<string> nombres;
            vector<int> saldos;
            vector<bool> estado;

            const int SALDO_INICIAL = 1000;

            string nombre;
            char confirmar;

            cin.ignore(1000, '\n');


            // Validacion de los nombres registrados

            while(nom_jug){

                // Limpiar vectores para evitar duplicados

                nombres.clear();
                saldos.clear();
                estado.clear();

                cout << endl << "Ingresa el nombre de los " << cant_jug
                     << " jugadores, iniciando por el numero 1" << endl;


                // Solicitar nombres y asignar saldos

                for(int i = 0; i < cant_jug; i++){

                    cout << "Jugador #" << i + 1 << ": ";
                    getline(cin, nombre);

                    nombres.push_back(nombre);
                    saldos.push_back(SALDO_INICIAL);
                    estado.push_back(true);

                }


                // Determinar el ancho del nombre mas largo

                int anchoNombre = 7;

                for(int i = 0; i < cant_jug; i++){

                    if(nombres[i].length() > anchoNombre){

                        anchoNombre = nombres[i].length();

                    }

                }


                // Mostrar los datos registrados

                cout << endl;
                cout << "============================================" << endl;
                cout << "          JUGADORES REGISTRADOS" << endl;
                cout << "============================================" << endl;

                cout << left << setw(anchoNombre + 4) << "Jugador"
                     << right << setw(16) << "Saldo (creditos)" << endl;

                cout << string(anchoNombre + 20, '-') << endl;


                for(int i = 0; i < cant_jug; i++){

                    cout << left << setw(anchoNombre + 4) << nombres[i]
                         << right << setw(16) << saldos[i] << endl;

                }

                cout << "============================================" << endl;


                // Confirmar los datos

                cout << endl << "Los datos registrados son correctos? (S/N): ";
                cin >> confirmar;


                // Validar respuesta

                while(confirmar != 'S' && confirmar != 's' &&
                      confirmar != 'N' && confirmar != 'n'){

                    cout << "Respuesta incorrecta. Ingresa S para si o N para no: ";
                    cin >> confirmar;

                }

                cin.ignore(1000, '\n');


                // Aceptar o volver a registrar

                if(confirmar == 'S' || confirmar == 's'){

                    cout << endl << "Datos confirmados correctamente."
                         << endl << "Que empiece la partida!" << endl;

                    nom_jug = 0;

                }else{

                    cout << endl << "Volvamos a registrar los nombres." << endl;

                }

            }


            // INICIO DEL JUEGO CON N JUGADORES

            bool competenciaActiva = true;
            int opjuego;
            int ronda = 1;
            char confirmarRetiro;


            while(competenciaActiva){

                cout << endl;
                cout << "============================================" << endl;
                cout << "                 RONDA " << ronda << endl;
                cout << "============================================" << endl;


                // Recorrer todos los jugadores

                for(int i = 0; i < cant_jug; i++){

                    // Comprobar si el jugador sigue activo y tiene dinero

                    if(estado[i] && saldos[i] > 0){

                        bool turnoTerminado = false;


                        // Mantener el turno hasta completar una accion

                        while(!turnoTerminado){

                            cout << endl;
                            cout << "============================================" << endl;
                            cout << "Turno de: " << nombres[i] << endl;
                            cout << "Saldo disponible: " << saldos[i] << endl;
                            cout << "============================================" << endl;

                            cout << "Selecciona el juego por favor:" << endl;

                            cout << "1. Blackjack" << endl
                                 << "2. Ruleta" << endl
                                 << "3. Carrera de Caballos" << endl
                                 << "4. Dados" << endl
                                 << "5. Tragamonedas" << endl
                                 << "6. Retirarse de la competencia" << endl;

                            cout << "Selecciona una opcion: ";
                            cin >> opjuego;


                            // Validar seleccion del juego

                            while(opjuego < 1 || opjuego > 6){

                                cout << "Opcion incorrecta. Selecciona una opcion del 1 al 6: ";
                                cin >> opjuego;

                            }


                            // Seleccionar juego

                            switch(opjuego){

                                case 1:

                                    cout << "Has seleccionado Blackjack." << endl;
                                    cout << "El juego estara disponible proximamente." << endl;
                                    turnoTerminado = true;
                                    break;


                                case 2:

                                    cout << "Has seleccionado Ruleta." << endl;
                                    cout << "El juego estara disponible proximamente." << endl;
                                    turnoTerminado = true;
                                    break;


                                case 3:

                                    cout << "Has seleccionado Carrera de Caballos." << endl;
                                    cout << "El juego estara disponible proximamente." << endl;
                                    turnoTerminado = true;
                                    break;


                                case 4:

                                    cout << "Has seleccionado Dados." << endl;
                                    cout << "El juego estara disponible proximamente." << endl;
                                    turnoTerminado = true;
                                    break;


                                case 5:

                                    cout << "Has seleccionado Tragamonedas." << endl;
                                    cout << "El juego estara disponible proximamente." << endl;
                                    turnoTerminado = true;
                                    break;


                                case 6:

                                    cout << "Confirmas que deseas abandonar la competencia? (S/N): ";
                                    cin >> confirmarRetiro;


                                    // Validar confirmacion

                                    while(confirmarRetiro != 'S' && confirmarRetiro != 's' &&
                                          confirmarRetiro != 'N' && confirmarRetiro != 'n'){

                                        cout << "Respuesta incorrecta. Ingresa S o N: ";
                                        cin >> confirmarRetiro;

                                    }


                                    if(confirmarRetiro == 'S' || confirmarRetiro == 's'){

                                        estado[i] = false;

                                        cout << nombres[i] << " ha abandonado la competencia." << endl;

                                        turnoTerminado = true;

                                    }else{

                                        cout << "Continua tu participacion." << endl;

                                    }

                                    break;

                            }

                        }

                    }

                }


                // Comprobar cuantos jugadores siguen activos

                int jugadoresActivos = 0;
                int indiceGanador = -1;

                for(int i = 0; i < cant_jug; i++){

                    if(estado[i] && saldos[i] > 0){

                        jugadoresActivos++;

                        indiceGanador = i;

                    }

                }


                // Comprobar si todos abandonaron o quedaron sin dinero

                if(jugadoresActivos == 0){

                    cout << endl << "No quedan jugadores activos." << endl;
                    cout << "La competencia ha finalizado sin ganador. mejoren bots" << endl;

                    competenciaActiva = false;

                }


                // Comprobar si queda un solo jugador en modo multijugador

                else if(cant_jug > 1 && jugadoresActivos == 1){

                    cout << endl;
                    cout << "============================================" << endl;
                    cout << "          FIN DE LA COMPETENCIA" << endl;
                    cout << "============================================" << endl;

                    cout << "El ganador es: " << nombres[indiceGanador] << endl;
                    cout << "Saldo final: " << saldos[indiceGanador] << " creditos" << endl;

                    competenciaActiva = false;

                }


                // Si quedan varios jugadores o es modo individual

                else{

                    cout << endl;
                    cout << "Todos los jugadores activos han completado sus turnos." << endl;
                    cout << "Finalizando ronda " << ronda << endl;

                    ronda++;

                }

            }

            break;
        }


        case 2:

            cout << "Esta opcion estara disponible proximamente" << endl;
            break;


        case 3:

            cout << "Esta opcion estara disponible proximamente" << endl;
            break;


        default:

            cout << "Chao pescao" << endl;
            return 0;

    }


    return 0;
}
