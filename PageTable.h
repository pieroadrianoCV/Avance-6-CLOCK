#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>
#include <vector>
using namespace std;

class PageTable{
    public:
        string nameColumnaFrameId = "Frame Id";
        int columnaFrameIdSize;

        string nameColumnaPageId = "Page Id";
        int columnPageIdSize;

        string nameColumnaDirttyId = "Dirty Bit";
        int columnaDirtyIdSize;

        string nameColumnaPinCount = "Pin Count";
        int columnaPinCountSize;

        //string nameColumnaLastUsed = "Last Used";
        //int columnaLastUsedSize;

        string nameColumnaRefBit = "Ref Bit";
        int columnaRefBitSize;

        int numColumnasEnPageTable = 4;
        vector<vector<int>> matrizPageTableLRU;
    public:
        PageTable();
        ~PageTable();
        void mostrarPageTableLRU();
        bool verificarExistenciaDePagina(int numPagina);
        int getNumFrameDeUnaPagina(int numPagina);
        void descontarPinCountApagina(int numPagina);
        void aumentarPinCountDePagina(int numPagina);
        void cambiarDirtyBitDePagina(int numPagina);
        //void renovarLastUsedDePagina(int numPagina);
        //void aumentarLastUsedDePagina(int numPagina);
        void aumentarRefBitDePagina(int numPagina);
        void actualizarInfoDePageTableSolictandoNuevaPagina(int numPaginaActualizar, int numFilaFrameId);
        //void aumentarLastUsedDeTodasLasDemasPaginas(int numFrameAignorar);
        void aplicarCLOCK(int numPagina, int numFrameAignorar, bool &eliminarPageSinEscrituraEnDisco, bool &eliminarPageConEscrituraEnDisco, int &numPaginaEliminada);
        void aplicarClockConCondicionPinCount(int numPagina, int numFrameAignorar, bool &eliminarPageSinEscrituraEnDisco, bool &eliminarPageConEscrituraEnDisco, int &numPaginaEliminada);
        //void aplicarLRU(int numPagina, int numFrameAignorar, bool &eliminarPageSinEscrituraEnDisco, bool &eliminarPageConEscrituraEnDisco, int &numPaginaEliminada);
        string analizarPageTableParaAgregarPagina(int numPagina);
        bool verificarFrameLlenos();
        void actualizarInformacionDePaginaEliminada(int numPaginaActualizar, int nuevaPaginaActualizar);
};

#endif