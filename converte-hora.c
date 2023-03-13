#include <stdio.h>
#include <string.h>

union Horas {
    struct {
        int horas;
        int minutos;
        char periodo[3];
    } doze_horas;

    struct {
        int horas;
        int minutos;
    } vinte_e_quatro_horas;
};

int main() {
    union Horas horas;
    char escolha_am_pm[3];

    printf("Digite a hora no formato 12 horas (HH:MM AM/PM): ");
    scanf("%d:%d %s", &horas.doze_horas.horas, &horas.doze_horas.minutos, escolha_am_pm);

    if (strcmp(escolha_am_pm, "PM") == 0 && horas.doze_horas.horas != 12) {
        horas.doze_horas.horas += 12;
    } else if (strcmp(escolha_am_pm, "AM") == 0 && horas.doze_horas.horas == 12) {
        horas.doze_horas.horas = 0;
    }

    printf("Hora em 24 horas: %02d:%02d\n", horas.doze_horas.horas, horas.doze_horas.minutos);

    printf("Digite a hora no formato 24 horas (HH:MM): ");
    scanf("%d:%d", &horas.vinte_e_quatro_horas.horas, &horas.vinte_e_quatro_horas.minutos);

    if (horas.vinte_e_quatro_horas.horas < 12) {
        printf("Hora em 12 horas: %02d:%02d AM\n", horas.vinte_e_quatro_horas.horas, horas.vinte_e_quatro_horas.minutos);
    } else if (horas.vinte_e_quatro_horas.horas == 12) {
        printf("Hora em 12 horas: %02d:%02d PM\n", horas.vinte_e_quatro_horas.horas, horas.vinte_e_quatro_horas.minutos);
    } else {
        printf("Hora em 12 horas: %02d:%02d PM\n", horas.vinte_e_quatro_horas.horas - 12, horas.vinte_e_quatro_horas.minutos);
    }

    return 0;
}
