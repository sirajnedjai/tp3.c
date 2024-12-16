#include <stdio.h>
#include <stdlib.h>

typedef struct component {
    int val;
    struct component *suivant;
} component;
// Create an empty string
component* creerListe() {
    return NULL; 
}

// Convert table values ​​to string
component* chargerListe(int Tab[], int taille, component* liste) {
    for (int i = 0; i < taille; i++) {
        component* nouveau = (component*)malloc(sizeof(component));
        nouveau->val = Tab[i];
        nouveau->suivant = liste;
        liste = nouveau;
    }
    return liste;
}

//Show series component
void afficherListe(component* L) {
    component* p1 = L;
    while (p1 != NULL) {
        printf("%d -> ", p1->val);
        p1 = p1->suivant;
    }
    printf("NULL\n");
}

// Delete last component in series
component* supprimerEnFin(component* L) {
    component* p2 = L;
    while (p2->suivant->suivant != NULL) {
        p2 = p2->suivant;
    }
    free(p2->suivant);
    p2->suivant = NULL;
    return L;
}

// Add an component at the beginning of the series 
component* ajouterEnDebut(component* L, int valeur) {
    component* nouveau = (component*)malloc(sizeof(component));
    nouveau->val = valeur;
    nouveau->suivant = L;
    return nouveau;
}

//Emptying string component 
void viderListe(component* L) {
    component* p3;
    while (L != NULL) {
        p3 = L;
        L = L->suivant;
        free(p3);
    }
    printf("La liste est vide.\n");
}
int main(){
int Tab[10]={1,3,5,7,8,10,9,11,13,20};
component*liste=creerListe();
component*L=chargerListe(Tab,10,liste);
afficherListe(L);
component* L1=supprimerEnFin(L);
afficherListe(L1);
component* L2=ajouterEnDebut(L1,40);
afficherListe(L2);
viderListe(L2);
return 0;
}
