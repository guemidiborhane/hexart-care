typedef struct hearbeat {
  int beats;
  int period;
  int startTime;
  int bpm;
}hearbeat;

// fonction permettant d'initialiser notre structure heartbeat avec
// des valeurs coherentes.
void startCapture(hearbeat *HB, int startTime, int period);

// fonction permettant une fois la capture finir d'obtenir le nombre
// de battement par minute
void determineBPM(hearbeat *HB);

// fonction qui permet de dire que notre capture est fini et ensuite
// capturer le nombre de battement par minute
int stopCapture(hearbeat *HB);
