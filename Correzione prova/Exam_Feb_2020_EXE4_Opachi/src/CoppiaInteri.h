#ifndef COPPIAINTERI_H_
#define COPPIAINTERI_H_

typedef struct CoppiaInteri* coppia_interi_ref;
coppia_interi_ref make(int, int);
coppia_interi_ref somma(coppia_interi_ref, coppia_interi_ref);
char* toString(coppia_interi_ref);
void delete(coppia_interi_ref*);

#endif /* COPPIAINTERI_H_ */
