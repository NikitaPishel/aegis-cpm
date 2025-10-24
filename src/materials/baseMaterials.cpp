#include "cpm/materialStore.h"

using namespace cpm;

namespace {
    int static registerMaterials() {
        Material steelS235(7850, 235e6);
        Material steelS355(7850, 235e6);
        Material alluminum6061(2720, 276e6);
        Material alluminum2014(2800, 414e6);
        Material woodOak(770, 20e6);

        MaterialStore::registerMaterial("base.steel.S235", steelS235);
        MaterialStore::registerMaterial("base.steel.S355", steelS355);
        MaterialStore::registerMaterial("base.alluminum.6061", alluminum6061);
        MaterialStore::registerMaterial("base.alluminum.2014", alluminum2014);
        MaterialStore::registerMaterial("base.wood.oak", woodOak);

        return 0;
    }

    static int materialInit = registerMaterials();
}