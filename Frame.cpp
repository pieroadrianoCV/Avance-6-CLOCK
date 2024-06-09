#include "./Frame.h"

Frame::Frame() {}

Frame::~Frame() {}

void Frame::leerDatosEnPaginaDeFrame(int numPagina) {
    cout << "muere en leer datos" << endl;
    this->paginaEnFrame.recogerRegistros(numPagina);
}
