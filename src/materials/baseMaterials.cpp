#include "cpm/materialStore.h"

using namespace cpm;

namespace {
    int static registerMaterials() {
        Material steelS235(7850, 235e6);
        Material alluminum(2800, 414e6);
        Material woodOak(770, 20e6);

        MaterialStore::registerMaterial("base.steel.S235", steelS235);
        MaterialStore::registerMaterial("base.alluminum", alluminum);
        MaterialStore::registerMaterial("base.wood.oak", woodOak);
    }
}