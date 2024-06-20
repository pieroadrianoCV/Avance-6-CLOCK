#include <iostream>
#include <queue>
#include "./BufferManager.cpp"
using namespace std;

struct Requerimiento {
    int numPagina;
    char accion;
};

queue<Requerimiento> colaDeRequerimientos;
queue<Requerimiento> colaDeEspera;

/* Funcion para ver REQUERIMIENTOS incial*/

void visualizarCola() {
    queue<Requerimiento> tempCola = colaDeRequerimientos; // Copiar la cola para no modificar la original
    cout << "Cola de Requerimientos:" << endl;
    if (tempCola.empty()) {
        cout << "La cola está vacía." << endl;
        return;
    }
    while (!tempCola.empty()) {
        Requerimiento req = tempCola.front();
        tempCola.pop();
        cout << "Pagina: " << req.numPagina << ", Accion: " << (req.accion == 'L' || req.accion == 'l' ? "Leer" : "Escribir") << endl;
    }
}

void procesarColaEscritura(int paginaLiberar) {
    queue<Requerimiento> tempCola;
    bool escrituraEncontrada = false;
    bool lecturaEncontrada = false;

    // Paso 1: Procesar escrituras primero
    while (!colaDeRequerimientos.empty()) {
        Requerimiento req = colaDeRequerimientos.front();
        colaDeRequerimientos.pop();
        
        if (req.numPagina == paginaLiberar && (req.accion == 'W' || req.accion == 'w')) {
            cout << "Procesando Escritura en Pagina: " << req.numPagina << endl;
            escrituraEncontrada = true;
            break; // Liberamos solo una escritura
        } else {
            tempCola.push(req);
        }
    }

    // Si encontramos una escritura, liberamos una sola y volvemos a procesar la cola
    if (escrituraEncontrada) {
        // Liberamos la primera escritura encontrada

        // Restaurar la cola original sin los procesados
        while (!tempCola.empty()) {
            colaDeRequerimientos.push(tempCola.front());
            tempCola.pop();
        }
        
        // Mostrar la cola actualizada después de liberar la escritura
        cout << "Cola actualizada después de liberar una escritura:" << endl;
        visualizarCola();
        return; // Terminamos aquí después de liberar la escritura
    }

    // Paso 2: Procesar una lectura después de liberar la escritura
    tempCola = queue<Requerimiento>(); // Restablecer la cola temporal
    while (!colaDeRequerimientos.empty()) {
        Requerimiento req = colaDeRequerimientos.front();
        colaDeRequerimientos.pop();

        if (req.numPagina == paginaLiberar && (req.accion == 'L' || req.accion == 'l')) {
            cout << "Procesando Lectura en Pagina: " << req.numPagina << endl;
            lecturaEncontrada = true;
            // Liberamos solo una lectura
            break;
        } else {
            tempCola.push(req);
        }
    }

    // Si no se encontraron escrituras y se encontró una lectura, mostrar mensaje
    if (!escrituraEncontrada && lecturaEncontrada) {
        // Mostrar la cola actualizada después de liberar una lectura
        cout << "Cola actualizada después de liberar una lectura:" << endl;
        while (!tempCola.empty()) {
            colaDeRequerimientos.push(tempCola.front());
            tempCola.pop();
        }
        visualizarCola();
    }

    // Mostrar la cola original ya que no se realizó ninguna liberación
    if (!escrituraEncontrada && !lecturaEncontrada) {
        cout << "Cola original sin liberaciones:" << endl;
        visualizarCola();
    }
}

void procesarColaLectura(int paginaLiberar) {
    queue<Requerimiento> tempCola;
    bool escrituraEncontrada = false;
    bool lecturaEncontrada = false;

    // Paso 1: Procesar escrituras primero
    while (!colaDeRequerimientos.empty()) {
        Requerimiento req = colaDeRequerimientos.front();
        colaDeRequerimientos.pop();
        
        if (req.numPagina == paginaLiberar && (req.accion == 'L' || req.accion == 'l')) {
            cout << "Procesando Escritura en Pagina: " << req.numPagina << endl;
            escrituraEncontrada = true;
            break; // Liberamos solo una escritura
        } else {
            tempCola.push(req);
        }
    }

    // Si encontramos una escritura, liberamos una sola y volvemos a procesar la cola
    if (escrituraEncontrada) {
        // Liberamos la primera escritura encontrada

        // Restaurar la cola original sin los procesados
        while (!tempCola.empty()) {
            colaDeRequerimientos.push(tempCola.front());
            tempCola.pop();
        }
        
        // Mostrar la cola actualizada después de liberar la escritura
        cout << "Cola actualizada después de liberar una escritura:" << endl;
        visualizarCola();
        return; // Terminamos aquí después de liberar la escritura
    }

    // Paso 2: Procesar una lectura después de liberar la escritura
    tempCola = queue<Requerimiento>(); // Restablecer la cola temporal
    while (!colaDeRequerimientos.empty()) {
        Requerimiento req = colaDeRequerimientos.front();
        colaDeRequerimientos.pop();

        if (req.numPagina == paginaLiberar && (req.accion == 'L' || req.accion == 'l')) {
            cout << "Procesando Lectura en Pagina: " << req.numPagina << endl;
            lecturaEncontrada = true;
            // Liberamos solo una lectura
            break;
        } else {
            tempCola.push(req);
        }
    }

    // Si no se encontraron escrituras y se encontró una lectura, mostrar mensaje
    if (!escrituraEncontrada && lecturaEncontrada) {
        // Mostrar la cola actualizada después de liberar una lectura
        cout << "Cola actualizada después de liberar una lectura:" << endl;
        while (!tempCola.empty()) {
            colaDeRequerimientos.push(tempCola.front());
            tempCola.pop();
        }
        visualizarCola();
    }

    // Mostrar la cola original ya que no se realizó ninguna liberación
    if (!escrituraEncontrada && !lecturaEncontrada) {
        cout << "Cola original sin liberaciones:" << endl;
        visualizarCola();
    }
}

void menuBufferManager(BufferManager &bufferManagerPrincipal) {
    cout << "Bienvenido a implementación de BUFFER" << endl;
    int pesoBytesBLoque;
    cout << "Ingrese el peso de su bloque de Disco: " << endl;
    cin >> pesoBytesBLoque;
    int numFrames;
    cout << "Ingrese la cantidad de Frames a tener en el Buffer Pool: " << endl;
    cin >> numFrames;
    
    bufferManagerPrincipal.crearBufferPoolSegunNumFrames(numFrames);
    bufferManagerPrincipal.establecerLimiteDeFrames(pesoBytesBLoque);
    
    cout << "Creación de estructura Básica de BufferManager implementado." << endl;
}

void menu() {
    BufferManager bufferManagerPrincipal;
    int opcion = 0;
    int numPagina;
    int numFrame;
    int opcionPaginaGuardado;

    while (opcion != 8) { // Cambiado a 8 para incluir la nueva opción
        cout << endl;
        cout << "------- Menú Principal Programa Buffer Manager -------" << endl;
        cout << "1. Crear Buffer Pool" << endl;
        cout << "2. Obtener Una Página" << endl;
        cout << "3. Mostrar Page Table" << endl;
        cout << "4. Liberar uso de Página" << endl;
        cout << "5. Unpinnear Una Página" << endl;
        cout << "6. Visualizar Cola de Requerimientos" << endl;
        cout << "7. Salir del programa principal" << endl;
        cout << "Ingrese el numero de opcion" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                menuBufferManager(bufferManagerPrincipal);
                break;
            }
            case 2: {
                cout << "Ingrese el numero de pagina que desea OBTENER (Modo Prueba 1 - 6): " << endl;
                cin >> numPagina;
                bufferManagerPrincipal.obtenerUnaPagina(numPagina);
                
                char accionPagina;
                cout << "Leer (L/l) o Escribir (W/w) en Pagina?: ";
                cin >> accionPagina;

                //bool requerimientoAgregado = false;

                Requerimiento req = {numPagina, accionPagina};
                colaDeRequerimientos.push(req);
                cout << "Requerimiento agregado a la cola." << endl;

                numFrame = bufferManagerPrincipal.pageTable.getNumFrameDeUnaPagina(numPagina);

                if (accionPagina == 'L' || accionPagina == 'l') {
                    cout << "Proceso de Lectura." << endl;
                    if (bufferManagerPrincipal.pageTable.verificarDirtyPagina(numPagina) == false) {
                        bufferManagerPrincipal.bufferPool.mostrarFramePagina(numFrame);
                        bufferManagerPrincipal.pageTable.aumentarPinCountDePagina(numPagina);
                    }
                    else {
                        cout << "Dirty Bit de la Pagina " << numPagina << " esta en 1." << endl;
                        cout << "No se puede procesar el requerimiento de Lectura hasta que Dirty Bit sea 0." << endl;
                        cout << "Si se quiere procesar el requerimiento de Lectura, debe guardar el archivo." << endl;
                        cout << "Guardar contenido? 0/NO GUARDAR  1/GUARDAR: ";
                        cin >> opcionPaginaGuardado;

                        if (opcionPaginaGuardado == 0) {
                            cout << "Requerimiento a cola de espera." << endl;
                            //Requerimiento colaEspera = {numPagina, accionPagina};
                            //colaDeEspera.push(colaEspera);
                            //requerimientoAgregado = true;
                        }
                        else if (opcionPaginaGuardado == 1) {
                            bufferManagerPrincipal.pageTable.cambiarDirtyBitDePagina(numPagina);
                            bufferManagerPrincipal.bufferPool.agregarContenidoPaginaAbloque(numFrame, numPagina);
                            bufferManagerPrincipal.pageTable.aumentarPinCountDePagina(numPagina);
                        }
                    }
                    break;
                }
                else if (accionPagina == 'W' || accionPagina == 'w') {
                    bufferManagerPrincipal.bufferPool.lecturaOescrituraPagina(numFrame); //escribir
                    bufferManagerPrincipal.pageTable.aumentarPinCountDePagina(numPagina);
                    bufferManagerPrincipal.pageTable.cambiarDirtyBitDePagina(numPagina);
                    break;
                }

                /*
                if (!requerimientoAgregado) {
                    Requerimiento req = {numPagina, accionPagina};
                    colaDeRequerimientos.push(req);
                    cout << "Requerimiento agregado a la cola." << endl;
                }
                */

                //Requerimiento req = {numPagina, accionPagina};
                //colaDeRequerimientos.push(req);
                //cout << "Requerimiento agregado a la cola." << endl;
                break;
            }
            case 3: {
                bufferManagerPrincipal.mostrarPageTAble();
                cout << endl;
                break;
            }
            case 4: {
                cout << "Ingrese el numero de la pagina a liberar (descontar PinCount)" << endl;
                cin >> numPagina;

                if (bufferManagerPrincipal.pageTable.verificarDirtyPagina(numPagina) == true) {
                    cout << "Dirty = 1 " << endl;
                    cout << "Para continuar, desea guardar el contenido? 0/NO GUARDAR  1/GUARDAR" << endl;
                    int opcionPaginaGuardado;
                    cin >> opcionPaginaGuardado;

                    if (opcionPaginaGuardado == 0) {
                        cout << "Página no guardada, no se descuenta pin count." << endl;
                    } else if (opcionPaginaGuardado == 1) {
                        bufferManagerPrincipal.pageTable.cambiarDirtyBitDePagina(numPagina);
                        bufferManagerPrincipal.bufferPool.agregarContenidoPaginaAbloque(numFrame, numPagina);
                        bufferManagerPrincipal.pageTable.descontarPinCountApagina(numPagina);
                        procesarColaEscritura(numPagina);
                    } else {
                        cout << "Opción inválida" << endl;
                    }
                } else if (bufferManagerPrincipal.pageTable.verificarDirtyPagina(numPagina) == false) {
                    cout << "Dirty = 0 " << endl;
                    bufferManagerPrincipal.pageTable.descontarPinCountApagina(numPagina);
                    procesarColaLectura(numPagina);
                }
                else {
                    cout << "sdfgsdf";
                }
                break;
            }
            case 5: {
                cout << "Ingrese Pagina a Despinnear " << endl;
                cin >> numPagina;
                bufferManagerPrincipal.pageTable.unpinnearPagina(numPagina);
                break;
            }
            case 6: {
                visualizarCola();
                break;
            }
            case 7: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:
                cout << "Opción inválida, por favor intente de nuevo." << endl;
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}