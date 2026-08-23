#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento() {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};
    Producto p2 = {"Pan", 200, 3};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p2);
    int total = carrito_total(&c);
    int descuento = carrito_descuento(total, 10);  /* 10% de descuento */
    ASSERT_IGUAL(1300, total);      /* 350*2 + 200*3 = 700 + 600 = 1300 */
    ASSERT_IGUAL(1170, descuento);  /* 700 - (700 * 10 / 100) = 630 */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar()
{
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));
    }
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
