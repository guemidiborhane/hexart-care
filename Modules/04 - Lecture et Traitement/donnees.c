#include "donnees.h"
#include <stdio.h>
#include <stdlib.h>

void read(FILE *s, struct heartBeat **h, int m) {
  fseek(s, 0, SEEK_SET); // remet le curseur au debut du fichier
  char tab[60];
  struct heartBeat *tmph;
  if((*h = (struct heartBeat *)malloc(sizeof(struct heartBeat) * (m))) == NULL) {
    printf("Impossible d'allouer de l'espace.\n");
    exit(-1);
  }

  int i;
  tmph = *h;
  for(i = 0; i < (m); ++i) {
    int ntok = fscanf(s, "%d;%d", &(tmph[i].timestamp), &(tmph[i].bpm)); // on lit la ligne et recupere les donné dans notre structure
    if(ntok != 2) {
      printf("File wrongly formatted.\n");
      exit(-1);
    }
  }
}


void sort(int n, struct heartBeat *a, int (cmp)(struct heartBeat *, struct heartBeat *)) { // fonction de tri
	int p0, e0, e1, strd = 1;

	struct heartBeat *tmp, *tmp0, *orig = a;

  if((tmp = malloc(n * sizeof(struct heartBeat))) == NULL) {
    fprintf(stderr, "Unable to malloc enough memory in sorting function.\n");
    exit(-1);
  }

	for(;strd < n;) {
		for(p0 = 0; p0 < (n - (2 * strd)) + 1; p0 = p0 + 2 * strd) {
			e0 = p0 + strd;
			e1 = e0 + strd;

			fuse(a, tmp, p0, e0, e0, e1, cmp);
		}
		if(p0 < n) {
			e0 = p0 + strd;
			e1 = e0 + strd;

			if(e0 > n) e0 = n;
			if(e1 > n) e1 = n;

			fuse(a, tmp, p0, e0, e0, e1, cmp);
		}

		tmp0 = a;
		a = tmp;
		tmp = tmp0;

		strd *= 2;
	}

	if(n >= 2 && tmp == orig) {
		for(p0 = 0; p0 < n; ++p0) {
			orig[p0] = a[p0];
		}
	}
	free(tmp);
}


void fuse(struct heartBeat *a, struct heartBeat *tmp, int s0, int e0, int s1, int e1, int (cmp)(struct heartBeat *, struct heartBeat *)){
  int i0 = s0;
	for(; i0 < e1; ++i0) {
		if(s1 == e1 || (s0 < e0 && (cmp(&a[s0], &a[s1]) <= 0))) {
			tmp[i0] = a[s0];
			s0++;
		}
		else {
			tmp[i0] = a[s1];
			s1++;
		}
	}
}


int compare_by_BPM(struct heartBeat *a, struct heartBeat *b){
    if (a->bpm >= b->bpm){
        return 1;
    } else{
        return 0;
    }
}


int compare_by_date(struct heartBeat *a, struct heartBeat *b){
    if (a->timestamp >= b->timestamp){
        return 1;
    } else{
        return 0;
    }
}
